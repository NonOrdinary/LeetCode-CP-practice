class Solution {
public:
    class DSU{
        public:
        vector<int>sze;
        vector<int>root;
        vector<int>compAnd;//stores the and of the component rooted at some point
        DSU(int n){

            n++;
            sze.resize(n,1);
            root.resize(n,0);
            compAnd.resize(n,1LL<<21);//note the initialisation here 
            for(int i=0;i<n;i++){
                root[i]=i;
                compAnd[i]--;//to make it all 1111111...
            }

        }

        int getRoot(int x){
            if(x==root[x]){
                return root[x];
            }
            return root[x]=getRoot(root[x]);
        }

        void Unite(int x,int y,int edge){
            int rootX=getRoot(x);
            int rootY=getRoot(y);
            if(rootX==rootY){
                compAnd[rootX]&=edge;//necessar as there can be multiple edges
                //and even if there were not then this operation has only significance
                //when edges are repeated but it cannot worsen answer as such due to and
                return;
            }
            if(sze[rootX]>sze[rootY]){
                //this stores the and of component with leader as rootX
                compAnd[rootX]&=compAnd[rootY];//merging two components and too
                compAnd[rootX]&=edge;//adding edge to componenet
                root[rootY]=rootX;
                sze[rootX]+=sze[rootY];
            }
            else{
                compAnd[rootY]&=edge;
                compAnd[rootY]&=compAnd[rootX];
                root[rootX]=rootY;
                sze[rootY]+=sze[rootX];

            }
        }

        int getPath(int x,int y){
            int rootX=getRoot(x);
            int rootY=getRoot(y);
            if(rootX!=rootY){
                return -1;
            }
            return compAnd[rootX];//if both are of same component then the total and
            //of component has to be the minimum
        }
    };
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        //Idea is that the AND will be minimised for whole component as
        //the walk belongs to complete graph so ,the minimum and will be of the 
        //complete component so we need to determine the AND of component
        //If two nodes don't belong to same then result is -1 otherwise its and of component
        DSU dsu(n);
        
        for(auto &i:edges){
            dsu.Unite(i[0],i[1],i[2]);
        }
        
        vector<int>result;
        for(auto &i:query){
            int minWalk=dsu.getPath(i[0],i[1]);
            result.push_back(minWalk);
        }
        return result;
    }
};