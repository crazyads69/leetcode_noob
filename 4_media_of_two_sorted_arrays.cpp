#include <iostream>
#include <vector>
using namespace std;

// Using the merge operation of merge sort to solve the problem in O(m+n)
class Solution_1 {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // Merge the two sorted arrays into a single sorted array
    vector<int> merged;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        merged.push_back(nums1[i]);
        i++;
      } else {
        merged.push_back(nums2[j]);
        j++;
      }
    }
    while (i < nums1.size()) {
      merged.push_back(nums1[i]);
      i++;
    }
    while (j < nums2.size()) {
      merged.push_back(nums2[j]);
      j++;
    }
    // Calculate the median of the merged array
    int n = merged.size();
    if (n % 2 == 0) {
      // If the size of the merged array is even, return the average of the two
      // middle elements
      return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    } else {
      // If the size of the merged array is odd, return the middle element
      return merged[n / 2];
    }
  }
};

// Improved version of the above solution with O(log(min(m,n))) complexity
class Solution_2 {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // Ensure that nums1 is the smaller array
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }
    int x = nums1.size();
    int y = nums2.size();
    int low = 0, high = x;
    // Perform binary search on the smaller array to find the partition
    while (low <= high) {
      int partitionX = (low + high) / 2;
      int partitionY = (x + y + 1) / 2 - partitionX;
      int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
      int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
      int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
      int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
      if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
        if ((x + y) % 2 == 0) {
          return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
        } else {
          return max(maxLeftX, maxLeftY);
        }
      } else if (maxLeftX > minRightY) {
        // Move the partition to the left side to make the partitionX smaller
        high = partitionX - 1;
      } else {
        // Move the partition to the right side to make the partitionX larger
        low = partitionX + 1;
      }
    }
    // If the input arrays are not sorted, return 0.0
    return 0.0;
  }
};