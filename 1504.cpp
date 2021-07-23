class Solution {
public:
    int numSubmat(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                if(arr[i][j] == 1){
                    arr[i][j] += arr[i][j-1];
                }
            }
        }
        int res=0;
        for(int k=0;k<n;k++){
            for(int j=0 ; j<m ; j++){
                if(arr[k][j] == 0)continue;
                int mn=INT_MAX;
                for(int i=k ; i<n ; i++){
                    if(arr[i][j]==0)break;
                    mn = min(mn , arr[i][j]);
                    res += mn;
                }
            }
        }
        
        
        return res;
    }
};