class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res, st;
    
        int n = s.length();
        for(int i=0 ; i<=n-10; i++){
            string str = s.substr(i , 10);
            if(st.find(str) != st.end())res.insert(str);
            else st.insert(str);
        }
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};