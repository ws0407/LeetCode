#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralArray(vector<vector<int>>& array)
    {
        int maxRow = array.size();
        if (!maxRow) return vector<int>(0);
        int maxColumn = array[0].size();
        if (!maxColumn) return vector<int>(0);
        int maxNum = maxRow * maxColumn;
        int curNum = 0;
        vector<int> outMatrix(maxNum);
        int row = 0, column = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右下左上
        int directionIndex = 0;
        while (curNum < maxNum)
        {
            outMatrix[curNum] = array[row][column];
            array[row][column] = 101;
            curNum++;
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= maxRow || nextColumn < 0 || nextColumn >= maxColumn || array[nextRow][nextColumn] == 101)
            {
                directionIndex = (directionIndex + 1) % 4; // 顺时针旋转至下一个方向
            }
            row = row + directions[directionIndex][0];
            column = column + directions[directionIndex][1];
        }
        return outMatrix;
    }
};


int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{7,8,9,10},{11,12,13,14}};
    Solution s;
    vector<int> res = s.spiralArray(matrix);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}