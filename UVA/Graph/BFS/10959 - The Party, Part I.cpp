/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 10959 - The Party, Part I         #
 * Date: 05/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

#define M 1002

vector<int> Graph[M];
int level[M];

void BFS( int source ) {
    bool visited[M] = {false};
    queue<int> Q;

    Q.push(source);
    level[source] = 0;
    visited[source] = true;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for( int i = 0; i < Graph[u].size(); i++ ) {
            int v = Graph[u][i];
            if(!visited[v]) {
                Q.push(v);
                level[v] = level[u] + 1;
                visited[v] = true;
            }
        }
    }
}

int main() {
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
    int t, p, d, u, v;
    bool f = 0;
    cin >> t;
    while(t--) {
        cin >> p >> d;
        while(d--) {
            cin >> u >> v;
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }
        BFS(0);
        if(f) puts("");
        f = true;
        for( int i = 1; i < p; i++ )
            cout << level[i] << endl;
        for( int i = 0; i < M; i++ )
            Graph[i].clear();
    }
}
