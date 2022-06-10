#include "entrypoint.h"
#include "error.h"

using namespace std;

entryPoint::entryPoint()
{
    mngr = nullptr;
}

void entryPoint::setFile(string str)
{
    if(!mngr){
        delete mngr;
        mngr = nullptr;
    }
    mngr = new TextFileManager(str);
    if(!mngr){
        throw AllocationError();}
}

shared_ptr<string> entryPoint::getDataFromFile()
{
    return mngr->getDataFromFile();
}

syntaxValidator::validateResult entryPoint::validate(shared_ptr<string> str)
{
    syntaxValidator val(str);
    return val.validate();
}



bool entryPoint::isFileSet()
{
    if(!!mngr)
        return true;
    else
        return false;
}

entryPoint::~entryPoint()
{
    if(!!mngr)
        delete mngr;
}
