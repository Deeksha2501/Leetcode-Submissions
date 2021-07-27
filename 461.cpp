class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int cnt=0;
        while(n){
            cnt++;
            n = n & (n-1);
        }
        return cnt;
    }
};