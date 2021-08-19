class Solution {
public:
    string longestNiceSubstring(string s) {
        // cout<<"\ns = "<<s;
        if(s.length() < 2)return "";
        unordered_set<char> st;
        for(char c : s)st.insert(c);
        for(int i=0 ; i<s.length() ; i++){
            char up = toupper(s[i]);
            char lo = tolower(s[i]);
            if(st.find(up) != st.end() && st.find(lo) != st.end())continue;
            string s1 = longestNiceSubstring(s.substr(0 , i));
            string s2 = longestNiceSubstring(s.substr(i+1));
            return s1.length() >= s2.length() ? s1 : s2;
        }
        // cout<<"returing = "<<s;
        return s;
    }
};