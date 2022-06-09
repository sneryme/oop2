#ifndef ERROR_H
#define ERROR_H
#include <exception>
using namespace std;

class BaseValidError:public exception
{
public:
    BaseValidError(){};
    virtual const char* what() const noexcept override{return "a";};
};

class AllocationError:public BaseValidError
{
public:
    AllocationError(){};
    const char* what() const noexcept override
    {return "Memory alloction error";}
};

class FileError:public exception
{
public:
    FileError(){};
    virtual const char* what() const noexcept override;
};

class FileWriteError:public BaseValidError
{
public:
    FileWriteError(){};
    const char* what() const noexcept override
    {return "File write error";}
};

class FileOpenError:public BaseValidError
{
public:
    FileOpenError(){};
    const char* what() const noexcept override
    {return "File opening error";}
};



#endif // ERROR_H
