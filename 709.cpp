class Solution {
public:
    string toLowerCase(string s) {
        for(char &c : s){
            if(c >= 65 && c <= 90){
                c += 32;
            }
        }
        return s;
    }
};

class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0 ; i<str.length() ; i++){
            int t = str[i];
            // cout<<"\nt = "<<t;
            if(65 <= t && t <= 90){
                str[i] += 32;
            }
        }
        return str;
    }
};