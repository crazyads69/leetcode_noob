#include <initializer_list>
#include <string>
#include <unordered_map>
using namespace std;

// Solution 1: Use greedy algorithm to solve this problem
// Time complexity: O(1)
class Solution_1 {
public:
  string intToRoman(int num) {
    string res = "";
    string roman[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                      "XL", "X",  "IX", "V",  "IV", "I"};
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for (int i = 0; i < 13; i++) {
      while (num >= val[i]) {
        num -= val[i];
        res += roman[i];
      }
    }
    return res;
  }
};

// Solution 2: Optimize solution 1
// Time complexity: O(1)
class Solution_2 {
public:
  string intToRoman(int num) {
    string res = "";
    string roman[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                      "XL", "X",  "IX", "V",  "IV", "I"};
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for (int i = 0; i < 13; i++) {
      int count = num / val[i];
      num %= val[i];
      for (int j = 0; j < count; j++) {
        res += roman[i];
      }
    }
    return res;
  }
};
