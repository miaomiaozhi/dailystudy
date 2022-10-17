template <class Info>
struct PersistentSegTree {
    int n, N;
    vector <int> root;
    vector <Info> tr {{}, {}};

    PersistentSegTree() = default;
    PersistentSegTree(int _n, int _N) : n(_n), N(_N), root(n + 5) {
        tr.reserve(n << 6);
    }
    int newNode() {
        tr.push_back(tr[0]);
        return (int) tr.size() - 1;
    }
    void pushup(int u) {
        // @TODO: pushup
        tr[u].cnt = tr[tr[u].lc].cnt + tr[tr[u].rc].cnt;
    }
    int insert(int v, int l, int r, int val) {
        int u = newNode();
        tr[u] = tr[v];
        if (l == r) {
            // @TODO: Leaf
            tr[u].cnt += 1;
        } else {
            int mid = l + r >> 1;
            if (val <= mid) {
                tr[u].lc = insert(tr[v].lc, l, mid, val);
            } else {
                tr[u].rc = insert(tr[v].rc, mid + 1, r, val);
            }
            pushup(u);
        }
        return u;
    }
    void insert(int i, int val) {
        root[i] = insert(root[i - 1], -N, N, val);
    }
    int query(int u, int v, int l, int r, int k) {
        if (l == r) {
            return r;
        }
        int cnt = tr[tr[u].lc].cnt - tr[tr[v].lc].cnt;
        int mid = l + r >> 1;
        if (k <= cnt) {
            return query(tr[u].lc, tr[v].lc, l, mid, k);
        } else {
            return query(tr[u].rc, tr[v].rc, mid + 1, r, k - cnt);
        }
    }
    int query(int l, int r, int k) {
        return query(root[r], root[l - 1], -N, N, k);
    }
};

struct Info {
    int lc = 0, rc = 0;
    int cnt = 0;
};
