class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lo=-1, hi = n;
        int mid = 0;
        while(mid < hi){
            if(nums[mid] == 0){
                lo++;
                swap(nums[lo] , nums[mid]);
                mid++;
            }else if(nums[mid] == 2){
                hi--;
                swap(nums[hi] , nums[mid]);
            }
            else mid++;
        }
        
    }
};
