class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
           for(int i=0 ; i<nums.size() ; i++){
               int in = abs(nums[i])-1;
               if(nums[in]<0){
                   res.push_back(in+1);
               }
               else{
                    nums[in] = -nums[in];
               }
           }
        return res;
    }
};
