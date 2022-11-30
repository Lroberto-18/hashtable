#include <stdio.h>
#include <stdlib.h>
#define M 23

//homogenea exterior
struct hash{
    int key;
    struct hash *next;
};
typedef struct hash H;
void creat_table(H *table[]){
    for(int i=0;i<M;i++){
        H *h =(H*) malloc(sizeof(H));
        h->key=-1;
        h->next=NULL;
        table[i]=h;
    }
}
int function_hash(int key){
    return key%M;
}
void insert(H *table[],int key){
    int index = function_hash(key);
    if(table[index]->key==-1){
        table[index]->key=key;
    }else{
        printf("COLISÂO\n");
        if(table[index]->next==NULL){
            H *h =(H*) malloc(sizeof(H));
            h->key=key;
            h->next=NULL;
            table[index]->next=h;
        }else{
            H *aux = table[index];
            while (aux->next!=NULL){
                aux=aux->next;
            }
            H *h =(H*) malloc(sizeof(H));
            h->key=key;
            h->next=NULL;
            aux->next = h;
        }
    }
}
void show(H *table[]){
    printf("HASH TABLE\n");
    for(int i=0;i<M;i++){
        printf("%d |%d|", i, table[i]->key);
        H *aux = table[i];
        while (aux->next!=NULL)
        {
            printf("-> %d", aux->next->key);
            aux=aux->next;
        }
        printf("\n");
    }
}
void main(){
    H *table[M];
    int vector[] ={1,5,50,150,145,245,4323,34,445,664,43,5,45,43,5345,435,4,5435,345,3,5452,576,7,77,
                    900,342,555,778,899,9827, 256,58,50,250,870,166,2645,1,45,2,45,66,377,8,6457,993
                };
    int len = sizeof(vector)/sizeof(vector[0]);
    creat_table(table);
    for(int i=0; i<len;i++) insert(table,vector[i]);
    //show(table);
    //insert(table,145);
    //insert(table,245);
    //insert(table,345);
    show(table);
}