#include <bits/stdc++.h>
using namespace std;
double const PI = 1.5707963267948965579989817342720925807952880859375;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << fixed << setprecision(9) << tan(PI * (1 - (double(1) / n))) << '\n';
  }
  return 0;
}
