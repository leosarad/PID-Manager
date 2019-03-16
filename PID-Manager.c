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
	} else{ 
		printf("\nProgram Ends\n");
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
void *createProcess(){
}
int allocatePID(){
}
int releasePID(int pid){
}
