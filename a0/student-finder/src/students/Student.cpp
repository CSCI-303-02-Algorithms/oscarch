//
// Created by Oscar Chaparro on 2/4/25.
//

#include "students/test/Student.h"

Student::Student() {
    name = "Oscar";
    birthday = "02/02/2023";
}

Student::Student(string pname, string bday) {
    this->name = pname;
    this->birthday = bday;
}

void Student::regularFunction() {

}
