class Solution {
public:
    unordered_set<int> res;
    vector<unsigned long long> nums;
    
    unordered_set<string> mem;
    
    void dfs(int presses , int num){
        if(presses == 0){
            res.insert(num);
            return;
        }
        string str="";
        str += to_string(presses) + " ";
        str += to_string(num);
        if(mem.find(str) != mem.end())return;
        mem.insert(str);
        presses--;
        for(int i=0 ; i<4 ; i++){
            int temp = nums[i]^num;
            dfs(presses , temp);
        }
    }
    
    int flipLights(int n, int presses) {
        nums = vector<unsigned long long>(4 , 0);
        unsigned long long set=1;
        
        for(int i=0 ; i<n ; i++){
            nums[0] |= set;
            if(i%2 == 0)nums[2] |= set;
            else nums[1] |= set;
            
            if((n-i-1)%3 == 0)nums[3] |= set;
            // cout<<"set = "<<set;
            set = set << 1;
        }
        // for(int i : nums)cout<<i<<" ";
        dfs(presses , 0);
        return res.size();
    }
};