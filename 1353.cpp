struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        if(a.second == b.second)return a.first > b.first;
        return a.second > b.second;
    }
};


class Solution {
public:
    // static bool cmp(pair<int, int> a , pair<int, int> b){
    //     if(a.first == b.first)return a.second>b.second;
    //     return a.first > b.first;
    //}
    
    
    void print(priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq){
        while(!pq.empty()){
            cout<<pq.top().first<<" "<<pq.top().second<<endl;
            pq.pop();
        }
    }
    
    int maxEvents(vector<vector<int>>& a) {
        priority_queue <int, vector<int>, greater<int>> pq;
        sort(a.begin(), a.end());
        int d = 0, res=0, n = a.size(), i=0;
        while(pq.size()>0 || i < n){
            if(pq.empty())d = a[i][0];
            while(i < n && a[i][0] <= d){
                pq.push(a[i++][1]);            
            }
            pq.pop();
            ++res, ++d;
            while (pq.size() > 0 && pq.top() < d)
                pq.pop();
        }
        return res;
    }
};




