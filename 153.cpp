class Solution {
public:
    vector<int> arr;
    
    int binarySearch(int low , int high){
        if(low > high)return INT_MAX;
        int mid = (low + high)/2;
        int res = INT_MAX;
        if(arr[low] <= arr[mid]){
            res = min({
                res  , 
                arr[low],
                binarySearch(mid+1 , high)
            });
            
        }else if(arr[mid] <= arr[high]){
            res = min({
                res , 
                arr[mid], 
                binarySearch(low , mid-1)                
            }); 
        }
        return res;
    }
    
    int findMin(vector<int>& nums) {
        arr = nums;
        int n = arr.size();
        return binarySearch(0 , n-1);
    }
};