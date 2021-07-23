class Solution {
public:
    void get(vector<int>& arr, int t, pair<int, int> &p, int l, int r){

        if(l>r)return;
            int mid = (l+r)/2;
            if(arr[mid] == t){
                if(mid == 0 || ( mid != 0 && (arr[mid] != arr[mid-1]))){
                    p.first = mid;
                }
                if(mid == arr.size()-1 || (mid != arr.size()-1 && (arr[mid] != arr[mid+1]))){ 
                    p.second = mid;
                }
                if(mid != 0 && (arr[mid] == arr[mid-1])){
                    get(arr, t, p, l, mid-1);
                }
                if(mid != arr.size()-1 && (arr[mid] == arr[mid+1])){
                    get(arr, t, p, mid+1 , r);
                }
                if(p.first != -1 && p.second != -1){
                    return;
                }
            }else if(t < arr[mid]){
                get(arr, t, p, l , mid-1);
                r = mid-1;
            }else{
                get(arr, t, p, mid+1 , r);
                l = mid+1;
            }
    }
    
    
    vector<int> searchRange(vector<int>& nums, int t) {
        pair<int, int> p(-1, -1);
        get(nums, t, p, 0, nums.size()-1);
        vector<int> v(2);
        v[0] = p.first;
        v[1] = p.second;
        return v;
    }
};