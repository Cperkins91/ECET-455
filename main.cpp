//
// Created by cperk on 2/11/2021.
//

/*
 * .  Create an employee class, basing it on Exercise 4 of Chapter 4. The member data should
comprise an int for storing the employee number and a float for storing the employee’s
compensation. Member functions should allow the user to enter this data and display it.
Write a main() that allows the user to enter data for three employees and display it.
 */
/*
 * Extend the employee class of Exercise 4 to include a date class (see Exercise 5) and an
etype enum (see Exercise 6 in Chapter 4). An object of the date class should be used to
hold the date of first employment; that is, the date when the employee was hired. The
etype variable should hold the employee’s type: laborer, secretary, manager, and so on.
These two items will be private member data in the employee definition, just like the
employee number and salary. You’ll need to extend the getemploy() and putemploy()
functions to obtain this new information from the user and display it. These functions will
probably need switch statements to handle the etype variable. Write a main() program that
allows the user to enter data for three employee variables and then displays this data.
 */
#include <iostream>
#include "Date.h"
using namespace std;

class employee {
public:
    Date DateHired;
    employee(const Date &dateHired) : DateHired(dateHired) {}
    void setID(){
        cout << "What is the employee ID? " << endl;
        cin >> ID;
    }
    void setCompensation(){
        cout << "What is the employee compensation? " << endl;
        cin >> EmpComp;
    }
    void getInfo() const{
        cout << "Employee " << ID << "'s compensation is " << EmpComp << endl;
    }
    int getID() const{
        return ID;}
    int getCompensation() const{
        return EmpComp;}
private:
    int ID;
    float EmpComp;
};

int main()
{
    employee e1(Date(1,1,1900)), e2(Date(1,1,1900)), e3(Date(1,1,1900)); // init objects
    int position = 0;
    while (position != -1) // While loop to keep program running
    {
        cout << "Which employee would you like to modify?: (1,2,3,etc) \n"
                " Enter -1 to exit and show employee database" << endl;
        cin >> position;
        switch (position) {
            case 1:
                e1.setID();
                e1.setCompensation();
                e1.DateHired.SetDate();
                break;
            case 2:
                e2.setID();
                e2.setCompensation();
                break;
            case 3:
                e3.setID();
                e3.setCompensation();
                break;
        }
    }
    e1.getInfo();
    e2.getInfo();
    e3.getInfo();
}


