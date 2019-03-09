#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

bool sortHelper(const vector<int>& v1, const vector<int>& v2) {
    if (v1[2] == v2[2])
        return v1[0] + v1[1] < v2[0] + v2[1];
    return v1[2] < v2[2];
}

int findRoot(const vector<int>& parent, const int& node) {
    int i = node;
    while (parent[i] != -1)
        i = parent[i];
    return i;
}

int kruskals(const int& g_nodes, const vector<int>& g_from, const vector<int>& g_to, const vector<int>& g_weight) {
    vector<vector<int>> edges(g_from.size());
    for (int i = 0; i < edges.size(); i++) {
        vector<int> edge;
        edge.push_back(g_from[i]);
        edge.push_back(g_to[i]);
        edge.push_back(g_weight[i]);
        edges[i] = edge;
    }

    sort(edges.begin(), edges.end(), sortHelper);

    vector<int> parent(edges.size(), -1);

    int totalCost = 0;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;

        if (findRoot(parent, u) != findRoot(parent, v)) {
            parent[v] = u;
            totalCost += edges[i][2];
        }
    }

    return totalCost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    fout << res << endl;

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
