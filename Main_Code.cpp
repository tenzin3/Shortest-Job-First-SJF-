#include<iostream>
#include<stdlib.h>
using namespace std;

void Print(int NumOfJob,int Table[][3]);

int main()
{
	//Limit of no of job/process has been assigned 9
	int NumOfJob=rand()%9+1;
	// Three columns ,1.Storing the number of the process 2. Arrival Time
	//                3.Cpu Burst Time
	int Table[10][3]; 
	
	cout<<"No of processess generated-->"<<NumOfJob<<endl;
	
	//Assigning process name
	for(int l=0;l<NumOfJob;l++)
	Table[l][0]=l+1;
	
    //Arrival Time should be entered in the increasing order
	cout<<"Entering the Arrival Time-->"<<endl;
	for(int j=0;j<NumOfJob;j++)
	cin>>Table[j][1];
	
	cout<<"Entering the CPU Burst-->"<<endl;
	for(int i=0;i<NumOfJob;i++)
	cin>>Table[i][2];
	
	cout<<"------THE TABLE------ "<<endl;
	Print(NumOfJob,Table);
	
	int Flag[10];      //Keeps the track of which process has/has'nt done
	for(int i=0;i<10;i++)
	Flag[i]=0;
	
	
	//Calculating the Time ticking
	int Time=0;
	//Counting how many processes has been Finished
	int count=0;
	
	//While all the job not done
    while(count<NumOfJob)
    {
       int m=0,Stand=0;
       int temp;
       
       if(Time==0)
       {
	    Time+=Table[m][1];
	    Stand=1;
	   }
	   else
	   {
		    while(Table[m][1]<=Time&&m<NumOfJob)
			m++;
	       
	       m--;
		   int smallest=1000;
		   
		   //Finding the smallest CpuBurstTime under the Arrival Time
		   int k;
		   for(k=0;k<=m;k++)
		   {
		   	 if(Table[k][2]<smallest&&Flag[k]==0)
				{
				smallest=Table[k][2];
				temp=k;
				Stand=1;
			    }
		   }
       }
	   if(Stand==1)
	   {
	   
		   cout<<"At Time: "<<Time<<"  Process no."<<temp+1<<endl; //Showing the process no on the screen
		   Time+=Table[temp][2]; //Time increased by smallest CpuBurst time
		   Flag[temp]=1;         //Informing Flag that particular process been done
	       count++;              //One more process done
	   }   
	   //If there are no process available then time is incremented
	   if(Stand==0)
	   Time++;           
    }

    cout<<"FINISHED!!!!!!!!!!";
	return 0;
}

void Print(int NumOfJob, int Table[][3])
{
	cout<<"Pi"<<"\t"<<"Arrival"<<"\t"<<"Burst"<<endl;
	for(int i=0;i<NumOfJob;i++)
	cout<<Table[i][0]<<"\t"<<Table[i][1]<<"\t"<<Table[i][2]<<endl;
	
}
