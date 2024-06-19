#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Using backtracking to generate all possible combinations of the letters
// Time complexity: O(4^n) where n is the number of digits in the input string
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    // if the input string is empty, return an empty vector
    if (digits.empty())
      return {};
    // initialize the phone number mapping
    unordered_map<char, string> phone = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    // initialize the result vector
    vector<string> res;
    // initialize the temporary string
    string temp;
    // call the recursive function backtracking
    backtrack(digits, phone, res, temp, 0);
    return res;
  }
  void backtrack(string &digits, unordered_map<char, string> &phone,
                 vector<string> &res, string temp, int i) {
    // if the temporary string has the same length as the input string, add it
    // to the result vector
    if (i == digits.size()) {
      res.push_back(temp);
      return;
    }
    // get the characters corresponding to the current digit
    string letters = phone[digits[i]];
    // iterate through the characters
    for (char c : letters) {
      // append the character to the temporary string
      temp.push_back(c);
      // call the recursive function with the next digit
      backtrack(digits, phone, res, temp, i + 1);
      // remove the last character from the temporary string
      // after the recursive call returns
      temp.pop_back();
    }
  }
};