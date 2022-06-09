#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H
#include <memory>
#include <string>
#include "syntaxvalidator.h"
#include "textfilemanager.h"

using namespace std;

class entryPoint
{
private:
    TextFileManager* mngr;
public:
    entryPoint();
    ~entryPoint();
    void setFile(string str);
    bool isFileSet();
    shared_ptr<string> getDataFromFile();
    syntaxValidator::validateResult validate(shared_ptr<string> str);
    void reWriteFile(shared_ptr<string> str);
};

#endif // ENTRYPOINT_H
