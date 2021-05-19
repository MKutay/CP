#include <bits/stdc++.h>
using namespace std;

struct trie {
  struct node {
    vector<int> edges;
    int cnt = 0;
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
      tree[current_node].cnt++;
      current_node = tree[current_node].edges[c];
    }
    tree[current_node].cnt++;
  }

  int innit(string s) {
    int current_node = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (tree[current_node].edges[c] == -1) {
        return 0;
      }
      current_node = tree[current_node].edges[c];
    }
    return tree[current_node].cnt;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("trie.gir", "r", stdin);
  freopen("trie.cik", "w", stdout);
  int T; cin >> T;
  trie tr;
  while (T--) {
    string op, s; cin >> op >> s;
    if (op == "add") {
      tr.add_string(s);
    } else {
      cout << tr.innit(s) << '\n';
    }
  }
}
