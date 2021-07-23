class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inv) {
        sort(inv.begin() , inv.end());
        int endPoint = inv[0][1], count=0;
        for(int i=1 ; i<inv.size() ; i++){
            if(inv[i][0] < endPoint){
                count++;
                endPoint = min(endPoint , inv[i][1]);
            }else{
                endPoint = inv[i][1];
            }
        }
        return count;
    }
};