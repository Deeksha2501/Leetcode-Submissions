class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)return "1";
        string prev = countAndSay(n-1);
        int cnt=1;
        char p = prev[0];
        string res = "";
        for(int i=1 ; i<prev.length() ; i++){
            if(prev[i] == p)cnt++;
            else{
                res = res + to_string(cnt) + p;
                cnt = 1;
            }
            p = prev[i];
        }
        res = res + to_string(cnt) + p;
        return res;
    }
};