class Solution {
public:
    int longestBeautifulSubstring(string word) {
        unordered_set<char> s;
        int n = word.length();
        int i=0;
        char prev = word[i];
        int st = 0, end = 0;
        int res = 0;
        while(i<n){
            if(i != 0 && word[i]<prev){
                if(s.size()==5){
                    res = max(res, end-st);
                }
                s.clear();
                
                st = i;
            }
            end++;
            s.insert(word[i]);
            prev = word[i];
            i++;
        }
        if(s.size()==5)res = max(res , end-st);
        return res;
    }
};