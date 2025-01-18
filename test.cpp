#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int maxConsecutive(int bottom, int top, vector<int> &special) {
    // Sắp xếp mảng special
    sort(special.begin(), special.end());
    int n = special.size();
    int res = 0;

    // Kiểm tra khoảng từ bottom đến số đặc biệt đầu tiên
    if (special[0] != bottom) {
      res = special[0] - bottom;
    }

    // Kiểm tra khoảng từ số đặc biệt cuối cùng đến top
    if (special[n - 1] != top) {
      res = max(res, top - special[n - 1]);
    }

    // Duyệt qua các khoảng giữa các số đặc biệt liên tiếp
    for (int i = 1; i < n; i++) {
      if (special[i] - special[i - 1] > 1) {
        res = max(res, special[i] - special[i - 1] - 1);
      }
    }

    return res;
  }
};

int main() { return 0; }