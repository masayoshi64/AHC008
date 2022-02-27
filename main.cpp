/* #region header */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// types
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<ll, ll> Pl;
typedef pair<int, int> Pi;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
template <typename T> using mat = vector<vector<T>>;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef vector<vector<char>> vvc;
// abreviations
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep_(i, a_, b_, a, b, ...) for (ll i = (a), max_i = (b); i < max_i; i++)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define rrep_(i, a_, b_, a, b, ...) for (ll i = (b - 1), min_i = (a); i >= min_i; i--)
#define rrep(i, ...) rrep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define srep(i, a, b, c) for (ll i = (a), max_i = (b); i < max_i; i += c)
#define SZ(x) ((int)(x).size())
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp make_pair
//入出力
#define print(x) cout << x << endl
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    return os;
}
void scan(int &a) {
    cin >> a;
}
void scan(long long &a) {
    cin >> a;
}
void scan(char &a) {
    cin >> a;
}
void scan(double &a) {
    cin >> a;
}
void scan(string &a) {
    cin >> a;
}
template <class T> void scan(vector<T> &a) {
    for (auto &i : a)
        scan(i);
}
#define vsum(x) accumulate(all(x), 0LL)
#define vmax(a) *max_element(all(a))
#define vmin(a) *min_element(all(a))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
// functions
// gcd(0, x) fails.
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll safemod(ll a, ll b) {
    return (a % b + b) % b;
}
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> T mypow(T x, ll n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1)
            (ret *= x);
        (x *= x);
        n >>= 1;
    }
    return ret;
}
ll modpow(ll x, ll n, const ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1)
            (ret *= x);
        (x *= x);
        n >>= 1;
        x %= mod;
        ret %= mod;
    }
    return ret;
}

uint64_t my_rand(void) {
    static uint64_t x = 88172645463325252ULL;
    x = x ^ (x << 13);
    x = x ^ (x >> 7);
    return x = x ^ (x << 17);
}
int popcnt(ull x) {
    return __builtin_popcountll(x);
}
template <typename T> vector<int> IOTA(vector<T> a) {
    int n = a.size();
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int i, int j) { return a[i] < a[j]; });
    return id;
}
struct Timer {
    clock_t start_time;
    void start() {
        start_time = clock();
    }
    int lap() {
        // return x ms.
        return (clock() - start_time) * 1000 / CLOCKS_PER_SEC;
    }
};
template <int Mod> struct modint {
    int x;

    modint() : x(0) {
    }

    modint(long long y) : x(y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod) {
    }

    modint &operator+=(const modint &p) {
        if ((x += p.x) >= Mod)
            x -= Mod;
        return *this;
    }

    modint &operator-=(const modint &p) {
        if ((x += Mod - p.x) >= Mod)
            x -= Mod;
        return *this;
    }

    modint &operator*=(const modint &p) {
        x = (int)(1LL * x * p.x % Mod);
        return *this;
    }

    modint &operator/=(const modint &p) {
        *this *= p.inverse();
        return *this;
    }

    modint operator-() const {
        return modint(-x);
    }

    modint operator+(const modint &p) const {
        return modint(*this) += p;
    }

    modint operator-(const modint &p) const {
        return modint(*this) -= p;
    }

    modint operator*(const modint &p) const {
        return modint(*this) *= p;
    }

    modint operator/(const modint &p) const {
        return modint(*this) /= p;
    }

    bool operator==(const modint &p) const {
        return x == p.x;
    }

    bool operator!=(const modint &p) const {
        return x != p.x;
    }

    modint inverse() const {
        int a = x, b = Mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }

    modint pow(int64_t n) const {
        modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const modint &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, modint &a) {
        long long t;
        is >> t;
        a = modint<Mod>(t);
        return (is);
    }

    static int get_mod() {
        return Mod;
    }

    constexpr int get() const {
        return x;
    }
};
template <typename T = int> struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {
    }

    operator int() const {
        return to;
    }
};

template <typename T = int> struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {
    }

    size_t size() const {
        return g.size();
    }

    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if (weighted)
                cin >> c;
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};

/* #endregion*/
// constant
#define inf 1000000000ll
#define INF 4000000004000000000LL
#define mod 998244353ll
const long double eps = 0.000000000000001;
const long double PI = 3.141592653589793;
using mint = modint<mod>;
using vmint = vector<mint>;
const int SIZE = 30;
const int TURN = 300;
vl px, py, pt;
vl hx, hy;
string udrl = "UDRL.";
map<char, int> dx = {{'U', -1}, {'D', 1}, {'R', 0}, {'L', 0}, {'.', 0}};
map<char, int> dy = {{'U', 0}, {'D', 0}, {'R', 1}, {'L', -1}, {'.', 0}};
mat<char> Map(SIZE, vector<char>(SIZE));
void move(string &haction, vector<string> &paction) {
    rep(i, paction.size()) {
        rep(j, paction[i].size()) {
            px[i] += dx[paction[i][j]];
            py[i] += dy[paction[i][j]];
        }
    }

    cout << "# ";
    rep(i, haction.size()) {
        if (islower(haction[i])) {
            char c = toupper(haction[i]);
            Map[hx[i] + dx[c]][hy[i] + dy[c]] = '#';
        } else {
            hx[i] += dx[haction[i]];
            hy[i] += dy[haction[i]];
        }
        cout << hx[i] << " " << hy[i] << " ";
    }
    cout << endl;
}
bool is_puttable(ll x, ll y) {
    for (char c : udrl) {
        ll nx = x + dx[c];
        ll ny = y + dy[c];
        rep(i, px.size()) {
            if (nx == px[i] && ny == py[i]) {
                return false;
            }
        }
    }
    return true;
}

bool is_all(vl x) {
    for (auto xx : x) {
        if (!xx)
            return false;
    }
    return true;
}

int count(int lx, int rx, int uy, int dy) {
    ll cnt = 0;
    rep(i, px.size()) {
        if (lx <= px[i] && px[i] < rx && uy <= py[i] && py[i] < dy) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(30) << fixed;
    ll n;
    cin >> n;
    px.resize(n);
    py.resize(n);
    pt.resize(n);
    rep(i, n) {
        cin >> px[i] >> py[i] >> pt[i];
        px[i]--;
        py[i]--;
    }
    ll m;
    cin >> m;
    hx.resize(n);
    hy.resize(n);
    rep(i, m) {
        cin >> hx[i] >> hy[i];
        hx[i]--;
        hy[i]--;
    }
    string haction(m, '.');
    vector<string> paction(n);
    ll lx = SIZE / 2, ly = 0, rx = SIZE / 2, ry = SIZE - 1;
    vl arrived(m);
    bool finished = false;
    rep(t, 300) {
        if (finished) {
            rep(i, m) haction[i] = '.';
        } else if (Map[lx][ly + 1] == '#') {
            int cnt = count(lx, SIZE, 0, ly);
            if (cnt <= n / 2) {
                if (is_puttable(hx[0] + 1, hy[0])) {
                    haction[0] = 'd';
                    finished = true;
                } else {
                    haction[0] = '.';
                }
            } else {
                if (is_puttable(hx[0] - 1, hy[0])) {
                    haction[0] = 'u';
                    finished = true;
                } else {
                    haction[0] = '.';
                }
            }
            rep(i, 1, m) haction[i] = '.';
        } else if (is_all(arrived)) {
            rep(i, m) {
                if (Map[hx[i]][hy[i] + 1] == '#') {
                    haction[i] = 'L';
                } else if (is_puttable(hx[i], hy[i] + 1) && i == 0) {
                    haction[i] = 'r';
                } else {
                    haction[i] = '.';
                }
            }
        } else {
            rep(i, m) {
                if (rx < hx[i])
                    haction[i] = 'U';
                else if (rx > hx[i])
                    haction[i] = 'D';
                else if (ry < hy[i])
                    haction[i] = 'L';
                else if (ry > hy[i])
                    haction[i] = 'R';
                else {
                    arrived[i] = 1;
                    haction[i] = '.';
                }
            }
        }
        print(haction);
        rep(i, n) {
            cin >> paction[i];
        }
        move(haction, paction);
    }
}