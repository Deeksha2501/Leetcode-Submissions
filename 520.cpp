class Solution {
public:
    bool detectCapitalUse(string s) {
        string up = s.substr(1);
        string lo = s.substr(1);
        transform(up.begin() , up.end() , up.begin() , ::toupper);
        transform(lo.begin() , lo.end() , lo.begin() , ::tolower);
        string ss = s.substr(1);
        if((ss == up && s[0]>=65 && s[0] <=90) || ss == lo)return true;
        return false;
    }
};