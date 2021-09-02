class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(k == n)return "0";
        if(n == 0)return "0";
        stack<char> st;
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string res = "";
        while(st.empty() == false){
            res = st.top() + res;
            st.pop();
        }
        int i=0;
        
        for(; i<res.length() ; i++){
            if(res[i] != '0')break;
            
        }
        if(i == res.length())return "0";
        res = res.substr(i);
        return res;
    }
};
