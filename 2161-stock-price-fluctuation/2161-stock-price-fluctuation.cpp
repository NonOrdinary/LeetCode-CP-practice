class StockPrice {
public:
    set<pair<int, int>> stocks;
    unordered_map<int, int> rev;
    int latest;
    int latestValue;
    // i want to keep track of last-variable//1
    // i want to keep track of max-set//logN
    // i want to keep track of min-set//logN
    // i can update entries any time-set//logN
    StockPrice() {
        latest = -1;
    }

    void update(int timestamp, int price) {
        if (rev.find(timestamp) == rev.end()) {
            stocks.insert({price, timestamp});
            rev[timestamp]=price;
            latest = max(timestamp,latest);
        }
        else{
            stocks.erase({rev[timestamp],timestamp});//logN
            stocks.insert({price,timestamp});
            rev[timestamp]=price;
        }
        
    }

    int current() { return rev[latest]; }

    int maximum() { return stocks.rbegin()->first; }

    int minimum() { return stocks.begin()->first; }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */