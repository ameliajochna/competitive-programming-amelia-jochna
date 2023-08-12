#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int pa, pb;
  cin >> pa >> pb;
  int sum = pa + pb;
  vector<int> v;
  for (int k = 0; k <= sum; k++) {
    int sa, sb, ba, bb;
    // case 1
    sa = sum / 2;
    sb = sum - sa;
    ba = -pa + sa + k;
    if (ba % 2 == 0 && ba / 2 >= 0) {
      ba /= 2;
      bb = k - ba;
      if (pa == (sa - ba + bb) && pb == (sb - bb + ba) && ba >= 0 && bb >= 0 &&
          ba <= sa && bb <= sb) {
        v.push_back(k);
        continue;
      }
    }

    sb = sum / 2;
    sa = sum - sb;
    ba = -pa + sa + k;
    if (ba % 2 == 0 && ba / 2 >= 0) {
      ba /= 2;
      bb = k - ba;
      if (pa == (sa - ba + bb) && pb == (sb - bb + ba) && ba >= 0 && bb >= 0 &&
          ba <= sa && bb <= sb) {
        v.push_back(k);
        continue;
      }
    }
  }
  cout << v.size() << '\n';
  for (auto k : v) {
    cout << k << " ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
