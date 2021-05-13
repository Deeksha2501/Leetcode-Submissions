class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int , int>m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
            if(m[nums[i]]>1){
                return nums[i];
            }
        }
        // for(auto a:m){
        //     if(a.second>1){
        //         return a.first;
        //     }
        // }
        return  nums[0];
    }
};