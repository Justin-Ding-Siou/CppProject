#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

/*#ifndef 指示检测指定的预处理器变量是否未定义*/
/*#define 指示接受一个名字并定义该名字为预处理器变量。*/
#include <string>

//類別宣告

struct student {
  int grade;
  int studentID;
  std::string name;
};
//定義基本類別框架
//解決的問題: 不用寫成三維陣列

class studentRecord {
  public:
    //客戶端使用攫取的地方
    //建構函式
    studentRecord();
    studentRecord(int newGrade, int newID, std::string newName);


    //成員函式，
    int grade();
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    std::string name();
    void setName(std::string newName);
    //將數字轉成字母
    std::string letterGrade();
    void showStudentProperties();

  private:
    int _grade;
    int _studentID;
    std::string _name;
    bool isValidGrade(int grade);

};

#endif
