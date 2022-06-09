#include "textfilemanager.h"
#include <fstream>
#include "error.h"
using namespace std;

TextFileManager::TextFileManager(string filePath)
{
    fileWay = filePath;
}

shared_ptr<string> TextFileManager::getDataFromFile()
{
    ifstream fin;
    shared_ptr<string>  str;
    fin.open(fileWay);
    if(fin.is_open())
    {
        str = shared_ptr<string>(new string);
        if(!str)
            throw AllocationError();
        try{
            str->assign(istreambuf_iterator<char>(fin.rdbuf()), istreambuf_iterator<char>());
            fin.close();
        } catch(exception& ex){
            throw AllocationError();
        }
    } else
        throw FileOpenError();
    return str;
}

void TextFileManager::rewriteFile(shared_ptr<string> pStr)
{
    ofstream file;
    int len = pStr->size();
    file.open(fileWay);
    if(!file.is_open())
        throw FileOpenError();
    try {
        file << *pStr;
        filesystem::resize_file(fileWay, len);
    } catch(exception& ex){
        throw FileWriteError();
    }
}
