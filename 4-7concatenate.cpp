#include <iostream>
#include <iomanip>

void concatenate(arrayString& s1, arrayString& s2){
  int s1_OldLength = length(s1);
  int s2_Length = length(s2);
  int s1_NewLength = s1_OldLength + s2_Length;
  arrayString newS = new char[oldLength + 1];

  for (int i = 0; i < OldLength; i++) {
    newS[i] = s1[i];
       /* code */
  }

  for (int i = 0; i < s2_Length; i++) {
    newS[s1_OldLength + i] = s2[i];
       /* code */
  }

  newS[s1_OldLength] = 0;
  delete[] s1;
  s1 = newS;



}
void concatenateTester(){
  arrayString a = new char[5];
  a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
  //arrayString b = new char[5];
  //a[0] = 'b'; a[1] = 'e'; a[2] = 'd'; a[3] = 0;
  //concatenate(a, b);

  arrayString c = new char[1];
  c[0] = 0;
  concatenate(c, a);
  cout << a << "\n" << c << "\n";
  cout << (void *) a << "\n" << (void *) c << "\n";


  return 0;

}
