class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c : s){
            if(st.empty() || st.top() != c)st.push(c);
            else if(st.top() == c)st.pop();
        }
        string res="";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin() , res.end());
        return res;
    }
};


class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        int n = s.length();
        if(n == 1)return s;
        while(i<n-1){
            if(s[i] == s[i+1]){
                string s1 = s.substr(0 , i);
                string s2 = s.substr(i+2);
                
                s = s1 + s2;
                i--;
                if(i<0)i=0;
                n = s.length();
            }
            else i++;
        }
        return s;
    }
};