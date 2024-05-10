#include<bits/stdc++.h>
#define size 12
using namespace std;

class Node{
    int data;
    Node* next;
    public:
    Node(){
        data=0;
        next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    friend class Graph;
};

class Graph{
    Node* arr[size];
    public:
    Graph(){
        for(int i=0;i<size;i++){
            arr[i]=NULL;
        }
    }

    //insert edge
    void insertEdge(int sv,int dv){
        Node* nn1=new Node(sv);
        Node* nn2=new Node(dv);

        //
        if(arr[sv]==NULL){
            arr[sv]=nn2;
        }
        else{
            Node* temp=arr[sv];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nn2;
        }
    }


    //display adjacency list 
    void display(){
        for(int i=0;i<size;i++){
            cout<<i<<" -> ";
            Node* temp=arr[i];
            while(temp!=NULL){
                cout<<temp->data<<" - ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    //Logic For BFS And DFS 

    void BFS(int sv){
        queue<int>q;
        bool visited[size]={false};
        q.push(sv);
        visited[sv]=1;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            cout<<front<<" ";
            Node* temp=arr[front];
            while(temp!=NULL){
                if(visited[temp->data]==0){
                    visited[temp->data]=1;
                    q.push(temp->data);
                }
                temp=temp->next;
            }
        }
    }


    void DFS(int sv){
        stack<int>q;
        bool visited[size]={false};
        q.push(sv);
        visited[sv]=1;
        while(!q.empty()){
            int front=q.top();
            q.pop();
            cout<<front<<" ";
            Node* temp=arr[front];
            while(temp!=NULL){
                if(visited[temp->data]==0){
                    visited[temp->data]=1;
                    q.push(temp->data);
                }
                temp=temp->next;
            }
        }
    }


    //-----------RECURSION ------------------

    void recursionBFS(queue<int>&recq,bool visited[size]){
        if(recq.empty()){
            return;
        }
        int front=recq.front();
        recq.pop();
        cout<<front<<" ";
        Node* temp=arr[front];
        while(temp!=NULL){
            if(visited[temp->data]==0){
                visited[temp->data]=1;
                recq.push(temp->data);
            }
            temp=temp->next;
        }

        recursionBFS(recq,visited);
    }

    void recBFS(int sv){
        queue<int>recq;
        bool visitedq[size]={false};
        recq.push(sv);
        visitedq[sv]=1;
        recursionBFS(recq,visitedq);
    }


    void recursionDFS(stack<int>&recq,bool visited[size]){
        if(recq.empty()){
            return;
        }
        int front=recq.top();
        recq.pop();
        cout<<front<<" ";
        Node* temp=arr[front];
        while(temp!=NULL){
            if(visited[temp->data]==0){
                visited[temp->data]=1;
                recq.push(temp->data);
            }
            temp=temp->next;
        }

        recursionDFS(recq,visited);
    }

    void recDFS(int sv){
        stack<int>recq;
        bool visitedq[size]={false};
        recq.push(sv);
        visitedq[sv]=1;
        recursionDFS(recq,visitedq);
    }
};
int main(){
    int V;
    cout<<"Enter the number of vertices in graph"<<endl;
    cin>>V;
    Graph obj;
    while(true){
        cout<<"Enter 1 for inserting edges between nodes in a graph"<<endl;
        cout<<"Enter 2 for Iterative BFS Traversal"<<endl;
        cout<<"Enter 3 for Recursive BFS Traversal"<<endl;
        cout<<"Enter 4 for iterative DFS Traversal"<<endl;
        cout<<"Enter 5 for recursive DFS Traversal"<<endl;
        cout<<"Enter 6 to display Adjaceny list"<<endl;
        int op;
        cout<<"Enter option"<<endl;
        cin>>op;
        if(op==1){
            for(int i=0;i<size;i++){
                int sv,dv;
                cout<<"Enter source and destination of "<<(i+1)<<" node"<<endl;
                cin>>sv>>dv;
                obj.insertEdge(sv,dv);
            }

        }
        else if(op==2){
            int sv;
            cout<<"Enter source node"<<endl;
            cin>>sv;
            obj.BFS(sv);
        }
        else if(op==3){
            int sv;
            cout<<"Enter source node"<<endl;
            cin>>sv;
            obj.recBFS(sv);
        }
        else if(op==4){
            int sv;
            cout<<"Enter source node"<<endl;
            cin>>sv;
            obj.DFS(sv);
        }
        else if(op==5){
            int sv;
            cout<<"Enter source node"<<endl;
            cin>>sv;
            obj.recDFS(sv);
        }
        else if(op==6){
            obj.display();
        }
    }
    return 0;
}