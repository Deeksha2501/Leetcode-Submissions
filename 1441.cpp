class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_set<int> s;
        vector<string> res;
        for(int i:target)s.insert(i);
        int nn = target.back();
        for(int i=1 ; i<=nn ; i++){
            if(s.find(i) != s.end())res.push_back("Push");
            else{
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};