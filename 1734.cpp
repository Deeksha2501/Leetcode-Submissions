class Solution {
public:
    vector<int> decode(vector<int>& en) {
        int first = 0;
        int n = en.size();
        for(int i=1 ; i<=n+1 ; i++){
            first = i ^ first;
        }
        for(int i=1 ; i<n ; i+=2){
            first ^= en[i];
        }
        vector<int> res;
        res.push_back(first);
        
        for(int i : en){
            res.push_back(first ^ i);
            first = res.back();
        }
        return res;
    }
};