class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int nn = s.size();
        for(int i=nn-2 ; i>=0 ; i--){
            if(s[i] < s[i+1]){
                int j = s.size()-1;
                while(j > i && s[j] <= s[i])j--;
                swap(s[i] , s[j]);
                reverse(s.begin()+i+1 , s.end());
                break;
            }
        }
        long temp = stol(s);
        if(temp == n || temp > INT_MAX)return -1;
        return (int)temp;
    }
};