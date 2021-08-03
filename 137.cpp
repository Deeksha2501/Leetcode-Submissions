class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto el : nums)mp[el]++;
        for(auto [key, val] : mp){
            if(val == 1)return key;
        }
        return -1;
    }
};