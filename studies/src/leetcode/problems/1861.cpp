#include <algorithm>
#include <vector>

using namespace std;

class solution {
    static inline bool isStone(char c) { return c == '#'; }
    static inline bool isObstacle(char c) { return c == '*'; }
    static inline bool isEmpty(char c) { return c == '.'; }

  public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid) {
        vector<vector<char>> rotatedBox(boxGrid[0].size(), vector(boxGrid.size(), '.'));

        size_t box_row_size = boxGrid.size(), box_col_size = boxGrid[0].size();
        size_t rotated_row_size = rotatedBox.size(), rotated_col_size = rotatedBox[0].size();

        // Transpose and mirror the grid
        for (int row = 0; row < box_row_size; row++)
            for (int col = 0; col < box_col_size; col++)
                rotatedBox[col][rotated_col_size - 1 - row] = boxGrid[row][col];

        for (int col = 0; col < rotated_col_size; col++) {
            int last_obstacle_idx = rotated_row_size - 1;
            for (int row = last_obstacle_idx; row >= 0; row--) {
                char &cell = rotatedBox[row][col];
                if (isEmpty(cell))
                    continue;

                if (isObstacle(cell) || row == last_obstacle_idx) {
                    last_obstacle_idx = row - 1;
                    continue;
                }

                rotatedBox[last_obstacle_idx][col] = '#';
                rotatedBox[row][col] = '.';
                last_obstacle_idx--;
            }
        }

        return rotatedBox;
    }
};
