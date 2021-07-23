class Solution {
public:
    static bool cmp(vector<int> a , vector<int> b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin() , in.end() , cmp);
        auto it = in.begin();
        
        int j=0;
        for(int i=0 ; i<in.size() ; i++){
            if(in[j][1] >= in[i][0]){
                in[j][1] = max(in[j][1] , in[i][1]);
            }else{
                j++;
                in[j][0] = in[i][0];
                in[j][1] = in[i][1];
            }
        }
        
        vector<vector<int>> res(j+1 , vector<int>(2));
        
        for(int i=0 ; i<j+1 ; i++){
            res[i][0] = in[i][0];
            res[i][1] = in[i][1];
        }
        
        return res;
    }
};