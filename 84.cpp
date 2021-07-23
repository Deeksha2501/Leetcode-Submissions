class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> s;
        s.push(0);
        int res = 0;
        int n = arr.size();
        for(int i=1 ; i<n ; i++){
            while(s.empty() == false && arr[s.top()] >= arr[i]){
                int tp = s.top();
                s.pop();
                int curr = arr[tp]*(s.empty() ? i : (i-s.top()-1));
                res = max(curr , res);
                
            }
            s.push(i);   
        }
        while(s.empty() == false){
            int tp =  s.top();
            s.pop();
            int curr = arr[tp]*(s.empty() ? n : (n-s.top()-1));
            res = max(curr , res);
        }
        return res;
    }
};