class Solution {
public:
    static bool cmp(int a , int b){
        return a<b;
    }
    
    int hIndex(vector<int>& cts) {
        sort(cts.begin(), cts.end(), cmp);
        int h=1, n=cts.size();
        
        for(int i=n-1 ; i>=0 ; i--){
            if(cts[i] >= h)h++;
            else break;
        }
        return h-1;
    }
};
