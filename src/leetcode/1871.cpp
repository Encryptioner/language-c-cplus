/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Fri May 27 2022
 */

// Time LImit Exceeded
// REFERENCE: https://leetcode.com/problems/jump-game-vii/

#include<bits/stdc++.h>

using namespace std;

class Solution {

private:
  int min(int v1, int v2) {
    if (v1 <= v2) {
      return v1;
    }
    return v2;
  }
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
  bool canReach(string s, int minJump, int maxJump) {
    
    int len = s.length();

    if(s[len -1] != '0') {
      return false;
    }

    vector<int> adjacencyList[len];
    vector<int> acceptableSources;
    acceptableSources.push_back(0);
    
    for (int i=0; i<len-1; i++) {
      bool isAcceptableSource = count(acceptableSources.begin(), acceptableSources.end(), i);
      if(s[i] != '0' || !isAcceptableSource) {
        continue;
      }
      int effectiveMaxJump = min(i + maxJump, len - 1);
      for (int j=i+minJump; j<=effectiveMaxJump; j++) {
        if (s[j] != '0') {
          continue;
        }
        adjacencyList[i].push_back(j);
        acceptableSources.push_back(j);
        // cout << " src = "<< i << ", dest = "<< j <<"\n";
      }
    }
    bool canReach = BFS(adjacencyList, 0, len - 1, len);
    return canReach;
  }
};

int main() {
  Solution sl;

  freopen("1871.txt","r",stdin);
  
  while(1) {
    string s;
    int minJump, maxJump;

    getline(cin, s);
    if(s == "") {
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
