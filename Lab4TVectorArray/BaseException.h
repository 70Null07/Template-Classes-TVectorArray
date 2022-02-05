//BaseException.h
#include "Config.h"

class BaseException : public exception
{
protected:
    string text;
public:
    virtual string what() = 0;
};

class NegativeIndex final :public BaseException
{
public:
    NegativeIndex(string _text = "Error. Negative Index.") { text = _text; }
    string what() { return text; }
};

class BellowZero final :public BaseException
{
public:
    BellowZero (string _text = "Error. Negative Input (Bellow Zero).") { text = _text; }
    string what() { return text; }
};

class StringException final :public BaseException
{
public:
    StringException(string _text = "Error. Negative Input (String).") { text = _text; }
    string what() { return text; }
};