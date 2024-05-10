// //8 Puzzle problem 
// #include<bits/stdc++.h>
// using namespace std;
// int calcManhattanDist(vector<vector<int>>&initialState,vector<vector<int>>&goalState){
//     int dist=0;
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             int val=initialState[i][j];
//             for(int k=0;k<3;k++){
//                 for(int l=0;l<3;l++){
//                     if(goalState[k][l]==val){
//                         dist+=abs(k-i)+abs(l-j);
//                     }
//                 }
//             }
//         }
//     }

//     return dist;
// }

// void swapVec(vector<vector<int>>&State,int row1,int col1,int row2,int col2 ){
//     auto temp=State[row1][col1];
//     State[row1][col1]=State[row2][col2];
//     State[row2][col2]=temp;

// }
// int main(){
//     vector<vector<int>>initialState(3,vector<int>(3,0));
//     vector<vector<int>>goalState={{1,2,3},{4,5,6},{7,8,-1}};

//     cout<<"Enter the initial State"<<endl;
//     //input of initial state
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             cin>>initialState[i][j];
//         }
//     }

//     //create a ds hold manhattan distance and state 
//     priority_queue<pair<int,vector<vector<int>>>,vector<pair<int,vector<vector<int>>>>,greater<pair<int,vector<vector<int>>>>>pq;
//     pq.push({calcManhattanDist(initialState,goalState),initialState});

//     while(!pq.empty()){
//         auto top=pq.top();
//         pq.pop();
//         auto heuVal=top.first;
//         auto state=top.second;
//         //check if state is goal state or not 
//         //print 
//         for(const auto &row:state){
//             for(const auto &val:row){
//                 cout<<val<<" ";
//             }
//             cout<<endl;
//         }

//         cout<<"Heuristic Distance is: "<<heuVal<<endl;

//         //check if it is a goal state or not 
//         if(state==goalState){
//             cout<<"Goal State reached"<<endl;
//             break;
//         }


//         //else find empty position and make possible moves 
//         int emptyRow=-1;
//         int emptyCol=-1;
//         for(int i=0;i<3;i++){
//             for(int j=0;j<3;j++){
//                 if(state[i][j]==-1){
//                     emptyRow=i;
//                     emptyCol=j;
//                 }
//             }
//         }

//         //possible moves
//         int moves[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//         for(const auto move:moves){
//             int newRow=emptyRow+move[0];
//             int newCol=emptyCol+move[1];
//             if(newRow>=0 && newRow<3 && newCol>=0 && newCol<3){
//                 //possible state 
//                 vector<vector<int>>possibleState=state;
//                 swapVec(possibleState,emptyRow,emptyCol,newRow,newCol);
//                 pq.push({calcManhattanDist(possibleState,goalState),possibleState});
//             }
//         }
        
//     }
//     return 0;
// }



