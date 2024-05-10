#include<bits/stdc++.h>
using namespace std;
class Job{
    int P_id,AT,BT,CT,TAT,WT;
    public:
    Job(){
        P_id=AT=BT=CT=TAT=WT=0;
    }

    Job(int P_id,int AT,int BT){
        this->P_id=P_id;
        this->AT=AT;
        this->BT=BT;
        CT=TAT=WT=0;
    }

    void operator=(const Job &j1){
        this->P_id=j1.P_id;
        this->AT=j1.AT;
        this->BT=j1.BT;
        CT=TAT=WT=0;
    }

    friend class Scheduling;
};
class Scheduling{
    vector<Job>readyQueue;
    Job *proccesses;
    int N;
    public:
    Scheduling(){
        N=0;
        proccesses=NULL;
    }

    Scheduling(int N){
        this->N=N;
        this->proccesses=new Job[N];
    }

    void input(){
        int a,b;
        for(int i=0;i<N;i++){
            cout<<"Enter the arrival Time and Burst time of "<<(i+1)<<" process"<<endl;
            cin>>a>>b;
            Job j1(i+1,a,b);
            proccesses[i]=j1;
        }
    }

    void display(){
        cout<<"P_id\t AT\t BT\t CT\t TAT\t WT\t"<<endl;
        for(int i=0;i<N;i++){
            cout<<(i+1)<<"\t"<<proccesses[i].AT<<"\t"<<proccesses[i].BT<<"\t"<<proccesses[i].CT<<"\t"<<proccesses[i].TAT<<"\t"<<proccesses[i].WT<<endl;
        }
        int sumTAT=0;
        int sumWT=0;
        for(int i=0;i<N;i++){
            sumTAT+=proccesses[i].TAT;
            sumWT=proccesses[i].WT;
        }

        float avgTat=0;
        float avgWt=0;
        
        avgTat=sumTAT/N;
        avgWt=sumWT/N;
        cout<<"Average TAT is: "<<avgTat<<endl;
        cout<<"Average WT is : "<<avgWt<<endl;
    }

    //main FCFS logic
    void FCFS(){
        int currTime=0;
        int TotalTime=0;
        int completedProcesses=0;
        
        //criteria 
        sort(proccesses,proccesses+N,[](const Job &j1,const Job &j2){
            return j1.AT<j2.AT;
        });

        for(int i=0;i<N;i++){
            TotalTime+=proccesses[i].BT;
        }

        //now we have to write main code 
        while(currTime<=TotalTime){
            if(completedProcesses<N && proccesses[completedProcesses].AT<=currTime){
                readyQueue.push_back(proccesses[completedProcesses]);
                ++completedProcesses;
            }

            if(readyQueue.size()>0){
                readyQueue[0].BT--;
                if(readyQueue[0].BT==0){
                    for(int i=0;i<N;i++){
                        if(readyQueue[0].P_id==proccesses[i].P_id){
                            proccesses[i].CT=currTime+1;
                            proccesses[i].TAT=proccesses[i].CT-proccesses[i].AT;
                            proccesses[i].WT=proccesses[i].TAT-proccesses[i].BT;
                        }
                    }
                    readyQueue.erase(readyQueue.begin());
                }
            }
            currTime+=1;
        }

        this->display();
    }

    void SJF(){
        int currTime=0;
        int TotalTime=0;
        int completedProcesses=0;
        
        //criteria 
        sort(proccesses,proccesses+N,[](const Job &j1,const Job &j2){
            return j1.AT<j2.AT;
        });

        for(int i=0;i<N;i++){
            TotalTime+=proccesses[i].BT;
        }

        //now we have to write main code 
        while(currTime<=TotalTime){
            if(completedProcesses<N && proccesses[completedProcesses].AT<=currTime){
                readyQueue.push_back(proccesses[completedProcesses]);
                ++completedProcesses;
            }

            sort(readyQueue.begin(),readyQueue.end(),[](const Job &j1,const Job &j2){
                return j1.BT<j2.BT;
            });

            if(readyQueue.size()>0){
                readyQueue[0].BT--;
                if(readyQueue[0].BT==0){
                    for(int i=0;i<N;i++){
                        if(readyQueue[0].P_id==proccesses[i].P_id){
                            proccesses[i].CT=currTime+1;
                            proccesses[i].TAT=proccesses[i].CT-proccesses[i].AT;
                            proccesses[i].WT=proccesses[i].TAT-proccesses[i].BT;
                        }
                    }
                    readyQueue.erase(readyQueue.begin());
                }
            }
            currTime+=1;
        }

        this->display();
    }


};
int main(){
    int N;
    cout<<"Enter the number of processes"<<endl;
    cin>>N;
    Scheduling obj(N);
    obj.input();
    obj.FCFS();
    cout<<endl;
    obj.SJF();
    return 0;
}