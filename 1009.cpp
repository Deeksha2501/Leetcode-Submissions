class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)return 1;
        int res = 0;
        int set = 1;
        
        while(n){
            if((n&1) == 0){
                res |= set;
            }
            set <<= 1;
            n >>= 1;
        }
        return res;
    }
};