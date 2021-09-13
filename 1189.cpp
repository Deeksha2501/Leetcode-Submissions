class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char , int> mp{{'b',0},{'a',0},{'l',0},{'o',0},{'n',0}};
        
        for(char c : text){
            if(mp.find(c) != mp.end()){
                mp[c]++;
            }
        }
        int mn = INT_MAX;
        for(auto [key , val] : mp){
            if(key == 'l' || key == 'o'){
                val = val/2;
            }
            mn = min(val , mn);
        }
        return mn;
    }
};