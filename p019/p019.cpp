/*

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

#include <iostream>

int daysInMonth(int month, int year) {
    if (month <= 7) {
        if (month == 2) {
            bool leapYear = (year % 4) == 0;
            if (year % 1000 == 0 && year % 400 != 0) {
                leapYear = false;
            }
            return leapYear ? 29 : 28;
        } else {
            return ((month) % 2) + 30;
        }
    } else {
        return ((month + 1) % 2) + 30;
    }
}

int main(int argc, char* argv[]) {
    int sundays = 0;
    int days = 1;
    
    for (int year = 1901; year <= 2000; year++) {
        for (int month = 1; month <= 12; month++) {
            if ((days - 1) % 7 == 0) {
                sundays++;
            }
            days += daysInMonth(month, year);
        }
    }
    
    std::cout << sundays << std::endl;
    
    return 0;
}
