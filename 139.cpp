class Solution {
public:
    unordered_set<string> wd;
    unordered_map<int , bool> mp;
    string s;
    int n;
    
    bool dfs(int start){
        if(start >= n)return true;
        if(mp.find(start) != mp.end())return mp[start];
        for(int i=start ; i<n ; i++){
            // cout<<"\ni = "<<i;
            string ss = s.substr(start , (i-start+1));
            // cout<<"ss = "<<ss;
            if(wd.find(ss) != wd.end() && dfs(i+1))return mp[start] = true;
            // cout<<"false";
        }
        return mp[start] = false;
    }
    
    bool wordBreak(string ss, vector<string>& wordDict) {
        // wd = wordDict;
        s = ss;
        int m = wordDict.size();
        n = s.length();
        for(int i=0 ; i<m ; i++){
            wd.insert(wordDict[i]);
        }
        return dfs(0);
    }
};