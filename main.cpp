#include <iostream>
#include <memory>
#include "Date.h"
#include "SmartPointer.h"
using namespace std;

int main() {
    Date date1(1, 5, 2023);

    SmartPointer<Date> sp(&date1);

    std::cout << "Date using SmartPointer: " << *sp << std::endl;

    std::cout << "Day using SmartPointer: " << sp->getDay() << std::endl;

    std::shared_ptr<Date> sptr = std::make_shared<Date>(2, 5, 2023);

    std::cout << "Date using shared_ptr: " << *sptr << std::endl;

    std::cout << "Day using shared_ptr: " << sptr->getDay() << std::endl;

    Date date2(1, 5, 2023);
    if (date1 == date2) {
        std::cout << "date1 and date2 are equal" << std::endl;
    } else {
        std::cout << "date1 and date2 are not equal" << std::endl;
    }

    std::cout << "date1 before increment: " << date1 << std::endl;
    ++date1;
    std::cout << "date1 after prefix increment: " << date1 << std::endl;
    Date date3 = date1++;
    std::cout << "date1 after postfix increment: " << date1 << std::endl;
    std::cout << "date3 after postfix increment: " << date3 << std::endl;

    Date date4(1, 1, 1970);
    std::cout << "Days since epoch for " << date4 << ": " << Date::daysSinceEpoch(date4) << std::endl;
    std::cout << "Difference in days between " << date1 << " and " << date4 << ": " << Date::getDifferenceDays(date1, date4) << std::endl;

    return 0;
}
