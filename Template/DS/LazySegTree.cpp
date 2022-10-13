template <class Info, class Tag>
struct SegTree {
    int n;
    vector <Info> tr;
    vector <Tag> tag;
    SegTree() {}
    SegTree(int _n): n(_n), tr((n + 5) * 4), tag((n + 5) * 4) {}
    SegTree(int _n, const vector<Info> &a): SegTree(_n) {
        function <void(int, int, int)> build = [&](int u, int l, int r) {
            if (l == r) {
                tr[u] = a[r];
                return;
            }
            int mid = l + r >> 1;
            build(u * 2, l, mid);
            build(u * 2 + 1, mid + 1, r);
            pushup(u);
        };
        build(1, 1, n);
    }
    void pushup(int u) {
        tr[u] = tr[u * 2] + tr[u * 2 + 1];
    }
    void apply(int u, const Tag &v) {
        tr[u].apply(v);
        tag[u].merge(v);
    }
    void pushdown(int u) {
        apply(u * 2, tag[u]);
        apply(u * 2 + 1, tag[u]);
        tag[u] = Tag();
    }
    void modify(int u, int l, int r, int x, const Info &v) {
        if (l == r) {
            tr[u] = v;
            return;
        }
        pushdown(u);
        int mid = l + r >> 1;
        if (x <= mid) {
            modify(u * 2, l, mid, x, v);
        } else {
            modify(u * 2 + 1, mid + 1, r, x, v);
        }
        pushup(u);
    }
    Info query(int u, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) {
            return Info();
        }
        if (ql <= l && r <= qr) {
            return tr[u];
        }
        pushdown(u);
        int mid = l + r >> 1;
        return query(u * 2, l, mid, ql, qr) + query(u * 2 + 1, mid + 1, r, ql, qr);
    }
    void rangeModify(int u, int l, int r, int ql, int qr, const Tag &v) {
        if (l > qr || r < ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            apply(u, v);
            return;
        }
        pushdown(u);
        int mid = l + r >> 1;
        rangeModify(u * 2, l, mid, ql, qr, v);
        rangeModify(u * 2 + 1, mid + 1, r, ql, qr, v);
        pushup(u);
    }
    void modify(int x, const Info &v) {
        modify(1, 1, n, x, v);
    }
    Info query(int l, int r) {
        return query(1, 1, n, l, r);
    }
    void rangeModify(int l, int r, const Tag &v) {
        rangeModify(1, 1, n, l, r, v);
    }
};

struct Tag {
    void merge(const Tag &o) {
    }
};

struct Info {
    void apply(const Tag &o) {
    }
};

Info operator+(const Info &l, const Info &r) {
    return {
    };
}