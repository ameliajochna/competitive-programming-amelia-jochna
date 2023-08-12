#include <iostream>
using namespace std;

bool potega[500000];
int n, hm;

void kwadraty(int n) {
  for (int i = 2; i * i <= n; i++)
    if (!potega[i])
      for (int j = 1; j * i * i <= n; j++) potega[i * i * j] = true;
}

int main() {
  cin >> n;
  kwadraty(n);
  for (int j = 1; j <= n; j++)
    if (!potega[j]) hm++;
  cout << hm;
  return 0;
}
