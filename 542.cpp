#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // Assume mat is not empty.
    // A loop of loop to find the min distance. Start from 1 to find all possible 0.
    vector<vector<int>> updateMatrix_1(vector<vector<int>>& mat) {
      vector<vector<int>> dist_mat;
      int nr = mat.size();
      dist_mat.resize(nr);
      int nc = mat[0].size();
      for (int i=0; i<nr; i++) {
        dist_mat[i].resize(nc);
        for (int j=0; j<nc; j++) {
          // Find the min distance for the current node
          queue<pair<int,int>> qe;
          set<pair<int,int>> visited;
          qe.push(make_pair(i,j));
          int dist = 0;
          while (!qe.empty()) {
            // Jump out of the loop when
            // 1. Find 0
            // 2. All nodes are visited
            pair<int,int> cur = qe.front();
            qe.pop();
            int r = cur.first, c = cur.second;
            if (mat[r][c]==0) {
              dist = abs(r-i) + abs(c-j);
              break;
            }
            //
            visited.insert(make_pair(r,c));
            //
            if (r<nr-1) {
              pair<int,int> nxt = make_pair(r+1,c);
              if (visited.find(nxt) == visited.end()) {
                qe.push(nxt);
              }
            }
            if (r>0) {
              pair<int,int> nxt = make_pair(r-1,c);
              if (visited.find(nxt) == visited.end()) {
                qe.push(nxt);
              }
            }
            if (c<nc-1) {
              pair<int,int> nxt = make_pair(r,c+1);
              if (visited.find(nxt) == visited.end()) {
                qe.push(nxt);
              }
            }
            if (c>0) {
              pair<int,int> nxt = make_pair(r,c-1);
              if (visited.find(nxt) == visited.end()) {
                qe.push(nxt);
              }
            }
          }
          dist_mat[i][j] = dist;
        }
      }
      return dist_mat;
    }

    // Assume mat is not empty.
    vector<vector<int>> updateMatrix_2(vector<vector<int>>& mat) {
      int nr = mat.size(), nc = mat[0].size();
      vector<vector<int>> dist_mat(nr, vector<int>(nc,0)), visited_mat(nr, vector<int>(nc,0));
      queue<pair<int,int>> qe;
      // First find all 0
      for (int i=0; i<nr; i++) {
        for (int j=0; j<nc; j++) {
          if (mat[i][j]==0) {
            visited_mat[i][j] = 1;
            // dist_mat[i][j] = 0;
            qe.push(make_pair(i,j));
          }
        }
      }
      // BFS loop from the 0s to its neighboring nodes
      while (!qe.empty()) {
        pair<int,int> cur = qe.front();
        qe.pop();
        int r = cur.first, c = cur.second;
        //
        if (r>0 && visited_mat[r-1][c]==0) {
          dist_mat[r-1][c] = dist_mat[r][c] + 1;
          qe.push(make_pair(r-1,c));
          visited_mat[r-1][c] = 1;
        }
        if (r<nr-1 && visited_mat[r+1][c]==0) {
          dist_mat[r+1][c] = dist_mat[r][c] + 1;
          qe.push(make_pair(r+1,c));
          visited_mat[r+1][c] = 1;
        }
        if (c>0 && visited_mat[r][c-1]==0) {
          dist_mat[r][c-1] = dist_mat[r][c] + 1;
          qe.push(make_pair(r,c-1));
          visited_mat[r][c-1] = 1;
        }
        if (c<nc-1 && visited_mat[r][c+1]==0) {
          dist_mat[r][c+1] = dist_mat[r][c] + 1;
          qe.push(make_pair(r,c+1));
          visited_mat[r][c+1] = 1;
        }
      }
      return dist_mat;
    }

};

void printMatrix(vector<vector<int>>& mat) {
  int nr = mat.size();
  if (nr==0) {
    cout << "[]" << endl;
    return;
  }
  cout << "[";
  for (int i=0; i<nr-1; i++) {
    cout << "[";
    int nc = mat[i].size();
    for (int j=0; j<nc-1; j++) {
      cout << mat[i][j] << ",";
    }
    cout << mat[i][nc-1] << "],";
  }
  cout << "[";
  int nc = mat[nr-1].size();
  for (int j=0; j<nc-1; j++) {
    cout << mat[nr-1][j] << ",";
  }
  cout << mat[nr-1][nc-1] << "]";
  cout << "]" << endl;
}

int main(void) {
  Solution sol;
  vector<vector<int>> mat;
  // case 1
  // mat = {
  //   {0,0,0},
  //   {0,1,0},
  //   {1,1,1}
  // };
  // case 2
  mat.resize(1);
  mat[0].resize(10000,1);
  mat[0][10000-1] = 0;
  //
  printMatrix(mat);
  //
  // vector<vector<int>> dist_mat = sol.updateMatrix_1(mat);
  vector<vector<int>> dist_mat = sol.updateMatrix_2(mat);
  printMatrix(dist_mat);
  return 0;
}
