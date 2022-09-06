/*
    FixedSizeMatrix <int, 3> a;
*/
template <typename T, size_t N> struct FixedSizeMatrixT {
public:
    T data[N][N];
    FixedSizeMatrixT() { memset(data, 0, sizeof(data)); }

    T *operator[](int i) { return data[i]; }

    const T *operator[](int i) const { return data[i]; }

    FixedSizeMatrixT &operator+=(const FixedSizeMatrixT &o) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                data[i][j] += o[i][j];
            }
        }
        return *this;
    }

    FixedSizeMatrixT operator+(const FixedSizeMatrixT &o) const {
        return FixedSizeMatrixT(*this) += o;
    }

    FixedSizeMatrixT &operator-=(const FixedSizeMatrixT &o) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                data[i][j] -= o[i][j];
            }
        }
        return *this;
    }

    FixedSizeMatrixT operator-(const FixedSizeMatrixT &o) const {
        return FixedSizeMatrixT(*this) -= o;
    }

    FixedSizeMatrixT operator*(const FixedSizeMatrixT &o) const {
        static T buffer[N];
        FixedSizeMatrixT result;
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                buffer[i] = o[i][j];
            }
            for (int i = 0; i < N; ++i) {
                for (int k = 0; k < N; ++k) {
                    result[i][j] += data[i][k] * buffer[k];
                }
            }
        }
        return result;
    }

    FixedSizeMatrixT power(uint64_t n) const {
        FixedSizeMatrixT r;
        for (int i = 0; i < N; ++i) {
            r[i][i] = T{1};
        }
        FixedSizeMatrixT a = *this;
        while (n) {
            if (n & 1) {
                r = r * a;
            }
            a = a * a;
            n >>= 1;
        }
        return r;
    }
};