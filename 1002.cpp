class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_set<char> st;
        vector<int> v1(26, 0);
        vector<int> v2(26 ,0);
        for(char c : words[0]){
            v1[c-'a']++;
        }
        int n = words.size();
        for(int i=1 ; i<n ; i++){
            string str = words[i];
            for(char c : str){
                v2[c-'a']++;
            }
            for(int i=0 ; i<26 ; i++){
                v1[i] = min(v1[i], v2[i]);
                v2[i] = 0;
            }
        }
        vector<string> res;
        for(int i=0 ; i<26 ; i++){
            if(v1[i]){
                int val = v1[i];
                while(val--){
                    char c = i + 'a';
                    string s;
                    s = c;
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};