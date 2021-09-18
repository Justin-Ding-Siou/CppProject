#include <iostream>
using namespace std;

//實作 apend，觀察記憶體
void append(arrayString& s,char c) {
  int oldLength = 0;
  while (s[oldLength] != 0) {
    oldLength++;
    /* code */
  }
  arrayString newS = new char[oldLength + 2];
  for (int i = 0; i < oldLength; i++) {
    newS[i] = s[i];
       /* code */
  }

  newS[oldLength] =c;
  newS[oldLength + 1 ] = 0;
  delete[] s;
  s = newS;


}
// append
void  appendTester() {
  arrayString a = new char[5];
  a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
  append(a, '!');
  cout << a << '\n';

}


int main() {


  cout << appendTester(a) << "\n";

	return 0;
}
