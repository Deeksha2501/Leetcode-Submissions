class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        int count=0;
        for(int i=0 ; i<allowed.size() ; i++){
            s.insert(allowed[i]);
        }
        for(int i=0 ; i<words.size() ; i++){
            bool flag = true;
            for(int j=0 ; j<words[i].size() ; j++){
                if(s.find(words[i][j]) == s.end()){
                    flag = false;
                    break;
                }
            }
            if(flag)count++;
        }
        return count;
    }
};