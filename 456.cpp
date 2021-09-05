class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        arr[0] = INT_MAX;
        for(int i=1 ; i<n ; i++){
            arr[i] = min(arr[i-1], nums[i-1]);
        }
        int top = n;
        for(int j=n-1 ; j>=0 ; j--){
            if(nums[j] <= arr[j])continue;
            while(top < n && arr[top] <= arr[j])top++;
            if(top<n && (nums[j] > arr[top]))return true;
            arr[--top] = nums[j];
        }
        return false;
    }
};

//132