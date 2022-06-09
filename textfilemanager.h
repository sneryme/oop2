#ifndef TEXTFILEMANAGER_H
#define TEXTFILEMANAGER_H
#include <memory>
#include <string>
using std::string;
using std::shared_ptr;

class TextFileManager
{
private:
    string fileWay;
public:
    TextFileManager() = delete;
    TextFileManager(string filePath);
    shared_ptr<string> getDataFromFile();
    void rewriteFile(shared_ptr<string> str);
};

#endif // TEXTFILEMANAGER_H
