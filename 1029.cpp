class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans=0;
        for(auto v : costs){
            ans += v[0];
        }
        vector<int> refund;
        for(auto v : costs){
            refund.push_back(v[1]-v[0]);
        }
        sort(refund.begin() , refund.end());
        int n = costs.size()/2;
        for(int i=0 ; i<n ; i++){
            ans += refund[i];
        }
        return ans;
    }
};

