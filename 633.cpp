class Solution {
public:
    bool isSqr(int num){
        if(num < 0)return false;
        int x = sqrt(num);
        return x * x == num;      
    }
    
    bool judgeSquareSum(int c) {
        for(int i=0 ; i<=sqrt(c) ; i++){
            if(isSqr(c - (i*i)))return true;
        }
        return false;
    }
};