class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& prq) {
        vector<vector<int>> adj(nc);
        vector<int> deg(nc , 0);
        for(int i=0 ; i<prq.size() ; i++){
            int b = prq[i][0];
            int a = prq[i][1];
            adj[b].push_back(a);
            deg[a]++;
        }
        
        queue<int> q;
        int cnt=0;
        for(int i=0 ; i<nc ; i++){
            if(deg[i] == 0){
                cnt++;
                q.push(i);
            }
        }
        
        while(q.size()>0){
            int n = q.size();
            for(int i=0 ; i<n ; i++){
                int t = q.front();
                q.pop();
                for(auto el : adj[t]){
                    deg[el]--;
                    if(deg[el] == 0){
                        cnt++;
                        q.push(el);
                    }
                }
            }
        }
        
        return (cnt == nc) ? true : false;
    }
};