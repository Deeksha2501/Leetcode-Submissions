class Solution {
public:
    int findPoisonedDuration(vector<int>& arr, int d) {
        int res=0;
        int n = arr.size();
        if(n == 0)
            return 0;
        for(int i=0 ; i<n-1 ; i++){
            if(arr[i+1]-arr[i]<d){
                res += arr[i+1]-arr[i];
            }else{
                res += d;
            }
        }
        res += d;
        return res;
    }
};