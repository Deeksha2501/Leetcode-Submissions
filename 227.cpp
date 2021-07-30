class Solution {
public:
    int calculate(string s) {
        int res=0;
        int last = 0;
        char op = '+';
        int n = s.length();
        int curr = 0;
        for(int i=0 ; i<n ; i++){
            if(isdigit(s[i])){
                curr = curr*10 + (s[i]-'0');
            }
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == n - 1){
                if(op == '-' || op == '+'){
                    res = res + last;
                    last = (op == '+') ? curr : -curr;
                }
                else if (op == '*') {
                    last = last * curr;
                } 
                else if (op == '/') {
                    last = last / curr;
                }
                op = s[i];
                curr = 0;
            }
        }
        res += last;
        return res;
    }
};