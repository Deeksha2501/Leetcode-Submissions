class Solution {
public:
    int dominantIndex(vector<int>& arr) {
        int mx=INT_MIN, mx2=INT_MIN, ans=-1;
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] > mx){
                if(mx == INT_MIN)mx = arr[i];
                else if(mx2 = INT_MIN){
                    mx2 = mx;
                    mx = arr[i];
                }
                if(mx2 == INT_MIN || mx >= 2*mx2)ans=i;
                else ans = -1;
            }
            else if(arr[i] > mx2){
                mx2 = arr[i];
                if(mx < 2*mx2)ans=-1;
            }
        }
        return ans;
    }
};