/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Tue Jun 07 2022
 */

// Wrong Answer
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

    int countOfDecreasingNumber = 0;
    int modifiedIndex = -1;
    int movingValue = 0;

    for (int i = 1; i < n; i++) {
      int earlierIndex = i-1;
      int earlierIndexValue = nums[earlierIndex];

      if(nums[i] >= earlierIndexValue) {
        continue;
      }
      
      if( modifiedIndex == -1) {
        countOfDecreasingNumber++;
      } else if(earlierIndex != modifiedIndex) {
        countOfDecreasingNumber++;
      } else if(nums[earlierIndex -1] > nums[i]) {
        countOfDecreasingNumber++;
      } else if(movingValue > nums[i]) {
        countOfDecreasingNumber++;
      }
      

      if(countOfDecreasingNumber > 1) {
        return false;
      }

      modifiedIndex = i;
      nums[earlierIndex] = nums[i];
      nums[i] = earlierIndexValue;
      movingValue = earlierIndexValue;

      for(int j= earlierIndex; j > 0; j--) {
        
        int comparingCurrentValue = nums[j];

        if(nums[j-1] < comparingCurrentValue) {
          break;
        }

        nums[j] = nums[j-1];
        nums[j-1] = comparingCurrentValue;
      }

      // for (int i = 0; i < n; i++) {
      //   cout<<nums[i]<<" ";
      // }
      // cout<<"\n";
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
