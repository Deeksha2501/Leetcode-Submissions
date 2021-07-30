class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> res;
        int a = sqrt(num+2);
        for(int i=a ; i>=1 ; i--){
            if((num+1)%i == 0){
                res.push_back(i);
                res.push_back((num+1)/i);
                return res;
            }
            if((num+2)%i == 0){
                res.push_back(i);
                res.push_back((num+2)/i);
                return res;
            }
        }
        return res;
    }
};