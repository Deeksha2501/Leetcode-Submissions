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

//optimised

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_tank=0, sum=0, start_index=0;
        for(int i=0 ; i<gas.size() ; i++){
            sum += gas[i]-cost[i];
            gas_tank += gas[i]-cost[i];
            if(gas_tank < 0){
                start_index = i+1;
                gas_tank = 0;
            }
        }
        if(sum < 0)return -1;
        return start_index;
    }
};