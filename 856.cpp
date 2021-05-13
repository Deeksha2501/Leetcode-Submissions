class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int i=0;
        int n = s.length();
        int ans = 0;
        int res = 0;
        for(int i=0 ; i<s.length() ; i++){
            if(i<n-1 && s[i] == '(' && s[i+1] == ')'){
                res++;
                i++;
            }else if(s[i] == '('){
                st.push(res);
                res=0;
            }else{
                res = 2*res + st.top();
                st.pop();
            }
        }
        return res;
    }
};