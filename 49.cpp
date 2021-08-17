class Solution {
public:
    string sortStr(string s){
        vector<int> cnt(26);
        for(char c : s){
            cnt[c-'a']++;
        }
        string t="";
        for(int i=0 ; i<26 ; i++){
            t += string(cnt[i] , i+'a');
        }
        return t;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s : strs){
             mp[sortStr(s)].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string , int> mp;
        int k=0;
        for(int i=0 ; i<strs.size() ; i++){
            // cout<<"\n i = "<<i;
            string ss = strs[i];
            sort(ss.begin() , ss.end());
            if(mp.find(ss) != mp.end()){
                int in = mp[ss];
                res[in].push_back(strs[i]);
            }else{
                mp[ss] = k;=
                vector<string> v;
                v.push_back(strs[i]);
                res.push_back(v);
                k++;
            }
        }
        return res;
    }
};


