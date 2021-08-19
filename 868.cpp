class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int pos=0;
        int diff = 0;
        while(n){
            pos++;
            if((n&1) == 1){
                if(prev == -1)prev = pos;
                else{
                    diff = max(diff , (pos-prev));
                    prev = pos;
                }
            }
            n >>= 1;
        }
        return diff;
    }
};