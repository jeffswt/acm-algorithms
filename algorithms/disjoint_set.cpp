
class DisjointSet
{
public:
    int n, par[maxn], size[maxn];
    lli vsm[maxn];
    int find(int p)
    {
        if (par[p] != p)
            par[p] = find(par[p]);
        return par[p];
    }
    bool joined(int p, int q)
    {
        return find(p) == find(q);
    }
    void join(int p, int q)
    {
        int gp = find(p),
            gq = find(q);
        if (gp == gq)
            return ;
        if (size[gq] < size[gp])
            swap(gq, gp);
        par[gp] = gq;
        size[gq] += size[gp];
        vsm[gq] += vsm[gp];
        return ;
    }
    void init(int n, lli w[])
    {
        rep(i, 1, n) {
            par[i] = i;
            size[i] = 1;
        }
        rep(i, 1, n)
            vsm[i] = w[i];
        return ;
    }
} dsu;
