class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue <long> low, high;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        low.push(num);
        high.push (-low.top());
        low.pop();
        if (low.size() < high.size()) {
            low.push (-high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        if (low.size() == high.size()) return (double) (low.top() - high.top())/2;
        else return low.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */