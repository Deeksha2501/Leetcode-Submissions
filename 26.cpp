class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int j=1;
        int i=1;
        while(i<nums.size()){
            if(nums[i] != nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};