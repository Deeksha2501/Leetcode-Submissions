class Solution {
public:
    vector<int> arr;
    int res,n;
    
    void dfs(int i , int diff , int cnt){
        if(i == n)return;
        if(arr[i] - arr[i-1] == diff){
            cnt++;
            res += cnt;
            dfs(i+1 , diff , cnt);
        }
        else{
            cnt = 0;
            res += cnt;
            dfs(i+1 , (arr[i]-arr[i-1]) , 0);
        }
            
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        if(n < 3)return 0;
        int diff = arr[1]-arr[0];
        dfs(2 , diff , 0);
        return res;
    }
};