#include <stdlib.h>
#include <stdio.h>

int main() {




    int n = 6; // Number of processes
    int m = 4; // Number of resources
    int alloc[6][4] = { { 0, 1, 0, 3 }, // P0	// Allocation Matrix
                        { 2, 0, 0, 3 }, // P1
                        { 3, 0, 2, 0 }, // P2
                        { 2, 1, 1, 5 }, // P3
                        { 0, 0, 2, 2 }, // P4
                        {1, 2 , 3, 1 } }; //P5

    int max[6][4] = { { 6, 4, 3, 4 }, // P0	// MAX Matrix
                      { 3, 2, 2, 4 }, // P1
                      { 9, 1, 2, 6 }, // P2
                      { 2, 2, 2, 8 }, // P3
                      { 4, 3, 3, 7 }, // P4
                      { 6, 2 , 6, 5 } }; //P5

    int avail[4] = { 2, 2, 2, 1 };      //Available resources
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
     printf("\n");

    int process__need_check = 0;
    char process_done[5] = {0,0,0,0,0};


    while(process__need_check <= 15){  //process__need_check ->5+4+3+2+1

        for(int p = 0; p < 5; p++) { //process
            int count = 0;
            for(int r = 0; r < 4; r++) {   // Resourch
                if (need[p][r] <= avail[r] & process_done[p] == 0){
                    count += 1;
                    }
                }

            if (count == 4){
                process_done[p] = 1;
                for(int r = 0; r < 4; r++) {   // available + allocation
                        avail[r] = alloc[p][r] + avail[r];
                        //printf("%d ",avail[r]);
                }
                printf("Process%d",p);
                printf("-->");
              }
          }

    process__need_check += 1;
    }

    int flag=1;
    for(int p = 0; p < 5; p++) {
        if (process_done[p]==0){
                flag=0;
                break;}
       // else{
         //   printf("%d ", process_done[p]);
       // }

    }




    if (flag == 1) {
        printf("safe");
    }
    else {
        printf("Deadlock Ahead");
    }

return 0;
}
