class Solution {
public:
    
    int get(vector<int> arr , int t , int l , int r){

        if(l>r)return -1;
        
        int mid = (r+l)/2;
        
        if(arr[mid] == t)return mid;
        
        if(arr[l] <= arr[mid]){
            //left sorted
            if(t >= arr[l] && t<arr[mid])
                return get(arr , t , l , mid-1);
            else 
                return get(arr , t , mid+1 , r);

        }else if(arr[mid] < arr[r]){
            //right sorted;
            if(arr[mid] < t && t <= arr[r])
                return get(arr , t , mid+1 , r);
            else
                return get(arr , t , l ,mid-1);

        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return get(nums , target , 0 , nums.size()-1);
    }
};