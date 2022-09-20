#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e3 + 5;

unordered_map<int, int> x_map, y_map, x_rmap, y_rmap;
vector<int> x_vector, y_vector;

// 去重排序方法一，使用set
void removeRepeatAndSort(vector<int>& vec) {
  set<int> setVec(vec.begin(), vec.end());
  vec.assign(setVec.begin(), setVec.end());
  sort(vec.begin(), vec.end());
}

int rectangleArea(vector<vector<int>>& rectangles) {
  int n = rectangles.size();
  for (auto rec : rectangles) {
    int x1 = rec[0];
    int y1 = rec[1];
    int x2 = rec[2];
    int y2 = rec[3];

    x_vector.push_back(x1);
    x_vector.push_back(x2);
    y_vector.push_back(y1);
    y_vector.push_back(y2);
  }

  removeRepeatAndSort(x_vector);
  removeRepeatAndSort(y_vector);

  int x_n = x_vector.size();
  int y_n = y_vector.size();

  vector<vector<int>> mp(x_n, vector<int>(y_n, 0));

  for (int i = 0; i < x_n; i++) {
    x_map[i] = x_vector[i];
    x_rmap[x_vector[i]] = i;
  }
  for (int i = 0; i < y_n; i++) {
    y_map[i] = y_vector[i];
    y_rmap[y_vector[i]] = i;
  }

  for (auto rec : rectangles) {
    int x1 = x_rmap[rec[0]];
    int y1 = y_rmap[rec[1]];
    int x2 = x_rmap[rec[2]];
    int y2 = y_rmap[rec[3]];

    for (int i = x1; i < x2; i++) {
      mp[i][y1]++;
      mp[i][y2]--;
    }
  }

  long long ans = 0;
  for (int i = 0; i < x_n - 1; i++) {
    int x_diff = x_map[i + 1] - x_map[i];
    int y_diff = 0;
    int y_cnt = 0;
    for (int j = 0; j < y_n - 1; j++) {
      y_cnt += mp[i][j];
      if (y_cnt > 0) {
        y_diff += y_map[j + 1] - y_map[j];
      }
    }
    printf("x_diff=%d,y_diif=%d\n", x_diff, y_diff);
    ans += 1ll * x_diff * y_diff;
  }
  return ans % (int)(1e9+7);
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> num = {{0, 0, 2, 2}, {1, 0, 2, 3}, {1, 0, 3, 1}};
  rectangleArea(num);
  return 0;
}
