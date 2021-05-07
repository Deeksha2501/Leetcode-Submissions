class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, n=nums.size();
        while(nums[i] == 0 && i<n){
            i++;
        }
        if(i == n)return 0;
        int prev = 0, curr=0,maxm = 0;
        int start = i;
        for(int i=start ; i<n ; i++){
            if(nums[i] == 1){
                curr++;
            }else{
                maxm = max(maxm , prev+curr);
                prev = curr;
                curr =0;
            }
        }
        maxm = max(maxm,curr+prev);
        
        if(maxm == n)return n-1;
        return maxm;
        
    }
};