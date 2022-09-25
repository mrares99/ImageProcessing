#include "MyException.h"


MyException::MyException(const char* msg, const int line, const std::string fileName, 
    std::string function, std::string information) : 
    std::exception(msg),
    line{ line },
    fileName{ fileName },
    function{ function },
    information{ information }
{
}

const std::string MyException::get_file_name() { return fileName; }
int MyException::get_line() { return line; }
const std::string MyException::get_function() { return function; }
const std::string MyException::get_information() { return information; }
void MyException::print_fields() {
    std::cout << "File name: " << fileName << " Function: " << function <<
        " Information: " << information << " Line: " << line;
}

