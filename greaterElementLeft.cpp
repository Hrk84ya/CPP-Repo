// code for next greater element in the left

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<int> s;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] <= a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = a[s.top()];
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
