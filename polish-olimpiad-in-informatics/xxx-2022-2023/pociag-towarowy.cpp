#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;

int const maxN = (int)3e5 + 10;

int n, m, k, prefsum[maxN];
vector<int> seq, subseq;
vector<int> ind[2];         // odpowiadajace indeksy podciagowi
vector<int> typepos[maxN];  // pozycje poszczegolnych kolorow
vector<pii> part[maxN];
bool ans[maxN];

void findsubseq(int dim) {
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (j == m) return;
    if (seq[i] == subseq[j]) ind[dim][j] = i + 1, j++;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();

  cin >> n >> m >> k;

  seq.resize(n);
  subseq.resize(m);
  ind[0].resize(m), ind[1].resize(m);

  for (int i = 0; i < n; i++) cin >> seq[i], typepos[seq[i]].push_back(i);
  for (int i = 0; i < m; i++) cin >> subseq[i];

  findsubseq(0);

  reverse(all(seq));
  reverse(all(subseq));

  findsubseq(1);
  reverse(all(ind[1]));
  reverse(all(seq));
  for (auto &x : ind[1]) x = n - x + 1;

  for (int i = 0; i < m; i++) {
    int a = ind[0][i] - 1, b = ind[1][i] - 1;
    part[seq[a]].push_back({a, b});
  }

  for (int i = 1; i <= k; i++) {
    // dla kazdego indeksu w danym kolorze patrze czy nalezy do jakiegos
    // przedzialu
    int x = 0;  // part[x]
    for (int q = 0; q < sz(typepos[i]) && x < sz(part[i]); q++) {
      int cur = typepos[i][q];
      if (part[i][x].st <= cur && cur <= part[i][x].nd) ans[cur] = true;
      if (part[i][x].nd <= cur) x++;
    }
  }

  for (int i = 0; i < n; i++) cout << (int)ans[i] << " ";
  cout << '\n';

  return 0;
}
