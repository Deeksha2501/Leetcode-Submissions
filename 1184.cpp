class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dis, int start, int d) {
        int sum=0;
        int n = dis.size();
        for(int i=0 ; i<dis.size() ; i++){
            sum += dis[i];
        }
        int s = 0;
        for(int i=start ; i!=d ; i = (i+1)%n){
            s += dis[i];
        }
        if(s > sum-s)return sum-s;
        return s;
    }
};