class Solution {
public:
    int secondHighest(string s) {
        set<int> st;
        set<int> :: iterator itr;
        for(int i=0 ; i<s.length() ; i++){
            if(isdigit(s[i]))st.insert(s[i]-'0');
        }
        if(st.size()<2)return -1;
        itr = st.end();
        itr--;
        itr--;
        return *itr;
    }
};