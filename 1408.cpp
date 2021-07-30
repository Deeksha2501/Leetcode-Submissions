class Solution {
public:
    static bool compFunc(const string &a, const string &b)
    {
        return a.size() < b.size();
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin() , words.end(), compFunc);
        int n = words.size();
        vector<string> res;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(words[j].find(words[i]) != string::npos){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};