class Solution {
public:
    vector<int> decode(vector<int>& e, int ft) {
        vector<int> res;
        res.push_back(ft);
        for(int i=0 ; i<e.size() ; i++){
            res.push_back(ft^e[i]);
            ft = ft ^ e[i];
        }
        return res;
    }
};