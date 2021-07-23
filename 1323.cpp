class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int count=0, res=-1;
        while(n){
            int r = n%10;
            // cout<<r = 
            if(r == 6)res = max(res , count);
            count++;
            n/=10;
        }
        
        cout<<res;
        n = num;
        
        if(res != -1){
            int up = num/pow(10, res+1)   ;
            up = up * pow(10, res+1);
            cout<<"\nup = "<<up;
            int i=0;
            int in = 0;
            while(i < (res)){
                in += (n%10 * (pow(10, i)));
                n/=10;
                i++;
            }
            cout<<"\nin = "<<in;
            int mid = 9 * pow(10, res);
            cout<<"\nmid = "<<mid;
            num = up+mid+in;
        }
        return num;
    }
};

// 9669
// 3210
// 9000+900+69
// 9669/pow(10, res+1) = 9*pow(10, res+1)
// 9 * pow(10, res);
// 9669/pow(10, res-1) = 



