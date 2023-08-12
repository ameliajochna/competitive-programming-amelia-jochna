#include <bits/stdc++.h>
using namespace std;
int const maxN = 2e5 + 10;

void solution() {
  int counter = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j < 9; j++) {
      char e;
      cin >> e;
      if (j == (counter) % 9) {
        if (char(int(e + 1)) == ':')
          cout << "1";
        else
          cout << char(int(e + 1));
      } else
        cout << e;
    }
    cout << '\n';
    counter += 3;
    if (i % 3 == 0) counter++;
  }
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
