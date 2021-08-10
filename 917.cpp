class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<int> st;
        for(char c : s){
            if(isalpha(c))st.push(c);
        }
        for(char &c : s){
            if(isalpha(c)){
                c = st.top();
                st.pop();
            }
        }
        return s;
    }
};