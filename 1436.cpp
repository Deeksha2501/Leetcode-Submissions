class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st , st2;
        int n = paths.size();
        for(int i=0 ; i<n ; i++){
            st.insert(paths[i][0]);
            st2.insert(paths[i][0]);
            st2.insert(paths[i][1]);
        }
        for(string s : st2){
            if(st.find(s) == st.end())return s;
        }
        return paths.back()[1];
    }
};