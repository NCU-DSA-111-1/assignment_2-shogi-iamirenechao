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
        if(plate[inputy][inputx]=='x' || plate[inputy][inputx]=='X'){
            xiang(count);
        }
        else if(plate[inputy][inputx]=='g' || plate[inputy][inputx]=='G'){
            guei(count);
        }
        else if(plate[inputy][inputx]=='y' ||plate[inputy][inputx]=='Y'){
            yin(count);
        }
        else if(plate[inputy][inputx]=='k' ||plate[inputy][inputx]=='K'){
            jin(count);
        }
        else if(plate[inputy][inputx]=='w' || plate[inputy][inputx]=='W'){
            wang(count);
        }
        // else if(plate[inputy][inputx]=='f' || plate[inputy][inputx]=='F'){
        //     fei(count);
        // }
        else if(plate[inputy][inputx]=='j' || plate[inputy][inputx]=='J'){
            jiao(count);
        }
         else if(plate[inputy][inputx]=='b' || plate[inputy][inputx]=='B'){
             bu(count);
        }
    }

}

int xiang(){
   
    if(count%2==0){
        if(fromx==tox && fromy>toy && plate[toy-1][9-toy]==' '){
           int k=0;
           for(int i=fromy-1; i>=toy; i--){
                if(plate[toy-1][9-tox]!=' '){
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
        else if(plate[toy-1][9-tox]>='a' && plate[toy-1][9-tox]<='z'){

        }   
        else{
            cannotmove();
        }
    }
    else{
        if(fromx==tox && fromy<toy && plate[toy-1][9-tox]==' '){
            int k=0;
            for(int i=fromy+1; i<=toy; i++){
                if(plate[toy-1][9-tox]!=' '){
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
        else if(plate[toy-1][9-tox]>='A' && plate[toy-1][9-tox]<='Z'){

        }
        else{
            cannotmove();
        }
    }
}

int guei(){
    
    if(count%2==0){
        if((fromx-1==tox || fromx+1==tox) && fromy-2==toy && plate[toy-1][9-tox]==' '){
            canmove();
        }
        else if(plate[toy-1][9-tox]>='a' && plate[toy-1][9-tox]<='z'){


        }
        else{
            cannotmove();
        }
        
    }
    else{
        if((fromx-1==tox || fromx+1==tox) && fromy+2==toy && plate[toy-1][9-tox]==' '){
            canmove();

        }
        else if(plate[toy-1][9-tox]>='A' && plate[toy-1][9-tox]<='Z'){

            
        }
        else{
            cannotmove();

        }
    }  
}

int yin(){
    if(abs(fromx-tox)<2 && abs(fromy-toy)<2){
        if(count%2==0){
            if((fromx-1==tox && fromy==toy) || (fromx+1==tox && fromy==toy) || (fromx==tox && fromy+1==toy)){
                cannotmove();
            }
            else{
                canmove();
            }
        }
        else{
            if((fromx-1==tox && fromy==toy) || (fromx+1==tox && fromy==toy) || (fromx==tox && fromy-1==toy)){
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
    if(abs(fromx-tox)<2 && abs(fromy-toy)<2){
        if(count%2==0){
            if((fromx-1==tox && fromy+1==toy) || (fromx+1==tox && fromy+1==toy)){
                cannotmove();
            }
            else{
                canmove();
            }
        }
        else{
            if((fromx-1==tox && fromy-1==toy) || (fromx+1==tox && fromy-1==toy)){
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
    if(abs(fromx-tox)<2 && abs(fromy-toy)<2){
        if(plate[toy-1][9-tox]==' '){
            canmove();
        }
        else if(count%2==0 && plate[toy-1][9-tox]>='a' && plate[toy-1][9-tox]<='z'){
         
        }
        else if(count%2!=0 && plate[toy-1][9-tox]>='A' && plate[toy-1][9-tox]<='Z'){
        
        }
        else{
            cannotmove();
        }
    }
    else{
        cannotmove();
    }
}

// int fei(){
//     if((fromx==tox || fromy==toy) && plate[toy-1][9-tox]==' '){
//         int k=0;
//         for()
//     }

// }

int jiao(){
   
    if(abs(fromx-tox)==abs(fromy-toy) && plate[toy-1][9-tox]==' '){
        int k=0;
        if(fromx-tox>0 && fromy-toy>0){
            for(int i=fromx-1, j=fromy-1; i>=tox, j>=toy ; i--, j--){
                if(plate[toy-1][9-tox]!=' '){
                    k++;
                }
            }
        }
        else if(fromx-tox>0 && fromy-toy<0){
            for(int i=fromx-1, j=fromy+1 ; i>=tox, j<=toy ; i--, j++){
                if(plate[toy-1][9-tox]!=' '){
                    k++;
                }
            }
        }
        else if(fromx-tox<0 && fromy-toy>0){
            for(int i=fromx+1, j=fromy-1 ; i<=tox, j>=toy ; i++, j--){
                if(plate[toy-1][9-tox]!=' '){
                    k++;
                }
            }
        }
        else{
            for(int i=fromx+1, j=fromy+1 ; i<=tox, j<=toy ; i++, j++){
                if(plate[toy-1][9-tox]!=' '){
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
    else if(count%2==0 && plate[toy-1][9-tox]>='a' && plate[toy-1][9-tox]<='z'){
         
    }
    else if(count%2!=0 && plate[toy-1][9-tox]>='A' && plate[toy-1][9-tox]<='Z'){
        
    }
    else{
        cannotmove();
    }

}

int bu(){
    
    if(count%2==0){
        if(fromx==tox && fromy-1==toy && plate[toy-1][9-tox]==' '){
            canmove();
            
        }
        else if(plate[toy-1][9-tox]>='a' && plate[toy-1][9-tox]<='z'){


        }
        else{
            cannotmove();
        }
    }
    else{
        if(fromx==tox && fromy+1==toy && plate[toy-1][9-tox]==' '){
            canmove();

        }
        else if(plate[toy-1][9-tox]>='A' && plate[toy-1][9-tox]<='Z'){

            
        }
        else{
            cannotmove();
        }
    }  
}

int canmove(){
    plate[toy-1][9-tox]=plate[fromy-1][inputx];
    plate[fromy-1][inputx]=' ';
    
}

void cannotmove(){
    printf("輸入錯誤\n");
    sleep(1);
}

void printColour(int color, char* str){
//    printf("\033[%dm%s\033[m",color, str);
   printf("\033[38:5:%dm%s",color,str);
}