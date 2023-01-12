#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;

int root[1000001];

int find(int a)
{
    if(root[a] == a)
        return a;
    
    else{
        // return find(root[a]); 최악의 경우 O(N)으로 길어질 수 있음
        return root[a] = find(a);
    }
}

void unionF(int a, int b)
{
    a = find(a);
    b = find(b);

    root[b] = a;
}

int main()
{
    fastio;

    cin >> n >> m;

    // root 노드 초기화
    for(int i = 1; i <= n; i++)
    {
        root[i] = i;
    }


    for(int i = 0; i < m; i++)
    {
        int cmd, a, b;

        cin >> cmd >> a >> b;

        if(cmd == 0)
        {
            unionF(a, b);
        }

        else if(cmd == 1)
        {
            int rootA, rootB;

            rootA = find(a);

            rootB = find(b);


            if(rootA == rootB)
            {
                cout << "YES" << '\n';
            }

            else{
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}