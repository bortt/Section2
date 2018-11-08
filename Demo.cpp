// Bryan Ortt
// CECS282 - Lab7

#include "Employee.h"
#include "Staff.h"
#include "Faculty.h"
#include "PartTime.h"
#include <iomanip>

#include <iostream>
using namespace std;


int main() {
	// Hello
    
    Employee *empArray[15];
    empArray[0] = new Staff("Allen","Paita","123",'M',"2/23/59",50.00);
    empArray[1] = new Staff("Zapata","Steven","456",'F',"7/12/64",35.00);
    empArray[2] = new Staff("Rios","Enrique","789",'M',"6/2/70",40.00);
    
    empArray[3] = new Faculty("Johnson", "Anne", "254", 'F', "4/27/62", "Full",Education("Ph.D", "Engineering", 3));
    empArray[4] = new Faculty("Bouris", "William", "791", 'F', "3/14/75", "Associate",Education("Ph.D", "english", 1));
    empArray[5] = new Faculty("Andrade", "Christopher", "623", 'F', "5/22/80", "Assistant",Education("MS", "Physical Education", 0));
    
    
    empArray[6] = new PartTime("Guzman","Augusto","455",'F',"8/10/77",35.00,30);
    empArray[7] = new PartTime("Depirro","Martin","678",'F',"9/15/87",30.00,15);
    empArray[8] = new PartTime("Aldaco","Marque","945",'M',"11/24/88",20.00,35);
    
    // putData print
    double ptSalaryTotal = 0;
    double employeeSalaryTotal = 0;
    
    cout <<"a. Employee information using the method putData: "<< endl;
    for (int i = 0; i < 9; i++) {
        
        if (typeid(*empArray[i]) == typeid(Faculty))  {
            cout << "~~FACULTY~~" << endl;
            ((Faculty*)empArray[i])->putData();
            employeeSalaryTotal += ((Faculty*)empArray[i])->monthlyEarning();
        } else if (typeid(*empArray[i]) == typeid(Staff)) {
            cout << "~~STAFF~~" << endl;
            ((Staff*)empArray[i])->putData();
            employeeSalaryTotal += ((Staff*)empArray[i])->monthlyEarning();
        } else {
            cout << "~~PARTTIME~~" << endl;
            ((PartTime*)empArray[i])->putData();
            ptSalaryTotal += ((PartTime*)empArray[i])->monthlyEarning();
            employeeSalaryTotal += ((PartTime*)empArray[i])->monthlyEarning();
        }
        cout << endl;
        
    }
    
    
    cout <<"b. Total monthly salary for all the part-time staff: $"<< ptSalaryTotal << endl;
    cout <<"c. Total monthly salary for all the employees: $"<< employeeSalaryTotal << endl;
   
    return 0;
}
