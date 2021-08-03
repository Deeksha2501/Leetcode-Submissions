class Solution {
public:
    stack<int> xx;
    stack<int> in;
    
    void solve(string s){
        int curr = 0;
        char op='+';
        int i=0;
        for(char c : s){
            if(c == '+' || c == '-'){
                if(op == '-'){
                    curr = -curr;    
                }
                in.push(curr);
                op = c;
                curr = 0;
            }else if(c == 'x'){
                if(curr == 0 && (i==0 || i>0 && (s[i-1] =='-' || s[i-1] == '+'))){
                    curr = 1;
                }
                if(op == '-')curr = -curr;
                xx.push(curr);
                curr = 0;
            }else{
                curr = 10*curr + c-'0';
            }
            i++;
        }
        if(op == '-'){
            curr = -curr;    
        }
        in.push(curr);
    }
    
    string solveEquation(string eq) {
        int st = eq.find("=");
        string a = eq.substr(0 , st);
        string b = eq.substr(st+1);
        solve(a);
        int ax = 0;
        int aa = 0;
        while(!xx.empty()){
            ax += xx.top();
            xx.pop();
        }
        while(!in.empty()){
            aa += in.top();
            in.pop();
        }
        
        solve(b);
        int bx = 0;
        int bb = 0;
        while(!xx.empty()){
            bx += xx.top();
            xx.pop();
        }
        while(!in.empty()){
            bb += in.top();
            in.pop();
        }
        
        if(ax == bx){
            if(aa == bb)return "Infinite solutions";
            else return "No solution";
        }
        int num = bb-aa;
        int l = ax-bx;
        if(ax < bx){
            num = -num;
            l = -l;
        }
        
        num = num/l;
        
        
        return  "x=" + to_string(num);
        
//         cout<<"\nax = "<<ax;
//         cout<<"\naa = "<<aa;
//         cout<<"\nbx = "<<bx;
//         cout<<"\nbb = "<<bb;
        
//         return a;
    }
};