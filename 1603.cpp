class ParkingSystem {
public:
    vector<int> sizes;
    vector<vector<int> > v;
    
    ParkingSystem(int big, int medium, int small) {
        sizes = vector<int>(3);
        v = vector<vector<int> >(3);
        // sizes.push_back(big);
        // sizes.push_back(medium);
        // sizes.push_back(small);
        sizes[0] = big;
        sizes[1] = medium;
        sizes[2] = small;
        // cout<<endl<<sizes[0]<<" "<<sizes[1]<<" "<<sizes[2];

    }
    
    bool addCar(int carType) {
        int i= carType-1;
        // cout<<"\n i = "<<i;
        // cout<<"\nv[i].size = "<<v[i].size();
        // cout<<"\nsizes[i] = "<<sizes[i];
        if(v[i].size() >= sizes[i])return false;
        v[i].push_back(1);
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */