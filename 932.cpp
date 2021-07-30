class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res;
        res.push_back(1);
        while(res.size() < n){
            vector<int> temp;
            for(auto i : res)if(2*i -1 <= n)temp.push_back(2*i-1);
            for(auto i : res)if(2*i <=n )temp.push_back(2*i);
            res = temp;
        }
        return res;
    }
};