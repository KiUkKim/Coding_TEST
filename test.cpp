#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int powN[45];
bool visited[10];
int n;
vector<int> vc;

int main()
{
    fastio;

    for(int i = 1; i < 45; i++)
    {
        int pn = pow(i, 2);


        powN[i] = pn;       
    }

    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int num;

        cin >> num;

        vc.push_back(num);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            
        }
    }



    return 0;
}