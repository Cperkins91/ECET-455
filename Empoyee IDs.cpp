//
// Created by cperk on 1/28/2021.
//

/*
 * . Create a structure called employee that contains two members: an employee number
(type int) and the employee’s compensation (in dollars; type float). Ask the user to fill
in this data for three employees, store it in three variables of type struct employee, and
then display the information for each employee.
 */

/*
 * I had planned on using a while loop and a switch statement to iterate through the employees. I was having trouble getting the switch
 * statement to work and was running short on time. Hopefully I can return and fix this so that is isn't so repetetive!
 */


/*
#include <iostream>
using namespace std;

struct employee {
    int ID;
    float compensation;
};

int main()
{
    employee e1,e2,e3; // declare structs
    int position = 0;
    while (position != -1) // While loop to keep program running
    {
        cout << "Which employee would you like to modify?: (1,2,3,etc) \n"
                " Enter -1 to exit and show employee database" << endl;
        cin >> position;
        switch (position) {
            case 1:
                cout << "Please enter the employee ID:" << endl;
                cin >> e1.ID;
                cout << "Please enter the employee compensation" << endl;
                cin >> e1.compensation;
                break;
            case 2:
                cout << "Please enter the employee ID:" << endl;
                cin >> e2.ID;
                cout << "Please enter the employee compensation" << endl;
                cin >> e2.compensation;
                break;
            case 3:
                cout << "Please enter the employee ID:" << endl;
                cin >> e3.ID;
                cout << "Please enter the employee compensation" << endl;
                cin >> e3.compensation;
                break;
        }
    }
    cout << "Employee 1 ID is: " << e1.ID << "\n Employee 1 Compensation: " << e1.compensation << endl;
    cout << "Employee 2 ID is: " << e2.ID << "\n Employee 2 Compensation: " << e2.compensation << endl;
    cout << "Employee 3 ID is: " << e3.ID << "\n Employee 3 Compensation: " << e3.compensation << endl;
}

 */