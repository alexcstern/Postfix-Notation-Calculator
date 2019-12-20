// Alexander Stern
// acs4wq
// 2/4/19
// testPostfixCalc.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "postfixCalculator.h"
#include "List.h"
using namespace std;

int main() {
  /*
  postfixCalculator a;
  a.pushNum(1);
  a.pushNum(2);
  a.pushNum(3);
  a.pushNum(4);
  a.pushNum(5);
  a.add();
  a.add();
  a.add();
  a.add();
  cout << "This should be 15 and actually is: " << a.getTopValue() << endl;

  postfixCalculator b;
  b.pushNum(-1);
  b.pushNum(-2);
  b.pushNum(-5);
  b.pushNum(3);
  b.multiply();
  b.pushNum(2);
  b.pushNum(-2);
  b.multiply();
  b.multiply();
  b.multiply();
  b.multiply();
  cout << "This should be 120 and actually is: " << b.getTopValue() << endl;

  postfixCalculator c;
  c.pushNum(-1512);
  c.pushNum(-12);
  c.pushNum(-2);
  c.divide();
  c.divide();
  c.pushNum(-2);
  c.divide();
  c.pushNum(3);
  c.divide();
  cout << "This should be 42 and actually is: " << c.getTopValue() << endl;

  postfixCalculator d;
  d.pushNum(-1);
  d.negate();
  d.negate();
  d.negate();
  cout << "This should be 1 and actually is: " << d.getTopValue() << endl;
*/
  postfixCalculator f;
  string s;
  while (cin >> s) {
    if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1]))) {
      int sInt;
      sInt = stoi(s);
      f.pushNum(sInt);
    }
    else  {
      if (s == "+") {
	f.add();
      }
      if (s == "-") {
	  f.subtract();
      }
      if (s == "*") {
	  f.multiply();
      }
      if (s == "/") {
	  f.divide();
      }
      if (s == "~") {
	  f.negate();
      }
	
    }
    // cout << s << endl;
  }
  cout << "The result of the postfix notation is: " << f.getTopValue() << endl;

  

  return 0;
}
