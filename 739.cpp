class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        stack<int> s;
        int n = tmp.size();
        vector<int> res(n);
        for(int i=n-1 ; i>=0 ; i--){
            while(!s.empty() && tmp[s.top()] <= tmp[i])s.pop();
            res[i] = s.empty() ? 0 : s.top()-i;
            s.push(i);
        }
        return res;
    }
};