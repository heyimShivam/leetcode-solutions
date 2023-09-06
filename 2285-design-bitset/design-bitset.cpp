class Bitset {
    vector<int> bitsetVar;
    int oneCount = 0;
    bool flips = false;

public:
    Bitset(int size) {
        bitsetVar.resize(size, 0);
    }
    
    void fix(int idx) {
        if(!flips) {
           if(bitsetVar[idx] == 0) oneCount++;
           bitsetVar[idx] = 1;
        } else {
            if(bitsetVar[idx] == 1) {
              oneCount++;
            }

            bitsetVar[idx] = 0;
        }
    }
    
    void unfix(int idx) {
        if(!flips) {
           if(bitsetVar[idx] == 1) oneCount--;
           
           bitsetVar[idx] = 0;
        } else {
            if(bitsetVar[idx] == 0) oneCount--;
            
            bitsetVar[idx] = 1;
        }
    }
    
    void flip() {
        flips = !flips;
        oneCount = bitsetVar.size() - oneCount;
    }
    
    bool all() {
        if(bitsetVar.size() == oneCount) return true;

        return false;
    }
    
    bool one() {
        if(oneCount >= 1) return true;
        return false;
    }
    
    int count() {
        return oneCount;
    }
    
    string toString() {
        string st;

        if(flips) {
            for( auto it : bitsetVar) {
                if(it==0) st += '1';
                else st += '0';
            }
        } else {
            for( auto it : bitsetVar) {
                if(it==0) st += '0';
                else st += '1';
            }
        }

        return st;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */