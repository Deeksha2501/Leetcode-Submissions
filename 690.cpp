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
    vector<Employee*> employee;
    unordered_map<int , int> mp;
    
    int dfs(int id){
        Employee* emp = employee[mp[id]];
        int sum = emp->importance;
        for(auto sub : emp->subordinates){
            sum += dfs(sub);
        }
        return sum;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        employee = employees;
        int n = employee.size();
        for(int i=0 ; i<n ; i++){
            Employee *emp = employee[i];
            mp[emp->id] = i;
        }
        return dfs(id);
    }
};