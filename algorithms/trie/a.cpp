#include <bits/stdc++.h>
using namespace std;

struct trie {
  struct node {
    vector<int> edges;
    bool is_end = 0;
    node() {
      edges.resize(26, -1);
    }
  };

  vector<node> tree;

  trie() {
    tree.resize(1);
  }

  void add_string(string s) {
    int current_node = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (tree[current_node].edges[c] == -1) {
        tree[current_node].edges[c] = tree.size();
        tree.emplace_back();
      }
      current_node = tree[current_node].edges[c];
    }
    tree[current_node].is_end = 1;
  }

  bool innit(string s) {
    int current_node = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (tree[current_node].edges[c] == -1) {
        return 0;
      }
      current_node = tree[current_node].edges[c];
    }
    return tree[current_node].is_end;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  trie tr;
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    tr.add_string(s);
  }
  int M; cin >> M;
  while (M--) {
    string s; cin >> s;
    cout << boolalpha << tr.innit(s) << '\n';
  }
}
