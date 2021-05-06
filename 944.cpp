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