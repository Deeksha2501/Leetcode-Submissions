class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string s : ops){
            if(isdigit(s.back())){
                st.push(stoi(s));
            }else if(!st.empty()){
                if(s == "+"){
                    int a = st.top();st.pop();
                    int b = st.top();
                    st.push(a);
                    st.push(a+b);
                }else if(s == "D"){
                    int a = st.top(); 
                    st.push(2*a);
                }else{
                    st.pop();
                }
            }
        }
        int sum=0;
        while(!st.empty()){
            sum += st.top();st.pop();
        }
        return sum;
    }
};


class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i=0 ; i<ops.size() ; i++){
            if(!s.empty() && ops[i] == "C"){
                s.pop();
                continue;
            }
            if(!s.empty() && ops[i] == "D"){
                int t = s.top();
                s.push(2*t);
                continue;
            }
            if(!s.empty() && ops[i] == "+"){
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.push(t1);
                s.push(t1+t2);
                continue;
            }
            s.push(stoi(ops[i]));
        }
        int sum=0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        
        return sum;
    }
};