/*
 Problem 680
 Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }
};

int main(){
    string s;
    cin>>s;

    Solution sol;
    bool out = sol.validPalindrome(s);
    cout<<boolalpha;
    cout<<"Is string "<<s<<" a palindrome after removing atmost 1 character?: "<<out;
    return 0;
}
