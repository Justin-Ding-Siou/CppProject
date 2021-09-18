#include <iostream>
#include "01-student-record-class.h"
#include <iostream>
using namespace std;

int main() {
    studentRecord s1(90, 1001, "Mike");
    s1.showStudentProperties();

    studentRecord s2; // NOT studentRecord s2();
    s2.showStudentProperties();
}
