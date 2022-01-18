#include <iostream>
#include <vector>
#include <queue>
// #include <unordered_map>
#include <map>
#include <utility>

using namespace std;

class Solution {
  public:
    vector<vector<int>> floodFill1(vector<vector<int>>& image, int sr, int sc, int newColor) {
      vector<vector<int>> new_img(image);
      int oldColor = image[sr][sc];
      if (oldColor == newColor) {
        return new_img;
      }
      int nr = image.size();
      // BFS
      pair<int,int> v = make_pair(sr,sc);
      queue<pair<int,int>> qe;
      qe.push(v);
      // unordered_map<pair<int,int>, bool> idx_visited;
      // This reports error: use of deleted function
      // Because it requires a less comprison for pair<int,int>.
      // And in fact, when a cheap comparison is unavailable, map is more efficient than unordered_map.
      // Refer to https://stackoverflow.com/questions/51220257/compilation-error-related-to-map-and-unordered-map-attempting-to-reference-a-d
      map<pair<int,int>, bool> idx_visited;
      idx_visited[v] = false;
      while (!qe.empty()) {
        v = qe.front();
        qe.pop();
        sr = v.first;
        sc = v.second;
        if ( (!idx_visited[v]) && (image[sr][sc]==oldColor) ) {
          idx_visited[v] = true;
          int nc = image[sr].size();
          // visit
          new_img[sr][sc] = newColor;
          // bottom
          if (sc>0) {
            v = make_pair(sr,sc-1);
            if (!idx_visited[v]) {
              qe.push(v);
            }
          }
          // top
          if (sc<nc-1) {
            v = make_pair(sr,sc+1);
            if (!idx_visited[v]) {
              qe.push(v);
            }
          }
          // left
          if (sr>0) {
            v = make_pair(sr-1,sc);
            if (!idx_visited[v]) {
              qe.push(v);
            }
          }
          // right
          if (sr<nr-1) {
            v = make_pair(sr+1,sc);
            if (!idx_visited[v]) {
              qe.push(v);
            }
          }
        }
      }
      return new_img;
    }
    vector<vector<int>> floodFill2(vector<vector<int>>& image, int sr, int sc, int newColor) {
      vector<vector<int>> new_img(image);
      int oldColor = image[sr][sc];
      if (oldColor == newColor) {
        return new_img;
      }
      int nr = image.size();
      // BFS
      pair<int,int> v = make_pair(sr,sc);
      queue<pair<int,int>> qe;
      qe.push(v);
      while (!qe.empty()) {
        v = qe.front();
        qe.pop();
        sr = v.first;
        sc = v.second;
        if (new_img[sr][sc]==oldColor) {
          int nc = image[sr].size();
          // visit
          new_img[sr][sc] = newColor;
          // bottom
          if (sc>0) {
            v = make_pair(sr,sc-1);
            qe.push(v);
          }
          // top
          if (sc<nc-1) {
            v = make_pair(sr,sc+1);
            qe.push(v);
          }
          // left
          if (sr>0) {
            v = make_pair(sr-1,sc);
            qe.push(v);
          }
          // right
          if (sr<nr-1) {
            v = make_pair(sr+1,sc);
            qe.push(v);
          }
        }
      }
      return new_img;
    }
};

int main(void) {
  Solution sol;
  vector<vector<int>> image;
  // vector<int> row;
  // row =
  image.push_back({1,1,1});
  image.push_back({1,1,0});
  image.push_back({1,0,1});
  int sr = 1, sc = 1, newColor = 2;
  // vector<vector<int>> new_img = sol.floodFill1(image, sr, sc, newColor);
  vector<vector<int>> new_img = sol.floodFill2(image, sr, sc, newColor);
  int nr = new_img.size();
  for (int i=0; i<nr; i++) {
    int nc = new_img[i].size();
    for (int j=0; j<nc-1; j++) {
      cout << new_img[i][j] << ",";
    }
    cout << new_img[i][nc-1] << endl;
  }
  return 0;
}
