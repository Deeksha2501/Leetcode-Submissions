class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        int n = s.length();
        if(n == 1)return s;
        while(i<n-1){
            if(s[i] == s[i+1]){
                string s1 = s.substr(0 , i);
                string s2 = s.substr(i+2);
                
                s = s1 + s2;
                i--;
                if(i<0)i=0;
                n = s.length();
            }
            else i++;
        }
        return s;
    }
};