class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res;
        int low = 0, high = s.length();
        for(char c : s){
            if(c == 'I'){
                res.push_back(low);
                low++;
            }else{
                res.push_back(high);
                high--;
            }
        }
        res.push_back(low);
        return res;
    }
};