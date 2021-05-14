class Solution {
public:
    int maxProfit(vector<int>& p) {
        int s=1,b=0,ans=0, ss = 1 , bb = 0;
        while(b<s && s < p.size()){
            if((p[s]-p[b]) > ans){
                ans = max(ans , p[s]-p[b]);
                ss = s;
                bb = b;
                s++;
            }else if(p[s]>p[b]){
                ans = max(ans , p[s]-p[b]);
                ss = s;
                bb = b;
                s++;
            }else if(p[s]>p[ss]){
                ans = max(ans , p[s]-p[bb]);
                ss = s;
                s++;  
            }
            else if(p[s]<=p[bb]){
                bb = s;
                b = s;
                s++;
            }
            else{
                b++;
                s++;            
            }
        }
        return ans;
    
    }
};

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int minp = INT_MAX;
        int maxp = 0;
        for(int i=0 ; i<p.size() ; i++){
            if(p[i] < minp){
                minp = p[i];
            }else if(p[i]-minp > maxp){
                maxp = p[i]-minp;
            }
        }
        return maxp;
    }
};