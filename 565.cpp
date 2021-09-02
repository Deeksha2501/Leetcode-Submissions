class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res=0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            int cnt=0;
            int j=nums[i];
            int k = i;
            while(j >= 0){
                nums[k] = -nums[k];
                if(nums[k] == 0)nums[k] = INT_MIN;
                cnt++;
                k = j;
                j = nums[j];
            }
            res = max(res , cnt);
        }
        return res;
    }
};