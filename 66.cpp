class Solution {
public:
    vector<int> plusOne(vector<int>& res) {
        int i = res.size()-1;
        res[i]++;
        int carry = 0;
        if(res[i] >= 10){
            res[i] = 0;
            carry = 1;
        }
        i--;
        while(i >= 0 && carry){
            res[i]++;
            if(res[i] >= 10){
                res[i] = 0;
                carry = 1;
            }else{
                carry = 0;
            }
            i--;
        }
        if(carry)res.insert (res.begin(), 1);
        return res;
    }
};