class Solution {
public:
    vector<int> arr;
    int target;
    
    int get(int s , int e){
        if(s > e)return -1;
        int mid = (s+e)/2;
        if(arr[mid] == target)return mid;
        if(target >= arr[s] && target< arr[mid])return get(s , mid-1);
        else return get(mid+1 , e);
    }
    
    int search(vector<int>& nums, int target) {
        arr = nums;
        int n = arr.size();
        this->target = target;
        return get(0 , n-1);
    }
};