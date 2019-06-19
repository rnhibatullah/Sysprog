#include "./../include/warehouse.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

//Mutex warehouse_m;

struct warehouse{
    unsigned int flour, sugar, choclate;
    int locked;
    
    unsigned int sugar_taken, flour_taken, choclate_taken;
    //TODO
    //Initialize signals for get and deposit functions

    
};

warehouse* warehouse_create(){
    warehouse* new_warehouse = (warehouse*) malloc(sizeof(warehouse));
    if(new_warehouse== NULL){
        printf("Unable to allocate memory in function %s()\n",__func__);
        return NULL;
    }
    new_warehouse->flour = 0;
    new_warehouse->sugar = 0;
    new_warehouse->choclate = 0;
    new_warehouse->locked = 0;

    //signal()
    //wait()
    //TODO
    
    new_warehouse->choclate_taken = 0;
    new_warehouse->flour_taken = 0;
    new_warehouse->sugar_taken = 0;
    return new_warehouse;
}

//FUNCTIONS CALLED BY WORKER THREADS
//@param: amount of flour/sugar/choclate to be taken from warehouse wh

unsigned int get_choclate(unsigned int amount, warehouse* wh){
    
    wh->choclate_taken += amount;
    wh->choclate -= amount;
    
    
    return amount;
}

unsigned int get_flour(unsigned int amount, warehouse* wh){
    
    //TODO
    
    wh->flour_taken += amount;
    wh->flour -= amount;
    
    return amount;
}

unsigned int get_sugar(unsigned int amount, warehouse* wh){
    
    //TODO
    
    wh->sugar_taken += amount;
    wh->sugar -= amount;
        
    return amount;
}


//FUNCTIONS CALLED BY SUPPLIER THREADS
//@param: amount of flour/sugar/choclate to be store in warehouse wh
void deposit_choclate(unsigned int amount, warehouse* wh){
    //TODO
    
    if(wh->choclate + amount > MAX_STORE_CAPACITY){
        wh->choclate = MAX_STORE_CAPACITY;
    }else{
        wh->choclate += amount;
    }
    
    
    return;
}

void deposit_sugar(unsigned int amount, warehouse* wh){
    //TODO
    
    if(wh->sugar + amount > MAX_STORE_CAPACITY){
        wh->sugar = MAX_STORE_CAPACITY;
    }else{
        wh->sugar += amount;
    }
    
    return;
}

void deposit_flour(unsigned int amount, warehouse* wh){
    //TODO
    
    if(wh->flour + amount > MAX_STORE_CAPACITY){
        wh->flour = MAX_STORE_CAPACITY;
    }else{
        wh->flour += amount;
    }
    
    return;
}


//FUNCTIONS CALLED BY BAKERY
void lock_warehouse(warehouse* wh){
    //TODO
    wh->locked=1;

}

unsigned int get_used_resources(warehouse* wh, int type){
    if(type == SUGAR) return wh->sugar_taken;
    if(type == FLOUR) return wh->flour_taken;
    if(type == CHOCLATE) return wh->choclate_taken;
    return 0;
}


void warehouse_destroy(warehouse* wh){
    //TODO
    free(wh);
    return;
}
