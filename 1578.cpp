class Solution {
public:
    
    int minCost(string s, vector<int>& cost) {
        int n = s.length();
        
        int res=0;
        
        for(int i=0 ; i<n-1 ; i++){
            int mx_index = i;
            int sum=0;
            while(s[i] == s[i+1]){
                sum += cost[i];
                if(cost[i]>cost[mx_index]){
                    mx_index = i;
                }
                i++;
            }
            sum += cost[i];
            if(cost[i]>cost[mx_index]){
                mx_index = i;
            }            
            // cout<<"\nat i = "<<i<<"sum = "<<sum;
            sum -= cost[mx_index];           
            // cout<<"at i = "<<i<<"sum = "<<sum;
            res += sum;
        }
        return res;
    }   
};