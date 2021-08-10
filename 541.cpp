class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        auto it = s.begin();
        int ptr = 0;
        while(ptr < n){
            if(k<=(n-ptr))reverse(it , it+k);
            else reverse(it , s.end());
            it = it + 2*k;
            ptr = ptr+2*k;
        }
        return s;
    }
};