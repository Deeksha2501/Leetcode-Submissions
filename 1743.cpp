class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        unordered_map<int , vector<int> > m;
        for(int i=0 ; i<ap.size() ; i++){
            m[ap[i][0]].push_back(ap[i][1]);
            m[ap[i][1]].push_back(ap[i][0]);
        }
        int left = INT_MAX , right = INT_MAX;
        for(auto itr = m.begin(); itr != m.end(); ++itr){
            // cout<<itr->first<<" ";
            vector<int> v = itr->second;
            if(v.size() == 1){
                if(left == INT_MAX){
                    left = itr->first;
                }else{
                    right = itr->first;
                    break;
                }
            }
            // for(int i=0 ; i<v.size() ; i++){
            //     cout<<v[i]<<" ";
            // }
            // cout<<endl;
            
        }
        vector<int> res;
        res.push_back(left);
        unordered_set<int> s;
        s.insert(left);
        
        cout<<left <<" "<<right;
        
        int curr = left;
        while(curr != right){
            vector<int> v = m[curr];
            for(int i=0 ; i<v.size() ; i++){
                if(s.find(v[i]) == s.end()){
                    res.push_back(v[i]);
                    s.insert(v[i]);
                    curr = v[i];
                    break;
                }
            }
        }
        
       
        return res;
    }
};