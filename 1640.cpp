class Solution {
public:
    int findInA(vector<int> arr , int el){
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] == el)
            return i;   
        }
        return -1;
    }
    
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int count=0;
        for(int i=0 ; i<pieces.size() ; i++){ 
            int res = findInA(arr , pieces[i][0]);
            if( res != -1){
                res++;
                for(int j=1 ; j<pieces[i].size() ; j++){
                    cout<<"\nres = "<<res;
                    if(arr[res] != pieces[i][j]){
                        return false;
                    }
                    res++;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};