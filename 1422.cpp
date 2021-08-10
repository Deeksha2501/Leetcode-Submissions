class Solution {
public:
    int maxScore(string s) {
        int ones=0,zeroes=0;
        for(char c : s){
            if(c == '0')zeroes++;
            else ones++;
        }
        unordered_map<char , int> m;
        int res=0;
        for(int i=0 ; i<s.length()-1 ; i++){
            m[s[i]]++;
            int score =  m['0'] + ones-m['1'];
            res = max(score , res);
        }
        return res;
    }
    
};
