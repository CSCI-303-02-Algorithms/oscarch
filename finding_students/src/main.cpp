//including other code
#include <iostream>
#include "students/Student.h"

//including a namespace

using namespace std;

bool findStudents(vector<Student> vector1);

//the entry point of the program
int main() {

    Student jack("jack", "01/31/2024");
    Student default1;
    Student oscar("oscar", "01/31/2024");
    Student anna("anna", "01/28/2024");

    vector<Student> allStudents;
    allStudents.push_back(jack);
    allStudents.push_back(default1);
    allStudents.push_back(oscar);
    allStudents.push_back(anna);

    cout << "it works: " << allStudents.size() << endl;

    bool found = findStudents(allStudents);

    if (found) {
        cout << "found " << endl;
    } else {
        cout << "not found " << endl;
    }

    return 0;
}

bool findStudents(vector<Student> vector1) {

    for (int i = 0; i < vector1.size(); i++) {
        Student st1 = vector1[i];
        for (int j = i + 1; j < vector1.size(); j++) {
            Student st2 = vector1[j];
            if (st1.birthdate == st2.birthdate)
                return true;
        }
    }

    ///-----


    /*
    for(int i = 0; i < vector1.size(); i++){
        //do stuf
    }
     */

    //----

//    int i = 0;
//    while(i < vector1.size()){
//        //do stuff
//        i++;
//    }

    return false;
}
