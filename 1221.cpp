class Solution {
public:
    int balancedStringSplit(string s) {
        int left = 0;
        int right = 0;
        int i=0, res=0;
        while(i<s.length()){
            if(s[i] == 'L')left++;
            else right++;
            if(left == right){
                res++;
                left=right=0;
            }
            i++;
        }
        
        return res;
    }
};