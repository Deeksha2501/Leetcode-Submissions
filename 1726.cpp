class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int p = nums[i]*nums[j];
                m[p]++;
            }
        }
        int ans = 0;
        for(auto a : m){
            if(a.second >= 2){
                ans += (a.second *(a.second-1))*4;
            }
        }
        return ans;
    }
};