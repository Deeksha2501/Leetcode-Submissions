class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int flag = false;
        int mn=INT_MAX, mx=INT_MIN;
        int n = nums.size();
        for(int i=1 ; i<n ; i++){
            if(nums[i] < nums[i-1])flag = true;
            if(flag)mn = min(nums[i] , mn);
        }
        
        flag = false;
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i] > nums[i+1])flag = true;
            if(flag)mx = max(nums[i] , mx);
        }
        int l,r;
        for(l=0 ; l<n ; l++){
            if(nums[l] > mn)break;
        }
        
        for(r = n-1 ; r>=0 ; r--){
            if(nums[r] < mx)break;
        }
        if(r<l)return 0;
        return r-l+1;
    }
};

//1 3 9 5 2 8