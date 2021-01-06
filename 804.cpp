class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0 ; i<words.size() ; i++){
            string str = words[i];
            string conv = "";
            for(int j=0 ; j<str.length() ; j++){
                conv += arr[str[j]-'a'];
            }
            s.insert(conv);
        }
        return s.size();
    }
};