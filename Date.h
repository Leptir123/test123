#ifndef NALOGA0901_DATE_H
#define NALOGA0901_DATE_H
#include <string>
#include <ostream>

class Date {
public:
    friend std::ostream &operator<<(std::ostream &os, const Date &date);

private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    static const int months[];

public:
    Date(unsigned int day, unsigned int month, unsigned int year);

    bool operator==(const Date& other) const;

    unsigned int getDay() const;
    void setDay(unsigned int day);

    unsigned int getMonth() const;
    void setMonth(unsigned int month);

    unsigned int getYear() const;
    void setYear(unsigned int year);

    std::string toString() const;

    //returns the current date
    static Date getCurrentDate();
    //returns the number of days since unix epoch which is 1. 1. 1970 (date - Date(1, 1, 1970))
    static unsigned int daysSinceEpoch(const Date& date);
    //returns difference between provided dates in days
    static int getDifferenceDays(const Date& date1, const Date& date2);

    Date& operator++();
    Date operator++(int dummy);
};

#endif //NALOGA0901_DATE_H
