#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;

vector<int> numVec;

int accmultae = 0;

int main()
{
    fastio;

    cin >> n >> m;

    numVec.push_back(0);

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        accmultae += tmp;

        numVec.push_back(accmultae);
    }

    for(int i = 0; i < m; i++)
    {
        int start, end;

        cin >> start >> end;

        cout << numVec[end] - numVec[start-1] << '\n';
    }



    return 0;
}