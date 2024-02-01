//
// Created by Oscar Chaparro on 1/31/24.
//

#ifndef FINDING_STUDENTS_STUDENT_H
#define FINDING_STUDENTS_STUDENT_H

#include <string>

using namespace std;

class Student {
public:
    string name;
    string birthdate;

    Student(string name1, string birthdate1);
    Student();
private:
    int myFunction(int num);
};


#endif //FINDING_STUDENTS_STUDENT_H
