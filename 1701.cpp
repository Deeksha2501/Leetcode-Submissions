class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double ans;
        int curr = 0;
        double wait = 0;
        for(int i=0 ; i<c.size() ; i++){
            int finish = max(c[i][0] , curr)+ c[i][1];
            wait += finish-c[i][0];
            curr = finish;
        }
        return wait/c.size();
    }
};