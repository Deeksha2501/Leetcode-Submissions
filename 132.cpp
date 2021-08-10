class Solution {
public:
    bool isPalindrome(int i , int j){
        while(i < j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<int>> v;
    string s;
    int n;
    
    int dfs(int i , int j){
        if(i >= j || isPalindrome(i , j))return 0;
        if(v[i][j] != -1)return v[i][j];
        int n = s.length();
        int res=INT_MAX;
        for(int k=i ; k<j ; k++){
            if(!isPalindrome(i , k))continue;
            int temp = 1 + dfs(k+1 , j);
            res = min(res , temp);
        }
        return v[i][j] = res;
    }
    
    int minCut(string s) {
        this->s = s;
        n = s.length();
        v = vector<vector<int>>(n , vector<int>(n , -1));
        return dfs(0 , n-1);
    }
};
