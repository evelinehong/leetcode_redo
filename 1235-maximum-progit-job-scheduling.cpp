//c++ map log(n) binary search
//dp[time] keeps the maximum profit until time;
//profit while adding a job is found by adding current and previous dp with endtime smaller (<=) than starttime;
//if it is larger than previous dp, update. else do not update because adding this job will not increase profit.
//why we use map: we need to find an endtime <= starttime. unorder map cannot do that.
class Solution {
public:
    vector<vector<int>> dp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); i++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        map <int, int> dp {{0,0}};
        for (auto &job: jobs){
            auto it = prev(dp.upper_bound(job[1]));
            int pf = it->second + job[2];
            if (pf > dp.rbegin() ->second) dp[job[0]] = pf;
        }
        return dp.rbegin()->second;
    }
    
};