#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool grid[101][101];
bool onedone, twodone;
int onecnt, twocnt, oneexval, twoexval;
int n;

pair<int, int> findplace(int val) {
  int diag;
  if (val == 3) {
    if (onedone)
      val = 2;
    else if (twodone)
      val = 1;
  }
  if (val == 1)
    diag = 0, onecnt++;
  else if (val == 2)
    diag = 1, twocnt++;

  if (onecnt == oneexval) onedone = true;
  if (twocnt == twoexval) twodone = true;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == diag && !grid[i][j]) {
        grid[i][j] = true;
        return {i, j};
      }
    }
  }
}

pair<int, pair<int, int> > move(int blck) {
  if (blck == 1) {
    if (twodone)
      return {3, findplace(3)};
    else
      return {2, findplace(2)};
  } else if (blck == 2) {
    if (onedone)
      return {3, findplace(3)};
    else
      return {1, findplace(1)};
  } else if (blck == 3) {
    if (onedone)
      return {2, findplace(2)};
    else
      return {1, findplace(1)};
  }
}

void solution() {
  cin >> n;

  oneexval = (n * n) / 2 + (n % 2 == 1);
  twoexval = (n * n) / 2;
  if (n == 1) twodone = 1, oneexval = 1;
  // parzyste przekatne - > 1
  // nieparzyste przekatne - > 2
  // sytuacje awaryjne - > 3
  // cout<<n<<" "<<oneexval<<" "<<twoexval<<'\n';
  int game = n * n;
  while (game--) {
    int ban;
    cin >> ban;
    pair<int, pair<int, int> > ans = move(ban);
    cout << ans.first << " " << ans.second.first + 1 << " "
         << ans.second.second + 1 << '\n';
    fflush(stdout);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  while (t--) solution();
}
