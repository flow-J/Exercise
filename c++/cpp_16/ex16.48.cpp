#include <iostream>
#include <memory>
#include <sstream>

template <typename T> std::string debug_rep(const T& t);
template <typename T> std::string debug_rep(T* p);

std::string debug_rep(const std::string &s);
std::string debug_rep(char* p);
std::string debug_rep(const char *p);


template <typename T> std::string debug_rep(const T& t)
{
    std::ostringstream ret;// 可以自动推导类型
    ret << t;
    return ret.str();
}


template<typename T> std::string debug_rep(T* p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;

    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";

    return ret.str();
}

std::string debug_rep(const std::string &s)
{
    return '"' + s +'"' ;
}


std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p)
{
    return debug_rep(std::string(p));
}
