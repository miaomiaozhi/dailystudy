/* 
空间为 O(n log_2(Max a))
assume : -inf < Max a < inf
*/
struct ChairManTree {
    const int inf = 0x3f3f3f3f;
    struct node {
        int l, r;
        int cnt;
        node(): l(0), r(0), cnt(0) {}
    };
    int n, idx;
    vector <int> a, root;
    vector <node> tr;

    ChairManTree(int _n = 1): n(_n + 5), idx(0), a(n), root(n), tr(n << 5) {}
    ChairManTree(int _n, vector <int> &_a): n(_n + 5), idx(0), a(_a), root(n), tr(n << 5) {
        for (int i = 1; i <= (int) a.size(); i++)
            insert(i, a[i]);
    }

    void insert(int &u, int v, int l, int r, int x) {
        u = ++idx;
        tr[u] = tr[v];
        tr[u].cnt++;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid) insert(tr[u].l, tr[v].l, l, mid, x);
        else insert(tr[u].r, tr[v].r, mid + 1, r, x);
    }
    int query(int u, int v, int l, int r, int k) {
        if (l == r) {
            return r;
        }
        int cnt = tr[tr[v].l].cnt - tr[tr[u].l].cnt;
        int mid = (l + r) >> 1;
        if (k <= cnt) return query(tr[u].l, tr[v].l, l, mid, k);
        else return query(tr[u].r, tr[v].r, mid + 1, r, k - cnt);
    }
    void insert(int i, int x) {
        insert(root[i], root[i - 1], -inf, inf, x);
    }
    int query(int l, int r, int k) {
        return query(root[l - 1], root[r], -inf, inf, k);
    }
};