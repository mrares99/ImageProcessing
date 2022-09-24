#ifndef MY_EXCEPTION_
#define MY_EXCEPTION_

#include <iostream>

class MyException : public std::exception
{
private:
    int line;
    const std::string fileName;
    const std::string function;
    const std::string information;
public:
    MyException(const char* msg, const int line, const std::string fileName, std::string function,
        std::string information = "");

    const std::string get_file_name();
    int get_line();
    const std::string get_function();
    const std::string get_information();
    void print_fields();
};


#endif