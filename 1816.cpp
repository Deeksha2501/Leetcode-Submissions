class Solution {
public:
    string truncateSentence(string s, int k) {
        int i=0;
        for(i=0 ; i<s.size() ; i++){
            if(s[i] == ' ')k--;
            if(k == 0){
                break;
            }
            
            
        }
        s = s.substr(0 , i);
        return s;
    }
};