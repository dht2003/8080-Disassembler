// File : dissassembler.h 
// Description: Interface of Code and dissassembler functions 

#ifndef DISSASSEMBLER_H
#define DISSASSEMBLER_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Code {
    int PC;
    unsigned char *buffer;
} code;

 
int dissassembler8080p(code *program);

void freeCode(code *program);

int fileSize(FILE *f);


#endif