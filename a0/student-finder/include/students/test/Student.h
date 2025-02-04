//
// Created by Oscar Chaparro on 2/4/25.
//

#include <string>

using namespace std;

#ifndef STUDENT_FINDER_STUDENT_H
#define STUDENT_FINDER_STUDENT_H

class Student {
private:
public:

    string name;
    string birthday;

    Student();
    Student(string name, string bday);

    void regularFunction();
};


#endif //STUDENT_FINDER_STUDENT_H
