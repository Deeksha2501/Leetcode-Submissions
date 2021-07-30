class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        vector<int> ps(n);
        ps[0] = nums[0];
        for(int i=1 ; i<n ; i++){
            sum += nums[i];
            ps[i] += sum;
        }
        for(int i=0 ; i<n ; i++){
            int left = ps[i]-nums[i];
            int right = sum - ps[i];
            if(left == right)return i;
        }
        return -1;
    }
};