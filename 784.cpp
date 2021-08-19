class Solution {
public:
    vector<string> res;
    void dfs(int i , string s){
        if(i == s.length()){
            res.push_back(s);
            return;
        }
        if(isdigit(s[i])){
            dfs(i+1 , s);
            return;
        }
        string ss = s;
        ss[i] = tolower(ss[i]);
        dfs(i+1 , ss);
        ss = s;
        ss[i] = toupper(ss[i]);
        dfs(i+1 , ss);
    }
    
    vector<string> letterCasePermutation(string s) {
        dfs(0 , s);
        return res;
    }
};