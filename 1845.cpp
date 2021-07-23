class SeatManager {
public:
    // vector<int> seats;
    // int nn, nextA;
    priority_queue<int, vector<int>,greater<int>> seats;
    SeatManager(int n) {
        // for(int i=1 ; i<=n ; i++){
        //     seats.push_back(i);
        // }
        // nn = n;
        // nextA = 0;
        for(int i=1 ; i<=n ; i++){
            seats.push(i);
        }
    }
    
    int reserve() {
        int val = seats.top();
        seats.pop();
        // seats[nextA] = -1;
        // for(int i=0 ; i<nn ; i++){
        //     if(seats[i] != -1){
        //         nextA = i;
        //         break;
        //     }
        // }
        
        return val;
    }
    
    void unreserve(int sn) {
        // seats[sn-1] = sn;
        // if(sn-1 < nextA)
        // nextA = sn-1;
        seats.push(sn);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */