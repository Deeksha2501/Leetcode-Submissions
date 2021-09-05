class Solution {
public:
    int maxDistToClosest(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n , 0);
        vector<int> right(n , 0);
        int l=-1, r = -1;
        for(int i=0, j=n-1 ; i<n, j>=0 ; i++, j--){
            if(arr[i] == 0){
                left[i] = l;
            }else{
                l = i;
            }
            if(arr[j] == 0){
                right[j] = r;
            }else{
                r = j;
            }
        }
        int res=0, ans = 0;
        for(int i=0 ; i<n ; i++){
            if(arr[i] == 0){
                int temp = INT_MAX;
                if(left[i] != -1)temp = i-left[i];
                if(right[i] != -1)temp = min(temp , right[i]-i);
                if(temp >= res){
                    res = temp;
                    ans = i;
                }
            }
        }
        return res;
    }
};