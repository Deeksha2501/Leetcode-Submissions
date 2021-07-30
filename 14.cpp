class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int n = INT_MAX;
        for(int i=0 ; i<strs.size() ; i++){
            int m = strs[i].length();
            n = min(n , m);
        }
        for(int i=0 ; i<n ; i++){
            char c = strs[0][i];
            for(int k=1 ; k<strs.size() ; k++){
                if(strs[k][i] != c)return res;
            }
            res += c;
        }
        return res;
    }
};