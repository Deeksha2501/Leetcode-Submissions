class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i,j;
        if(x!=1)i = ceil(log(bound)/log(x));
        else i = 1;
        
        if(y != 1)j = ceil(log(bound)/log(y));
        else j = 1;
        
        // cout<<"i = "<<i;
        // cout<<"j = "<<j;
        
        vector<int> v;
        unordered_set<int> s;
        unordered_set<int>::iterator it;
        
        for(int ii=0 ; ii<=i ; ii++){
            for(int jj=0 ; jj<=j ; jj++){
                int sum = pow(x , ii);
                sum += pow(y, jj);
                if(sum<=bound){
                    s.insert(sum);
                }
            }
        }
        for(it = s.begin() ; it!=s.end() ; it++){
            v.push_back(*it);
        }
        sort(v.begin(), v.end());
        return v;
    }
};