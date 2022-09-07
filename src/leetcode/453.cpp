/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Thu Jun 02 2022
 */

// Time Limit Exceeded
// REFERENCE: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minMoves(vector<int>& nums) {
    // first sort the numbers
    sort(nums.begin(), nums.end());

    
    int n = nums.size();
    int startIndex = 0;
    int endIndex = n-1;
    int minMoves = 0;

    // printf("sorted array:\n");
    // for (int i = 0; i < n; i++) {
    //   cout<<nums[i]<<" ";
    // }
    // printf("\n");

    while(1) {
      // cout << startIndex << "\n";

      // startIndexPosition gets replaced by earlier highest value at the end of loop
      int valueAtStartIndex = nums[startIndex];

      int highestValue = nums[endIndex] + minMoves;
      int difference = highestValue - valueAtStartIndex;
      
      if(difference <= 0) {
        break;
      }

      // startIndex has reached to last element
      if(startIndex >= (endIndex)) {
        break;
      }

      // we are not actually increasing array value
      // we can count the increased value from min moves
      // which get added by calculating difference
      // only endIndex value, which are lower than highest value is increased
      int valueAtPositionAfterStartIndex = nums[startIndex + 1] + minMoves;

      // value is same, increase startIndex
      if(valueAtStartIndex == valueAtPositionAfterStartIndex) {
        startIndex++;
        continue;
      }

      // increasing n-1 elements value by difference
      minMoves += difference;
      // cout << "increased minmove: "<< minMoves <<"\n";

      // earlier highest value will now be positioned after startIndex
      // (n-2) index has now highest value
      // startIndex is now positioned on earlier highest value
      startIndex++;
      nums.insert(nums.begin()+(startIndex), highestValue);
      nums.pop_back();

      // printf("sorted array:\n");
      // for (int i = 0; i < n; i++) {
      //   cout<<nums[i]<<" ";
      // }
      // printf("\n");
    }

    return minMoves;
  }
};

int main() {
  Solution sl;

  while(1) {
    int num, x;
    scanf("%d", &num);
    
    vector<int>nums;

    for (int i = 0; i < num; i++) {
      scanf("%d", &x);
      nums.push_back(x);
    }

    int output = sl.minMoves(nums);
    cout<<"output : "<< output <<"\n";
  }
  return 0;
}



// Test cases

// [1,2,3]
// 3
// [1,1,1]
// 0
// [-1, 5, 1]
// 8
// [0,-1,-1,5,3]
// 11
// [5,0,2,-1,5,5]
// 22

// Explanation

// After sort [0,-1,-1,5,3] becomes [-1,-1,0,5,3]
// startIndex = 1 as first two is same
// difference = nums[endIndex] - nums[startIndex] = 6
// so, now [5,5,6,9,5]
// startIndex = startIndex+1
// highest index value is moved to new startIndex position [5,5,5,6,9]
// Here, we don\'t actually update the value, as it will take O(n)
// we know value has increased for n-1 elements, except the earlier highest value 
// which is now positioned at startIndex 
// So, current array will look like this [-1,-1,5,0,3]
// and it will continue go on with same logic until difference is zero 
// or startIndex reaches to endIndex
