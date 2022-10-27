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
int count=0;
char plate[ROW][COL];
void ini();
void print();
void movecheck();
int xiang();
int guei();
int yin();
int jin();
int wang();
int fei();
int jiao();
int bu();
int canmove();
void cannotmove();
void printColour(int color, char* str);

int main(void){
    ini();
    print();
    while(1){
        movecheck();
        system("clear");
        print();
    }
    
    return 0;
}

void ini(){
    int i,j;
    for ( i=0 ; i<ROW ; i++){
        for ( j=0 ; j<COL ; j++){

            if( (i==0 && j==0)||(i==0 && j==8)){
                plate[i][j]='x';
            } 
            else if((i==8 && j==0)||(i==8 && j==8)){
                plate[i][j]='X';
            }
            else if( (i==0 && j==1)||(i==0 && j==7)){
                plate[i][j]='g';
            } 
            else if((i==8 && j==1)||(i==8 && j==7)){
                plate[i][j]='G';
            }
            else if( (i==0 && j==2)||(i==0 && j==6)){
                plate[i][j]='y';
            } 
            else if((i==8 && j==2)||(i==8 && j==6)){
                plate[i][j]='Y';
            }
            else if( (i==0 && j==3)||(i==0 && j==5)){
                plate[i][j]='k';
            } 
            else if((i==8 && j==3)||(i==8 && j==5)){
                plate[i][j]='K';
            }
            else if( (i==0 && j==4)){
                plate[i][j]='w';
            } 
            else if((i==8 && j==4)){
                plate[i][j]='W';
            }
            else if( (i==1 && j==1)){
                plate[i][j]='f';
            } 
            else if((i==7 && j==7)){
                plate[i][j]='F';
            }
            else if( (i==1 && j==7)){
                plate[i][j]='j';
            } 
            else if((i==7 && j==1)){
                plate[i][j]='J';
            }
            else if(i==2){
                plate[i][j]='b';
            }
            else if(i==6){
                plate[i][j]='B';
            }
            else{
                plate[i][j]=' ';
            }

        }
    }
}

void print(){
    printf(" 9 8 7 6 5 4 3 2 1\n");
    for(int i=0 ; i<ROW ; i++ ){
        for( int j=0 ; j<COL ; j++){
            switch(plate[i][j]){
            case'x':
                printColour(BLUE,"香");
                break;
            case'g':
                printColour(BLUE,"桂");
                break;
            case'y':
                printColour(BLUE,"銀");
                break;
            case'k':
                printColour(BLUE,"金");
                break;
            case'w':
                printColour(BLUE,"王");
                break;
            case'f':
                printColour(BLUE,"飛");
                break;
            case'j':
                printColour(BLUE,"角");
                break;
            case'b':
                printColour(BLUE,"步");
                break;
            case'X':
                printColour(YELLO,"香");
                break;
            case'G':
                printColour(YELLO,"桂");
                break;
            case'Y':
                printColour(YELLO,"銀");
                break;
            case'K':
                printColour(YELLO,"金");
                break;
            case'W':
                printColour(YELLO,"玉");
                break;
            case'F':
                printColour(YELLO,"飛");
                break;
            case'J':
                printColour(YELLO,"角");
                break;
            case'B':
                printColour(YELLO,"步");
                break;
            default:
                printf("  ");
                break;
            }
            

        }
        printf("%d",i+1);
        printf("\n");
    }
    
}

void movecheck(){
    
    printf("輸入移動的X座標與Y座標\n");
    scanf("%d%d",&fromx,&fromy);
    inputx=9-fromx;
    inputy=fromy-1;
    if(plate[inputy][inputx]==' '){
        printf("這裡是空的\n");
    }
    else{
        printf("輸入目標X座標與Y座標\n");
        scanf("%d%d",&tox,&toy);
        outputx=9-tox;
        outputy=toy-1;
        if(plate[inputy][inputx]=='x' || plate[inputy][inputx]=='X'){
            xiang();
        }
        else if(plate[inputy][inputx]=='g' || plate[inputy][inputx]=='G'){
            guei();
        }
        else if(plate[inputy][inputx]=='y' ||plate[inputy][inputx]=='Y'){
            yin();
        }
        else if(plate[inputy][inputx]=='k' ||plate[inputy][inputx]=='K'){
            jin();
        }
        else if(plate[inputy][inputx]=='w' || plate[inputy][inputx]=='W'){
            wang();
        }
        else if(plate[inputy][inputx]=='f' || plate[inputy][inputx]=='F'){
            fei();
        }
        else if(plate[inputy][inputx]=='j' || plate[inputy][inputx]=='J'){
            jiao();
        }
         else if(plate[inputy][inputx]=='b' || plate[inputy][inputx]=='B'){
             bu();
        }
    }

}

int xiang(){
   
    if(count%2==0){
        if(inputx==outputx && inputy>outputy && plate[outputy][outputx]==' '){
           int k=0;
           for(int i=inputy-1; i>=outputy; i--){
                if(plate[i][outputx]!=' '){
                    k++;
                }
            }
            if(k==0){
                canmove();
            }
            else{
                cannotmove();
            }
        }
        else if(plate[outputy][outputx]>='a' && plate[outputy][outputx]<='z'){

        }   
        else{
            cannotmove();
        }
    }
    else{
        if(inputx==outputx && inputy<outputy && plate[outputy][outputx]==' '){
            int k=0;
            for(int i=inputy+1; i<=outputy; i++){
                if(plate[i][outputx]!=' '){
                    k++;
                }
            }
            if(k==0){
                canmove();
            }
            else{
                cannotmove();
            }
        }
        else if(plate[outputy][outputx]>='A' && plate[outputy][outputx]<='Z'){

        }
        else{
            cannotmove();
        }
    }
}

int guei(){
    
    if(count%2==0){
        if((inputx-1==outputx || inputx+1==outputx) && inputy-2==outputy && plate[outputy][outputx]==' '){
            canmove();
        }
        else if(plate[outputy][outputx]>='a' && plate[outputy][outputx]<='z'){


        }
        else{
            cannotmove();
        }
        
    }
    else{
        if((inputx-1==outputx || inputx+1==outputx) && inputy+2==outputy && plate[outputy][outputx]==' '){
            canmove();

        }
        else if(plate[outputy][outputx]>='A' && plate[outputy][outputx]<='Z'){

            
        }
        else{
            cannotmove();

        }
    }  
}

int yin(){
    if(abs(inputx-outputx)<2 && abs(inputy-outputy)<2){
        if(count%2==0){
            if((inputx-1==outputx && inputy==outputy) || (inputx+1==outputx && inputy==outputy) || (inputx==outputx && inputy+1==outputy)){
                cannotmove();
            }
            else{
                canmove();
            }
        }
        else{
            if((inputx-1==outputx && inputy==outputy) || (inputx+1==outputx && inputy==outputy) || (inputx==outputx && inputy-1==outputy)){
                cannotmove();
            }
            else{
                canmove();
            }
        }
    }
    else{
        cannotmove();
    }
}

int jin(){
    if(abs(inputx-outputx)<2 && abs(inputy-outputy)<2){
        if(count%2==0){
            if((inputx-1==outputx && inputy+1==outputy) || (inputx+1==outputx && inputy+1==outputy)){
                cannotmove();
            }
            else{
                canmove();
            }
        }
        else{
            if((inputx-1==outputx && inputy-1==outputy) || (inputx+1==outputx && inputy-1==outputy)){
                cannotmove();
            }
            else{
                canmove();
            }
        }
    }
    else{
        cannotmove();
    }
}

int wang(){
    if(abs(inputx-outputx)<2 && abs(inputy-outputy)<2){
        if(plate[outputy][outputx]==' '){
            canmove();
        }
        else if(count%2==0 && plate[outputy][outputx]>='a' && plate[outputy][outputx]<='z'){
         
        }
        else if(count%2!=0 && plate[outputy][outputx]>='A' && plate[outputy][outputx]<='Z'){
        
        }
        else{
            cannotmove();
        }
    }
    else{
        cannotmove();
    }
}

int fei(){
    if((inputx==outputx || inputy==outputy) && plate[outputy][outputx]==' '){
        int k=0;
        if(inputx==outputx && inputy>outputy){
            for(int i=inputy-1; i>outputy; i--){
                if(plate[i][outputx]!=' '){
                    k++;
                    printf("%d\n",k);
                }
            }
        }
        else if(inputx==outputx && inputy<outputy){
            for(int i=inputy+1; i<outputy; i++){
                if(plate[i][outputx]!=' '){
                    k++;
                                        printf("%d\n",k);

                }
            }
        }
        else if(inputx<outputx && inputy==outputy){
            for(int i=inputx+1; i<outputx; i++){
                if(plate[outputy][i]!=' '){
                    k++;
                                        printf("%d\n",k);

                }
            }
        }
        else if(inputx>outputx && inputy==outputy){
            for(int i=inputx-1; i>outputx; i--){
                if(plate[outputy][i]!=' '){
                    k++;
                                        printf("%d\n",k);

                }
            }
        }

        if(k==0){
            canmove();
        }
        else{
            cannotmove();
        }
    }
    else if(count%2==0 && plate[outputy][outputx]>='a' && plate[outputy][outputx]<='z' && (inputx==outputx || inputy==outputy)){
         
    }
    else if(count%2!=0 && plate[outputy][outputx]>='A' && plate[outputy][outputx]<='Z' && (inputx==outputx || inputy==outputy)){
        
    }
    else{
        cannotmove();
    }

}

int jiao(){
   
    if(abs(inputx-outputx)==abs(inputy-outputy) ){
        int k=0;
        if(inputx-outputx>0 && inputy-outputy>0){
            for(int i=inputx-1, j=inputy-1; i>=outputx, j>=outputy ; i--, j--){
                if(plate[j][i]!=' '){
                    k++;
                }
            }
        }
        else if(inputx-outputx>0 && inputy-outputy<0){
            for(int i=inputx-1, j=inputy+1 ; i>=outputx, j<=outputy ; i--, j++){
                if(plate[j][i]!=' '){
                    k++;
                }
            }
        }
        else if(inputx-outputx<0 && inputy-outputy>0){
            for(int i=inputx+1, j=inputy-1 ; i<=outputx, j>=outputy ; i++, j--){
                if(plate[j][i]!=' '){
                    k++;
                }
            }
        }
        else{
            for(int i=inputx+1, j=inputy+1 ; i<=outputx, j<=outputy ; i++, j++){
                if(plate[j][i]!=' '){
                    k++;
                }
            }
        }
        
        if(k==0){
            canmove();
        }
        else{
            cannotmove();
        }
    }
    else if(count%2==0 && plate[outputy][outputx]>='a' && plate[outputy][outputx]<='z'){
         
    }
    else if(count%2!=0 && plate[outputy][outputx]>='A' && plate[outputy][outputx]<='Z'){
        
    }
    else{
        cannotmove();
    }

}

int bu(){
    
    if(count%2==0){
        if(inputx==outputx && inputy-1==outputy && plate[outputy][outputx]==' '){
            canmove();
            
        }
        else if(plate[outputy][outputx]>='a' && plate[outputy][outputx]<='z'){


        }
        else{
            cannotmove();
        }
    }
    else{
        if(inputx==outputx && inputy+1==outputy && plate[outputy][outputx]==' '){
            canmove();

        }
        else if(plate[outputy][outputx]>='A' && plate[outputy][outputx]<='Z'){

            
        }
        else{
            cannotmove();
        }
    }  
}

int canmove(){
    plate[outputy][outputx]=plate[inputy][inputx];
    plate[inputy][inputx]=' ';
    count++;
}

void cannotmove(){
    printf("輸入錯誤\n");
    sleep(1);
}

void printColour(int color, char* str){
//    printf("\033[%dm%s\033[m",color, str);
   printf("\033[38:5:%dm%s",color,str);
}