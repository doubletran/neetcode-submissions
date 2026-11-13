class MinStack {
    vector<pair<int,int>>numbers;
    int minimum;
public:
    MinStack() {
        minimum = pow(2, 31)-1;
        
    }
    
    void push(int val) {
        minimum = min(val, minimum);
        numbers.push_back({val, minimum});
    }
    
    void pop() {
        numbers.pop_back();
        if (numbers.size() == 0){
            minimum = pow(2, 31)-1;
        }
        else{
            minimum = numbers[numbers.size()-1].second;
        }
        
        
    }
    
    int top() {
        return numbers[numbers.size()-1].first;
        
    }
    
    int getMin() {
        return minimum;
        
    }
};
