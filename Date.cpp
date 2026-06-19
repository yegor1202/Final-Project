#include "Date.h"

#include <chrono>
#include <ctime>
#include <sstream>
#include <string>

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

Date Date::today()
{
    auto now = chrono::system_clock::now();

    time_t currentTime =
        chrono::system_clock::to_time_t(now);

    tm* localTime =
        localtime(&currentTime);

    return Date(
        localTime->tm_mday,
        localTime->tm_mon + 1,
        localTime->tm_year + 1900
    );
};
Date Date::fromString(const string& text)
{
    stringstream ss(text);

    int day;
    int month;
    int year;

    char dot;

    ss >> day >> dot
       >> month >> dot
       >> year;

    return Date(day, month, year);
}

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

