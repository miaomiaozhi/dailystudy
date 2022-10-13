struct ChairManTree {
    const int inf = 0x3f3f3f3f;

    struct node {
        int l = 0, r = 0;
        LL val = 0;
    };
    
    int n, idx;
    vector <int> root;
    vector <node> tr;
    ChairManTree() {}
    ChairManTree(int _n) : n(_n), idx(0), root(n + 5), tr((n + 5) << 5) {}
    ChairManTree(int _n, const vector <int> &a) : ChairManTree(_n) {
        for (int i = 1; i <= n; i++) {
            insert(root[i], root[i - 1], 0, inf, a[i]);
        }
    }
    void newNode(int &u) {
        u = ++idx;
    }
    void pushup(int u) {
        tr[u].val = tr[tr[u].l].val + tr[tr[u].r].val;
    }
    void insert(int &u, int v, int l, int r, int val) {
        newNode(u);
        tr[u] = tr[v];
        if (l == r) {
            tr[u].val += val;
            return;
        }
        int mid = l + r >> 1;
        if (val <= mid) {
            insert(tr[u].l, tr[v].l, l, mid, val);
        } else {
            insert(tr[u].r, tr[v].r, mid + 1, r, val);
        }
        pushup(u);
    }
    LL query(int u, int v, int l, int r, LL val) {
        if (!u && !v) {
            return 0;
        }
        if (r <= val) {
            return tr[u].val - tr[v].val;
        }
        if (l > val) {
            return 0;
        }
        int mid = l + r >> 1;
        return query(tr[u].l, tr[v].l, l, mid, val) + query(tr[u].r, tr[v].r, mid + 1, r, val);
    }
    LL query(int l, int r, LL val) {
        return query(root[r], root[l - 1], 0, inf, val);
    }
};