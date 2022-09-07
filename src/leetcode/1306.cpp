/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Thu May 26 2022
 */

// Accepted
// REFERENCE: https://leetcode.com/problems/jump-game-iii/

#include<bits/stdc++.h>

using namespace std;

class Solution {

private:
  bool BFS(
    vector<int> adj[], 
    int src, 
    int dest, 
    int len
  )
  {
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // BFS algorithm
    list<int> queue;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[len];

    // initially all vertices are unvisited
    // so visited[i] for all i is false
    for (int i = 0; i < len; i++) {
      visited[i] = false;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop_front();
      for (int i = 0; i < adj[u].size(); i++) {
        if (visited[adj[u][i]] == false) {
          visited[adj[u][i]] = true;
          queue.push_back(adj[u][i]);

          // We stop BFS when we find
          // destination.
          if (adj[u][i] == dest) {
            return true;
          }
        }
      }
    }
    return false;
  }

public:
  bool canReach(vector<int>& arr, int start) {
    
    if(arr[start] == 0) {
      return true;
    }
    int len = arr.size();
    if(len == 1) {
      return false;
    }
    vector<int> adjacencyList[len];
    vector<int> zeroValuedIndex;
    
    for (int i=0; i<len; i++) {
      int indexValue = arr[i];
      if (indexValue == 0) {
        zeroValuedIndex.push_back(i);
        continue;
      }
      int nextTargetIndex = i + indexValue;
      int preTargetIndex = i - indexValue;

      if(nextTargetIndex < len) {
        adjacencyList[i].push_back(nextTargetIndex);
      }
      if(preTargetIndex >= 0) {
        adjacencyList[i].push_back(preTargetIndex);
      }
    }

    int zeroValueIndexSize = zeroValuedIndex.size();
    if (zeroValueIndexSize == 0) {
      return false;
    }

    bool canReach = false;
    for (int i=0; i<zeroValueIndexSize; i++) {
      canReach = BFS(adjacencyList, start, zeroValuedIndex[i], len);
      if(canReach) {
        break;
      }
    }
    return canReach;
  }
};

int main() {
  Solution sl;
  
  while(1) {
    int num, start;
    scanf("%d", &num);
    if(num <=0) {
      break;
    }
    vector<int>nums;
    for (int i=0; i<num; i++) {
      int val;
      scanf("%d", &val);
      nums.push_back(val);
    }
    scanf("%d", &start);
    bool output = sl.canReach(nums, start);
    cout<<"output : "<< output <<"\n";
  }
  return 0;
}

// Test cases

// arr = [4,2,3,0,3,1,2], start = 5, output = true
// arr = [4,2,3,0,3,1,2], start = 0, output = true
// arr = [3,0,2,1,2], start = 2, output = false
// arr = [5], start = 0, output = false
// arr = [0], start = 0, output = true
// arr = [5,0], start = 1, output = true
// arr = [0,1,2,0,1], start = 2, output = true
