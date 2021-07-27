class Solution {
public:
    unordered_map<char , string> m;
    string s;
    vector<string> ans;
    
    void dfs(int i , string res){
        if(i>= s.length()){
            if(res != "")ans.push_back(res);
            return;
        }
        string ss = m[s[i]];
        for(int j=0 ; j<ss.length() ; j++){
            string res1 = res;
            res1 += ss[j];
            dfs(i+1 , res1);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        s = digits;
        dfs(0 , "");
        return ans;
        
    }
    
};


