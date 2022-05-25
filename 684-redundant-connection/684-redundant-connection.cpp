class union_find
{
	int n;
	vector<int> par;
	vector<int> sz;
public:
	union_find(int nval)
	{
		n = nval;
		par.resize(n + 1);
		sz.resize(n + 1);

		for (int i = 1; i <= n; ++i)
			par[i] = i, sz[i] = 1;
	}

	//O(1) ammortized
	int root(int x)
	{
		/*while(x!=par[x])
			x=par[x];
		return x;*/

		if (x == par[x])
			return x;

		return par[x] = root(par[x]);
	}

	//O(1) ammortized
	bool find(int a, int b)
	{
		return root(a) == root(b);
	}

	//O(1) ammortized
	bool un(int a, int b)
	{
		int ra = root(a);
		int rb = root(b);

		if (ra == rb)
			return false;

		if (sz[ra] > sz[rb])
			swap(ra, rb);

		par[ra] = rb;
		sz[rb] += sz[ra];
        
        return true;
	}
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        union_find dsu (edges.size()+1);
        for(auto edge: edges){
            if(!dsu.un(edge[0],edge[1])) return edge;
        }
        return {};
    }
};