class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int i=0;
        string curr = "",res="";
        while(i<s.length()){
            if(s[i] == ')'){
                curr+= ')';
                st.pop();
                // cout<<"element poped!\n";
                if(st.empty()){
                    // cout<<"empty\n";
                    cout<<curr;
                    res += curr.substr(1 , curr.length()-2);
                    curr="";
                }
            }else{
                // cout<<"pushed\n";
                curr += '(';
                st.push(s[i]);
            }
            i++;
        }
        return res;
    }
};