class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        s.push(0);
        unordered_map<int, int> m;
        int n = prices.size();
        for(int i=1 ; i<n ; i++){
            // if(s.empty()){
            //     s.push(i);
            //     continue;
            // }
            
            while(s.empty() == false && prices[s.top()]>=prices[i]){
                m[s.top()] = prices[i];
                s.pop();
            }
            s.push(i);
        }
        for(int i=0 ; i<n ; i++){
            prices[i] -= m[i];
        }
        return prices;
    }
};