//
// Created by cperk on 2/12/2021.
//

#ifndef TEST_ENV_DATE_H
#define TEST_ENV_DATE_H

class Date {
public:
   // Date(int d=1, int m=1, int y=1900);
    Date(int d, int m, int y) : day(d), month(m),year(y){}
    void SetDate(){
        char dummy;
        std::cout << "Please enter the date in format DD/MM/YYYY: " << std::endl;
        std::cin >> day >> dummy >> month >> dummy >> year;
    }
    void getdate() const{
        std::cout << "The date you input was: " << day << "/" << month << "/" << year << std::endl;}
private:
    int day;
    int month;
    int year;
};

#endif //TEST_ENV_DATE_H