#include "syntaxvalidator.h"
#include <string>
#include <iostream>
#include <stack>
#include <set>
#include "error.h"
using std::stod;
using std::cout;
using std::set;
using std::stack;

syntaxValidator::validateResult syntaxValidator::validate()
{

    len = str->size();
    int cur = 0;
    stringNum = 1;
    charNum = 0;
    int end = cur;
    stack < set <string> > objects;

    validateResult rez = validateJson(cur, end, objects);
    if(!rez)
        return rez;
    skipWhiteSpaces(end);
    if(end != len){
        return makeValidateResult(BEGIN);
    }
    else
        return makeValidateResult(END);
}

syntaxValidator::validateResult syntaxValidator::validateJson(int cur, int& end,  stack < set <string> >& objects)
{
    State state = BEGIN;
    validateResult rez;
    while(cur!= len)
    {
        Lexem lexem = getLexem(cur, end);
        charNum += end - cur;

        rez = lexemAnalize(cur, end, state, lexem, objects);

        if(!rez)
            break;
        else {
            State newState = syntax[state][lexem];
            if(newState == ERR){
                rez = makeValidateResult(state, lexem);
                break;
            } else if (newState == END){
                rez = makeValidateResult(END);
                break;
            }
            state = newState;
            cur = end;
        }
        skipWhiteSpaces(cur);
    }

    if(cur == len)
        return makeValidateResult(state, L_ERROR);
    else
        return rez;
}

syntaxValidator::validateResult syntaxValidator::lexemAnalize(int cur, int& end, State state, Lexem lexem, stack<set<string>>& objects)
{
    try{

    switch(lexem){
    case L_ERROR:
        return makeValidateResult(OVALUE);
    case L_OBEGIN:
        if(state == BEGIN)
            objects.push(set<string>());
        break;
    case L_OEND:
        objects.pop();
        break;
    case L_STRING:
        if(state == OBJECT){
            if(objects.top().find(str->substr(cur, end-cur)) == objects.top().end())  //проверка встречался ли такой же ключ в разбираемом классе
            objects.top().insert(str->substr(cur, end-cur));
        else
            return makeValidateResult(OBJECT);
        }
        break;
    default:;
    }

    }catch(exception& ex){throw AllocationError();}

    if((state == OVALUE || state == AVALUE || state == ARRAY) &&  // запуск подразбора если массив или объект
      (lexem == L_OBEGIN || lexem == L_ABEGIN)){
        validateResult rez = validateJson(cur, end, objects);
        if(!rez)
            return rez;
    }

    return makeValidateResult(END);
}

void syntaxValidator::skipWhiteSpaces(int& cur)
{
    while(isspace((*str)[cur])){
        if((*str)[cur] == '\n'){
            stringNum++;
            charNum = 0;
        } else
            charNum++;
        cur++;
    }
}

syntaxValidator::Lexem syntaxValidator::getLexem(int cur, int& end)
{
    if(cur == len)
        return L_ERROR;
    end = cur + 1;
    switch ((*str)[cur]) {
        case '{': return L_OBEGIN;
        case '}': return L_OEND;
        case '[': return L_ABEGIN;
        case ']': return L_AEND;
        case ':': return L_COLON;
        case ',': return L_COMMA;
        case char(34): return getString(cur, end);
        default: return getValue(cur, end);
    }
}

syntaxValidator::Lexem syntaxValidator::getString(int cur, int& end)
{
    cur++;
    //cout << "string enter " <<(*str)[cur];
    while(cur != len && (*str)[cur] != '"')
    {
        if((*str)[cur]=='\n')
            stringNum++;
        cur++;
    }
    if((*str)[cur] == '"'){
        end = cur + 1;
        return L_STRING;
    } else
        return L_ERROR;
}

syntaxValidator::Lexem syntaxValidator::getValue(int cur, int& end)
{
    end = cur;
    Lexem lexem;
    if(str->compare(cur, sizeof("true") - 1, "true") == 0){
        end += sizeof("true") - 1;
        lexem = L_BOOL;
    } else if (str->compare(cur, sizeof("false") - 1, "false") == 0){
        end += sizeof("false") - 1;
        lexem = L_BOOL;
    } else if (str->compare(cur, sizeof("null") - 1, "null") == 0){
        end += sizeof("null") - 1;
        lexem = L_NULL;
    } else {
        size_t n = 0;
        try{
            stod(str->substr(cur, std::min(len - cur + 1,  20)), &n);
        } catch(std::exception ex){};
        if(n==0){
            lexem = L_ERROR;
        } else {
            end += n;
            lexem = L_NUMBER;
        }
    }
    return lexem;
}


