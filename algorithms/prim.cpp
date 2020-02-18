#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair <lli, lli> ii;
typedef vector <lli> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vii> vvi;

// min-heap
typedef priority_queue <ii, vii, greater<ii>> pq;

vvi graph;
vb visited;
pq pqueue;

lli prim() {
    lli min_cost = 0;
    ii source = make_pair(0, 1);

    pqueue.push(source);

    while(!pqueue.empty()) {
        source = pqueue.top();
        pqueue.pop();

        if (!visited[source.second]) {
            min_cost += source.first;
            visited[source.second] = true;
            
            for (auto edge: graph[source.second]) {
                pqueue.push(edge);
            }   
        }
    }

    return min_cost;
}

int main() {
    lli vertex, edges;
    lli source, destiny, cost;

    cin >> vertex >> edges;

    graph.resize(vertex + 1);
    visited.resize(vertex + 1, false);

    for (lli i = 0; i < edges; ++i) {
        cin >> source >> destiny >> cost;

        // criacao do grafo bidirecionado
        graph[source].push_back(make_pair(cost, destiny));
        graph[destiny].push_back(make_pair(cost, source));
    }

    

    cout << prim() << endl;

    return 0;
}