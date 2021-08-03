class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>arr(n , vector<int>(n , 0));
        int cnt=1;
        int is=0, js=0, ie=n-1, je=n-1;
        while(cnt<=n*n){
            for(int j=js ; j<=je ; j++){
                arr[is][j] = cnt;
                cnt++;
            }
            is++;
            if(cnt >= n*n+1)break;
            for(int i=is ; i<=ie ; i++){
                arr[i][je] = cnt;
                cnt++;
            }
            je--;
            if(cnt >= n*n+1)break;
            for(int j=je ; j>=js ; j--){
                arr[ie][j] = cnt;
                cnt++;
            }
            ie--;
            if(cnt >= n*n+1)break;
            for(int i=ie ; i>=is ; i--){
                arr[i][js] = cnt;
                cnt++;
            }
            js++;
            if(cnt >= n*n+1)break;
        }
        return arr;
    }
};