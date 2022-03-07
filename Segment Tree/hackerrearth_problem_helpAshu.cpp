#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

vector<bool> isPrime(1e7, true);
void sieve()
{
    for (int p = 2; p * p <= 1e7; p++)
        if (isPrime[p] == true)
            for (int i = p * p; i <= 1e7; i += p)
                isPrime[i] = false;
}

void buildTree(int idx, int start, int end, vector<int> &st, vector<int> &arr)
{
    if (start == end)
    {
        st[idx] = arr[start] % 2;
        return;
    }

    int mid = (start + end) / 2;
    buildTree(2 * idx + 1, start, mid, st, arr);
    buildTree(2 * idx + 2, mid + 1, end, st, arr);

    st[idx] = st[2 * idx + 1] + st[2 * idx + 2];
}

int query(int idx, int start, int end, int l, int r, vector<int> &st)
{
    if (start > r || end < l)
        return 0;

    if (start >= l && end <= r)
        return st[idx];
    int mid = (start + end) / 2;
    int left = query(2 * idx + 1, start, mid, l, r, st);
    int right = query(2 * idx + 2, mid + 1, end, l, r, st);

    return left + right;
}

void update(int idx, int start, int end, int updateIdx, vector<int> &st, vector<int> &arr)
{
    if (start == end)
    {
        st[idx] = arr[start] % 2;
        return;
    }

    int mid = (start + end) / 2;

    if (updateIdx <= mid)
    {
        update(2 * idx + 1, start, mid, updateIdx, st, arr);
    }
    else
    {
        update(2 * idx + 2, mid + 1, end, updateIdx, st, arr);
    }

    st[idx] = st[2 * idx + 1] + st[2 * idx + 2];
}

void solve()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int> st(4 * n + 4, 0);
    buildTree(0, 0, n - 1, st, arr);

    int q;
    cin >> q;

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 0)
        {
            arr[l - 1] = r;
            update(0, 0, n - 1, l - 1, st, arr);
        }
        else if (t == 1)
        {
            cout << (r - l + 1) - query(0, 0, n - 1, l - 1, r - 1, st) << endl;
        }
        else
        {
            cout << query(0, 0, n - 1, l - 1, r - 1, st) << endl;
        }
    }
}

int main()
{
    // Problem Link - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/

    OJ;
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    // sieve();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}