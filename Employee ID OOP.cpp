//
// Created by cperk on 2/11/2021.
//

/*
 * .  Create an employee class, basing it on Exercise 4 of Chapter 4. The member data should
comprise an int for storing the employee number and a float for storing the employee’s
compensation. Member functions should allow the user to enter this data and display it.
Write a main() that allows the user to enter data for three employees and display it.
 */

#include <iostream>
using namespace std;

class employee {
public:
    void setID(){
        cout << "What is the employee ID? " << endl;
        cin >> ID;
    }
    void setCompensation(){
        cout << "What is the employee compensation? " << endl;
        cin >> EmpComp;
    }
    void getInfo(){
        cout << "Employee " << ID << "'s compensation is " << EmpComp << endl;
    }
    int getID(){
        return ID;}
    int getCompensation(){
        return EmpComp;}
private:
    int ID;
    float EmpComp;
};

int main()
{
    employee e1,e2,e3; // init objects
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


