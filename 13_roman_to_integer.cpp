#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Solution 1: Using a map to store the value of each Roman numeral
// Time complexity: O(n)
class Solution_1 {
public:
  int romanToInt(string s) {
    unordered_map<char, int> roman_map = {{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};

    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      // If the current value is less than the next value, subtract the current
      // (e.g., IV = 5 - 1 = 4, IX = 10 - 1 = 9, XL = 50 - 10 = 40, etc.)
      if (i < s.size() - 1 && roman_map[s[i]] < roman_map[s[i + 1]]) {
        result -= roman_map[s[i]];
      } else {
        // Otherwise, add the current value
        result += roman_map[s[i]];
      }
    }
    return result;
  }
};

// Solution 2: Using a switch statement to convert Roman numerals to integers
// Time complexity: O(n)
class Solution_2 {
public:
  int value(char roman) {
    switch (roman) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return 0;
    }
  }

  int romanToInt(string s) {
    int total = 0;
    int prev = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
      int curr = value(s[i]);
      if (curr >= prev) {
        total += curr;
      } else {
        total -= curr;
      }
      prev = curr;
    }
    return total;
  }
};