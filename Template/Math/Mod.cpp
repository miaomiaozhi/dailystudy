constexpr int P = 1000000007;
// constexpr int P = 998244353;

// assume -p <= x < 2P
int norm(int x) {
    if (x < 0) { x += P; }
    if (x >= P) { x -= P; }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b >>= 1, a *= a)  if (b & 1) res *= a;
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const { return x; }
    Z operator-() const { return Z(norm(P - x)); }
    Z inv() const { assert(x != 0); return power(*this, P - 2); }
    Z &operator*=(const Z &rhs) { x = (long long)(x) * rhs.x % P; return *this; }
    Z &operator+=(const Z &rhs) { x = norm(x + rhs.x); return *this; }
    Z &operator-=(const Z &rhs) { x = norm(x - rhs.x); return *this; }
    Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
    friend Z operator*(const Z &lhs, const Z &rhs) { Z res = lhs; res *= rhs; return res; }
    friend Z operator+(const Z &lhs, const Z &rhs) { Z res = lhs; res += rhs; return res; }
    friend Z operator-(const Z &lhs, const Z &rhs) { Z res = lhs; res -= rhs; return res; }
    friend Z operator/(const Z &lhs, const Z &rhs) { Z res = lhs; res /= rhs; return res; }
    friend bool operator==(const Z &lhs, const Z &rhs) { return lhs.val() == rhs.val(); }
    friend istream &operator >> (istream &input, Z &o) {  input >> o.x; return input; }
    friend ostream &operator << (ostream &output, const Z &o) { output << o.val(); return output; }
};