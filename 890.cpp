class Solution {
    
    string getPattern(string s){
        unordered_map<char , int> m;
        string ans = "";
        int count = 0;
        for(char c : s){
            if(m.find(c) != m.end()){
                ans += to_string(m[c]) + "_";
            }else{
                count++;
                m[c] = count;
                ans += to_string(m[c]) + "_";
            }
        }
        return ans;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        
        string target = getPattern(pattern);
        
        // cout<<"\ntarget = "<<target;
        
        for(string w : words){
            if(target == getPattern(w)){
                // cout<<"\n get = "<<getPattern(w);
                res.push_back(w);
            }
        }
        return res;
    }
};