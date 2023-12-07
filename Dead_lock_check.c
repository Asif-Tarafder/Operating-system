#include <stdlib.h>
#include <stdio.h>

int main() {

    int n = 5; // Number of processes
    int m = 4; // Number of resources
	int alloc[5][4] = { { 0, 1, 0, 3 },
			   { 2, 0, 0, 0 },
			   { 3, 0, 2, 0 },
			   { 2, 1, 1, 5 },
			   { 0, 0, 2, 2 } };

	int max[5][4] = { { 6, 4, 3, 4 },
			{ 3, 2, 2, 1 },
			{ 9, 1, 2, 6 },
			{ 2, 2, 2, 8 },
			{ 4, 3, 3, 7 } };
	int avai[4] = {3,3,2,1};


	// Step1--> Need find out
	int need[n][m];

	for(int p = 0; p < 5; p++) {
        	for(int r = 0; r < 4; r++) {
            		need[p][r] = max[p][r] - alloc[p][r];
            		//printf("%d ", need[i][j]);
		}
	}

    printf("Need matrix\n");
    for(int p = 0; p < 5; p++) {
        	for(int r = 0; r < 4; r++) {
            		printf("%d ", need[p][r]);
		}
		printf("\n");
	}
     printf("\navailable\n");

    int process__need_check = 0;
    char process_done[5] = {0,0,0,0,0};


    while(process__need_check <= 15){  //process__need_check ->5+4+3+2+1

        for(int p = 0; p < 5; p++) { //process
            int count = 0;
            for(int r = 0; r < 4; r++) {   // Resourch
                if (need[p][r] <= avai[r] & process_done[p] == 0){
                    count += 1;
                    }
                }

            if (count == 4){
                process_done[p] = 1;
                for(int r = 0; r < 4; r++) {   // available + allocation
                        avai[r] = alloc[p][r] + avai[r];
                        printf("%d ",avai[r]);
                }
                printf("\n");
              }
          }

    process__need_check += 1;
    }

    int flag=1;
    for(int p = 0; p < 5; p++) {
        if (process_done[p]==0){
                flag=0;
                break;}
        //else{
          //  printf("%d ", process_done[p]);
        //}

    }




    if (flag == 1) {
        printf("safe");
    }
    else {
        printf("Deadlock Ahead");
    }

return 0;
}
