#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;

int house[1001][3];
int minN = 987654321;

int main()
{
    fastio;

    int colorCost[3] = {0,};

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> colorCost[0] >> colorCost[1] >> colorCost[2];

        if(i == 0)
        {
            house[0][0] = colorCost[0];
            house[0][1] = colorCost[1];
            house[0][2] = colorCost[2];
        }

        else{
            house[i][0] = min(house[i-1][1], house[i-1][2]) + colorCost[0];
            house[i][1] = min(house[i-1][2], house[i-1][0]) + colorCost[1];
            house[i][2] = min(house[i-1][0], house[i-1][1]) + colorCost[2];
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(minN > house[n-1][i])
            minN = house[n-1][i];
    }

    cout << minN << '\n';

    return 0;
}