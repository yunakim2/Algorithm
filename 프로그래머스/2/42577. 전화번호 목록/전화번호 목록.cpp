#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    string checkStr = "";
    for(int i = 0; i < phone_book.size()-1; i++) {
        checkStr = phone_book[i];
        if (phone_book[i+1].substr(0, checkStr.size()) == checkStr) {
                return false;
        }
    }
    return true;
}