class person{
    public:
    int in=0;
    int out=0;
};

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        vector<person> p(n);
        for(int i=0 ; i<e.size() ; i++){
            int a = e[i][0], b = e[i][1];
            p[a].out++;
            p[b].in++;
        }
        
        vector<int> res;
        for(int i=0 ; i<n ; i++){
            if(p[i].in == 0)res.push_back(i);
        }
        
        return res;
    }
};