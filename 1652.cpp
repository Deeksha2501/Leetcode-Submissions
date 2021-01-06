class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n , 0);
        int p = 1;
        if(k == 0)
            return res;
        if(k<0){
            p=-1;
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j>k ; j--){
                        int index = (i+j-1)%n;
                        // cout<<"\nindex = "<<index;
                        if(index<0)
                            index = n+index;
                        // cout<<"\nrevised index = "<<index;
                        res[i] += code[index];
                }
            }
            return res;
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<k ; j = j + p){
                int index = (i+j+p)%n;
                res[i] += code[index];
            }
        }
        return res;
    }
};