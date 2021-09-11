#include <iostream>
using namespace std;

//宣告節點
struct listNode {
  int studentNum;
  int grade;
  listNode * next;
};

//typedef 是一個關鍵字。 它用來對一個資料類型取一個別名，目的是為了使原始碼更易於閱讀和理解。
typedef listNode * studentCollection;




int main() {

  studentCollection sc;
  listNode * node1 = new listNode;
  node1 -> studentNum = 1001; node1 -> grade = 78;
  listNode * node2 = new listNode;
  node2 -> studentNum = 1012; node1 -> grade = 93;
  listNode * node3 = new listNode;
  node3 -> studentNum = 1076; node1 -> grade = 85;
  sc = node1;
  node1 -> next = node2;
  node2 -> next = node3;
  node3 -> next = NULL;
  node1 = node2 = node3 = NULL;

  return 0;
}
