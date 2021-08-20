class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        vector<unordered_set<char>> rows(n);
        vector<unordered_set<char>> cols(n);
        vector<unordered_set<char>> boxes(n);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                char val = board[i][j];
                if(val == '.')continue;
                
                if(rows[i].find(val) != rows[i].end()){
                    return false;
                }
                rows[i].insert(val);
                
                if(cols[j].find(val) != cols[j].end()){
                    return false;
                }
                cols[j].insert(val);
                
                int idx = (i/3)*3 + (j/3);
                if(boxes[idx].find(val) != boxes[idx].end()){
                    return false;
                }
                boxes[idx].insert(val);
            }
        }
        return true;
    }
};