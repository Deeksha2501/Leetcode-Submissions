class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(char c:s){
            if(('a'<= c && c <= 'z') || (0 <= c-'0'  && c-'0'<= 9)){
                res += c;
            };
        }
        int i=0;
        int j=res.size()-1;
        while(i <= j){
            if(res[i] != res[j])return false;
            i++;
            j--;
        }
        return true;
    }
};