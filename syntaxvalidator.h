#ifndef SYNTAXVALIDATOR_H
#define SYNTAXVALIDATOR_H
#include <memory>
#include <string>
#include <set>
#include <stack>

using std::shared_ptr;
using std::unique_ptr;
using std::string;
using std::set;
using std::stack;

class syntaxValidator
{
private:
    shared_ptr<string> str;
    int len;
    int stringNum;
    int charNum;
    enum State {
        BEGIN,
        OBJECT,
        COLON,
        OVALUE,
        OCOMMA,
        ARRAY,
        ACOMMA,
        AVALUE,
        ERR,
        END
    };
    enum Lexem {
        L_OBEGIN,
        L_OEND,
        L_ABEGIN,
        L_AEND,
        L_COLON,
        L_COMMA,
        L_STRING,
        L_NUMBER,
        L_BOOL,
        L_NULL,
        L_ERROR
    };
    const State syntax [8][10] = {
    //           L_OBEGIN   L_OEND  L_ABEGIN L_AEND L_COLON L_COMMA L_STRING L_NUMBER   L_BOOL  L_NULL
    /*BEGIN*/   {OBJECT,    ERR,    ARRAY,  ERR,    ERR,    ERR,    END,    END,        END,    END},
    /*OBJECT*/  {ERR,       END,    ERR,    ERR,    ERR,    ERR,    COLON,  ERR,        ERR,    ERR},
    /*COLON*/   {ERR,       ERR,    ERR,    ERR,    OVALUE, ERR,    ERR,    ERR,        ERR,    ERR},
    /*OVALUE*/  {OCOMMA,    ERR,    OCOMMA, ERR,    ERR,    ERR,    OCOMMA, OCOMMA,     OCOMMA, OCOMMA},
    /*OCOMMA*/  {ERR,       END,    ERR,    ERR,    ERR,    OBJECT, ERR,    ERR,        ERR,    ERR},
    /*ARRAY*/   {ACOMMA,    ERR,    ACOMMA, END,    ERR,    ERR,    ACOMMA, ACOMMA,     ACOMMA, ACOMMA},
    /*ACOMMA*/  {ERR,       ERR,    ERR,    END,    ERR,    AVALUE, ERR,    ERR,        ERR,    ERR},
    /*AVALUE*/  {ACOMMA,    ERR,    ACOMMA, ERR,    ERR,    ERR,    ACOMMA, ACOMMA,     ACOMMA, ACOMMA}
        };

public:
    class validateResult{
        bool rez;
        int stringNum;
        int charNum;
        unique_ptr<string> strInfo;
    public:
        bool operator!();
        string what();
        int whatStr();
        int whatChar();
        friend class syntaxValidator;
    };
    friend class validateResult;

    syntaxValidator() = delete;
    syntaxValidator(shared_ptr<string> pStr){ str = pStr;};
    validateResult validate();

private:
    validateResult validateJson(int cur, int& end, stack < set <string> >& objects);
    void skipWhiteSpaces(int& cur);
    validateResult makeValidateResult(State, Lexem);
    validateResult makeValidateResult(State);
    validateResult lexemAnalize(int, int&, State, Lexem, stack < set <string> >&);
    Lexem getLexem(int cur, int& end);
    Lexem getString(int cur, int& end);
    Lexem getValue(int cur, int& end);
};



#endif // SYNTAXVALIDATOR_H
