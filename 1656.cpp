class OrderedStream {
    vector<string> vect;
    int ptr;
    int len;
public:
    
    OrderedStream(int n) {
        ptr = 0;
        len = n;
        vect = vector<string>(n);
    }
    
    vector<string> insert(int id, string value) {
        vector<string> v;
        if(ptr == id-1){
            // cout<<"\nentered at ptr = "<<ptr+1;
            vect[ptr] = value;
            do{
                // cout<<"\ng at ptr = "<<ptr;
                v.push_back(vect[ptr]);
                ptr++;
                // cout<<"\nv[p] = "<<vect[ptr];
            }while(vect[ptr].length() != 0 && ptr<len);
        }else{
            vect[id-1] = value;
        }
        // cout<<"\n";
        // for(int i=0 ; i<len ; i++){
        //     cout<<vect[i]<<" ";
        // }
        // cout<<"\n";
        return v;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */