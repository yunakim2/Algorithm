#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  int age;
  string gender, age_s;
  cin >> s;
  int sp = s.find_first_of("-");
  if (s[sp + 1] == '1' || s[sp + 1] == '2') {
    if (s[sp+1] == '1') gender = "M";
    else gender = "W";
    age_s = "19" + s.substr(0,2);
    age = 2019 - stoi(age_s) + 1;
  } else {
    if (s[sp+1] == '3') gender = "M";
    else gender = "W";
    age_s = "20" + s.substr(0,2);
    age = 2019 - stoi(age_s) + 1;
  }
  cout << age << " " << gender;
}