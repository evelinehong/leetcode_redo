class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x), y = abs(y);
        queue <pair<int, int>> coors;
        int step = 0;
        while (x > 4 || y > 4){
            step += 1;
            if (x >= y){
                x = abs(x-2);
                y = abs(y-1);
            }
            else {
                y = abs(y-2);
                x = abs(x-1);
            }
        }
        coors.push({x,y});
        int con = INT_MAX;
        int zero = INT_MAX;
        while (!coors.empty()) {
            int siz = coors.size();
            for (int i = 0; i < siz; i++){
                auto [x,y] = coors.front();
                coors.pop();
                if (x == 0 && y == 0) {zero = step; while (!coors.empty()) coors.pop(); break;}
                if (x + y == 2 && con == INT_MAX) con = step + 2;
                coors.push({abs(x-2), abs(y-1)});
                coors.push({abs(x-1), abs(y-2)});
            }
            step ++;
        }
        return min (con, zero);
    }
};