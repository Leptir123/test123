#include "Date.h"
#include <iostream>
#include <ctime>
#include <chrono>

Date::Date(unsigned int day, unsigned int month, unsigned int year) : day(day), month(month), year(year) {}

const int Date::months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

unsigned int Date::getDay() const {
    return day;
}

void Date::setDay(unsigned int day) {
    Date::day = day;
}

unsigned int Date::getMonth() const {
    return month;
}

void Date::setMonth(unsigned int month) {
    Date::month = month;
}

unsigned int Date::getYear() const {
    return year;
}

void Date::setYear(unsigned int year) {
    Date::year = year;
}

std::string Date::toString() const {
    return std::to_string(day) + ". " + std::to_string(month) + ". " + std::to_string(year);
}

Date Date::getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return {(unsigned int)ltm->tm_mday, (unsigned int)(1 + ltm->tm_mon), (unsigned int)(1900 + ltm->tm_year)};
}

unsigned int Date::daysSinceEpoch(const Date& date) { /* Rata Die day one is 0001-01-01 */
    unsigned int d = date.day;
    unsigned int m = date.month;
    unsigned int y = date.year;
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

int Date::getDifferenceDays(const Date &date1, const Date &date2) {
    return daysSinceEpoch(date1) - daysSinceEpoch(date2);
}

bool Date::operator==(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
}

Date& Date::operator++() {
    day++;
    if (day > months[month - 1]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator++(int dummy) {
    Date temp(day, month, year);
    operator++();
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << "day: " << date.day << " month: " << date.month << " year: " << date.year;
    return os;
}
