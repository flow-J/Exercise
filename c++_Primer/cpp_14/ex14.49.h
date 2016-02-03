#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>

class Date
{
    friend bool             operator ==(const Date &lhs, const Date& rhs);
    friend bool             operator < (const Date &lhs, const Date& rhs);
    friend bool             check(const Date &d);
    friend std::ostream&    operator <<(std::ostream& os, const Date &d);

public:
    typedef std::size_t Size;

    Date() =default;

    explicit Date(Size days);
    Date(Size d, Size m, Size y) : day(d), month(m), year(y) { }
    Date(std::istream &is, std::ostream &os);

    Date(const Date& d);
    Date(Date&& d) noexcept;

    Date& operator= (const Date& d);
    Date& operator= (Date&& rhs) noexcept;

    ~Date(){ std::cout << "destroying\n"; }

    Size toDays() const;
    Date& operator +=(Size offset);
    Date& operator -=(Size offset);
    explicit operator bool() { return (year<4000) ? true : false; }

private:
    Size    day = 1;
    Size    month = 1;
    Size    year = 0;
};


static const Date::Size YtoD_400 = 146097;
static const Date::Size YtoD_100 =  36524;
static const Date::Size YtoD_4   =   1461;
static const Date::Size YtoD_1   =    365;


static const std::vector<Date::Size> monthsVec_n =
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

static const std::vector<Date::Size> monthsVec_l =
{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


std::ostream&
operator <<(std::ostream& os, const Date& d);
std::istream&
operator >>(std::istream& is, Date& d);
int
operator - (const Date& lhs, const Date& rhs);
bool
operator ==(const Date& lhs, const Date& rhs);
bool
operator !=(const Date& lhs, const Date& rhs);
bool
operator < (const Date& lhs, const Date& rhs);
bool
operator <=(const Date& lhs, const Date& rhs);
bool
operator  >(const Date& lhs, const Date& rhs);
bool
operator >=(const Date& lhs, const Date& rhs);
Date
operator - (const Date& lhs, Date::Size rhs);
Date
operator + (const Date& lhs, Date::Size rhs);

bool check(const Date &d);
inline bool
isLeapYear(Date::Size y);

inline bool
check(const Date &d)
{
    if(d.month==0 || d.month >12)
        return false;
    else
    {
        if (d.month==1 || d.month==3 || d.month==5 || d.month== 7 ||
            d.month==8 || d.month==10|| d.month==12)
        {
            if(d.day==0 || d.day > 31) return false;
            else
                return true;
        }
        else
        {
            if(d.month==4 || d.month==6 || d.month==9 || d.month==1)
            {
                if(d.day==0 || d.day > 30) return false;
                else
                    return true;
            }
            else
            {
                if(isLeayYear(d.year))
                {
                    if(d.day== || d.day >29) return false;
                    else
                        return true;
                }
                else
                {
                    if(d.day==0 || d.day >28) return false;
                    else
                        return true;
                }
            }
        }
    }
}

inline bool
isLeapYear(Date::Size y)
{
    if (!(y%400))
    {
        return true;
    }
    else
    {
        if(!(y%100))
        {
            return false;
        }
        else
            return !(y%4);
    }
}

#endif


/*****************************************************************
*****************************************************************/
#include <algorithm>

Date::Date(Size days)
{
    Size y400 = days/YtoD_400;
    Size y100 = (days - y400*YtoD_400)/YtoD_100;
    Size y4   = (days - y400*YtoD_400 - y100YtoD_100)/YtoD_4;
    Size y    = (days - y400*YtoD_400 - y100*YtoD_100 - y4*YtoD_4)/365;
    Size d    =  days - y400*YtoD_400 - y100*YtoD_100 - y4*YtoD_4 - y*365;
    this->year = y400*400 + y100*100 + y4*4 + y;

    std::
}
