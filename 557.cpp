class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word;
        string res;
        while(ss >> word){
            reverse(word.begin() , word.end());
            res += word + " ";
        }
        int n = res.length();
        res = res.substr(0 , n-1);
        return res;
    }
};