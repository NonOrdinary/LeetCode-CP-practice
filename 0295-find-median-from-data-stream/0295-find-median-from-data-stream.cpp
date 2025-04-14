class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()){
            left.push(num);
            return;
        }
        if(left.size()>right.size()){
            //add to right 
            if(num<left.top()){
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            else{
                right.push(num);
            }
        }
        else{
            if(num>right.top()){
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            else{
                left.push(num);
            }
        }
    }
    
    double findMedian() {
        if((left.size()+right.size())%2){
            return left.top();
        }
        else{
            return (left.top()+right.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */