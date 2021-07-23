class Solution {
public:
    bool checkRecord(string s) {
        int i=0;
        int n = s.length();
        int a=0, l = 0;
        while(i<n){
            if(s[i] == 'A'){
                a++;
                l=0;
                if(a>=2)return false;
            }else if(s[i] == 'L'){
                l++;
                if(l>=3)return false;
            }else{
                l=0;
            }
            i++;
        }
        return true;
    }
};