class Solution {
public:
    int titleToNumber(string s) {
        int n= s.length();
        int sum=0;
        for(int i=n-1 ; i>=0 ; i--){
            int x = (s[i]-'A') + 1;
            int p = pow(26 , (n-1-i));
            sum += (p*x);
        }
        return sum;
    }
};