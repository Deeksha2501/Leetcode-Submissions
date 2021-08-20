class Solution {
public:
    bool hasAllCodes(string s, const int k) {
        int need = 1 << k;
        int n = s.length();
        unordered_set<string> st;
        for(int i=k ; i<=n ; i++){
            string str = s.substr(i-k , k);
            if(st.find(str) == st.end()){
                st.insert(str);
                need--;
                if(need == 0)return true;
            }
        }
        return false;
    }
};