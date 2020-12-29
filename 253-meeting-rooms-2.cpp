bool cmp(vector<int>&a, vector<int>&b){
    return a[0] < b[0];
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map <int, int> changes;
        for (auto &i: intervals){
            changes[i[0]] += 1;
            changes[i[1]] -= 1;
        }
        int rooms = 0, maxrooms = 0;
        for (auto &c: changes){
            maxrooms = max(maxrooms, rooms += c.second);
        }
        return maxrooms;
    }
};