#include <iostream>
using namespace std;
int const maxN = 100010;
int aarr[maxN], barr[maxN], n;

void input() {
  for (int i = 0; i < n; i++) cin >> aarr[i];
  for (int i = 0; i < n; i++) cin >> barr[i];
}
void solution() {
  bool minus = false, plus = false, avail = true;
  int a, b;
  cin >> n;
  input();
  if (aarr[0] == barr[0]) {
    if (aarr[0] < 0)
      minus = true;
    else if (aarr[0] > 0)
      plus = true;

    for (int i = 1; i < n; i++) {
      a = aarr[i];
      b = barr[i];
      if (a < b) {
        if (!plus) {
          avail = false;
          break;
        }
      }
      if (a > b) {
        if (!minus) {
          avail = false;
          break;
        }
      }
      if (a < 0)
        minus = true;
      else if (a > 0)
        plus = true;
    }
  } else
    avail = false;
  if (avail)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
