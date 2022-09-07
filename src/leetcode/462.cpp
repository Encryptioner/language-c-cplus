/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Sun Jun 05 2022
 */

// Wrong Answer
// REFERENCE: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minMoves2(vector<int>& nums) {
    int n = nums.size();
    
    long double sum = 0;
    for (int i = 0; i < n; i++) {
      long double value = double(nums[i]);
      sum += value;
    }

    int average = round(sum / n);
    int belowAverage = 0;
    int equalAverage = 0;
    int aboveAverage = 0;

    for (int i = 0; i < n; i++) {
      if(nums[i] < average) {
        belowAverage++;
      } else if (nums[i] > average){
        aboveAverage++;
      } else {
        equalAverage++;
      }
    }
    
    long long int minMoves = 0;
    int belowClosestToAverage = INT32_MIN + 1;
    int aboveClosestToAverage = INT32_MAX - 1;

    for (int i = 0; i < n; i++) {
      int difference = abs(nums[i] - average);
      minMoves += difference;

      if(nums[i] < average && nums[i] > belowClosestToAverage) {
        belowClosestToAverage = nums[i];
      }
      if(nums[i] > average && nums[i] < aboveClosestToAverage) {
        aboveClosestToAverage = nums[i];
      }
    }

    int belowAverageDiff = 0;
    int aboveAverageDiff = 0;
    long long int checkedMinMoves = minMoves;
    int start = abs(aboveAverage - belowAverage);

    if(belowClosestToAverage != (INT32_MIN + 1)) {
      belowAverageDiff = abs(average - belowClosestToAverage);
    }
    if(aboveClosestToAverage != (INT32_MAX - 1)) {
      aboveAverageDiff = abs(average - aboveClosestToAverage);
    }
    

    // cout << average << " "<<belowAverage << " "<< aboveAverage << " "<<equalAverage<<"\n";

    // cout << start << " "<<belowAverageDiff << " "<<aboveAverageDiff << " "<<belowClosestToAverage << " "<< aboveClosestToAverage << " "<<minMoves<<"\n";
    
    while((belowAverage > aboveAverage) && (start > 0) && (start <= belowAverageDiff)) {
      int aboveOrEqualAverage = aboveAverage + equalAverage;
      int addition = (belowAverage * start * -1) + (aboveOrEqualAverage * start);
      start ++;

      if(addition >= 0 || checkedMinMoves < 0) {
        break;
      }
      checkedMinMoves = minMoves + addition;
    }

    while((aboveAverage > belowAverage) && (start > 0) && (start <= aboveAverageDiff)) {
      int belowOrEqualAverage = belowAverage + equalAverage;
      int addition = (aboveAverage * start * -1) + (belowOrEqualAverage * start);
      start ++;

      if(addition >= 0 || checkedMinMoves < 0) {
        break;
      }
      checkedMinMoves = minMoves + addition;
    }
    
    return checkedMinMoves;
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

    int output = sl.minMoves2(nums);
    cout<<"output : "<< output <<"\n";
  }
  return 0;
}



// Test cases

// [1,2,3]
// 2
// [1,10,2,9]
// 16
// [-1, 5, 1]
// 6
// [0,-1,-1,5,3]
// 10
// [5,0,2,-1,5,5]
// 14
// [1,0,0,8,6]
// 14
// [203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143]
// 203125577 -349566234 230332704 48321315 66379082 386516853 50986744 -250908656 -425653504 -212123143
// 2127271182
// [1]
// 0
// [1,1,2]
// 1