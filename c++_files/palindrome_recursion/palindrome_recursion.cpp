#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
    int size = str.size();
    if(str.empty() || size == 1) return true;
    if (str[0] == str[size-1]) return isPalindrome(str.substr(1, size-2));
    return false;
}

int main() {
    string str;
    while(str.compare(".") != 0) {
    cin >>  str;
    cout << isPalindrome(str) << endl;
    }
    return 0;
}