#pragma once

#include <exception>
#include <string>
#include <sstream>
#include <string.h>

namespace hamurai
{
    class Exception : public std::exception
    {
    public:
        Exception( const std::string& description, std::string fileName = "", int line = -1 )
            :_desc(description), _fileName(fileName), _line(line)
        {

        }

        Exception( const Exception& other )
        {
            _desc = other._desc;
            _line = other._line;
            _fileName = other._fileName;
        }

        virtual const char* what() const throw()
        {
            return _desc.c_str();
        }

        virtual const char* file() const throw()
        {
            return _fileName.c_str();
        }

        virtual const int line() const throw()
        {
            return _line;
        }

        virtual std::string verbose_what() const throw()
        {
            // std::cerr << _desc << std::endl;
            std::stringstream sstr;
            sstr << "Hamurai Exception [ " << _fileName << ":" << _line << " ] - " << _desc;
            return sstr.str();
        }

    private:
        std::string _desc;
        std::string _fileName;
        int _line;

    };
}

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define HAMURAI_THROW(arg) throw hamurai::Exception( arg, __FILENAME__, __LINE__ );
