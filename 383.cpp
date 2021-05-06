class Solution {
public:
    bool canConstruct(string r, string m) {
        int v[26] = {0};
        for(int i=0 ; i<m.length() ; i++){
            v[m[i]-'a']++;
            
        }
        for(int i=0 ; i<r.length() ; i++){
            v[r[i]-'a']--;
            if(v[r[i]-'a'] < 0)return false;
        }
        return true;
    }
};