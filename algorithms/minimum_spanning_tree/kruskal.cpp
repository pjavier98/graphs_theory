#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef tuple <lli, lli, lli> iii;
typedef vector <lli> vi;
typedef vector <iii> vtuple;

vtuple edgeList;
vi parent;
vi depth;

// garante que a arvore tenha log(n) de tamanho
// tendo assim um find de O(log(n))
lli findParent(lli i) {
    if (parent[i] != i) {
        parent[i] = findParent(parent[i]);
    }
    return parent[i];
}

lli isSameParent(lli i, lli j) {
    return findParent(i) == findParent(j);
}

void unionSet(lli i, lli j) {
    if (isSameParent(i, j)) return;
    lli x = findParent(i);
    lli y = findParent(j);

    if (depth[x] > depth[y]) {
        parent[y] = x;
    } else {
        parent[x] = y;
        if (depth[x] == depth[y]) depth[y] += 1;
    }
}

lli kruskal() {    
    lli source, destiny, cost, min_cost;
    min_cost = 0;

    sort(edgeList.begin(), edgeList.end());        

    for (auto edge: edgeList) {
        cost = get<0>(edge);
        source = get<1>(edge);
        destiny = get<2>(edge);   

        if (!isSameParent(source, destiny)) {
            min_cost += cost;
            unionSet(source, destiny);
        }
    }    

    return min_cost;
}

int main() {
    lli vertex, edges;
    lli source, destiny, cost;

    cin >> vertex >> edges;

    parent.resize(vertex + 1);
    depth.resize(vertex + 1, 0);

    for (int i = 0; i < parent.size(); ++i) {
        parent[i] = i;
    }

    for (lli i = 0; i < edges; ++i) {
        cin >> source >> destiny >> cost;
        // criacao a lista com as arestas
        edgeList.push_back(make_tuple(cost, source, destiny));
    }

    cout << kruskal() << endl;

    return 0;
}