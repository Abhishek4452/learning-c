/* STATUS - NOT YET COMPLETE
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// macros
#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct{
    char name[MAX_NAME];
    int age;
    // --- other stuff
}person;


/*🔹 What it actually means
👉 hash_table is an array of pointers to person
hash_table → an array
Each element → a pointer (person *)
Size of array → TABLE_SIZE*/
person *hash_table[TABLE_SIZE];

/* function -hash
status - collision occur during hashing
description - - i want to take my function known by the name so i will take name
*/
unsigned int hash(char *name){  
    size_t length  = strnlen(name,MAX_NAME);
    unsigned int hash_value = 0;
    for (int i=0;i<length;i++){
        hash_value += name[i];
        hash_value = (hash_value*name[i]) % TABLE_SIZE;
         /// printf("name i : %u \n",name[i]); goves us ascii value corresponding to input
    }
    return hash_value;
}
/*function - init_hash_table
status - 
description - set the table value to NULL
*/
void init_hash_table(){
    for (int i= 0;i<TABLE_SIZE;i++){
        hash_table[i] = NULL;

    }
}

void print_table(){
    printf("\n start \n");
    for (int i =0;i<TABLE_SIZE;i++){
        if(hash_table[i] == NULL){
            printf("\t %d \t ---- \n",i);
        }
        else{
            printf("\t %d \n %s \n",i,hash_table[i]->name);
        }
        
    }
    printf("\n END \n");
}

/* function  - hash_table_insert 
status - done
description - this function return 0 or 1 based on if we truely add 
               value into it or not ?
*/

bool hash_table_insert(person *p){
    if(p == NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] != NULL){
        return false;
    }
    hash_table[index] = p;
    return true;
}

/// find a person in the table by tehir name
person *hash_table_lookup(char *name){
    int index = hash(name);
    if (hash_table[index] != NULL && (strncmp(hash_table[index]->name,name,TABLE_SIZE)==0)){
        return hash_table[index];
    }
    else{
        return NULL;
    }
}


int main(void){
    init_hash_table(); // to make sure that we start with the clean hash table
    print_table();

    person jacob = {.name = "jacob",.age = 256};
    person kate = {.name = "kate",.age = 27};
    person mpho = {.name = "mpho",.age = 66};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);

    print_table();

    person *tmp =hash_table_lookup("mpho");
    if (tmp == NULL){
        printf("NOT found ! \n");
    }else{
        printf(" data already exist with this name %s. \n",tmp->name);
    }

    tmp =hash_table_lookup("george");
    if (tmp == NULL){
        printf("NOT found ! \n");
    }else{
        printf(" data already exist with this name %s. \n",tmp->name);
    }

 /*   printf("abhishek => %u \n",hash("abhishek"));
    printf("Rahul => %u \n",hash("Rahul"));
    printf("akhil => %u \n",hash("akhil"));
    printf("nishtha => %u \n",hash("nishtha"));
    printf("jay => %u \n",hash("jay"));
    printf("manisha => %u \n",hash("manisha"));
    printf("anisha => %u \n",hash("anisha"));
    printf("suyash => %u \n",hash("suyash"));
printf("strnlen => %u \n",strlen("suyash")); // return 6 for suyash
/*   Important Points about strlen()
The following points should be kept in mind while using strlen():

strlen() does not count the NULL character '\0'.
The time complexity of strlen() is O(n), where n is the number of characters in the string.
Its return type is size_t ( which is generally unsigned int ).
*/
 //   printf("strnlen => %u \n",strnlen("suyash",MAX_NAME)); // return 6 for suyash
/*| Case                       | `strlen`             | `strnlen(s, maxlen)`      |
| -------------------------- | -------------------- | ------------------------- |
| Normal string              | Returns full length  | Returns full length       |
| String shorter than maxlen | —                    | Returns length            |
| String longer than maxlen  | —                    | Returns `maxlen`          |
| Missing `'\0'`             | ❌ Undefined behavior | ✅ Returns `maxlen` safely |

*/

return 0;
}