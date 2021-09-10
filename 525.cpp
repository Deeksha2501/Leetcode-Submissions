class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int> mp;
        int a=0, b=0;
        int n = nums.size();
        mp[0] = -1;
        int res=0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 0)a++;
            else b++;
            if(mp.find(a-b) != mp.end()){
                res = max(res , i-mp[a-b]);
            }else{
                mp[a-b] = i;
            }
        }
        return res;
    }
};