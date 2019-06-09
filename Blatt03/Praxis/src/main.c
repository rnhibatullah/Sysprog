#include <stdio.h>
#include <stdlib.h>

#include "../include/task.h"
#include "../include/MLF.h"
#include "../include/Queue.h"
#include "../include/RR.h"
#include "../include/SJN.h"
#include "../include/LCFS-PR.h"
#include "../include/SRTN.h"

int main(int argc, char **argv)
{
    if (init_LCFS_PR() == 0) {
        puts("LCFS-PR");
        arrive_LCFS_PR(0,3);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        arrive_LCFS_PR(1,6);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        arrive_LCFS_PR(2,4);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        arrive_LCFS_PR(3,5);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        arrive_LCFS_PR(4,2);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ",running_task->id);
        tick_LCFS_PR();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
    }

    if (init_SRTN() == 0) {
        puts("\nSRTN");
        arrive_SRTN(0,3);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        arrive_SRTN(1,6);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        arrive_SRTN(2,4);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        arrive_SRTN(3,5);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        arrive_SRTN(4,2);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ",running_task->id);
        tick_SRTN();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        free_SRTN();
    }

    if (init_RR(2) == 0) {
        puts("\nRR");
        arrive_RR(0,3);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        arrive_RR(1,6);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        arrive_RR(2,4);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        arrive_RR(3,5);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        arrive_RR(4,2);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ",running_task->id);
        tick_RR();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        free_RR();
    }

    if (init_SJN() == 0) {
        puts("\nSJN");
        arrive_SJN(0,3);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        arrive_SJN(1,6);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        arrive_SJN(2,4);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        arrive_SJN(3,5);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        arrive_SJN(4,2);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ",running_task->id);
        tick_SJN();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        free_SJN();
    }

    if (init_MLF(1,3) == 0) {
        puts("\nMLF");
        arrive_MLF(0,3);
        tick_MLF();
        printf("%i ",running_task->id);
        tick_MLF();
        printf("%i ",running_task->id);
        arrive_MLF(1,6);
        tick_MLF();
        printf("%i ",running_task->id);
        tick_MLF();
        printf("%i ",running_task->id);
        arrive_MLF(2,4);
        tick_MLF();
        printf("%i ",running_task->id);
        tick_MLF();
        printf("%i ",running_task->id);
        arrive_MLF(3,5);
        tick_MLF();
        printf("%i ",running_task->id);
        tick_MLF();
        printf("%i ",running_task->id);
        arrive_MLF(4,2);
        tick_MLF();
        printf("%i ",running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        tick_MLF();
        printf("%i ", running_task == NULL ? -1 : running_task->id);
        free_MLF();
    }
    return 0;
}
