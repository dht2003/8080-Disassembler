#include "dissassembler.h"


int dissassembler8080p(code *program) {
    unsigned char &opcode = program->buffer[program->PC];
    int opbytes = 1;
    printf("%04x", program->PC);
    switch (*opcode) {
       case 0x00:
            printf("NOP");
            break;
        case 0x01:
            printf("LXI B,#$%0x2%0x2" , opcode[2] ,opbytes[1]);
            opbytes = 3;
            break;
        case 0x02:
            printf("STAX B");
            break;
        case 0x03:
            printf("INX B");
            break;
        case 0x04:
            printf("INR B");
            break;
        case 0x05:
            prinf("DCR B");
            break;
        case 0x06:
            printf("MVI B ,  #$%0x2" , opcode[1]);
            opbytes = 2;
            break;
        case 0x07:
            printf("RLC");
            break;
        case 0x08:
            printf("NOP");
            break;
        case 0x09:
            printf("DAD B");
            break;
        case 0x0a:
            printf("LDAX B");
            break;
        case 0x0b:
            printf("DCX B");
            break;
        case 0x0c:
            printf("INR C");
            break;
        case 0x0d:
            printf("DCR C");
            break;
        case 0x0e:
            printf("MVI C , #$%0x2",opcode[1]);
            opbytes = 2;
            break;
        case 0x0f:
            printf("RRC");
            break;
        case 0x10:
            printf("NOP");
            break;
        case 0x11:
            printf("LXI D , #$0x2%0x2" , code[2], code[1]);
            opbytes = 3;
            break;
        case 0x12:
            printf("STAX D");
            break;
    }
    printf("\n");
    program->PC += opbytes;
}

void freeCode(code *program) {
    free(program->buffer);
}

int fileSize(FILE *f) {
    fseek(f,0L,SEEK_END);
    int fsize = ftell(f);
    fseek(f , 0L , SEEK_SET);
    return fsize;
}