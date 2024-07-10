// next smaller element to left

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
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            while (!s.empty() && s.top() >= a[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = s.top();
            }
        }
        s.push(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}