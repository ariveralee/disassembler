#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DisFunctions.h"

//First digit commands 
#define HALT    0
#define LD      1
#define ST      2
#define ADD     3 
#define SUB     4
#define LDA     5
#define JMP     6
#define SIM2    7  //7000 Level commands
#define SIM3    8  //8000 Level commands 

//Second digit commands 7000 Level
#define SKIP 0
#define SKEQ 1
#define SKNE 2
#define SKGT 3 
#define SKGE 4
#define SKLT 5
#define SKLE 6

//Second digit commands 8000 Level
#define IN    0
#define OUT   1
#define CLR   2
#define INC   3
#define DEC   4
#define NEG   5
#define SHFTL 6
#define SHFTR 7


void assembly(int addr[], int opCode[], char *inst[], int *instrAddress[], int lineCount) {
  int digit1, digit2, digit3, digit4, digit34, halted = 0;
 
  for(int i = 0; i < lineCount; i++) {
   /*Parse the codes into digits 
     if code is 1024, digit1 = 1, digit2 = 0, digit3 = 2, digit4 = 4, digit34 = 24*/
    digit1 = opCode[i] / 1000;
    digit2 = (opCode[i] / 100) % 10;
    digit3 = (opCode[i] / 10) % 10;
    digit4 = opCode[i] % 10;
    digit34 = opCode[i] % 1000;

    //Process the codes by opCode 
    switch (digit1) {
      case HALT: 
        if (!halted) {
            	halted = 1;
            	inst[i] = malloc(5 * sizeof(char));
            	strcpy(inst[i], "HALT");
            	instrAddress[i] = NULL;
        } 
        else {
            	inst[i] = malloc(6 * sizeof(char));
            	strcpy(inst[i], ".word");
            	instrAddress[i] = NULL;
        }
       
        break;
      case LD: 
        inst[i] = malloc(3);
        strcpy(inst[i], "LD");
        instrAddress[i] = malloc(sizeof(int));
        *instrAddress[i] = digit34;
        break;
      case ST:
        inst[i] = malloc(3);
        strcpy(inst[i], "ST");
        instrAddress[i] = malloc(sizeof(int));
        *instrAddress[i] = digit34;
        break;
      case ADD:
        inst[i] = malloc(4);
        strcpy(inst[i], "ADD");
        instrAddress[i] = malloc(sizeof(int));
        *instrAddress[i] = digit34;
        break;
      case SUB:
        inst[i] = malloc(4);
        strcpy(inst[i], "SUB");
        instrAddress[i] = malloc(sizeof(int));
        *instrAddress[i] = digit34;
        break;
      case JMP:
        inst[i] = malloc(4);
        strcpy(inst[i], "JMP");
        instrAddress[i] = malloc(sizeof(int));
        *instrAddress[i] = digit34;
        break;
    
    // SIM 2 needs a second digit to work
    case SIM2: 
      
      switch (digit2) {
        case SKIP: 
        	inst[i] = malloc(5);
        	strcpy(inst[i], "SKIP");
        	instrAddress[i] = NULL;
        	break;
        case SKEQ:
        	inst[i] = malloc(5);
        	strcpy(inst[i], "SKEQ");
        	instrAddress[i] = NULL;
        	break;
        case SKNE: 
        	inst[i] = malloc(5);
        	strcpy(inst[i], "SKNE");
        	instrAddress[i] = NULL;
        	break;
        case SKGT:
        	inst[i] = malloc(5);
        	strcpy(inst[i], "SKGT");
        	instrAddress[i] = NULL;
        	break;
        case SKGE:
        	inst[i] = malloc(5);
        	strcpy(inst[i], "SKGE");
        	instrAddress[i] = NULL;
        	break;
        case SKLT:
        	inst[i] = malloc(5);
        	strcpy(inst[i], "SKLT");
        	instrAddress[i] = NULL;
        	break;
        case SKLE:
        	inst[i] = malloc(5);
        	strcpy(inst[i], "SKLE");
        	instrAddress[i] = NULL;
        	break;
    
        default: 
        	inst[i] = malloc(6);
        	strcpy(inst[i], "Error");
        	instrAddress[i] = NULL;
        	break;
      }//end inner switch
          break;
    
    case SIM3: 
      
      switch (digit2) {
        case IN: 
        	inst[i] = malloc(3);
        	strcpy(inst[i], "IN");
        	instrAddress[i] = NULL;
        	break;
        case OUT: 
        	inst[i] = malloc(4);
        	strcpy(inst[i], "OUT");
        	instrAddress[i] = NULL;
        	break;
        case CLR: 
        	inst[i] = malloc(4);
        	strcpy(inst[i], "CLR");
        	instrAddress[i] = NULL;
        	break;
        case INC: 
        	inst[i] = malloc(4);
        	strcpy(inst[i], "INC");
        	instrAddress[i] = NULL;
        	break;
        case DEC: 
        	inst[i] = malloc(4);
        	strcpy(inst[i], "DEC");
        	instrAddress[i] = NULL;
        	break;
        case NEG: 
        	inst[i] = malloc(4);
        	strcpy(inst[i], "NEG");
        	instrAddress[i] = NULL;
        	break;
        case SHFTL: 
        	inst[i] = malloc(6);
        	strcpy(inst[i], "SHFTL");
        	instrAddress[i] = NULL;
        	break;
        case SHFTR: 
        	inst[i] = malloc(6);
        	strcpy(inst[i], "SHFTR");
        	instrAddress[i] = NULL;
        	break;
        default: 
        	inst[i] = malloc(6);
        	strcpy(inst[i], "Error");
        	instrAddress[i] = NULL;
      }//end of switch
          break;
        default: 
          inst[i] = malloc(1);
          strcpy(inst[i], "");
          instrAddress[i] = NULL;
          break;
    }//end outer switch
 }//End for 

  return;
}
