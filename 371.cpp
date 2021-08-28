class Solution {
public:
    int getSum(int a, int b) {
        int ans = a ^ b;
        unsigned int c = a & b;
        while(c != 0) {
            c <<= 1;
            int ans_prim = ans ^ c;
            c = ans & c;
            ans = ans_prim;
        }
        return ans;

    }
};