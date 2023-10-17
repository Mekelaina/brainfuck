#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define CELL_COUNT 255



//-----------------------------------
//           File I/O
//-----------------------------------

char* buffer; 
int fileLen;

char* slurpFile(char* filename){
    FILE *fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error: counldnt open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    long numbytes = ftell(fp);

    fseek(fp, 0L, SEEK_SET);

    buffer = (char*)calloc(numbytes, sizeof(char));

    if(buffer == NULL){
        printf("Error: Couldnt allocat memory for file.\n");
        exit(1);
    }

    fread(buffer, sizeof(char), numbytes, fp);
    fclose(fp);

    //printf("Test dump:\n%s", buffer);

    fileLen = sizeof(char) * numbytes;

    return buffer;
}

void cleanup(){
    free(buffer);
}



//-----------------------------------
//          Interpreter
//-----------------------------------

typedef struct {
    __uint8_t pointer;
    __uint8_t cells[CELL_COUNT];
    __uint8_t jumpstack[CELL_COUNT];
    __uint8_t sp;
} Environment;


void parse(char* content){
    for(int i = 0; i < fileLen; i++){
        char c = content[i];
        
        switch(c){
            case '>':
            case '<':
            case '+':
            case '-':
            case ',':
            case '.':
            case '[':
            case ']':
            default:
        }
    }
}

void initEnv(Environment *env){
    env->pointer = 0;
    __uint8_t i = 0;
    for(;;) {
        env->cells[i] = 0;
        env->jumpstack[i] = 0;
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
    //setVal(&env, 100, 255);
    //printf("%d\n", env.cells[100]);
    //dumpEnv(&env);

    char* content = slurpFile("text.bf");
    parse(content);
    
    cleanup();

    return 0;
}