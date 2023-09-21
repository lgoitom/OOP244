/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name                Date            Reason
// Luwam Goitom-Worre  Sept. 21, 2023  completing workshop
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare overloaded read function prototypes
   bool read(char*& name);
   bool read(int& employeeNum);
   bool read(double& salary);

}

#endif // !SDDS_FILE_H_