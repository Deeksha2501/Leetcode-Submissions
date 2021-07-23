class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        vector<vector<int>> res;
        int i=0 , j=0;
        while(i < fl.size() and j < sl.size()){
            // cout<<"\n--i = "<<i<<"\nj = "<<j;
            
            // if(fl[i][0] <= sl[j][1] || sl[j][0] <= fl[i][1]){
                int start = max(fl[i][0] , sl[j][0]);
                int end = min(fl[i][1] , sl[j][1]);
                
                if(start <= end)res.push_back({start , end});
            // }
            if(fl[i][1]<sl[j][1])i++;
            else j++;
        }
        return res;
    }
};