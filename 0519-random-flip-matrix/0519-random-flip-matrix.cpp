class Solution {
private:
    int rows;                                 
    int cols;                                 
    int totalCells;                           
    random_device rd;                    
    mt19937 randomGenerator{rd()};       
    unordered_map<int, int> flippedCellsMap;
  
public:
    
    Solution(int m, int n) : rows(m), cols(n), totalCells(m * n) {}

    
    vector<int> flip() {
        
        uniform_int_distribution<> distrib(0, totalCells - 1);
        int randomIndex = distrib(randomGenerator);
        totalCells--;

        int cellIndex = flippedCellsMap.count(randomIndex) ? flippedCellsMap[randomIndex]:randomIndex;

    
        flippedCellsMap[randomIndex] = flippedCellsMap.count(totalCells) ? flippedCellsMap[totalCells] : totalCells;

        
        return {cellIndex / cols, cellIndex % cols};
    }

    
    void reset() {
        totalCells = rows * cols;
        flippedCellsMap.clear();
    }
};

/**
 * The following are the typical operations that will be performed on an instance of the Solution class:
 * 
 * Solution obj(m, n);
 * std::vector<int> params = obj.flip();
 * obj.reset();
 */
