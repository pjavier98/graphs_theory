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

pq pqueue;
vvi graph;
vi distances;
vi predecessor;
vi way;

lli dijkstra() {
    ii start = make_pair(0, 1);
    distances[1] = 0;
    pqueue.push(start);  
    
    // enquanto a fila nao for vazia o algoritmo executa
    while(!pqueue.empty()) {
        start = pqueue.top();
        pqueue.pop();

        // percorre a lista de adj de um vertice
        for (auto edge: graph[start.second]) {
            lli v = edge.second;
            lli w = edge.first;

            // so atualiza se o custo de eu chegar no novo vertice for menor
            if (distances[v] > w + start.first) {
                predecessor[v] = start.second;
                // atualiza a distancia caso ela seja menor que o que ja tinhamos
                distances[v] = w + start.first;

                // precisa passar a nova distancia e o vertice.
                pqueue.push(make_pair(distances[v], v));
            }
        }
    }

    return distances[graph.size() - 1];
}

void print_graph() {
    for (lli i = 0; i < graph.size(); ++i) {
        printf("%lld ", i);
        for (auto edge: graph[i]) {
            printf("{ %lld, %lld} -> ", edge.first, edge.second);
        }
        printf("null\n");
    }
    printf("\n");
}

void get_min_way() {
    lli index = predecessor.size() - 1;
    while (index != 1) {
        way.insert(way.begin(), index);
        index = predecessor[index]; 
    }
    way.insert(way.begin(), index);
}

void print_min_way() {
    for (int i = 0; i < way.size(); ++i) {
        if (i == 0) {
            printf("%lld", way[i]);
        } else {
            printf(" => %lld", way[i]);
        } 
    }
    printf("\n");
}


int main() {
    lli vertex, edges;
    lli source, destiny, cost;

    cin >> vertex >> edges;

    distances.resize(vertex + 1, INT_MAX);
    predecessor.resize(vertex + 1);
    graph.resize(vertex + 1);

    for (lli i = 0; i < edges; ++i) {
        cin >> source >> destiny >> cost;

        // criacao do grafo bidirecionado
        graph[source].push_back(make_pair(cost, destiny));
        graph[destiny].push_back(make_pair(cost, source));
    }

    printf("%lld\n", dijkstra());

    get_min_way();
    print_min_way();
    
    return 0;
}