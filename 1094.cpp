class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector <int> num(1001 , 0);
        for(int i=0 ; i<trips.size(); i++){
            num[trips[i][1]] += trips[i][0];
            num[trips[i][2]] -= trips[i][0];
            
        }
        int maxm = num[0];
        for(int i=1 ; i<1001 ; i++){
            num[i] += num[i-1];
            maxm = max(num[i] , maxm);
        }
        if(maxm > capacity){
            return false;
        }
        
        return true;
        
    }
};