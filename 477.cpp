class Solution {
public:
    int get(int a , int b){
        int xr = a^b;
        int cnt=0;
        while(xr){
            cnt++;
            xr = xr & (xr-1);
        }
        return cnt;
    }
    
    int totalHammingDistance(vector<int>& nums) {
        // int n=nums.size();
        // int sum=0;
        // for(int i=0 ; i<n ; i++){
        //     for(int j=i+1 ; j<n ; j++){
        //         sum += get(nums[i] , nums[j]);
        //     }
        // }
        
        int total = 0, n = nums.size();
        for (int j=0;j<32;j++) {
            int bitCount = 0;
            for (int i=0;i<n;i++) 
                bitCount += (nums[i] >> j) & 1;
            total += bitCount*(n - bitCount);
        }
        return total;

        
        // return sum;
    }
};