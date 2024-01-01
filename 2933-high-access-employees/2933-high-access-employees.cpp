class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        // name -> access times
        unordered_map<string, vector<int>> mp;

        for (const auto& it : access_times) {
            int time = stoi(it[1]); 
            mp[it[0]].push_back(time);  
        }

        for (auto& it : mp)
            sort(it.second.begin(), it.second.end());

   
     vector<string> ans;

        for (const auto& it : mp) {
            const vector<int>& time = it.second;
            for (int i = 2; i < time.size(); ++i) {
                if (time[i] - time[i - 2] < 100) {
                    ans.push_back(it.first);
                    break;
                }
            }
        }

        return ans;
    }
};
