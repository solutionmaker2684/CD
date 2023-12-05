#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of productions: ";
    cin >> n;
    vector<pair<char, string>> prod(n);
    cout << "Enter the productions\n";
    for (int i = 0; i < n; i++)
    {
        cin >> prod[i].first >> prod[i].second;
    }
    map<char, set<char>> first;
    for (int i = 0; i < n; i++)
    {
        char non_term = prod[i].first;
        string term = prod[i].second;
        if (islower(term[0]))
        {
            first[non_term].insert(term[0]);
        }
        else
        {
            for (int j = 0; j < term.size(); j++)
            {
                if (isupper(term[j]))
                {
                    first[non_term].insert(first[term[j]].begin(), first[term[j]].end());
                    if (first[term[j]].find('$') == first[term[j]].end())
                    {
                        break;
                    }
                }
                else
                {
                    first[non_term].insert(term[j]);
                    break;
                }
            }
        }
    }
    cout << "First of non-terminals:\n";
    for (auto i : first)
    {
        cout << i.first << " : ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}