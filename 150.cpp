class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string c : tokens){
            if(c == "+"){
                string b = st.top(); st.pop();
                string a = st.top();st.pop();
                int bb = stoi(b);
                int aa = stoi(a);
                int temp = aa+bb;
                string t = "";
                t = to_string(temp);
                st.push(t);
                
            }else if(c == "-"){
                string b = st.top(); st.pop();
                string a = st.top();st.pop();
                int bb = stoi(b);
                int aa = stoi(a);
                int temp = aa-bb;
                string t = "";
                t = to_string(temp);
                st.push(t);
                
            }else if(c == "*"){
                string b = st.top(); st.pop();
                string a = st.top();st.pop();
                int bb = stoi(b);
                int aa = stoi(a);
                int temp = aa*bb;
                string t = "";
                t = to_string(temp);
                st.push(t);
                
            }else if(c == "/"){
                string b = st.top(); st.pop();
                string a = st.top(); st.pop();
                int bb = stoi(b);
                int aa = stoi(a);
                int temp = aa/bb;
                string t = "";
                t = to_string(temp);
                st.push(t);
                
            }else{
                st.push(c);
            }
        }
        string ans = st.top();
        int res = stoi(ans);
        return res;
    }
};