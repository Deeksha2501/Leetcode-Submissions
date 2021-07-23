class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int kk=k;
        string res="";
        int i = s.length()-1;
        while(i >= 0){
            while(k-- && i >= 0 ){
                if(s[i] != '-')res += toupper(s[i]);
                else{
                    i--;
                    while(i >=0 && s[i] == '-')i--;
                    if(i>=0)res += toupper(s[i]);
                }
                i--;
            }
            if(k == -1 && i != -1 && res != ""){
                k = kk;
                res += '-';
            }
        }
        reverse(res.begin() , res.end());
        if(res != "" && res[0] == '-')res = res.substr(1);
        return res;
    }
};