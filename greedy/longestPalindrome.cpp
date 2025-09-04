/*Question Number 409 : Easy

 Given a string s which consists of lowercase or uppercase letters, return the length of the longest Palindrome that can be built with those letters.

 Letters are case sensitive, for example, "Aa" is not considered a palindrome.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> out(52,0);
        int len = 0;

        for(int i=0;i<s.size();i++){
            if((s[i] >= 97) && (s[i] <= 122)){
                out[s[i] - 'a']++;
                if(out[s[i] - 'a'] % 2 == 0)    len += 2;
            }

            else{
                out[s[i] - 'A' + 26]++;
                if(out[s[i] - 'A' + 26] % 2 == 0)    len += 2;

            }
        }

        for(int i=0;i<52;i++){
            if(out[i] %2 == 1){
                len += 1;
                break;
            }
        }
        return len;
    }
};


int main(){
    string input;
    cin>>input;

    Solution sol;
    int result = sol.longestPalindrome(input);
    cout<<result<<endl;
    return 0;
}
