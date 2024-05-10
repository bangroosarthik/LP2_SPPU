//Single source shortest path algo -> By Sarthik Bangroo (DIJKSTRA ALGO)
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    //i want to create an adjacency list 
    vector<vector<pair<int,int>>>adj;
    //first int represents the node and second represents the cost 
    public:
    Graph(int V){
        this->V=V;
        adj.resize(V);
    }

    //insert edge and their corresponding weight in adjacency list 
    void insertEdge(int u,int v,int w){
        //it is a undirected graph
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    //write main logic 

    //requirement -> 2 things 
    //first datastructure 2nd distance vector that will contain shortest distance from source to that particular node 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    // here also inside pair first represent node and second cost 
    vector<int>Dijkstra(int sv){
        vector<int>Distance(V,INT_MAX);
        Distance[sv]=0;
        pq.push({sv,0});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            auto node=top.first;
            for(const auto &neigh:adj[node]){
                auto n1=neigh.first;
                auto cost=neigh.second;

                if(Distance[n1]>Distance[node]+cost){
                    Distance[n1]=Distance[node]+cost;
                    pq.push({n1,Distance[n1]});
                }
            }
        }

        return Distance;
    }

};
int main(){
    int V,edges;
    cout<<"Enter the number of vertices and edges"<<endl;
    cin>>V>>edges;
    Graph obj(V);
    while(true){
        cout<<"Enter 1 to insert edge"<<endl;
        cout<<"Enter 2 to calculate Single source shortest path"<<endl;
        cout<<"Enter op"<<endl;
        int op;
        cin>>op;
        if(op==1){
            cout<<"Enter (src,dest,weight)"<<endl;
            for(int i=0;i<edges;i++){
                int src,dest,w;
                cin>>src>>dest>>w;
                obj.insertEdge(src,dest,w);
            }
        }
        else if(op==2){
            int sv;
            cout<<"Enter source node"<<endl;
            cin>>sv;
            vector<int>ans=obj.Dijkstra(sv);
            for(int i=0;i<ans.size();i++){
                cout<<sv<<"-"<<i<<" -> "<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
