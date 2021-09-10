class Solution {
public:
    bool isIdealPermutation(vector<int>& a) {
        int cmax = 0;
        int n = a.size();
        for(int i=0 ; i<n-2 ; i++){
            cmax = max(cmax , a[i]);
            if(cmax > a[i+2])return false;
        }
        return true;
    }
};