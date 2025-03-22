class Solution {
public:
    class DSU{
        public:
        vector<int>root;
        vector<int>size;//stores total vertices
        vector<int>edges;//stores total edges
        DSU(int n){
            root.assign(n,-1);
            size.assign(n,1);
            edges.assign(n,0);
            for(int i=0;i<n;i++){
                root[i]=i;

            }
        }

        int getRoot(int x){
            if(root[x]==x){
                return x;
            }
            return root[x]=getRoot(root[x]);
        }

        void Unite(int x,int y){
            int rootX=getRoot(x);
            int rootY=getRoot(y);

            if(rootX==rootY){
                edges[rootX]++;//important,but what to do if edge was repeated?maybe use sets?
             return;
            }
            
            if(size[rootX]<size[rootY]){
                swap(rootX,rootY);
            }

            size[rootX]+=size[rootY];
            edges[rootX]+=edges[rootY]+1;
            root[rootY]=rootX;
        }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //the problem is basically finding componenets which can be done
        //via dfs/bfs or any other but to learn i have used DSU
        //anyway in complete graph there are n*(n-1)/2 edges for n vertices 
        //so we need to find subgraph that are complete
        DSU dsu(n);
        for(auto &i:edges){
            dsu.Unite(i[0],i[1]);
        }
        int result=0;
        for(int i=0;i<n;i++){
            
            if(dsu.root[i]==i){
                int vertices=dsu.size[i];
                int totalEdges=dsu.edges[i];

                //cout<<dsu.root[i]<<" "<<vertices<<" "<<totalEdges<<endl;
                if(vertices*(vertices-1) == (2*totalEdges)){
                    result++;
                }
            }
        }

        return result;
    }
};