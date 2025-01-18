#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int minSwaps(vector<vector<int>> &grid) {
    vector<int> zeros(grid.size());
    for (int i = 0; i < grid.size(); i++) {
      int count = 0;
      for (int j = grid[i].size() - 1; j >= 0; j--) {
        if (grid[i][j] == 0) {
          count++;
        } else {
          break;
        }
      }
      zeros[i] = count;
    }
    int res = 0;
    for (int i = 0; i < zeros.size(); i++) {
      int target = zeros.size() - i - 1;
      if (zeros[i] >= target) {
        continue;
      }
      int j = i + 1;
      while (j < zeros.size() && zeros[j] < target) {
        j++;
      }
      if (j == zeros.size()) {
        return -1;
      }
      while (j > i) {
        swap(zeros[j], zeros[j - 1]);
        res++;
        j--;
      }
    }
    return res;
  }
};

int main() { return 0; }