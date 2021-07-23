class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length()<3)return 0;
        
        int count=0;
        unordered_set<int> st;
        for(int i=0 ; i<3 ; i++){
            st.insert(s[i]);
        }
        if(st.size() == 3)count++;
        
        for(int i=3 ; i<s.length() ; i++){
            st.erase(s[i-3]);
            st.insert(s[i]);
            if(st.size() == 3)count++;
        }
        return count;
    }
};