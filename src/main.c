#include "../inc/main.h"

int main(int argc, char **argv){
    ini();
    
    current= (cunptr) malloc(sizeof(cun));
    current->prev=NULL;
    start=current;

    while((z=getopt(argc, argv, "ns:l:"))!=-1){
        switch(z){
            case 'n':
                status=1;
                break;

            case 's':
                status=1;
                file=fopen(optarg,"w+");
                if(file==NULL){
                    printf("File cannot be opened!\n");
                    return 0;
                }
                
                break;

            case 'l':
                status=2;
                file=fopen(optarg,"r+");
                if(file==NULL){
                    printf("File cannot be opened!");
                    return 0;
                }
                while(!feof(file)){
                    fscanf(file,"%d %d %d %d %c%c\n",&current->ix,&current->iy,&current->ox,&current->oy,&current->chessori,&current->chessalt);
                    cunptr nb=(cunptr)malloc(sizeof(cun));
                    current->next=nb;
                    nb->prev=current;
                    nb->next=NULL;
                    current=nb;
                    count++;
                }
                current=start;

                break;
        }
    }
    while(status==1 && end==0){
        
        if(saveminor[saveminloc-1]=='w' || savemajor[savemajloc-1]=='W'){
            printf("遊戲結束◎ ▽ ◎\n");
            current=start;
            rewind(file);
            for(int i=0; i<count; i++){
                fprintf(file,"%d %d %d %d %c%c\n",current->ix,current->iy,current->ox,current->oy,current->chessori,current->chessalt);
                current=current->next;
            }
            fflush(file);
            return 0 ;
        }
        system("clear");
        for(int i=0; i<savemajloc; i++){
            print(savemajor[i]);
        }
        printf("\n");

        printf("９８７６５４３２１\n");
        for(int i=0 ; i<ROW ; i++ ){
            for( int j=0 ; j<COL ; j++){
                print(plate[i][j]);
            }
            printf("%d",i+1);
            printf("\n");
        }
        for(int i=0; i<=saveminloc; i++){
            print(saveminor[i]);
        }
        printf("\n");
        movecheck();
        getchar();

    }
    while(status==2 ){
        system("clear");
        for(int i=0; i<savemajloc; i++){
            print(savemajor[i]);
        }
        printf("\n");

        printf("９８７６５４３２１\n");
        for(int i=0 ; i<ROW ; i++ ){
            for( int j=0 ; j<COL ; j++){
                print(plate[i][j]);
            }
            printf("%d",i+1);
            printf("\n");
        }
        for(int i=0; i<=saveminloc; i++){
            print(saveminor[i]);
        }
        printf("\n");
        printf("輸入f/F查看下一步\n輸入b/B查看上一步\n");
        scanf("%c",&firstinput);
        // printf("count = %d, dudangyongcount = %d\n",count,dudangyongcount);
        // sleep(1);
        outputx=current->ox;
        outputy=current->oy;
        inputx=current->ix;
        inputy=current->iy;
        if((firstinput=='f'||firstinput=='F') && dudangyongcount<count){
            if(dudangyongcount%2==0 && plate[outputy][outputx]!='.'){
                saveminor[saveminloc]=plate[outputy][outputx];
                saveminloc++;
            }
            else if(dudangyongcount%2==1 && plate[outputy][outputx]!='.'){
                savemajor[savemajloc]=plate[outputy][outputx];
                savemajloc++;
            }

            plate[outputy][outputx]=plate[inputy][inputx];
            plate[inputy][inputx]='.';
            current=current->next;
            dudangyongcount++;
        }
        else if((firstinput=='b'||firstinput=='B')&& dudangyongcount>0){
            current=current->prev;
            plate[current->iy][current->ix]=plate[current->oy][current->ox];
            plate[current->oy][current->ox]=current->chessori;
            if(dudangyongcount%2==1 && saveminor[saveminloc-1]==current->chessori){
                saveminloc--;
                saveminor[saveminloc]='.';
            }
            else if(dudangyongcount%2==0 && savemajor[savemajloc-1]==current->chessori){
                savemajloc--;
                savemajor[savemajloc]='.';
            }
            dudangyongcount--;
        }
        else if((firstinput=='b'||firstinput=='B') && dudangyongcount==0){
            printf("已經到開始的狀態了\n");
            sleep(1);
        }
        else if((firstinput=='f'||firstinput=='F') && dudangyongcount>=count){
            printf("已經是最後一步了\n");
            sleep(1);
        }
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
                plate[i][j]='.';
            }

        }
    }
}

void print(char chess){
    

            switch(chess){
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
            case '.':
                printf("　");
                break;
            // default:
            //     printf("  ");
            //     break;
            }
            

        
        
    
}

void movecheck(){
    
    printf("輸入移動的X座標與Y座標\n");
    scanf("%c",&firstinput);
    if(firstinput=='0'){
        if(count==0){
            printf("悔到底了\n");
            sleep(1);
            return;
        }
        current=current->prev;
        plate[current->iy][current->ix]=plate[current->oy][current->ox];
        plate[current->oy][current->ox]=current->chessori;
        free(current->next);
        current->next=NULL;
        if(count%2==1 && saveminor[saveminloc-1]==current->chessori){
            saveminloc--;
            saveminor[saveminloc]='.';
        }
        else if(count%2==0 && savemajor[savemajloc-1]==current->chessori){
            savemajloc--;
            savemajor[savemajloc]='.';
        }
        count--;
        return;
    }
    else if(firstinput=='s' || firstinput=='S'){
        current=start;
        rewind(file);
        for(int i=0; i<count; i++){
            fprintf(file,"%d %d %d %d %c%c\n",current->ix,current->iy,current->ox,current->oy,current->chessori,current->chessalt);
            current=current->next;
        }
        fflush(file);
        return;
    }
    else if(firstinput=='/'){
        printf("退出遊戲\n");
        current=start;
            rewind(file);
            for(int i=0; i<count; i++){
                fprintf(file,"%d %d %d %d %c%c\n",current->ix,current->iy,current->ox,current->oy,current->chessori,current->chessalt);
                current=current->next;
            }
            fflush(file);
            end=1;
            return;
    }
    else{
        scanf("%d",&fromy);
    }

    fromx=firstinput-'0';
    inputx=9-fromx;
    inputy=fromy-1;

    if(count%2==0){
        if(plate[inputy][inputx]<='A' || plate[inputy][inputx]>='Z'){
            printf("a\n");
            cannotmove();
            return;
        }
    }
    else{
        if(plate[inputy][inputx]<='a' || plate[inputy][inputx]>='z'){
            printf("x=%d\n",fromx);
            cannotmove();
            return;
        }
    }


    if(plate[inputy][inputx]=='.'){
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
        if(inputx==outputx && inputy>outputy){
           int k=0;
           for(int i=inputy-1; i>outputy; i--){
                if(plate[i][outputx]!='.'){
                    k++;
                }
            }
            if(k==0 && eat(plate[outputy][outputx])){
                canmove();
            }
            else{
                cannotmove();
            }
        }
        else{
            cannotmove();
        }
    }
    else{
        if(inputx==outputx && inputy<outputy){
            int k=0;
            for(int i=inputy+1; i<outputy; i++){
                if(plate[i][outputx]!='.'){
                    k++;
                }
            }
            if(k==0 && eat(plate[outputy][outputx])){
                canmove();
            }
            else{
                cannotmove();
            }
        }
        else{
            cannotmove();
        }
    }
}

int guei(){
    
    if(count%2==0){
        if((inputx-1==outputx || inputx+1==outputx) && inputy-2==outputy && eat(plate[outputy][outputx])){
            canmove();
        }
        else{
            cannotmove();
        }
        
    }
    else{
        if((inputx-1==outputx || inputx+1==outputx) && inputy+2==outputy && eat(plate[outputy][outputx])){
            canmove();

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
                if(eat(plate[outputy][outputx])){
                    canmove();
                }
                else{
                    cannotmove();
                }
            }
        }
        else{
            if((inputx-1==outputx && inputy==outputy) || (inputx+1==outputx && inputy==outputy) || (inputx==outputx && inputy-1==outputy)){
                cannotmove();
            }
            else{
                if(eat(plate[outputy][outputx])){
                    canmove();
                }
                else{
                    cannotmove();
                }
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
                if(eat(plate[outputy][outputx])){
                    canmove();
                }
                else{
                    cannotmove();
                }

            }
        }
        else{
            if((inputx-1==outputx && inputy-1==outputy) || (inputx+1==outputx && inputy-1==outputy)){
                cannotmove();
            }
            else{
                if(eat(plate[outputy][outputx])){
                    canmove();
                }
                else{
                    cannotmove();
                }
            }
        }
    }
    else{
        cannotmove();
    }
}

int wang(){
    if(abs(inputx-outputx)<2 && abs(inputy-outputy)<2){
        if(eat(plate[outputy][outputx])){
            canmove();
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
    if((inputx==outputx || inputy==outputy)){
        int k=0;
        if(inputx==outputx && inputy>outputy){
            for(int i=inputy-1; i>outputy; i--){
                if(plate[i][outputx]!='.'){
                    k++;
                }
            }
        }
        else if(inputx==outputx && inputy<outputy){
            for(int i=inputy+1; i<outputy; i++){
                if(plate[i][outputx]!='.'){
                    k++;
                }
            }
        }
        else if(inputx<outputx && inputy==outputy){
            for(int i=inputx+1; i<outputx; i++){
                if(plate[outputy][i]!='.'){
                    k++;
                }
            }
        }
        else if(inputx>outputx && inputy==outputy){
            for(int i=inputx-1; i>outputx; i--){
                if(plate[outputy][i]!='.'){
                    k++;
                }
            }
        }

        if(k==0 && eat(plate[outputy][outputx])){
            canmove();
        }
        else{
            cannotmove();
        }
    }
    else{
        cannotmove();
    }

}

int jiao(){
   
    if(abs(inputx-outputx)==abs(inputy-outputy) ){
        int k=0;
        if(inputx-outputx>0 && inputy-outputy>0){
            for(int i=inputx-1, j=inputy-1; i>outputx, j>outputy ; i--, j--){
                if(plate[j][i]!='.'){
                    k++;
                }
            }
        }
        else if(inputx-outputx>0 && inputy-outputy<0){
            for(int i=inputx-1, j=inputy+1 ; i>outputx, j<outputy ; i--, j++){
                if(plate[j][i]!='.'){
                    k++;
                }
            }
        }
        else if(inputx-outputx<0 && inputy-outputy>0){
            for(int i=inputx+1, j=inputy-1 ; i<outputx, j>outputy ; i++, j--){
                if(plate[j][i]!='.'){
                    k++;
                }
            }
        }
        else{
            for(int i=inputx+1, j=inputy+1 ; i<outputx, j<outputy ; i++, j++){
                if(plate[j][i]!='.'){
                    k++;
                }
            }
        }
        
        if(k==0 && eat(plate[outputy][outputx])){
            canmove();
        }
        else{
            cannotmove();
        }
    }
    else{
        cannotmove();
    }

}

int bu(){
    
    if(count%2==0){
        if(inputx==outputx && inputy-1==outputy){
            if(eat(plate[outputy][outputx]))
                canmove();
            
        }
        else{
            cannotmove();
        }
    }
    else{
        if(inputx==outputx && inputy+1==outputy){
            if(eat(plate[outputy][outputx]))
                canmove();

        }
        else{
            cannotmove();
        }
    }  
}

void canmove(){

    if(count%2==0 && plate[outputy][outputx]!='.'){
        saveminor[saveminloc]=plate[outputy][outputx];
        saveminloc++;
    }
    else if(count%2==1 && plate[outputy][outputx]!='.'){
        savemajor[savemajloc]=plate[outputy][outputx];
        savemajloc++;
    }
    current->ix=inputx;
    current->iy=inputy;
    current->ox=outputx;
    current->oy=outputy;
    current->chessalt=plate[inputy][inputx];
    current->chessori=plate[outputy][outputx];
    cunptr nb=(cunptr)malloc(sizeof(cun));
    current->next=nb;
    nb->prev=current;
    nb->next=NULL;
    current=nb;

    plate[outputy][outputx]=plate[inputy][inputx];
    plate[inputy][inputx]='.';
    count++;
}

void cannotmove(){
    printf("輸入錯誤\n");
    sleep(1);
}

void printColour(int color, char* str){
//    printf("\033[%dm%s\033[m",color, str);
   printf("\033[38:5:%dm%s\033[0m",color,str);
}

int eat(char p){
    if(count%2==0){
        switch (p)
        {
        case 'x':
        case 'g':
        case 'y':
        case 'k':
        case 'w':
        case 'j':
        case 'f':
        case 'b':
        case '.':
            return 1;
            break;
        
        default:
            return 0;
            break;
        }
    }
    else{
        switch(p){
            case 'X':
            case 'G':
            case 'Y':
            case 'K':
            case 'W':
            case 'J':
            case 'F':
            case 'B':
            case '.':
                return 1;
                break;

            default:
                return 0;
                break;
        }
    }
   
}