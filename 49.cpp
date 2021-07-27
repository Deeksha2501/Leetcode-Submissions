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
                // cout<<"\npushing to old one = "<<in;
            }else{
                mp[ss] = k;
                // cout<<"\nassigning k = "<<k;
                vector<string> v;
                v.push_back(strs[i]);
                res.push_back(v);
                k++;
            }
        }
        return res;
    }
};