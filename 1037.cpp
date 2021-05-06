class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        
        int mu=points[1][1]-points[0][1];
        int mn=points[1][0]-points[0][0];
        int left=mn*(points[2][1]-points[1][1]);
        int right=mu*(points[2][0]-points[1][0]);
        return left!=right;
        
    }
};