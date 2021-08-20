class Solution {
public:
    vector<int> res;
    int n;
    
    bool check(int a , int b){
        int xr = a ^ b;
        xr = xr & (xr - 1);
        return xr == 0;
    }
    
    bool dfs(vector<int> v , unordered_set<int> s){
        if(v.size() > n)return true;
        if(v.size() == n){
            if(check(v[0] , v.back())){
                res = v;
                return true;
            }else return false;
        }
        for(int i=0 ; i<n ; i++){
            if(s.find(i) == s.end()){
                if(check(v.back() , i)){
                    vector<int> vv = v;
                    vv.push_back(i);
                    unordered_set<int> ss = s;
                    ss.insert(i);
                    if(dfs(vv , ss))return true;
                }
            }
        }
        return false;
    }
    
    vector<int> circularPermutation(int nn, int start) {
        n = pow(2 , nn);
        // dfs({start} , {start});
        for(int i=0 ; i<n ; i++){
            res.push_back(start ^ ( i ^ (i>>1)));
        }
        return res;
    }
};