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

// Declaring required functions for program;
int allocateMap();
int allocatePID();
int releasePID();
void *createProcess();
int totalAvail();
int nextAvail();
// Menu Functions
void menuA();
void menuB();
void choiceB();


// Main Function
int main(){
	printf("Process ID Manager");
	menuA();
	printf("\nProgram Ends\n");
	return 0;
}

// Function Definitions
void menuA(){
   printf("\nMenu:");
	printf("\nPress 1: Start PID Manager");
	printf("\nPress Any Key: Exit");
	char ch;
	printf("\nMenu Choice: ");
	ch=getchar();
	if(ch=='1'){
		allocateMap();
		menuB();
	} else{ 
		printf("\nProgram Ends\n");
		exit(0);
	}
}

void menuB(){
   printf("\nMenu:");
	printf("\n1. Total PID's available");
	printf("\n2. First PID available");
	printf("\n3. Create Processes");
	printf("\n4. Press any key to Exit.");
	choiceB();
}

void choiceB(){
	char ch;
	printf("\n\nMenu Choice (|1|2|3|): ");
	getchar();
	ch=getchar();
	if(ch=='1'){
		int totalId=totalAvail();
		printf("\nTotal Available PID: %d",totalId);
		choiceB();
	} else if(ch=='2'){
		int nextId=nextAvail();
		printf("\nFist Available PID: %d",nextId);
		choiceB();
	} else if(ch=='3'){
		int num,time;
		printf("\nCreate Process:\nInput-> Number of Process | Execution Time :");
		scanf("%d %d",&num,&time);
		int valid=totalAvail();
		if(num>0 && num<=valid && time>0){
			printf("\nProcesses created: ");
			for(int i=0;i<num;i++){
				createProcess(i,time);
			}
		} else{
			printf("\nInputs Invalid)");
		}
		choiceB();
	}
	else{ 
		printf("Program Ends\n");
		exit(0);
	}
}

int allocateMap(){
	for(int i=0;i<size;i++){
		bitMap[i]=0;
	}
	printf("\nPID Manager Starts\nRange: %d - %d(Inclusive)\nTotal Available: %d",start+1,end,size);
	return 1;
}

int totalAvail(){
}
int nextAvail(){
}
void *createProcess(int num,int time){
	printf("\nProcess PID: %d\nExecution time: %d",num,time);
}
int allocatePID(){
}
int releasePID(int pid){
}
