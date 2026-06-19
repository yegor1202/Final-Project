#include "Date.h"

#include <chrono>
#include <ctime>
#include <sstream>

Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
};

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
};

int Date::getDay() const
{
    return day;
};

int Date::getMonth() const
{
    return month;
};

int Date::getYear() const
{
    return year;
};

void Date::setDay(int day)
{
    this->day = day;
};

void Date::setMonth(int month)
{
    this->month = month;
};

void Date::setYear(int year)
{
    this->year = year;
};

string Date::toString() const
{
    stringstream ss;

    if (day < 10)
        ss << "0";
    ss << day << ".";

    if (month < 10)
        ss << "0";
    ss << month << ".";

    ss << year;

    return ss.str();
};


bool Date::operator<(const Date& other) const
{
    if (year != other.year)
        return year < other.year;

    if (month != other.month)
        return month < other.month;

    return day < other.day;
};

bool Date::operator>(const Date& other) const
{
    return other < *this;
};

bool Date::operator==(const Date& other) const
{
    return day == other.day
        && month == other.month
        && year == other.year;
};

