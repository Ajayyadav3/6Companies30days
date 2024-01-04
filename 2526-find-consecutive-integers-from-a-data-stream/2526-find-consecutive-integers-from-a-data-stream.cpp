class DataStream {
    private:
    int value;
    int k;
    vector<int> stream;
     int targetCount;
public:
    DataStream(int value, int k) {
    this->value = value;
        this->k = k;
        this->targetCount = 0;
        
    }
    
    bool consec(int num) {
      stream.push_back(num);

        // Update targetCount based on the new integer added
        if (num == value) {
            targetCount++;
        }

        // If the stream size is greater than k, adjust targetCount for the removed integer
        if (stream.size() > k) {
            if (stream[stream.size() - k - 1] == value) {
                targetCount--;
            }
        }

        // Check if the last k integers are equal to the target value
        return (targetCount == k);
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */