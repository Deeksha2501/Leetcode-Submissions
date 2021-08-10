class Solution {
public:
    static bool mycmp(vector<int> a , vector<int> b){
        return a[0] > b[0];
    }
    
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<vector<int>> v(n);
        for(int i=0 ; i<n ; i++){
            v[i].push_back(score[i]);
            v[i].push_back(i);
        }
        sort(v.begin() , v.end() , mycmp);
        vector<string> res(n);
        for(int i=0 ; i<n ; i++){
            if(i == 0)res[v[i][1]] = "Gold Medal";
            else if(i == 1)res[v[i][1]] = "Silver Medal";
            else if(i == 2)res[v[i][1]] = "Bronze Medal";
            else res[v[i][1]] = to_string(i+1);
        }
        return res;
    }
};