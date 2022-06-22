#include <bits/stdc++.h> //code for dfs traversal usig list representation
using namespace std;
const int N = 1e3 + 10;
vector<int> current_cc; //for storing connected components
vector<vector<int>> cc; //for storing connected componet
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
vector<int> g[N];
bool vis[N];
void dfs(int vertex)
{
    vis[vertex] = true;
    current_cc.pb(vertex); //storing the connected componets
    for (int c : g[vertex])
    {
        cout << "par" << vertex << "child" << c << endl;
        if (vis[c])
            continue;
        dfs(c);
    }
}
int main()
{
    int n, m; //n=number of vertices,m =number of edge
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    int ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue; //this is to find connected components in a graph
        current_cc.clear();
        dfs(i);
        cc.pb(current_cc);
        ct++;
    }
    cout << cc.size() << endl;
    /*for (auto c_cc : cc)//this is for printing connected components
    {
        for (int vertex : c_cc)
        {
            cout << vertex << " ";
        }

        cout << endl;
    }*/

    return 0;
}