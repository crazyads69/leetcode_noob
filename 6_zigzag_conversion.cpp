#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution 1: Create a vector 2D to store the characters in each row and column
// Time complexity: O(n)
class Solution_1 {
public:
  string convert(string s, int numRows) {
    // Check if numRows is 1
    if (numRows == 1)
      return s;
    // Create a vector 2D to store the characters in each row
    vector<vector<string>> zigzag(numRows, vector<string>(s.size(), ""));
    // Initialize the row and column
    int row = 0, col = 0;
    // Initialize the direction
    bool down = true;
    // Iterate through the string
    for (int i = 0; i < s.size(); i++) {
      // Store the character in the current row and column
      zigzag[row][col] = s[i];
      // If the direction is down
      if (down) {
        // If the row is less than numRows - 1
        if (row < numRows - 1) {
          // Increment the row
          row++;
        } else {
          // Change the direction
          down = false;
          // Decrement the row
          row--;
          // Increment the column
          col++;
        }
      } else {
        // If the row is greater than 0
        if (row > 0) {
          // Decrement the row
          row--;
          // Increment the column
          col++;
        } else {
          // Change the direction
          down = true;
          // Increment the row
          row++;
        }
      }
    }
    // Initialize the result
    string result = "";
    // Iterate through the vector 2D
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < s.size(); j++) {
        // If the character is not empty
        if (zigzag[i][j] != "") {
          // Append the character to the result
          result += zigzag[i][j];
        }
      }
    }
    // Return the result
    return result;
  }
};

// Solution 2: Create a vector of strings to store the characters in each row
// Time complexity: O(n)
class Solution_2 {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
      rows[curRow] += c;
      if (curRow == 0 || curRow == numRows - 1)
        goingDown = !goingDown;
      curRow += goingDown ? 1 : -1;
    }

    string ret;
    for (string row : rows)
      ret += row;
    return ret;
  }
};

// Solution 3: Use cycle to calculate the row index of each character
// Time complexity: O(n)
class Solution_3 {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    string ret;
    int n = s.size();
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
      // Iterate through the string to get the cycle characters
      for (int j = 0; j + i < n; j += cycleLen) {
        ret += s[j + i];
        if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
          ret += s[j + cycleLen - i];
      }
    }
    return ret;
  }
};
