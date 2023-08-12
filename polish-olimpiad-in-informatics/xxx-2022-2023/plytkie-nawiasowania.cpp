#include <iostream>
#include <vector>
using namespace std;

#define st first
#define nd second
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
typedef pair<int, int> pii;

int const maxN = (int)1e6 + 10;
int val[maxN], n, h;
vector<pii> minloc;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> h;
  cin >> s;

  for (int i = 1; i <= n; i++) {
    char cur = s[i - 1];
    if (cur == '(')
      val[i] = val[i - 1] + 1;
    else
      val[i] = val[i - 1] - 1;
  }

  int glob = 0, cost = 0;
  for (int i = 1; i <= n; i++) {
    if (val[i] - glob > h) {
      int toadd = val[i] - h - glob;
      toadd += (toadd % 2);
      cost += toadd;
      glob += toadd;
    }
    if (val[i] - glob < 0) glob = val[i];
    glob -= (glob % 2);
  }
  cout << cost;

  return 0;
}
