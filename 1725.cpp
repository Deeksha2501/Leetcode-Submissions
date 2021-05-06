class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        vector<int> ans;
        for(int i=0 ; i<r.size() ; i++){
            ans.push_back(min(r[i][0],r[i][1]));
            // cout<<min(r[i][0],r[i][1])<<endl;
        }
        sort(ans.begin(),ans.end());
        int n = ans.size();
        int prev = ans[n-1],count=1;
        for(int i=n-2 ; i>=0 ; i--){
            if(ans[i] == prev){
            count++;
                // cout<<"prev = "<<prev;
            }
            else break;
        }
        return count;
    }
};