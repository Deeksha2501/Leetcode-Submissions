class Solution {
public:
    static bool cmp(int x , int y){
        // cout<<"\ncomparing "<<x<<" and "<<y<<"\n";
        string a = to_string(x)+to_string(y);
        string b = to_string(y)+to_string(x);
        return a > b;
    }
        
    string largestNumber(vector<int>& nums) {
        sort(nums.begin() , nums.end() , cmp);
        string res="";
        if(nums[0] == 0)return "0";
        for(int a : nums)res += to_string(a);
        // cout<<endl;
        return res;
    }
};

class Solution {
public:
    void getVector(vector<int> nums){
        cout<<"\n";
        for(int i=0 ; i<nums.size() ; i++){
            cout<<nums[i]<<" ";
        }
    }
    
    string largestNumber(vector<int>& nums) {
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                // cout<<"\n value of i"<<nums[i];
                // cout<<"\nvalue of j"<<nums[j];
                for(int k=0 ; k<max(to_string(nums[j]).length() , to_string(nums[i]).length()) ; k++){
                    // cout<<"\n char in 1 : "<<to_string(nums[i])[k];
                    // cout<<"\n char in 2 : "<<to_string(nums[j])[k];
                    if(to_string(nums[i])[k] == NULL){
                        // cout<<"null condition acjieved";
                        if(to_string(nums[j])[k] > to_string(nums[i])[0]){
                            swap(nums[i] , nums[j]);
                            break;
                        }else if(to_string(nums[j])[k] == to_string(nums[i])[0]){
                            for(int in = 1 ; in<to_string(nums[i]).length() ; in++){
                                if(to_string(nums[j])[k] > to_string(nums[i])[in]){
                                    // cout<<"swap hua";
                                    swap(nums[i] , nums[j]);
                                    break;
                                }
                                else if(to_string(nums[j])[k] < to_string(nums[i])[in]){
                                    break;
                                }
                            }
                        }
                    }else if(to_string(nums[j])[k] == NULL){
                        // cout<<"null condition achieved";
                        if(to_string(nums[i])[k] < to_string(nums[j])[0]){
                            swap(nums[i] , nums[j]);
                            break;
                        }else if(to_string(nums[i])[k] == to_string(nums[j])[0]){
                            for(int in = 1 ; in<to_string(nums[j]).length() ; in++){
                                if(to_string(nums[i])[k] < to_string(nums[j])[in]){
                                    swap(nums[i] , nums[j]);
                                    break;
                                }else if(to_string(nums[i])[k] > to_string(nums[j])[in]){
                                    break;
                                }
                            }
                        }
                    }
                    else if(to_string(nums[i])[k] < to_string(nums[j])[k]){
                        // cout<<"swapped";
                        swap(nums[i] , nums[j]);
                        break;
                    }else if(to_string(nums[i])[k] == to_string(nums[j])[k]){
                        continue;
                    }
                    else if(to_string(nums[i])[k] > to_string(nums[j])[k]){
                        break;
                    }
                }
                // getVector(nums);
            }
        }
        string res = "";
        bool zeroes = true;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] != 0){
                zeroes = false;
            }
        }
        if(zeroes){
            return "0";
        }
        for(int i=0 ; i<nums.size() ; i++){
            res += to_string(nums[i]);
        }
        
        return res;
    }
};