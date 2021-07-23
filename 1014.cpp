class Solution {
public:
    int res=0 , n;
    vector<int> values;
    
    void dfs(int i , int j){
        // cout<<"\ni = "<<i<<" j = "<<j;
        if(j >= n || i >= n)return;
        int temp = values[i] + values[j] + (i-j);
        res = max(res , temp);
        dfs(i, j+1);
        dfs(i+1 , j+1);
    }
    
    int maxScoreSightseeingPair(vector<int>& vs) {
        values = vs;
        n = vs.size();
        // dfs(0 , 1);
        // return res;
        int lmax = vs[0] + 0;
        int res = 0;
        for(int i=1 ; i<n ; i++){
            res = max(res , vs[i] - i + lmax);
            lmax = max(vs[i]+i , lmax);
        }
        
        return res;
           
    }
};