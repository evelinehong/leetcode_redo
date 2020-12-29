class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for (auto &c: instructions){
            if (c == 'R') i = (i + 1) % 4;
            else if (c == 'L') i = (i + 3) % 4;
            else if (c == 'G') x += directions[i][0], y += directions[i][1];
        }
        if ((x == 0 && y == 0) || i != 0) return true;
        return false;
    }
};