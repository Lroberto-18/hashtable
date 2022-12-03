#include <stdio.h>
#include <stdlib.h>
#define M 23
// Tabela de dispersão homogêneo encadeamento exterior

struct hash_keys{
    int key;
    //struct Data *data; caso queira atribur dados para as chaves.
    struct hash_keys *next;
};
typedef struct hash_keys H;

H *creat_element(int key){
    //criar elementos da tabela 
    H *h =(H*) malloc(sizeof(H));
    h->key=key;
    h->next=NULL;
    return h;
}
void creat_table(H *table[]){
    /* Criar tabela de dispersão.
     *  -1 indica que a posição da tabela é vazia.
     * H *table[] vetor de structs.
     */
    for(int i=0;i<M;i++){
        H *h =creat_element(-1);
        table[i]=h;
    }
}
int function_hash(int key){
    // f(x) = x mod 23
    return key%M;
}
int search_element(H *table[],int key){
    /**
     * Buscar chave na tabela.
     * retorna 0 caso não encontre a chave.
     * retorna 1 caso encontre a chave.
     */
    int control = 0;
    int index = function_hash(key);
    if(table[index]->key==-1){
        //NULL
        return control;
    }else{
       H *aux = table[index];
       while (control==0){
        if(aux->key==key){
            //Found
            //printf("%d \n", aux->key); imprimir chave 
            control=1;
        }
        aux=aux->next;
        if(aux==NULL) break;
       }
    }
    return control;
}
void insert(H *table[],int key){
    /**
     * Inserir chave na tabela.
     */
    int control = search_element(table,key);
    if(control==0){
        int index = function_hash(key);
        if(table[index]->key==-1){
            table[index]->key=key;
        }else{
            //Tratar colisões
            if(table[index]->next==NULL){
                H *h =creat_element(key);
                table[index]->next=h;
            }else{
                H *aux = table[index];
                while (aux->next!=NULL){
                    aux=aux->next;
                }
                H *h =creat_element(key);
                aux->next = h;
            }
        }
    }
}
void show(H *table[]){
    //Imprimir a tabela.
    printf("\n_____HASH TABLE____\n");
    for(int i=0;i<M;i++){
        printf("%d |%d|", i, table[i]->key);
        H *aux = table[i];
        while (aux->next!=NULL){
            printf("-> %d", aux->next->key);
            aux=aux->next;
        }
        printf("\n");
    }
}
void remove_element(H *table[],int key){
    /**
     * Remover elemento pela chave.
     */
    int control = search_element(table,key);
    if(control==1){
        int index = function_hash(key);
        if(table[index]->key==key){
            if(table[index]->next==NULL) table[index]->key = -1;
            else table[index] = table[index]->next;
        }else if(table[index]->next->key==key){
           table[index]->next = table[index]->next->next;
        }else{
            H *left = table[index]->next;
            H *aux = table[index]->next->next;
            do{if(aux->key==key){
                    left->next= aux->next;
                    free(aux);
                    break;
                }
                left=aux;
                aux=aux->next;
            }while(aux!=NULL);          
        }
    }
}
int main(){
    H *table_hash[M];

    int vector[] ={1,5,50,150,145,245,4323,34,445,664,43,5,49,
                    43,5345,435,4,5435,345,3,5452,576,7,77,67,98,
                    900,342,555,778,899,9827, 256,58,50,250,678,
                    9,870,166,2645,1,45,2,45,66,377,8,6457,993,
                    78,34,12,7,67,88,99,140,23434,12,21333,4353,
                    6765,765,230,2300,23000,411,412,413,10,12,13,33,56,
                    456,897,437,990,63,816,1542,1625,217,88,99,21
                };
    int len = sizeof(vector)/sizeof(vector[0]);//tamanho do vetor

    //Testes de funções
    creat_table(table_hash);
    for(int i=0; i<len;i++) insert(table_hash,vector[i]);//criar tabela com elementos de um vetor

    show(table_hash);
    remove_element(table_hash,411);
    show(table_hash);
return 0;
}