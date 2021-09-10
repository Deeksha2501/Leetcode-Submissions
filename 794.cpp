class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int o=0, x=0;
        bool winner = false;
        bool xwin=false, owin=false;
        
        for(string s : board){
            if(s == "XXX" || s == "OOO"){
                if(winner == false)winner = true;
                else{
                    return false;
                }
                if(s == "XXX"){
                    xwin = true;
                }
                if(s == "OOO")owin = true;
            }
            
            for(char c : s){
                if(c == 'X')x++;
                else if(c == 'O') o++;
            }
        }
        if(owin && x > o)return false;
        if(o > x)return false;
        if(x-o > 1)return false;
        if(xwin && x == o)return false;
        for(int j=0 ; j<3 ; j++){
            string s = "";
            for(int i=0 ; i<3 ; i++){
                s += board[i][j];
            }
            if(s == "XXX" || s == "OOO"){
                if(s == "XXX" && owin == true)return false;
                else if(s == "XXX"){
                    if(x == o)return false;
                    else xwin = true;
                }
                else if(s == "OOO" && xwin == true)return false;
                    else if(s == "OOO"){
                    if(x > o)return false;
                    else owin = true;
                }
            }
        }
        
        string s1="", s2="";
        for(int i=0 ; i<3 ; i++){
            s1 += board[i][i];
            s2 += board[i][2-i];
        }
        // cout<<"\n1";
        if(s1 == "XXX" || s1 == "OOO"){
            if(s1 == "XXX" && owin == true)return false;
            else if(s1 == "XXX"){
                    if(x == o)return false;
                    else xwin = true;
                }
            else if(s1 == "OOO" && xwin == true)return false;
            else if(s1 == "OOO"){
                if(x > o)return false;
                else owin = true;
            }
            
        }
        
        // cout<<"\n2";
        
        
        if(s2 == "XXX" || s2 == "OOO"){
            if(s2 == "XXX" && owin == true)return false;
            else if(s2 == "XXX"){
                    if(x == o)return false;
                    else xwin = true;
                }
            else if(s2 == "OOO" && xwin == true)return false;
            else if(s2 == "OOO"){
                if(x > o)return false;
                else owin = true;
            }
        }
        return true;
    }
    
};

// ["XOX",
//  "OXO",
//  "XOX"]

// ["XXX",
 // "OOX",
 // "OOX"]

// ["OXX",
//  "XOX",
//  "OXO"]

// ["OXX","XOX","OXO"]

// ["XXX",
//  "XOO",
//  "OO "]