class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int set = 1;
        while(num != 0) {
            if((num&1)== 0) {
                result |= set;
            }
            set <<= 1;
            num >>= 1;
        }
        return result;
    }
};