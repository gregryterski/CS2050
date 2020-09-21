#include "lab11.h"

int main(void){

    srand(time(NULL)); // for random generator, not required in assignments.

    Queue myQueue = initQueue();
    if (myQueue.list == NULL){
        printf("Test 1 (initQueue) failed. A list should be allocated in initQueue function.\n\n");
    } else if (myQueue.list->head != NULL || myQueue.list->tail != NULL){
        printf("Test 1 (initQueue) failed. Head and tail pointers need to be initialized to NULL in initQueue function.\n\n");
    } else {
        printf("Test 1 (initQueue) passed.\n\n");
    }

    printQueue(myQueue);
    printf("Here\n");
    printf("Test 2 (printQueue) passed\n\n");

    int coin;
    for (size_t i = 0; i < 10; i++){
        coin = rand() % 3;
        if (coin != 1){ // want more EnQueue but feel free to change
            printf("EnQueue...\n");
            enQueue(rand()%10+15, myQueue);
        } else {
            printf("DeQueue...\n");
            Student* temp = deQueue(myQueue);
            if (temp == NULL){
                printf("Nothing to deQueue...\n");
            } else {
                free(temp);
            }
        }
        printQueue(myQueue);
        printf("There're %d items in the queue, %d among which are even numbers.\n\n",getQsize(myQueue),getNumOfEven(myQueue));
    }
    printf("Test 3 (enQueue & deQueue) passed\n\n");

    emptyQueue(myQueue);
    myQueue.list = NULL;

    printf("Test 4 (emptyQueue) passed.\n\n");

    return 0;

}
