/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, int> m;
    vector<bool> vis;
    int imp=0;
    
    int fillM(vector<Employee*> emp){
        int mx = 0;
        for(int i=0 ; i<emp.size() ; i++){
            int id = emp[i]->id;
            m[id] = i;
            mx = max(mx , id);
        }
        return mx;
    }
    
    void get(vector<Employee*> emp, int id){
        if(vis[id] == true)return;
        vis[id] = true;
        int in = m[id];
        imp += emp[in]->importance;
        
        vector<int> sub = emp[in]->subordinates;
        
        for(int i=0 ; i<sub.size() ; i++){
            int index = m[sub[i]];
            // imp += emp[index]->importance;
            get(emp , sub[i]);

        }
    }
    
    int getImportance(vector<Employee*> emp, int id) {
        
        int n = fillM(emp);
        vis = vector<bool>(n+1 , false);
        
//         int in = m[id];
//         int imp = emp[in]->importance;
//         vector<int> sub = emp[in]->subordinates;
        
//         for(int i=0 ; i<sub.size() ; i++){
//             // int index = sub[i]-1;
//             int index = m[sub[i]];
//             imp += emp[index]->importance;
//         }
        get(emp , id);
        return imp;
    }
};