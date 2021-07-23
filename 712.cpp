class Solution {
public:
    int res=INT_MAX;
    string s,t;
    int n,m;
    vector<vector<int> > mem;
    
    int dfs(int i , int j){
        
        if(mem[i][j] != -1){
            return mem[i][j];
        }
        
        if(i >= n || j >= m){
            int sum=0;
            while(i < n){
                sum += int(s[i]);
                i++;
            }
            while(j < m){
                sum += int(t[j]);
                j++;
            }
            
            return sum;
        }
        
        int res = INT_MAX;
        if(s[i] == t[j]){
            res = min(res , dfs(i+1 , j+1));
        }
        else{
            res = min({
                dfs(i+1 , j ) + int(s[i]),
                dfs(i , j+1 ) + int(t[j]),
                res
            });
        }
        return mem[i][j] = res;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        s = s1, t=s2;
        n = s.length(), m = t.length();
        mem = vector<vector<int>>(n+1 , vector<int>(m+1 , 0));
        
        int presum=0;
        for(int j=m-1 ; j>=0 ; j--){
            mem[n][j] = int(t[j]) + presum;
            presum = mem[n][j];
        }
        
        presum=0;
        
        for(int i=n-1 ; i>=0 ; i--){
            mem[i][m] = int(s[i]) + presum;
            presum = mem[i][m];
        }
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=m-1 ; j>=0 ; j--){
                if(s[i] == t[j])mem[i][j] = mem[i+1][j+1];
                else{
                    mem[i][j] = min({
                        mem[i+1][j] + int(s[i]),
                        mem[i][j+1] + int(t[j])
                    });
                }
            }
        }
        
        
        return mem[0][0];
        
        
        // return dfs(0 , 0);
        
        
    }
};