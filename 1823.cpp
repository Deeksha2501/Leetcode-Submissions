class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        vector<int> ::iterator itr;
        int m = n;
        for(int i=0 ; i<n ; i++){
            v[i] = i+1;
        }
        int curr = 0;
        while(n>1){
            int left = (curr+k-1)%v.size();

            itr = v.begin()+left;
            v.erase(itr);

            int n = v.size();
            if(n == 1)break;

            curr = left;
        }
        return v[0];
    }
};