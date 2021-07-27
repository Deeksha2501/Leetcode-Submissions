class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , int> mp;
        int cnt=0;
        string res1 = "", res2 = "";
        for(int i=0 ; i<s.length() ; i++){
            if(mp.find(s[i]) != mp.end())res1 += "-" + to_string(mp[s[i]]);
            else{
                mp[s[i]] = cnt;
                res1 += "-" + to_string(mp[s[i]]);
                cnt++;
            }
        }
        
        cnt = 0;
        mp.clear();
        for(int i=0 ; i<t.length() ; i++){
            // cout<<"\n i = "<<i;
            if(mp.find(t[i]) != mp.end())res2 += "-" + to_string(mp[t[i]]);
            else{
                mp[t[i]] = cnt;
                res2 += "-" + to_string(mp[t[i]]);
                cnt++;
                // cout<<"\nres2 = "<<res2;
            }
        }
        
//         cout<<"\nres1 = "<<res1;
//         cout<<"\nres2 = "<<res2;
        
        
        return res1 == res2;
        
    }
};