/*Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest lexicographical order among all possible results.*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> freq(26,0);
        vector<int> inStack(26,false);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for(char ch : s){
            freq[ch - 'a']--;

            if(inStack[ch - 'a']) continue;

            while(!st.empty() && st.top()  > ch && freq[st.top() - 'a'] > 0){
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            inStack[ch - 'a'] = true;
        }

        string out = "";

        while(!st.empty()){
            out = st.top() + out;
            st.pop();
        }

        return out;
    }
};
