#include <bits/stdc++.h>

using namespace std;

map<string, vector<string> > G;

int bfs( string s, string des )
{
    map<string,int> d;
    map<string,bool> visited;
    queue<string> Q;
    d[s] = 0;
    Q.push(s);
    visited[s] = 1;

    while(!Q.empty())
    {
        string u = Q.front();
        Q.pop();
        for( int i = 0; i < G[u].size(); i++ )
        {
            string v = G[u][i];
            if(!visited[v])
            {
                visited[v] = 1;
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
    return d[des];
}

bool transformation( string s1, string s2 )
{
    if(s1.size()==s2.size())
    {
        int a = 0;
        for( int i = 0; i < s1.size(); i++ )
        {
            if(s1[i]!=s2[i])
                a++;
            if(a>1) return false;
        }
        return true;
    }
    return false;
}

int main()
{
    vector<string> v;
    string s;
    int t;
    bool f = 0;

    scanf("%d", &t);

    while(t--)
    {
        while(cin>>s)
            if(s=="*") break;
            else v.push_back(s);
        for( int i = 0; i < v.size(); i++ )
            for( int j = 0; j < v.size(); j++ )
        {
            if(i!=j)
            {
                if(transformation(v[i],v[j]))
                {
                    G[v[i]].push_back(v[j]);
                    G[v[j]].push_back(v[i]);
                }
            }
        }
        cin.ignore();
        if(f) puts("");
        f = 1;
        while(1)
        {
            getline(cin,s);
            if( s == "" ) break;
            else
            {
                int i = 0;
                while(s[i]!=' ')
                    i++;
                cout << s << ' ' << bfs(s.substr(0,i),s.substr(i+1)) << endl;
            }
        }

        G.clear();
    }
}
