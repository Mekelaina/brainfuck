#include <stdio.h>
#include <stddef.h>

#define CELL_COUNT 255


typedef struct {
    __uint8_t pointer;
    __uint8_t cells[CELL_COUNT];

} Environment;


void initEnv(Environment *env){
    env->pointer = 0;
    __uint8_t i = 0;
    for(;;) {
        env->cells[i] = 0;
        i++;
        if(i == 255){
            break;
        }
    }
}

void dumpEnv(Environment *env){
    printf("Pointer: %d\n", env->pointer);
    int count  = 0;
    for(int i = 0; i < 16; i++){
        printf("%x:%x |", i, 15);
        for(int j = 0; j < 16; j++){
            //printf("--- %d ---\n", temp);
            printf("%02x", env->cells[count]);
            count++;
            if(j == 15){
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}



void setVal(Environment *env, __uint8_t index, __uint8_t val){
    env->cells[index] = val;
    //printf("%d\n", env->cells[index]);
}

int main(){
    Environment env;
    initEnv(&env);
    setVal(&env, 100, 255);
    //printf("%d\n", env.cells[100]);
    dumpEnv(&env);

    return 0;
}