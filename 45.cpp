class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxm=0, count=0,end=0;
        
        for(int i=0 ; i<n-1 ; i++){
            maxm = max(maxm , i+nums[i]);
            if(i == end){
                count++;
                end = maxm;
            }
        }
        
        return count;
    }
};