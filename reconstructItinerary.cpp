// reconstruct Itinerary code

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

void dfs(string src, unordered_map<string, multiset<string> > &adj, vector<string> &res)
{
    while (adj[src].size())
    {
        string v = *adj[src].begin();
        adj[src].erase(adj[src].begin());
        dfs(v, adj, res);
    }
    res.push_back(src);
}

vector<string> findItinerary(vector<vector<string> > &tickets)
{
    unordered_map<string, multiset<string> > adj;
    for (auto ticket : tickets)
    {
        adj[ticket[0]].insert(ticket[1]);
    }
    vector<string> res;
    dfs("JFK", adj, res);
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<vector<string> > tickets;
    int n;
    cout << "Enter the number of tickets: ";
    cin >> n;
    cout << "\n";
    cout << "Enter the tickets: ";
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        vector<string> temp;
        string x;
        cin >> x;
        temp.push_back(x);
        cin >> x;
        temp.push_back(x);
        tickets.push_back(temp);
    }
    cout << "\n";
    vector<string> res = findItinerary(tickets);
    cout << "Itinerary: ";
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}


// Input:
// Enter the number of tickets: 4
// Enter the tickets:
// JFK SFO
// SFO ATL
// ATL JFK
// JFK ATL

