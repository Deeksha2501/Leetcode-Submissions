class Solution {
public:
    vector<vector<string>> ans;
    string s;
    int n;
    
    bool check(string s){
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    
    void dfs(int i , vector<string> v){
        if(i>=n)ans.push_back(v);
        string str = "";
        for(int k=i ; k<n ; k++){
            str += s[k];
            if(check(str)){
                vector<string> vv = v;
                vv.push_back(str);
                dfs(k+1 , vv);
            }
        }
        
    }
    
    vector<string> dfs(int i){
        if(i>=n)return vector<string>();
        string str = "";
        for(int k=i ; k<n ; k++){
            str += s[k];
            if(check(str)){
                vector<string> v = dfs(k+1);
            }
        }
    }
    
    
    vector<vector<string>> partition(string ss) {
//         vector<string> r;
//         if(check(s)){
//             r.push_back(s);
//             ans.push_back(r);
//         }
        
//         for(int i=1 ; i<s.length() ; i++){
//             vector<string> res;
//             string l = s.substr(0 , i);
//             string r = s.substr(i , s.length()-i);
//             vector<string> left = mcm(l);
//             for(int k=0 ; k<left.size() ; k++){
//                 res.push_back(left[k]);
//             }
//             vector<string> rgt = mcm(r);
//             for(int k=0 ; k<rgt.size() ; k++){
//                 res.push_back(rgt[k]);
//             }
//             ans.push_back(res);
//         }
        s = ss;
        n = s.length();
        vector<string> res;
        dfs(0 , res);
        
        
        return ans;
    }
};