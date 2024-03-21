#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

ll n;
vvl B;
vvl dp;

ll solve(ll y, ll x) {
  if (dp[y][x] < 0) {
    dp[y][x] = 0;

    for (auto r = 0; r < y; ++r) {
      if (r + B[r][x] == y) {
        dp[y][x] += solve(r, x);
      }
    }

    for (auto c = 0; c < x; ++c) {
      if (c + B[y][c] == x) {
        dp[y][x] += solve(y, c);
      }
    }
  }

  return dp[y][x];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;

  B = vvl(n, vl(n));
  for (auto&& r : B) {
    for (auto&& x : r) {
      cin >> x;
    }
  }

  dp = vvl(n, vl(n, -1));
  dp[0][0] = 1;

  cout << solve(n - 1, n - 1);

  return 0;
}