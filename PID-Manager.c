// Including Headers Required for Program 
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<pthread.h>

// Defining Constants Required for Program 
#define start 100
#define end 1000
#define size end-start
int bitMap[size];
int c=0;
// Declaring required functions for program;
int allocateMap();
int allocatePID(int);
int releasePID(int);
void *createProcess(void *time);
int totalAvail();
int nextAvail();
// Menu Functions
void menu();
void choice();


// Main Function
int main(){
	allocateMap();
	menu();
	printf("\nMain Program Ends\n");
	return 0;
}

// Function Definitions

void menu(){
   printf("\n-------------------------------");
	printf("\n|   PID Manager               |");
	printf("\n-------------------------------");
	printf("\n|Key  | Menu                  |");
	printf("\n-------------------------------");
	printf("\n|1    | Total PID's available |");
	printf("\n|2    | First PID available   |");
	printf("\n|3    | Create Processes      |");
	printf("\n|4    | Any Key to Exit       |\n");
	printf("-------------------------------\n");
	choice();
	getchar();
}

void choice(){
	c=0;
	char ch;
	printf("\nMenu Choice | 1 | 2 | 3 | exit |: ");
	ch=getchar();
	if(ch=='1'){
		int totalId=totalAvail();
		printf("-------------------------------");
		printf("\n| Total PID Available: %d     |",totalId);
		printf("\n-------------------------------\n");
	} else if(ch=='2'){
		int nextId=nextAvail();
		printf("-------------------------------");
		printf("\n| First Available PID: %d     |",nextId);
		printf("\n-------------------------------\n");
	} else if(ch=='3'){
		int num,time;
		//printf("\nCreate Process:\nInput-> Number of Process | Execution Time :");
		printf("\n-------------------------------");
		printf("\n| Create Process:             |");
		printf("\n-------------------------------\n");
		printf("Number of Process: ");
		scanf("%d",&num);
		printf("Execution Time: ");
		scanf("%d",&time);
		int a[3]={num,time,0};
		int valid=totalAvail();
		if(num>0 && num<=valid && time>0){
			printf("-------------------------");
			printf("\n|   %d Process created   |",num);
			printf("\n-------------------------\n");
			printf("|PID | Execution Time   |\n");
			for(int i=0;i<num;i++){
				pthread_t p;
				pthread_create(&p,NULL,createProcess,a);
			}
			back:
			if(c!=num)
				goto back;
			else{
				printf("-------------------------\n");	
			}
		} else{
			printf("\nInputs Invalid)");
		}
	} else{ 
		printf("Program Ends\n");
		exit(0);
	}
	getchar();
	choice();
}

int allocateMap(){
	for(int i=0;i<size;i++){
		bitMap[i]=0;
	}
	return 1;
}
int totalAvail(){
	int total=0; 
	for(int i=0;i<size;i++){
		if(bitMap[i]==0)
			total++;
	}
	return total;
}
int nextAvail(){
	for(int i=0;i<size;i++){
		if(bitMap[i]==0){
			int pid=start+i+1;
			return pid;
			}
	}
}
void *createProcess(void *a){
	int pid;
	int time=*((int *)a+1);
	int num=*((int *)a+0);
	int *count=((int *)a+2);
	*count=*count+1;
	pid=allocatePID(time);
	sleep(time);
	releasePID(pid);		
	return NULL;
}
int allocatePID(int time){
	int pid;
	for(int i=0;i<size;i++){
		if(bitMap[i]==0){
			pid=start+i+1;
			bitMap[i]=1;
			break;
			}
	}
	printf("|%d |   %d              |\n",pid,time);
	c++;
	return pid;
}
int releasePID(int pid){
	int i=pid-start-1;
	printf("Released PID :%d\n",pid);
	if(bitMap[i]==1){
		bitMap[i]=0;
		}
	return 1;
}
