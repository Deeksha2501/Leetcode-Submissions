class Solution {
public:
    bool check(vector<int> v1 , vector<int> v2){
        for(int i=0 ; i<26 ; i++){
            if(v1[i] != v2[i])return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(p.length() > s.length())return res;
        vector<int> v1(26 , 0);
        vector<int> v2(27 , 0);
        for(int i=0 ; i<p.length() ; i++){
            v1[s[i]-'a']++;
            v2[p[i]-'a']++;
        }
        
        
        if(check(v1 , v2))res.push_back(0);
        int i=p.length();
        int m=p.length();
        for( ; i<s.length() ; i++){
            v1[s[i]-'a']++;
            v1[s[i-m]-'a']--;
            if(check(v1 , v2))res.push_back(i-m+1);
        }
        return res;
    }
};
