class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int count = 0,res=0;
        int kk = k;
        int n = nums.size();
        while(end < nums.size()){
            if(nums[end] == 1){
                end++;
                count++;
                res = max(res , count);
            }
            else {
                if(kk>0){
                kk--;
                count++;
                end++;
                res = max(res , count);
            }

            else {
                while(kk<=0){
                    if(nums[start]==0)kk++;
                    start++;
                    count--;
                }
            }
            }
        }
        return res;
    }
};