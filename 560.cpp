class Solution {
public:
    int subarraySum(vector<int>& nums, int t) {
        unordered_map<int , int> mp;
        int sum=0, res=0;
        mp[0]=1;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            if(mp.find(sum-t) != mp.end()){
                res += mp[sum-t];
            }
                        mp[sum]++;

        }
        
        return res;
    }
};
