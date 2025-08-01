#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

vector<ll> dijkstra(ll node, vector<vector<pair<ll, ll>>>& adj) {
    ll n = adj.size();

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> distance(n, INT_MAX);

    pq.push({node, 0});
    distance[node] = 0;

    while(!pq.empty()) {
        ll nd = (pq.top()).first;
        ll ww = (pq.top()).second;
        pq.pop();

        for(auto neighbour : adj[nd]) {
            ll nd1 = neighbour.first;
            ll ww1 = neighbour.second;
            if(distance[nd1] > distance[nd] + ww1) {
                distance[nd1] = distance[nd] + ww1;
                pq.push({nd1, distance[nd1]});
            }
        }
    }

    return distance;
}

int main() {

    ll n = 5;

    vector<vector<pair<ll, ll>>> adj(n);
    ll node = 0;

    vector<ll> distances = dijkstra(node, adj);

    return 0;
}