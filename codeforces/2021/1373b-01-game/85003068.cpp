#include <iostream>
using namespace std;
typedef long long ll;
void solution() {
  string s;
  cin >> s;
  int onecnt = 0, zerocnt = 0;
  for (auto e : s) {
    if (e == '1')
      onecnt++;
    else
      zerocnt++;
  }
  onecnt = min(onecnt, zerocnt);
  if (onecnt == 0)
    cout << "NET\n";
  else if (onecnt % 2 == 0)
    cout << "NET\n";
  else
    cout << "DA\n";
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
