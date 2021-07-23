class Solution {
public:
    int n, sum=0;

    
    void dfs(int i , vector<bool> vis){
        if(i >= n){
            sum++;
            return;
        }
        for(int j=1 ; j<=n ; j++){   
            if(!vis[j]){
                if((i+1)%j == 0 || j%(i+1)==0){
                    vis[j] = true;
                    dfs(i+1 , vis);
                    vis[j] = false;
                }
            }
        }
    }
    
    int countArrangement(int nn) {
        n = nn;
        vector<bool> vis(n+1 , false);
        dfs(0 , vis);
        return sum;
    }
};


//     vector<int> getNums(int d , unordered_set<int> s){
//         vector<int> res;
//         for(int i=1 ; i<=n ; i++){
            
//             if(s.find(i) == s.end()){
//                 // cout<<"\i= "<<i;
//                 if(i%d == 0 || d%i==0){
                    
//                     res.push_back(i);
//                 }
//             }
//         }
//         return res;
//     }