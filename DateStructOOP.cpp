//
// Created by cperk on 2/11/2021.
//
/*
 * Start with the date structure in Exercise 5 in Chapter 4 and transform it into a date
class. Its member data should consist of three ints: month, day, and year. It should also
have two member functions: getdate(), which allows the user to enter a date in
12/31/02 format, and showdate(), which displays the date.
 */

#include <iostream>
using namespace std;

class date {
public:
    date(int d, int m, int y) : day(d), month(m),year(y){}
    void setdate(int d ,int m ,int y){
        day = d;
        month = m;
        year = y;
    }
    void getdate() const{
        cout << "The date you input was: " << day << "/" << month << "/" << year << endl;}
private:
    int day;
    int month;
    int year;
};

int main()
{
    int d,m,y;
    char dummy;
    cout << "Please enter the date in format DD/MM/YYYY: " << endl;
    std::cin >> d >> dummy >> m >> dummy >> y;
    class date d1(d,m,y);
    d1.getdate();
}



