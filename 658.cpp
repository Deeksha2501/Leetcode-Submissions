class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // auto cmp = [&](int a , int b) {
        //     if(abs(a-x) == abs(b-x))return a < b;
        //     return abs(a-x) < abs(b-x);
        // };
        // sort(arr.begin() , arr.end() , cmp);
        // arr.resize(k);
        // sort(arr.begin() , arr.end());
        // return arr;
        int n = arr.size();
        int l = 0, r = n-k;
        while(l < r){
            int mid = l + (r-l)/2;
            if(x-arr[mid] > arr[mid+k] - x){
                l = mid+1;
            }else r = mid;
        }
        return vector<int>(arr.begin()+l , arr.begin()+l+k);
    }
};