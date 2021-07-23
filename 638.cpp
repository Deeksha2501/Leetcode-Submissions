class Solution {
public:
    vector<vector<int>> sp;
    vector<int> prices;
    int n, m;
    
    int dfs(int i , vector<int> needs){
        if(i >= n){
            int p=0;
            for(int k=0 ; k<m ; k++){
                if(needs[k] > 0)p += needs[k]*prices[k];
            }
            return p;
        }
        
        bool flag = true;
        for(int k=0 ; k<m ; k++){
            if(sp[i][k] > needs[k]){
                flag = false;
                break;
            }
        }
        
        int res = dfs(i+1 , needs);
        if(flag){
            vector<int> v(m);
            for(int k=0 ; k<m ; k++){
                v[k] = needs[k] - sp[i][k];
            }
            res = min({
               res,
               sp[i][m] + dfs(i , v)
            });
        }
        return res;
    }
    
    
    int shoppingOffers(vector<int>& price, vector<vector<int>> special, vector<int>& needs) {
        sp = special;
        prices = price;
        n = special.size();
        m = price.size();
        return dfs(0 , needs);
                                                                                             
    }
};