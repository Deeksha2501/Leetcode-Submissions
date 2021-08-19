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


class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        int n = encoded.size();
        res.push_back(first);
        for(int i=0 ; i<n ; i++){
            res.push_back(encoded[i] ^ first);
            first = encoded[i] ^ first;
        }
        return res;
    }
};