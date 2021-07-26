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