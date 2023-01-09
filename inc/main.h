#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#define ROW 9
#define COL 9
#define BLUE 81
#define YELLO 218

int fromx, fromy;
int tox, toy;
int inputx, inputy, outputx, outputy;
char firstinput;
int count=0;
int dudangyongcount=0;
int end=0;
char plate[ROW][COL];
char saveminor[500], savemajor[500];
int saveminloc=0, savemajloc=0;
void ini();
void print(char chess);
void movecheck();
int xiang();
int guei();
int yin();
int jin();
int wang();
int fei();
int jiao();
int bu();
void canmove();
void cannotmove();
void printColour(int color, char* str);
int eat(char p);
extern char *optarg;
extern int optind, opterr, optopt;
FILE *file;
int z;
int status;
struct node{
    int ix, iy, ox, oy;
    char chessori, chessalt;
    struct node* next;
    struct node* prev;
};

typedef struct node cun;
typedef struct node* cunptr;
cunptr current;
cunptr start;

#endif