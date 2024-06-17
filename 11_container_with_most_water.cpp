#include <vector>
using namespace std;

// Solution 1: Use two pointers to solve this problem
// Time complexity: O(n)
class Solution_1 {
public:
  int maxArea(vector<int> &height) {
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int max_area = 0;
    while (left < right) {
      max_area =
          max(max_area, min(height[left], height[right]) * (right - left));
      if (height[left] < height[right]) {
        left++;
      } else {
        // If height[left] == height[right], we can move either left or right to
        // have potential larger area
        if (height[left] == height[right]) {
          right--;
          left++;
        } else
          right--;
      }
    }
    return max_area;
  }
};
