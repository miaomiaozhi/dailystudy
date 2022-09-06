template <typename T = long long>
struct SegTree {
    struct node {
        int l, r;
    };
    int n;
    vector <node> tr;
    vector <T> a;

    SegTree(int _n = 1): n(_n), tr((_n + 5) << 2), a(_n + 5) {
        build(1, 1, n);
    }
    SegTree(int _n, const vector <T> &_a) : n(_n), tr((_n + 5) << 2), a(_a) {
        build(1, 1, n);
    }

    void init(int u, int r) {
        assert(1 <= r && r <= n);
    }
    void pushup(node &u, node &l, node &r) {
        
    }
    void pushdown(node &u, node &l, node &r) {
        
    }
    void modify(int u, int l, int r, LL c) {
        if(tr[u].l >= l && tr[u].r <= r) {
            
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, c);
        if(r > mid) modify(u << 1 | 1, l, r, c);
        pushup(u);
    }
    LL len(int &u) {
        return 1LL * tr[u].r - tr[u].l + 1;
    }
    LL len(node &u) {
        return 1LL * u.r - u.l + 1; 
    }
    void pushup(int u) {
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    void pushdown(int u) {
        pushdown(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    void build(int u, int l, int r) {
        tr[u].l = l, tr[u].r = r;
        if(l == r) {
            init(u, r);
            return;
        }
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    node query(int u, int l, int r) {
        if(tr[u].l >= l && tr[u].r <= r) {
            return tr[u];
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid) return query(u << 1, l, r);
        else if (l > mid) return query(u << 1 | 1, l, r);
        else {
            node res, left, right;
            left = query(u << 1, l, r);
            right = query(u << 1 | 1, l, r);
            pushup(res, left, right);
            return res;
        }
    }
};