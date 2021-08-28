class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prq) {
        vector<vector<int>> edges(num);
        vector<int> in(num);
        for(auto v : prq){
            int a = v[0];
            int b = v[1];
            edges[b].push_back(a);
            in[a]++;
        }
        
        queue<int> q;
        
        for(int i=0 ; i<num ; i++){
            if(in[i] == 0)q.push(i);
        }
        
        vector<int> res;
        
        while(q.size() > 0){
            int temp = q.front();
            auto v = edges[temp];
            res.push_back(temp);
            for(int i=0 ; i<v.size() ; i++){
                in[v[i]]--;
                if(in[v[i]] == 0)q.push(v[i]);
            }
            q.pop();
        }
        if(res.size() != num)return {};
        return res;
        
    }
};