#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <queue>
using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        if(abs(a) == abs(b))
        {
            return a > b;
        }

        return abs(a) > abs(b);
    }
};

int n;

int main()
{
    fastio;
    priority_queue<int, vector<int>, compare> pq;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        if(tmp != 0)
        {
            pq.push(tmp);        
        }

        else{
            if(pq.empty())
            {
                cout << '0' << '\n';
            }

            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }


    return 0;
}