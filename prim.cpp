void kruskal()
{
    int edges = 0, i = 0;
    vector<bool> connected(V, false);
    while (edges < (V - 1) && i < edgesVector.size())
    {
        auto v = edgesVector[i].first.first;
        auto u = edgesVector[i].first.second;
        if (!connected[v] || !connected[u])
        {
            connected[v] = true;
            connected[u] = true;
            cout << names[v] << "  " << names[u] << " : " << edgesVector[i].second << endl;
            edges++;
        }
        i++;
    }
}