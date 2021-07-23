class person{
    public:
    int in=0;
    int out=0;
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<person> p(n+1);
        for(int i=0 ; i<trust.size() ; i++){
            int a = trust[i][0];
            int b = trust[i][1];
            p[a].out++;
            p[b].in++;
        }
        for(int i=1 ; i<=n ; i++){
            if(p[i].in == n-1 && p[i].out == 0)return i;
        }
        return -1;
    }
};