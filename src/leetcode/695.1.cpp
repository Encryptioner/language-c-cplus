/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Tue Jun 07 2022
 */

// Accepted
// REFERENCE: https://leetcode.com/problems/non-decreasing-array/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int n = nums.size();

    if( n == 1) {
      return true;
    }

    vector<int>filteredNums;
    vector<int>filteredNumsWithEarlierIndexValue;
    vector<int>filteredNumsWithLaterIndexValue;

    int corruptedIndex = -1;
    int countOfDecreasingNumber = 0;

    for (int i = 1; i < n; i++) {
      
      if(nums[i-1] <= nums[i]) {
        filteredNums.push_back(nums[i-1]);
        filteredNumsWithEarlierIndexValue.push_back(nums[i-1]);
        filteredNumsWithLaterIndexValue.push_back(nums[i-1]);
        continue;
      }

      filteredNumsWithEarlierIndexValue.push_back(nums[i-1]);
      filteredNumsWithLaterIndexValue.push_back(nums[i]);
      corruptedIndex = i;
      countOfDecreasingNumber++;
      i++;
      
      if(countOfDecreasingNumber > 1) {
        return false;
      }
    }

    if(n <=2 ) {
      return true;
    }

    if(corruptedIndex != n-1) {
      filteredNums.push_back(nums[n-1]);
      filteredNumsWithEarlierIndexValue.push_back(nums[n-1]);
      filteredNumsWithLaterIndexValue.push_back(nums[n-1]);
    }

    n = filteredNums.size();
    // for (int i = 0; i < n; i++) {
    //   cout<<filteredNums[i]<<" ";
    // }
    // cout<<"\n";

    for (int i = 1; i < n; i++) {
      if(filteredNums[i-1] > filteredNums[i]) {
        return false;
      }
    }

    countOfDecreasingNumber = 0;
    n = filteredNumsWithEarlierIndexValue.size();
    // for (int i = 0; i < n; i++) {
    //   cout<<filteredNumsWithEarlierIndexValue[i]<<" ";
    // }
    // cout<<"\n";

    for (int i = 1; i < n; i++) {
      if(filteredNumsWithEarlierIndexValue[i-1] > filteredNumsWithEarlierIndexValue[i]) {
        countOfDecreasingNumber++;
      }
      if(countOfDecreasingNumber > 1) {
        return false;
      }
    }

    n = filteredNumsWithLaterIndexValue.size();
    // for (int i = 0; i < n; i++) {
    //   cout<<filteredNumsWithLaterIndexValue[i]<<" ";
    // }
    // cout<<"\n";

    for (int i = 1; i < n; i++) {
      if(filteredNumsWithLaterIndexValue[i-1] > filteredNumsWithLaterIndexValue[i]) {
        countOfDecreasingNumber++;
      }
      if(countOfDecreasingNumber > 1) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  int n, x;
  Solution sl;

  while(1) {
    scanf("%d", &n);
    if(n <= 0) {
      break;
    }
    vector<int>nums;

    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      nums.push_back(x);
    }

    bool output = sl.checkPossibility(nums);
    cout<<"output : "<< output <<"\n";
  }
  return 0;
}

// Test cases
// 4 2 3
// 1
// 4 2 1
// 0
// 8 9 10 1
// 1
// 4 2 5 1
// 0
// -8 -9 -10 -4
// 0
// -9 -8 -10 -4
// 1
// 1
// 1
// 4 2
// 1
// [3,4,2,3]
// 0
// [3,4,2,2]
// 0
// [3,5,2,4]
// 0
// [5,5,5,4,6]
// 1
// [-1,4,2,3]
// 1
