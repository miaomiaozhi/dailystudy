template <class T>
struct Fenwick {
    int n;
    vector <T> tr;
    Fenwick (int _n = 1) : n(_n), tr(_n + 1) {}
    void modify(int x, T c) {
        assert(x > 0);
        for( ; x <= n; x += x & -x) {
            tr[x] += c;
        }
    }
    T query(int x) {
        assert(x >= 0);
        T res = 0;
        for( ; x > 0; x -= x & -x) {
            res += tr[x];
        }
        return res;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};