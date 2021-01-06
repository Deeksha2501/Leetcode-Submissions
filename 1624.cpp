int const CHAR = 256;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int occ[CHAR];
        fill(occ , occ+CHAR , -1);
        int res = -1;
        for(int i=0 ; i<s.length() ; i++){
            if(occ[s[i]] != -1){
                res = max(res , (i-occ[s[i]]-1));
            }else{
                occ[s[i]] = i;
            }
        }
        return res;
    }
};
