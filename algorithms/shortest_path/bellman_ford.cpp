#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair <lli, lli> ii;
typedef vector <lli> vi;
typedef vector <ii> vii;
typedef vector <vii> vvi;

vvi graph;
vi distances;
bool hasNegativeCycle = false;

lli bellman_ford(lli start) {
    distances[start] = 0;
    lli vertex = graph.size();
    lli v, w;

    for (lli i = 0; i <  vertex; i++) {
        for (lli u = 0; u < vertex; ++u) {
            for (lli k = 0; k < graph[u].size(); ++k) {
                v = graph[u][k].second;
                w = graph[u][k].first;

                if (i == vertex && distances[v] > distances[u] + w) {
                    hasNegativeCycle = true;
                } else {
                    distances[v] = min(distances[v], distances[u] + w);
                }
            }
        }
    }

    return distances[vertex - 1];
}

int main() {
    lli vertex, edges;
    lli source, destiny, cost;

    cin >> vertex >> edges;

    distances.resize(vertex + 1, INT_MAX);
    graph.resize(vertex + 1);

    for (lli i = 0; i < edges; ++i) {
        cin >> source >> destiny >> cost;

        // criacao do grafo bidirecionado
        graph[source].push_back(make_pair(cost, destiny));
        graph[destiny].push_back(make_pair(cost, source));
    }

    printf("%lld\n", bellman_ford(1));

    return 0;
}