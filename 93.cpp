class Solution {
public:
    vector<string> res;
    string s;
    int n;
        
    void dfs(int i , int k , string a){
        if(i >= n)return;
        if(k == 1){
            if(s[i] == '0' && i != n-1)return;
            string ss = s.substr(i);
            if(ss.length() > 3)return;
            int x = stoi(ss);
            if(0<=x && x<=255){
                a = a + '.' + ss;
                res.push_back(a);
            }
            return;
        }
        if(s[i] == '0'){
            string temp;
            if(a == "")temp = '0';
            else temp = a + "." + '0';
            dfs(i+1 , k-1, temp);
            return;
        }
        for(int j=i ; j<=i+2 ; j++){
            string ss = s.substr(i , (j-i+1));
            int x = stoi(ss);
            if(0<=x && x<=255){
                string temp;
                if(a == "")temp = ss;
                else temp = a + "." + ss;
                dfs(j+1 , k-1, temp);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        n = s.length();
        dfs(0 , 4 , "");
        return res;
    }
};