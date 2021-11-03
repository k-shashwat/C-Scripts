// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

unordered_set<int> p1;
void dfs(int val[], int n, vector<int> adj[], int v,
		unordered_set<int>& values, int& ans)
{
	if (values.count(val[v]))
		return;
    
	ans++;
	values.insert(val[v]);
    p1.insert(val[v]);
	// Call dfs on all adjacent nodes
	for (auto ele : adj[v]) {
		dfs(val, n, adj, ele, values, ans);
	}
	values.erase(val[v]);
}

// Driver code
int main()
{
	int val[] = { 0, 2, 1, 4, 3, 4, 8, 10, 2, 5, 1 };
	int n = sizeof(val) / sizeof(val[0]);

	vector<int> adj[n];

	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);
	adj[2].push_back(6);
	adj[3].push_back(7);
	adj[5].push_back(8);
	adj[5].push_back(9);
	adj[5].push_back(10);

	unordered_set<int> values;
    unordered_set<int> :: iterator itr;
    vector <int>k;
    for(itr = p1.begin(); itr!=p1.end();itr++) k.push_back(*itr);
	int ans = 0;

	dfs(val, n, adj, 1, values, ans);

	cout << ans << endl;
    sort(k.begin(),k.end());
    for(auto g: k) cout <<g << " ";
	return 0;
}
