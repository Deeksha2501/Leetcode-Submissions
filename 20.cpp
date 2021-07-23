class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int i=0;
        int n = s.length();
        while(i<n){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(st.empty())return false;
                char d = st.top();
                st.pop();
                if(d != '('){
                    return false;
                }
            }else if(s[i] == '}'){
                if(st.empty())return false;
                char d = st.top();
                st.pop();
                if(d != '{'){
                    return false;
                }
            }else if(s[i] == ']'){
                if(st.empty())return false;
                char d = st.top();
                st.pop();
                if(d != '['){
                    return false;
                }
            }
            i++;
        }
        return st.empty();
    }
};