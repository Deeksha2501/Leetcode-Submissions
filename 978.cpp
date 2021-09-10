class Solution {
public:
    int cmp(int a , int b){
        if(a > b)return 1;
        if(a == b)return 0;
        return -1;
    }
    
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int st = 0;
        int ans=1;
        for(int i=1 ; i<n ; i++){
            int c = cmp(arr[i-1] , arr[i]);
            if(c == 0){
                st = i;
            }else if(i == n-1 || c*cmp(arr[i] , arr[i+1]) != -1){
                ans = max(ans , i-st+1);
                st = i;
            }
        }
        return ans;
    }
};