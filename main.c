#include "dissassembler.h"

int main(int argc , char ** argv){
    if (argc < 2 || argc > 3) {
        printf("usage : ./dissassembler [INPUT_FILE] [OUTPUT_FILE]\n");
        exit(1);
    }
    FILE * fp , *f = fopen(argv[1] , "rb");
    if (f == NULL) {
        printf("can't open FILE");
        exit(1);
    }
    if (argc == 3){
    if ((fp = freopen(argv[2],"w",stdout)) == NULL) {
        printf("can't open output file");
        exit(1);
    } }
    
    code program = {.PC = 0 };
    int fsize = fileSize(f);
    program.buffer = malloc(fsize);
    fread(program.buffer , fsize , 1 , f);
    fclose(f);
    while(program.PC < fsize) 
        dissassembler8080p(&program);
    freeCode(&program);
    if (argc == 3) fclose(fp);
    return 0;
}