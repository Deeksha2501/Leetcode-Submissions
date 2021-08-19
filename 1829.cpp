class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xr=0;
        int n = nums.size();
        int mxb = pow(2 , maximumBit) - 1;
        for(int i=0 ; i<n ; i++){
            xr ^= nums[i];
        }
        vector<int> res;
        
        for(int i=n-1 ; i>=0 ; i--){
            res.push_back(xr ^ mxb);
            xr = xr^nums[i];
        }
        return res;
    }
}; 
