class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ec) {
        int n=candies.size();
        vector<bool> res;
        int max = candies[0];
        for(int i=0 ; i<n ; i++){
            if(candies[i]>max){
                max = candies[i];
            }
        }
        for(int i=0 ; i<n ; i++){
            if(candies[i]+ec >= max){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};