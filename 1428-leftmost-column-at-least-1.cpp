/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int rows = binaryMatrix.dimensions()[0];
        int cols = binaryMatrix.dimensions()[1];
        int right = cols - 1;
        for (int i = 0; i < rows; i++){
            while (right >= 0 && binaryMatrix.get(i, right) == 1) right--;
        }
        if (right == cols - 1) return -1;
        return right + 1;
    }
};