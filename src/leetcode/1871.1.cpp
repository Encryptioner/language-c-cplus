/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Fri May 27 2022
 */

// Accepted
// REFERENCE: https://leetcode.com/problems/jump-game-vii/

#include<bits/stdc++.h>

using namespace std;

class Solution {

public:
  bool canReach(string s, int minJump, int maxJump) {
    
    int len = s.length();
    int lastIndex = len -1;

    if(!len || s[lastIndex] != '0' || s[0] != '0') {
      return false;
    }

    int visited[len];
    visited[0] = 1;
    for (int i=1; i<len; i++) {
      visited[i] = 0;
    }

    int difference = 0;
    
    for (int i=1; i<len; i++) {
      int left = i-maxJump-1;
      int right = i-minJump;

      if (right >= 0) {
        difference += visited[right];
      }
      if (left >= 0)  {
        difference -= visited[left];
      }
      if(s[i] == '0') {
        if(difference > 0) {
          visited[i] = 1;
        }
        else {
          visited[i] = 0;
        }
      }
    }
    return visited[lastIndex] > 0;
  }
};


int main() {
  Solution sl;

  freopen("1871.txt","r",stdin);
  
  while(1) {
    string s;
    int minJump, maxJump;

    getline(cin, s);
    if(s == "" || s[0] == '/') {
      continue;
    }
    if(s == "0") {
      break;
    }
    scanf("%d", &minJump);
    scanf("%d", &maxJump);
    
    cout << "s = "<< s[0] <<
    ", minJump = "<<minJump <<
    ", maxJump = "<<maxJump <<
    ", len = "<<s.length() 
    <<"\n";
    
    bool output = sl.canReach(s, minJump, maxJump);
    cout<<"output : "<< output <<"\n";
  }
  return 0;
}

// Test cases

// s = "011010", minJump = 2, maxJump = 3, output = true
// s = "01101110", minJump = 2, maxJump = 3, output = false
// s = "011010 ", minJump = 2, maxJump = 2, output = false
// s = "000", minJump = 2, maxJump = 2, output = true
// s = "0000", minJump = 2, maxJump = 2, output = false
// s = "0111111111111111111111111111111101111101111111111111111110", minJump = 5, maxJump = 26, output = false
