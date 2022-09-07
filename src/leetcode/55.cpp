/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Thu May 26 2022
 */

// Time Limit Exceeded
// REFERENCE: https://leetcode.com/problems/jump-game/

#include<bits/stdc++.h>

using namespace std;

class Solution {

private: 
  void addEdge(vector<int> adj[], int src, int dest)
  {
    adj[src].push_back(dest);
    // cout << src << " "<< dest << "\n";
  }
  void printShortestPath(int pred[], int dest) {
    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
      path.push_back(pred[crawl]);
      crawl = pred[crawl];
    }
    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--) {
      cout << path[i] << " ";
    }
    cout <<"\n";
  }
  int getShortestDistance(
    vector<int> adj[], 
    int src,
    int dest,
    int len
  )
  {
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from src
    int pred[len], dist[len];

    if (BFS(adj, src, dest, len, pred, dist) == false) {
      return -1;
    }

    // printShortestPath(pred, dest);

    return dist[dest];
  }
  bool BFS(
    vector<int> adj[], 
    int src, 
    int dest, 
    int len,
    int pred[], 
    int dist[]
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
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < len; i++) {
      visited[i] = false;
      dist[i] = INT_MAX;
      pred[i] = -1;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop_front();
      for (int i = 0; i < adj[u].size(); i++) {
        if (visited[adj[u][i]] == false) {
          visited[adj[u][i]] = true;
          dist[adj[u][i]] = dist[u] + 1;
          pred[adj[u][i]] = u;
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
  bool canJump(vector<int>& nums) {
    int len = nums.size();
    if(len <=1) {
      return true;
    }
    vector<int> adjacencyList[len];
    
    for (int i=0; i<len-1; i++) {
      int indexValue = nums[i];
      if (indexValue <=0) {
        continue;
      }
      for (int j=1; j<=indexValue; j++) {
        int targetIndex = i+j;
        if (targetIndex >= len) {
          break;
        }
        addEdge(adjacencyList, i, targetIndex);
      }
    }

    int shortestDistance = getShortestDistance(adjacencyList, 0, len-1, len);
    return shortestDistance != -1;
  }
};

int main() {
  Solution sl;

  int num;
  while(1) {
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
    bool output = sl.canJump(nums);
    cout<< output << "\n";
    cout<<"output : "<< output <<"\n";
  }
  return 0;
}

// Test cases

// [2,3,1,1,4] = true
// [3,2,1,0,4] = false
// [1] = true
// [2,0] = true
