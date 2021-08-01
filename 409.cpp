class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char , int>mp;
        for(char c:s){
            mp[c]++;
        }
        int sum=0;
        int cnt = 0;
        for(auto it : mp){
            sum += it.second;
            if(it.second % 2 == 1){
                cnt++;
            }
        }
        if(cnt > 0)cnt--;
        return sum-cnt;
    }
};