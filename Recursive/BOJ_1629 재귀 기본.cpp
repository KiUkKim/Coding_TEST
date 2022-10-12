#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int A, B, C;

long long Recursive(int a, int b, int c)
{
    if(b==1)
        return a % c;

    else{
        long long tmp = Recursive(a, b/2, c);

        if(b%2)
            return ((tmp*tmp) % c * a) % c;
        else 
            return (tmp * tmp)  % c;
    }

}


int main()
{
    fastio;

    cin >> A >> B >> C;
    
    cout <<  Recursive(A , B, C) << '\n';

    return 0;
}