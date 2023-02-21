#include <bits/stdc++.h>

using namespace std;
string s;
vector<string> vowels = {"a", "e", "i", "o", "u"};

bool checkRule1(const string &word) {
  for (auto i : vowels) {
    if (word.find(i) != string::npos) return true;
  }
  return false;
}

bool checkRule2(const string &word) {
  if (word.length() < 3) return true;
  for (int i = 0; i < word.length() - 2; i++) {
    string sub = word.substr(i, i + 3);
    int vow = 0;
    int con = 0;
    for (int k = 0; k < 3; k++) {
      string ss(1, sub[k]);
      if (find(vowels.begin(), vowels.end(), ss) == vowels.end()) {
        con += 1;
      } else {
        vow += 1;
      }
    }
    if (vow == 3 || con == 3) {
      return false;
    }
  }
  return true;
}

bool checkRule3(const string &word) {
  if (word.length() < 2) return true;
  for (int i = 0; i < word.length() - 1; i++) {
    string sub = word.substr(i, 2);
    if (sub == "ee" || sub == "oo") {
        continue;
    }
    if (sub[0] == sub[1]) return false;
  }
  return true;
}

void printNotAcceptWord() {
  cout << "<" << s << "> is not acceptable.\n";
}

void printAcceptWord() {
  cout << "<" << s << "> is acceptable.\n";
}

int main() {
  while (1) {
    cin >> s;
    if (s == "end") break;
    if (checkRule1(s) && checkRule2(s) && checkRule3(s)) {
      printAcceptWord();
    } else {
      printNotAcceptWord();
    }
  }
  return 0;
}