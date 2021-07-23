class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mp;
        vector<int> res;
        for(int i=0 ; i<nums.size() ; i++){
            int cmp = target-nums[i];
            if(mp.find(cmp) != mp.end()){
                vector<int> v;
                v.push_back(mp[cmp]);
                v.push_back(i);
                res = v;
                
            }else{
                mp[nums[i]] = i;
            }
        }
        return res;
    }
};