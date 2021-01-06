class Solution {
public:
    int xorOperation(int n, int start) {
        int i=0 , val=0;
        while(i<n){
            val = val ^ (start + 2*i);
            i++;
        }
        return val;
    }
};