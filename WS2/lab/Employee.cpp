/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name                Date            Reason
// Luwam Goitom-Worre  Sept. 21, 2023  completing workshop
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   //global variables
    int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& emp) {
      bool ok = false;
      
      if (read(emp.m_empNo) && read(emp.m_salary) && read(emp.m_name)){

          ok = true;
      }
      // return the combined success result of the three read functions. These read 
      // functions should set the properties of the reference argument of the load function
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;

      if (openFile("employees.csv")) {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];

         
          int i;
          for (i = 0; i < noOfEmployees; i++) {

              if (load(employees[i])) {
                  ok = true;
              }
              else {
                  cout << "Error: incorrect number of records read; the data is possibly corrupted.\n";
                  delete[] employees; 
              }
          }
        closeFile();
      }
      else {
          cout << "Could not open data file: employees.csv" << endl;
      }
 
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(Employee& employees) {

       cout << employees.m_empNo << ": " << employees.m_name << ", $";
       cout.setf(ios::fixed);
       cout.precision(0);
       cout << employees.m_salary << endl;

   }
   void display() {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();

       int i;
       for (i = 0; i < noOfEmployees; i++) {

           cout << i + 1 << "- ";
           display(employees[i]);
      }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       int i;

       for (i = 0; i < noOfEmployees; i++) {
           delete[] employees[i].m_name;
       }
       delete[] employees;
       noOfEmployees = 0;
   }


}