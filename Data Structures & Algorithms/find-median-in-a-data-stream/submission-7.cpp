class MedianFinder {
public:
    priority_queue<int, vector<int>,    less<int>> lower;
    priority_queue<int, vector<int>, greater<int>> upper;

    MedianFinder() {}
    
    void addNum(int num) {
        if (lower.empty()) 
        {
            lower.push(num);
        } 
        else if (upper.empty())
        {
            if (lower.top() > num) 
            {
                int tmp = lower.top();
                lower.pop();
                lower.push(num);
                upper.push(tmp); 
                return;
            }
            upper.push(num);
        }
        else 
        {
            if (upper.size() == lower.size()) {
                if (num > upper.top())
                {
                    upper.push(num);
                }
                else 
                {
                    lower.push(num);
                }
            }
            else if (upper.size() > lower.size())
            {
                if (num > upper.top()) 
                {
                    int tmp = upper.top();
                    upper.pop();
                    upper.push(num);
                    lower.push(tmp); 
                    return;
                }
                lower.push(num);
            }
            else /* lower.size() > upper.size() */
            {
                if (lower.top() > num) 
                {
                    int tmp = lower.top();
                    lower.pop();
                    lower.push(num);
                    upper.push(tmp); 
                    return;
                }
                upper.push(num);
            }
        
        }
    }
    
    double findMedian() {
        if (upper.empty())
        {
            return static_cast<double>(lower.top());
        }
        else if (lower.empty())
        {
            return static_cast<double>(upper.top());
        }
        else 
        {
            if (lower.size() > upper.size())
            {
                return static_cast<double>(lower.top());
            }
            else if (upper.size() > lower.size()) 
            {
                return static_cast<double>(upper.top());
            }
            else
            {
                if (upper.size() == lower.size()) 
                {
                    return ( static_cast<double>(lower.top()) + static_cast<double>(upper.top()) ) / (2.0);
                }
                else if (upper.size() > lower.size())
                {
                    return static_cast<double>(upper.top());
                }
                else 
                {
                    return static_cast<double>(lower.top());
                }
            
            }
        }
    }
};
