class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int kk) {
        vector<int> k, res;
        while(kk){
            int r = kk%10;
            k.push_back(r);
            kk/=10;
        }
        reverse(k.begin() , k.end());
        int n = num.size(), m = k.size();
        int i=n-1,j=m-1;
        int carry=0;
        while(i>=0 && j>=0){
            int temp = num[i] + k[j] + carry;
            if(temp >=10){
                carry = 1;
                temp -= 10;
            }else carry=0;
            res.push_back(temp);
            i--;
            j--;
        }
        while(i >= 0){
            int temp = num[i] + carry;
            if(temp >=10){
                carry = 1;
                temp -= 10;
            }else carry=0;
            res.push_back(temp);
            i--;
        }
        
        while(j >= 0){
            int temp = k[j] + carry;
            if(temp >=10){
                carry = 1;
                temp -= 10;
            }else carry=0;
            res.push_back(temp);
            j--;
        }
        
        if(carry)res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};