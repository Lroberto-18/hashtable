#include <stdio.h>
#include <stdlib.h>
#define LEN 50
//het. encademento exterior

void creat(int table[]){
    for(int i=0;i<LEN;i++) table[i]=-1;
}
void show(int table[]){
    printf("HASH TABLE\n");
    for(int i=0;i<LEN;i++) printf("%d -> %d \n", i, table[i]);
}
int function_hash(int key){
    return key%23;
}
void insert(int table[],int key){
    int index = function_hash(key);
    if(table[index]==-1) table[index]=key;
    else printf("COLISÂO\n");
}
int search(int table[],int key){
    int index = function_hash(key);
    if(table[index]==-1) return-1;
    else printf("ID = %d KEY = %d\n",index, table[index]);
}
void main(){
    int table[LEN];
    creat(table);
    insert(table,67);
    show(table);
    //insert(table,67);
    //printf("%d ", search(table,67));
    search(table,67);
}