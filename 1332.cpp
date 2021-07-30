class Solution {
public:
    int removePalindromeSub(string s) {
        if(s == "")return 0;
        string ss = s;
        reverse(ss.begin() , ss.end());
        if(s == ss)return 1;
        return 2;
    }
};