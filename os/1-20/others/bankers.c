#include<stdio.h>
#include<stdlib.h>

int main() {
	
	printf("\nEnter the number of processes: ");
	int p = 0;
	scanf("%d",&p);
	
	printf("\nEnter the number of resources: ");
	int r = 0;
	scanf("%d",&r);
	
	//now matrix
	//allocation, max
	//available array of r size

	//first get the max
	int max[p][r];
	printf("\nEnter the max matrix: ");
	for(int i = 0; i < p; i++) {
		for(int j = 0; j < r; j++) {
				printf("\nmax[%d][%d]: ",i,j);
				scanf("%d",&max[i][j]);
		}
	}
	
	//allocation matrix
	int allocation[p][r];
	printf("\nEnter the allocation matrix");
	for(int i = 0; i < p; i++) {
		for(int j = 0; j < r; j++) {
				printf("\nallocation[%d][%d]: ",i,j);
				scanf("%d",&allocation[i][j]);
		}
	}
	int finished[p];
	for(int i = 0; i < p;i++) finished[i] = 0;
	
	//available array
	printf("\nEnter the available resource count");
	int available[r];
	for(int i = 0; i < r; i++) {
		scanf("%d",&available[i]);
	}
	
	//now calculate need
	printf("\nCalculating the need matrix");
	int need[p][r];
	for(int i = 0; i < p; i++) {
		int j;
		for(j = 0; j < r; j++) {
				need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	
	//now run the algorithm
	//run a while loop
	//in that first initialize found = 0
	int safe[p];
	int counter = 0;
	while(counter < p) {
		int found = 0;
		for(int i = 0; i < p; i++) {
			if(finished[i] == 0) {
			int j;
			for(j = 0; j < r; j++ ) {
					if(need[i][j] > available[j]) break;
			}
			if(j == r) {
				//execute the process
				for(int k = 0; k < r; k++)
					available[k] += allocation[i][k];
				
				//mark as finished and enter in the safe sequence
				finished[i] = 1;
				safe[counter++] = i;
				found = 1;
			}
		}
	}
	if(found != 1) {
		printf("\nThe system is not in the safe state"); return 0;
	}
}
	printf("\nThe safe state is\n");
	for(int i = 0; i < p; i++) {
			printf("%d -> ",safe[i]);
	}
	return 0;
}
