class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int i=0;
        while(i < n){
            int end = min(i+k , n);
            reverse(s.begin()+i , s.begin()+end);
            i = end + k;
            
        }
        return s;
    }
};




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