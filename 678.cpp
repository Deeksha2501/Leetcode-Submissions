class Solution {
public:
    bool checkValidString(string s) {
        int cmin=0, cmax=0;
        for(char c:s){
            if(c == '('){
                cmin++;
                cmax++;
            }
            else if(c == ')'){
                cmax--;
                cmin = max(cmin-1 , 0);
            }else{
                cmax++;
                cmin = max(cmin-1 , 0);
            }
            if(cmax < 0)return false;
        }
        return cmin == 0;
    }
};
