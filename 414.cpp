class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> s;
        for(int i:nums){
            if(s.find(i) != s.end())continue;
            pq.push(i);
            while(pq.size()>3)pq.pop();
            s.insert(i);
        }
        
        if(pq.size() == 2)pq.pop();
        return pq.top();
    }
};


