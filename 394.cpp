class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(char c : s){
            if(c == ']'){
                string ss="";
                while(!st.empty() && st.top() != "["){
                    ss = st.top() + ss;
                    st.pop();
                }
                // cout<<"\nss = "<<ss;
                if(!st.empty() && st.top() == "[")st.pop();
                
                string num="";
                // cout<<"\nstop = "<<st.top();
                while(!st.empty() && isdigit(st.top()[0])){
                    num = st.top() + num;
                    st.pop();
                }
                
                int n=1;
                if(num != "")n = stoi(num);
                // cout<<"\nnum = "<<n;
                string res="";
                for(int j=0 ; j<n ; j++){
                    // cout<<"\nj = "<<j;
                    res += ss;
                }
                st.push(res);
                    
            }else{
                string temp = "";
                temp+=c;
                st.push(temp);
                // cout<<"\nc = "<<c;
            }
        }
        string ans="";
        while(!st.empty()){
            // cout<<"\nhhh = "<<st.top();
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};