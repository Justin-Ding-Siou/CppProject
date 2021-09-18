#include <iostream>
using namespace std;

//指向number 儲存資料所在記憶體的參照。
void refParamFunction(int & x) {
  //const 增加效能。
	x = 10;
}
//允許程式的不同部分或程式中的不同資料結構存取相同的資料。


//堆疊，stack
int functionB(int inputValue) {
  return inputValue - 10;
}

int functionA(int num) {
  int localValue = functionB(num * 10);
  return localValue;
}




int main() {
	int number = 5;
  //共用記憶體
	refParamFunction(number);
	cout << number << "\n";

  //STACK 運作方式
  int y = 12;
  int z = functionA(y);
  cout << z << "\n";

	return 0;
}
