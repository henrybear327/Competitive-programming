int main()
{
    cin.sync_with_stdio(0);
    int N;
    long long a, s = 0, S, ans = 0;
    cin >> N >> S;
    map<long long, int> M;
    M[s] = 1;
    for (int i = 0; i < N; i++) {
        cin >> a;
        s += a;
        if (M.find(s - S) != M.end())
            ans += M[s - S];
        //	cout << s << "\n";
        M[s] = M[s] + 1;
    }
    cout << ans << "\n";
    return 0;
}
