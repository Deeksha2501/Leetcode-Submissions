class Solution {
public:
    int cnt=0;
    vector<int> arr;
    vector<vector<int>> mem;
    void dfs(int i , int even , int odd , bool flag){
        if(i >= arr.size()){
            if(even == odd && flag==true)cnt++;
            return;
        }
        
        // if(mem[i][flag] != -1)return me
        
        if(flag){
            int e=even, o=odd;
            if(i%2)e += arr[i];
            else o += arr[i];
            dfs(i+1 , e , o , flag);   
        }else{
            int e=even, o=odd;
            if(i%2)o += arr[i];
            else e += arr[i];
            dfs(i+1 , even , odd , !flag);
            dfs(i+1 , e , o , flag); 
        }
        
        
        
    }
    
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n);
        vector<int> endsum(n);
        
        for(int i=0;i<nums.size() ;i++){        
            if(i==0 || i==1){
                presum[i]=nums[i];
                endsum[nums.size() -1-i]=nums[nums.size() -i-1];
            }else {
                presum[i]=nums[i]+presum[i-2];
                endsum[nums.size() -i-1]=nums[nums.size() -i-1]+endsum[nums.size() -i+1];
            }
        }
    
        int res=0;
        for(int i=0;i<nums.size() ;i++){
            int sum1=0;
            int sum2=0;
            if(i-2>=0)sum1+=presum[i-2];
            if(i+1<nums.size() )sum1+=endsum[i+1];
            if(i-1>=0)sum2+=presum[i-1];
            if(i+2<nums.size() )sum2+=endsum[i+2];
            if(sum1==sum2)res++;
        }
        return res;
    }
};