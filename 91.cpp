class Solution {
public:
    
    string s;
    int n;
    vector<int> mem;
    
    int dfs(int i){
        // if(i >= n)return 1;
        if(s[i] == '0')return 0;
        if(i >= n-1)return 1;
        if(mem[i] != -1)return mem[i];
        string ss = s.substr(i , 2);
        int x = stoi(ss);
        if(x >= 1 && x <= 26){
            return mem[i] = dfs(i+1) + dfs(i+2);
        }else{
            return mem[i] = dfs(i+1);
        }
    }
    
    int numDecodings(string s) {
        this->s = s;
        n = s.length();
        mem = vector<int>(n , -1);
        return dfs(0);
    }
};