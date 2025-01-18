#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumPartition(string s, int k) {
    int n = s.size();
    // Tạo mảng dp lưu số đoạn tối thiểu, khởi tạo với giá trị lớn
    vector<long long> dp(n, INT_MAX);
    dp[0] = 1; // Chỉ cần 1 đoạn để chia ký tự đầu tiên

    for (int i = 0; i < n; i++) {
      long long value = 0; // Lưu giá trị đoạn con
      for (int j = i; j >= 0; j--) {
        value = stoll(s.substr(j, i - j + 1)); // Đoạn con từ j đến i
        if (value > k) {
          break; // Nếu giá trị đoạn con > k, dừng xét
        }
        if (j == 0) {
          dp[i] = 1; // Nếu đoạn bắt đầu từ đầu chuỗi, chỉ cần 1 đoạn
        } else {
          dp[i] = min(dp[i], dp[j - 1] + 1); // Tính số đoạn tối thiểu
        }
      }
    }
    return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
  }
};

int main() { return 0; }