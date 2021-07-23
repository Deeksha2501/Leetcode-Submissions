class Solution {
public:
    string restoreString(string s, vector<int>& in) {
        string res=s;
        for(int i=0 ; i<in.size() ; i++){
            // cout<<"\nin[i] = "<<in[i]<<" s[i] = "<<s[in[i]];
            res[in[i]] = s[i];
        }
        return res;
    }
};