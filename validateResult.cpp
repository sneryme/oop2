#include "syntaxvalidator.h"
#include <memory>
#include <iostream>
#include <string>

using std::shared_ptr;
using std:: string;
#include "error.h"

string syntaxValidator::validateResult::what()
{
    if (!!strInfo)
        return *strInfo;
    return "Json is valid";
}

int syntaxValidator::validateResult::whatStr()
{
    return stringNum;
}

int syntaxValidator::validateResult::whatChar()
{
    return charNum;
}

bool syntaxValidator::validateResult::operator!()
{
    return !rez;
}

syntaxValidator::validateResult syntaxValidator::makeValidateResult(State st, Lexem lx)
{
    validateResult rez;
    rez.rez = false;
    rez.stringNum = stringNum;
    rez.charNum = charNum;
    try{
    rez.strInfo = std::make_unique<string>("(" + std::to_string(stringNum) + ", " + std::to_string(charNum) + "): Waiting for ");
    switch (st) {
    case AVALUE:
    case ARRAY:
    case OVALUE:
    case BEGIN:
        rez.strInfo->append("value");
        break;
    case OCOMMA:
        rez.strInfo->append("',' or '}'");
    case ACOMMA:
        rez.strInfo->append("',' or ']'");
        break;
    case OBJECT:
        rez.strInfo->append("string");
        break;
    case COLON:
        rez.strInfo->append("':'");
        break;
    default:
        break;
    }
    rez.strInfo->append(" but get ");
    switch(lx){
    case L_OBEGIN:
        rez.strInfo->append("'{'");
        break;
    case L_OEND:
        rez.strInfo->append("'}'");
        break;
    case L_ABEGIN:
        rez.strInfo->append("'['");
        break;
    case L_AEND:
        rez.strInfo->append("']'");
        break;
    case L_COLON:
        rez.strInfo->append("':'");
        break;
    case L_COMMA:
        rez.strInfo->append("','");
        break;
    case L_STRING:
        rez.strInfo->append("string");
        break;
    case L_NUMBER:
    case L_BOOL:
    case L_NULL:
        rez.strInfo->append("value");
        break;
    case L_ERROR:
        rez.strInfo->append("end of string");
        break;
    }
    }catch(std::exception& ex){throw AllocationError();}
    return rez;
}

syntaxValidator::validateResult syntaxValidator::makeValidateResult(State st)
{
    validateResult rez;
    if(st == END){
        rez.rez = true;
    } else {
        rez.rez =false;
        rez.stringNum = stringNum;
        rez.charNum = charNum;
        try{
        rez.strInfo = std::make_unique<string>("(" + std::to_string(stringNum) + ", " + std::to_string(charNum) + "): ");
        if(st == OVALUE)
            rez.strInfo->append("Error in lexem syntax");
        else if (st == OBJECT)
            rez.strInfo->append("Repeating key in object");
        else if (st == BEGIN)
            rez.strInfo->append("Some trash after json");
        }catch(std::exception& ex){throw AllocationError();}
    }
    return rez;
}
