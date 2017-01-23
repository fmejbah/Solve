/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 762 - We Ship Cheap               #
 * Date: 05/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

#define M 1000

map<string, vector<string> > G;
map<string,bool> visited;
map<string,string> root;

void bfs( string s, string d )
{
    queue<string> Q;
    Q.push(d);
    visited[d] = 1;
    while(!Q.empty())
    {
        string v = Q.front();
        Q.pop();
        for( int i = 0; i < G[v].size(); i++ )
        {
            string u = G[v][i];
            if( visited[u] == 0 )
            {
                visited[u] = 1;
                root[u] = v;
                //if( u == s ) return;
                Q.push(u);
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    string s1, s2;
    bool f = 0;

    while( scanf("%d", &n) == 1 )
    {
        G.clear();
        root.clear();
        visited.clear();

        while(n--)
        {
            cin >> s1 >> s2;
            G[s1].push_back(s2);
            G[s2].push_back(s1);
            visited[s1] = visited[s2] = 0;
        }
        cin >> s1 >> s2;
        bfs(s1,s2);

        if(f) puts("");
        f = 1;
        if(root[s1] == "")
        {
            printf("No route\n");
            continue;
        }
        while( s1 != s2)
        {
            cout<<s1<<" ";
            s1 = root[s1];
            cout<<s1;
            cout<<endl;
        }
    }
}
