#ifndef _GETPASSWORD_
#include <conio.h>
#include <windows.h>
#include <string>
#include <iostream>
using namespace std;
#define _GETPASSWORD_
string getpassword() {
 string str = "";
 char init = '\0';
while (1)
 {
  init = _getch();
  if (init == VK_RETURN) 
  {
   cout << endl;
   break;
  }
  else if (init == VK_BACK) {
   cout << "\b \b" << flush;
   str.erase(str.length() - 1);
  }
  else {
   cout << "*" << flush;
   str += init;
  }
 }
 return str;
}

#endif