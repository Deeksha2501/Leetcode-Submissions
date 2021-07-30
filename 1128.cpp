class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> seen;
        int result = 0;
        for(auto& v:dominoes){
            if(v[0] > v[1]){
                swap(v[0], v[1]);
            }
            seen[make_pair(v[0],v[1])]++;
        }
        for(auto& [key, value] : seen){
            result += value*(value-1)/2;
        }
        return result;
    }
};