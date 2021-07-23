class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin() , p.end());
        
        int endPoint = p[0][1];
        int balloon = 1;
        for(int i= 1 ; i<p.size() ; i++){
            if(p[i][0] <= endPoint){
                endPoint = min(p[i][1] , endPoint);
            }else{
                balloon++;
                endPoint = p[i][1];
            }
        }
        return balloon;
            
    }
};