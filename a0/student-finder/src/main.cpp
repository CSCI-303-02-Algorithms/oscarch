//including other code
#include <iostream>
#include <vector>
#include "students/test/Student.h"

//including a namespace
using namespace std;

int test() {
    return 2343;
}

bool findStudents(vector<Student> students);

//the entry point of the program
int main() {

    vector<Student> students;
    Student jack("Jack", "01/01/2020");
    Student jack2 = Student("Jack2", "03/01/2020");
    Student defaulSt;
    Student defaulSt2;

    students.push_back(jack);
    students.push_back(jack2);
    students.push_back(defaulSt);
    students.push_back(defaulSt2);
    students.push_back(Student("Kate", "01/01/2021"));

    bool found = findStudents(students);
    if (found) {
        cout << "Students found" << endl;
        //cerr << "Errors" <<endl;
    } else{
        cout << "Students not found" <<endl;
    }

    int result = test();

    return 0;
}

bool findStudents(vector<Student> students){
    for (int i = 0; i < students.size(); ++i) {
        Student st1 = students[i];
        for (int j = i + 1; j < students.size(); ++j) {
            Student st2 = students[j];
            if (st1.birthday == st2.birthday)
                return true;
        }
    }
    return false;
}
