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
    std::ostringstream ret;
    ret << t;
    return ret.str();
}


template <typename T>
