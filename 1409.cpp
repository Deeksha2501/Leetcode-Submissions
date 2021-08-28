class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> v , res;
        for(int i=1 ; i<=m ; i++)v.push_back(i);
        for(int q : queries){
            int i=0;
            for(i=0 ; i<=m ; i++){
                if(v[i] == q)break;
            }
            v.erase(v.begin()+i);
            v.insert(v.begin() , q);
            res.push_back(i);
        }
        return res;
    }
};