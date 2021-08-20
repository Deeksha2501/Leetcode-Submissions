class Solution {
public:
    vector<vector<int>> st , mn;
    int n;
    int res=0;
    
    int calc(int i , int j){
        int m = st[i].size() , r=0;
        for(int k=0 ; k<m ; k++){
            if(st[i][k] == mn[j][k])r++;
        }
        return r;
    }
    
    void dfs(int i , vector<bool> arr , int sum){
        if(i >= n){
            res = max(res , sum);
            return;
        }
        for(int j=0 ; j<n ; j++){
            if(arr[j] == false){
                arr[j] = true;
                int x = calc(i , j);
                dfs(i+1 , arr , sum+x);
                arr[j] = false;
            }
        }
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        st = students;
        mn = mentors;
        n = st.size();
        vector<bool>arr(n , false);
        dfs(0 , arr , 0);
        return res;
    }
};