class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<int> vov{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        string v="";
        for(char c : s){
            if(vov.find(c) != vov.end())v += c;
        }
        reverse(v.begin(), v.end());
        int j=0;
        for(int i=0 ; i<s.size() ; i++){
            char c = s[i];
            if(vov.find(c) != vov.end()){
                s[i] = v[j];
                j++;
            }
        }
        return s;
    }
};