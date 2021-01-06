class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        vector<int> start;
        int curr_feul = 0;
        int flag = 0;
        for(int i=0 ; i<n ; i++){
            if(gas[i] >= cost[i]){
                curr_feul = 0;
                flag = 1;
                curr_feul += gas[i];
                curr_feul -= cost[i];
                int j=1;
                while(j<n){
                    int index = (i+j)%n;
                    curr_feul += gas[index];
                    if(cost[index] <= curr_feul){
                        curr_feul -= cost[index];
                        j++;
                        continue;
                    }
                    else{
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag == 1){
                return i;
            }
        }
        return -1;
        
    }
};
