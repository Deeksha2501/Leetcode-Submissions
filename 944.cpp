class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        int cnt=0;
        for(int j=0 ; j<m ; j++){
            for(int i=1 ; i<n ; i++){
                if(strs[i][j] < strs[i-1][j]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s[0].length();
        int count=0;
        for(int i=0 ; i<n ; i++){
            int j=1;
            for(j=1 ; j<s.size() ; j++){
                if(s[j][i]<s[j-1][i])break;
            }
            if(j != s.size())count++;
        }
        return count;
    }
};