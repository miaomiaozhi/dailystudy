template <typename T>
struct Fenwick {
    vector <T> tr;
    int N;
    Fenwick (int _size = 1) : tr(_size + 1), N(_size) {}
    int lowbit(int x) { 
        return x & -x;
    }
    void modify(int x, T c) { 
        assert(x > 0); 
        for( ; x <= N; x += lowbit(x)) tr[x] += c;
    }
    T query(int x) {
        assert(x >= 0);
        T res = 0;
        for( ; x > 0; x -= lowbit(x)) res += tr[x];
        return res;
    }
    T query(int l, int r) { return query(r) - query(l - 1); } 
};