class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();
        
        deque<int> in;
        for(int i=0 ; i<n ; i++){
            in.push_back(i);
        }
        
        vector<int> ans(n);
        sort(deck.begin(), deck.end());
        
        for(int card : deck){
            ans[in.front()] = card;
            in.pop_front();
            if(!in.empty()){
                in.push_back(in.front());
                in.pop_front();
            }
        }
        
        
        
        return ans;
    }
};