class Solution {
public:
    vector<string> s;
    
    bool checkrow(int x , char p){
        for(int j=0 ; j<3 ; j++){
            if(s[x][j] != p)return false;
        }
        return true;
    }
    
    bool checkcol(int y , char p){
        for(int i=0 ; i<3 ; i++){
            if(s[i][y] != p)return false;
        }
        return true;
    }
    
    bool checkDiag(char p){
        for(int i=0 ; i<3 ; i++){
            if(s[i][i] != p)return false;
        }
        return true;
    }
    
    bool checkAntiDiag(char p){
        for(int i=0 ; i<3 ; i++){
            if(s[i][2-i] != p)return false;
        }
        return true;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        string ss="   ";
        for(int i=0 ; i<3 ; i++)s.push_back(ss);
        
        int n = moves.size();
        char c = 'A';
        for(auto m : moves){\
            int x = m[0];
            int y = m[1];
            s[x][y] = c;
            if(checkrow(x, c) || checkcol(y, c) || checkDiag(c) || checkAntiDiag(c)){
                if(c == 'A')return "A";
                return "B";    
            }
            if(c == 'A')c = 'B';
            else c = 'A';
        }
        
        if(n == 9)return "Draw";
        return "Pending";
    }
};