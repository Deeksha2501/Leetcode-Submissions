class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int e = 0;
        int o = n-1;
        int i=0;
        while(i<n){
            if(nums[i]%2 == 0){
                res[e] = nums[i];
                e++;
            }else{
                res[o] = nums[i];
                o--;
            }
            i++;
        }
        return res;
    }
};