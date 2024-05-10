// #include<bits/stdc++.h>
// using namespace std;
// class Graph{
//     int V;
//     vector<vector<pair<int,int>>>adj;
//     public:
//     Graph(int V){
//         this->V=V;
//         adj.resize(V);
//     }

//     void insertEdges(int u,int v,int w){
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }

//     //data structure 
//     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

//     //parent vector 
    
//     vector<int>parent;

//     int findParent(int u){
//         if(parent[u]==u){
//             return u;
//         }
//         return parent[u]=findParent(parent[u]);
//     }

//     void unioOp(int u,int v){
//         int up=findParent(u);
//         int vp=findParent(v);
//         if(up!=vp){
//             parent[up]=vp;
//         }
//     }


//     int kruskal(){
//         int total=0;
//         //initialize parent vector
//         parent.resize(V);
//         for(int i=0;i<V;i++){
//             parent[i]=i;
//         }

//         //sare edges pq me dalna hai 

//         for(int i=0;i<V;i++){
//             for(const auto &neigh:adj[i]){
//                 auto node=neigh.first;
//                 auto w=neigh.second;
//                 pq.push({w,{i,node}});
//             }
//         }


//         while(!pq.empty()){
//             auto top=pq.top();
//             pq.pop();

//             auto weight=top.first;
//             auto src=top.second.first;
//             auto dest=top.second.second;


//             if(findParent(src)!=findParent(dest)){
//                 //they are not from same component 
//                 total+=weight;
//                 unioOp(src,dest);
//             }
//         }


//         return total;
//     }
// };
// int main(){
//     int v,edges;
//     cout<<"Enter the number of vertices and number of edges"<<endl;
//     cin>>v>>edges;
//     Graph obj(v);
//     for(int i=0;i<edges;i++){
//         int s,v,w;
//         cin>>s>>v>>w;
//         obj.insertEdges(s,v,w);
//     }

//     int ans=obj.kruskal();
//     cout<<ans<<endl;
//     return 0;
// }


