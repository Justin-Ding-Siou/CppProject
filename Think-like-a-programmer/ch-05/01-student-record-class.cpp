#include <iostream>
//#include <string>
#include "01-student-record-class.h"

//預設建構函式
//建構函式是與類別名稱相同的方法成員，且沒有傳回值
studentRecord::studentRecord() {

  setStudentID(-1);
  setGrade(0);
  setName("");

}

//定義建構函式
studentRecord::studentRecord(int newGrade, int newID, std::string newName){
  setStudentID(newID);
  setGrade(newGrade);
  setName(newName);
}


//呼叫相關成員的目前值
int studentRecord::grade() {
  return _grade;
}

//用參數 newGrade 更改 _grade
void studentRecord::setGrade(int newGrade) {
  if(isValidGrade(newGrade))
    _grade = newGrade;
}

//呼叫相關成員的目前值
int studentRecord::studentID() {
    return _studentID;
}

//用參數 newGrade 更改 _studentID
void studentRecord::setStudentID(int newID) {
    _studentID = newID;
}


//呼叫相關成員的目前值
std::string studentRecord::name() {
    return _name;
}

//用參數 newGrade 更改 _name
void studentRecord::setName(std::string newName) {
    _name = newName;
}


void studentRecord::showStudentProperties() {
    std::cout << "ID           : " << _studentID    << std::endl;
    std::cout << "Name         : " << _name         << std::endl;
    std::cout << "Grade        : " << _grade        << std::endl;
    std::cout << "Grade Letter : " << letterGrade() << std::endl;
    std::cout << "-------------------: "  << std::endl;
}


//支援方法，使得基本類別類別框架
std::string studentRecord::letterGrade() {

  if(!isValidGrade(_grade)) return "ERROR";
  const int NUMBER_CATEGORIES = 11;
  const std::string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
  const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
  int category = 0;
  while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade) {
    category++;
    /* code */
  }
  return GRADE_LETTER[category - 1];
}

bool studentRecord::isValidGrade(int grade) {
    if ((grade >= 0) && (grade <= 100))
        return true;
    return false;
}
