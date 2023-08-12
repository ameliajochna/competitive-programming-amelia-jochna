#include <iostream>

using namespace std;
string wyraz;
int a, n, tab[36], ilosc, lt;
int main() {
  cin >> n;
  cin >> wyraz;
  for (int i = 0; i < n; i++) {
    a = wyraz[i];
    if (a < 91) a = a + 32;
    tab[a - 97]++;
  }

  for (int i = 0; i < 36; i++)
    if (ilosc < tab[i]) {
      ilosc = tab[i];
      lt = i + 97;
    }
  cout << tab[lt - 97] << " " << (char)lt << '\n';
  return 0;
}
