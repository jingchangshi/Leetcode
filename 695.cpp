#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;

class Solution {
  public:
    int maxAreaOfIsland_1(vector<vector<int>>& grid) {
      int max_area = 0;
      queue<pair<int,int>> qe;
      pair<int,int> v;
      set<pair<int,int>> visited;
      int nr = grid.size();
      for (int i=0; i<nr; i++) {
        int nc = grid[i].size();
        for (int j=0; j<nc; j++) {
          if (grid[i][j]==1) {
            int area=0;
            v = make_pair(i,j);
            if (visited.find(v) == visited.end()) {
              qe.push(v);
              while (!qe.empty()) {
                v = qe.front();
                qe.pop();
                if (visited.find(v) != visited.end()) {
                  continue;
                }
                area++;
                visited.insert(v);
                int r = v.first;
                int c = v.second;
                if (r>0) {
                  if (grid[r-1][c]==1 && visited.find(make_pair(r-1,c))==visited.end()) {
                    qe.push(make_pair(r-1,c));
                  }
                }
                if (r<nr-1) {
                  if (grid[r+1][c]==1 && visited.find(make_pair(r+1,c))==visited.end()) {
                    qe.push(make_pair(r+1,c));
                  }
                }
                if (c>0) {
                  if (grid[r][c-1]==1 && visited.find(make_pair(r,c-1))==visited.end()) {
                    qe.push(make_pair(r,c-1));
                  }
                }
                if (c<nc-1) {
                  if (grid[r][c+1]==1 && visited.find(make_pair(r,c+1))==visited.end()) {
                    qe.push(make_pair(r,c+1));
                  }
                }
              } // while qe.empty()
            } // if visited
            if (area>max_area) {
              max_area = area;
            }
          } // if grid[i][j]==1
        } // for j
      } // for i
      return max_area;
    }
    //
    int maxAreaOfIsland_2(vector<vector<int>>& grid) {
      int max_area = 0;
      queue<pair<int,int>> qe;
      pair<int,int> v;
      set<pair<int,int>> visited;
      int nr = grid.size();
      for (int i=0; i<nr; i++) {
        int nc = grid[i].size();
        for (int j=0; j<nc; j++) {
          if (grid[i][j]==1) {
            int area=0;
            v = make_pair(i,j);
            if (visited.find(v) == visited.end()) {
              qe.push(v);
              while (!qe.empty()) {
                v = qe.front();
                qe.pop();
                if (visited.find(v) != visited.end()) {
                  continue;
                }
                area++;
                visited.insert(v);
                int r = v.first;
                int c = v.second;
                if (r>0) {
                  if (grid[r-1][c]==1) {
                    qe.push(make_pair(r-1,c));
                  }
                }
                if (r<nr-1) {
                  if (grid[r+1][c]==1) {
                    qe.push(make_pair(r+1,c));
                  }
                }
                if (c>0) {
                  if (grid[r][c-1]==1) {
                    qe.push(make_pair(r,c-1));
                  }
                }
                if (c<nc-1) {
                  if (grid[r][c+1]==1) {
                    qe.push(make_pair(r,c+1));
                  }
                }
              } // while qe.empty()
            } // if visited
            if (area>max_area) {
              max_area = area;
            }
          } // if grid[i][j]==1
        } // for j
      } // for i
      return max_area;
    }
    //
    int maxAreaOfIsland_3(vector<vector<int>>& grid) {
      int max_area = 0;
      queue<pair<int,int>> qe;
      pair<int,int> v;
      // Do not use set to record the visited grid point. Change the grid point value to mark it.
      int nr = grid.size();
      for (int i=0; i<nr; i++) {
        int nc = grid[i].size();
        for (int j=0; j<nc; j++) {
          if (grid[i][j]==1) {
            int area=0;
            v = make_pair(i,j);
            qe.push(v);
            while (!qe.empty()) {
              v = qe.front();
              qe.pop();
              // if (visited.find(v) != visited.end()) {
              if (grid[v.first][v.second]==2) {
                continue;
              }
              area++;
              grid[v.first][v.second]=2;
              int r = v.first;
              int c = v.second;
              if (r>0) {
                if (grid[r-1][c]==1) {
                  qe.push(make_pair(r-1,c));
                }
              }
              if (r<nr-1) {
                if (grid[r+1][c]==1) {
                  qe.push(make_pair(r+1,c));
                }
              }
              if (c>0) {
                if (grid[r][c-1]==1) {
                  qe.push(make_pair(r,c-1));
                }
              }
              if (c<nc-1) {
                if (grid[r][c+1]==1) {
                  qe.push(make_pair(r,c+1));
                }
              }
            } // while qe.empty()
            if (area>max_area) {
              max_area = area;
            }
          } // if grid[i][j]==1
        } // for j
      } // for i
      return max_area;
    }

};

int main(void) {
  Solution sol;
  vector<vector<int>> grid;
  // grid.push_back({0,0,1,0,0,0,0,1,0,0,0,0,0});
  // grid.push_back({0,0,0,0,0,0,0,1,1,1,0,0,0});
  // grid.push_back({0,1,1,0,1,0,0,0,0,0,0,0,0});
  // grid.push_back({0,1,0,0,1,1,0,0,1,0,1,0,0});
  // grid.push_back({0,1,0,0,1,1,0,0,1,1,1,0,0});
  // grid.push_back({0,0,0,0,0,0,0,0,0,0,1,0,0});
  // grid.push_back({0,0,0,0,0,0,0,1,1,1,0,0,0});
  // grid.push_back({0,0,0,0,0,0,0,1,1,0,0,0,0});
  // 
  grid.push_back({1,1,0,0,0});
  grid.push_back({1,1,0,0,0});
  grid.push_back({0,0,0,1,1});
  grid.push_back({0,0,0,1,1});
  // cout << sol.maxAreaOfIsland_1(grid) << endl;
  // cout << sol.maxAreaOfIsland_2(grid) << endl;
  cout << sol.maxAreaOfIsland_3(grid) << endl;
  return 0;
}
