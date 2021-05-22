#include "dissassembler.h"

int main(int argc , char ** argv){
    if (argc != 2) { 
        printf("usage : ./dissassembler [FILE-Name]\n");
        exit(1);
    }
    FILE *f = fopen(argv[1] , "rb");
    if (f == NULL) {
        printf("can't open FILE");
        exit(1);
    }
    code program = {.PC = 0 };
    int fsize = fileSize(f);
    program.buffer = malloc(fsize);
    fread(program.buffer , fsize , 1 , f);
    fclose(f);
    while(program.PC < fsize) 
        dissassembler8080p(&program);
    freeCode(&program);
    return 0;
    

}