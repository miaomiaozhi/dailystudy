struct SAM {
    static constexpr int ALPHABET_SIZE = 26, N = 1e6 + 10;
    struct node {
        int len;
        int link;
        int ne[ALPHABET_SIZE];
        node() : len(0), link(0), ne{0} {}
    } t[N * 2];
    
    int tot, last;
    SAM() : tot(1), last(1) {}

    void extend(int c) {
        int p = last, now = last = ++tot;
        t[now].len = t[p].len + 1;
        for (; p && !t[p].ne[c]; p = t[p].link)
            t[p].ne[c] = now;
        if (!p) {
            t[now].link = 1;
        } else {
            int q = t[p].ne[c];
            if (t[q].len == t[p].len + 1) {
                t[now].link = q;
            } else {
                int cur = ++tot;
                t[cur] = t[q], t[cur].len = t[p].len + 1;
                t[q].link = t[now].link = cur;
                for (; p && t[p].ne[c] == q; p = t[p].link)
                    t[p].ne[c] = cur;
            }
        }
    }
};