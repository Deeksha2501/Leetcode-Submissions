class Solution {
public:
    void reverse(vector<int> &nums , int l , int r){
        while(l <= r){
            swap(nums[l] , nums[r]);
            l++;
            r--;
        }
    }
    
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i=n-1;
        while(i >= 1){
            if(arr[i] <= arr[i-1]){
                i--;
                continue;
            }
            break;
        }
        // cout<<"\ni = "<<i;
        int temp = i-1;
        if(temp == -1){
            reverse(arr,0 , n-1);
            return;
        }
        int k = n-1;
        // cout<<"\ntemp = "<<temp;
        while(arr[k] <= arr[temp] && k > 0)k--;
        // cout<<"\nk = "<<k;
        swap(arr[temp] , arr[k]);
        reverse(arr , temp+1 , n-1);
    }
};