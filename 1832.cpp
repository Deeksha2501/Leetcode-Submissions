class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> arr(26,0);
        for(int i=0 ; i<s.length() ; i++){
            arr[s[i]-'a']++;
        }
        for(int i=0 ; i<26 ; i++){
            if(arr[i] == 0)return false;
        }
        return true;
    }
};