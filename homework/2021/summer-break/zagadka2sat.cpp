#include <iostream>
#include <stack>
#include <vector>

int n, m, k, lst, Pshift, Sshift;
std::vector<std::vector<int> > town, G, revG;
std::vector<int> comp;
std::stack<int> order;
std::vector<bool> vis, assignment;

void prefixVertices() {
  int p_i = Pshift, p_next = Pshift + 1;
  for (int q = 0; q < town.size(); q++)
    for (int i = 0; i < town[q].size(); i++) {
      int cur = town[q][i];
      // cur=>p_i
      G[2 * cur].push_back(2 * p_i);
      G[2 * p_i + 1].push_back(2 * cur + 1);

      if (i < town[q].size() - 1) {
        // p_i=>p_(i+1)
        G[2 * p_i].push_back(2 * p_next);
        G[2 * p_next + 1].push_back(2 * p_i + 1);
      }
      p_i++, p_next++;
    }
}

void suffixVertices() {
  int s_i = Sshift, s_prev = Sshift - 1;
  for (int q = 0; q < town.size(); q++) {
    for (int i = 0; i < town[q].size(); i++) {
      int cur = town[q][i];
      // cur=>s_i
      G[2 * cur].push_back(2 * s_i);
      G[2 * s_i + 1].push_back(2 * cur + 1);

      if (i != 0) {
        // s_i=>s_prev
        G[2 * s_i].push_back(2 * s_prev);
        G[2 * s_prev + 1].push_back(2 * s_i + 1);
      }
      s_i++, s_prev++;
    }
  }
  lst = 2 * s_i;
}

void buildGraph() {
  Pshift = n + 1, Sshift = 2 * n + 1;
  // in general: a => b : ~a or b : a=>b and ~b=>~a
  prefixVertices();
  suffixVertices();
  int p_prev = Pshift - 1, s = Sshift;
  for (int q = 0; q < town.size(); q++) {
    p_prev++, s++;
    for (int i = 1; i < town[q].size(); i++) {
      //~p_(i-1) or ~s_i : p=>~s and s=>~p
      G[2 * p_prev].push_back(2 * s + 1);
      G[2 * s].push_back(2 * p_prev + 1);
      p_prev++, s++;
    }
  }

  revG.resize(6 * n + 10);
  for (int i = 2; i < lst; i++) {
    for (auto u : G[i]) {
      revG[u].push_back(i);
    }
  }
}

void dfs1(int u) {
  vis[u] = true;
  for (auto v : G[u])
    if (!vis[v]) dfs1(v);
  order.push(u);
}

void dfs2(int u, int const c) {
  comp[u] = c;
  for (int v : revG[u]) {
    if (comp[v] == -1) dfs2(v, c);
  }
}

bool solve_2SAT() {
  vis.resize(6 * n + 10);
  for (int i = 2; i < lst; i++) {
    if (!vis[i]) dfs1(i);
  }
  vis.clear();
  G.clear();

  comp.resize(lst + 1, -1);
  int cur = 1;
  while (!order.empty()) {
    int u = order.top();
    if (comp[u] == -1) dfs2(u, cur++);
    order.pop();
  }
  revG.clear();

  assignment.resize(lst / 2);
  for (int i = 2; i < lst; i += 2) {
    if (comp[i] == comp[i + 1]) return false;
    assignment[i / 2] = comp[i] > comp[i + 1];
  }
  return true;
}

void answer() {
  std::vector<int> whichTown(n);
  for (int i = 0; i < town.size(); i++)
    for (int j = 0; j < town[i].size(); j++) whichTown[town[i][j]] = i;
  std::vector<int> ans(n);
  for (int i = 1; i <= n; i++)
    if (assignment[i]) ans[whichTown[i]] = i;

  for (int i = 0; i < k; i++) std::cout << ans[i] << " ";

  whichTown.clear();
  ans.clear();
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> n >> m >> k;

  G.resize(6 * n + 10);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    G[2 * u + 1].push_back(2 * v);
    G[2 * v + 1].push_back(2 * u);
  }

  town.resize(k);
  for (int i = 0; i < k; i++) {
    int sz;
    std::cin >> sz;
    town[i].resize(sz);
    for (int j = 0; j < sz; j++) std::cin >> town[i][j];
  }

  buildGraph();

  if (solve_2SAT()) {
    std::cout << "TAK\n";
    answer();
  } else
    std::cout << "NIE\n";
}
