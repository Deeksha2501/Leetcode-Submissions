class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int lmax = nums[0];
        int rmin=nums[1];
        int n = nums.size();
        vector<int> ra(n);
        ra[n-1] = nums[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            ra[i] = min(nums[i] , ra[i+1]);
        }
        
        for(int i=1 ; i<n ; i++){
            // cout<<"\nlmax = "<<lmax<<" r = "<<ra[i];
            
            if(lmax <= ra[i]){
                return i;
            }
            else{
                lmax = max(nums[i] , lmax);
            }
        }
        
        return n-1;
        
    }
};