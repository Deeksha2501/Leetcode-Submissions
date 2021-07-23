class Solution {
public:
    
    vector<vector<int> >mem;
    
    int fun(int p, int i, int n){
        if(i >= n){
            return 1;
        }
        if(p>5)return 0;
        if(mem[p][i] != -1)return mem[p][i];
        int x = 0;
        for(int j = p ; j<=5 ; j++){
            x += fun(j , i+1 , n);
        }
        mem[p][i] = x;
        return x;
    }
    
    int countVowelStrings(int n) {
        
        mem = vector<vector<int >>(6 , vector<int>(n+1 , -1));
        
        int res=0;
        return fun(1 , 0 , n );
    }
};