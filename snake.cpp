#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

bool gameOver;
const int width=40;
const int height=15;
int x,y,friutX,fruitY,score;
enum Direction{ STOP =0,LEFT,RIGHT,UP,DOWN};
Direction dir;
int tailX[100];
int tailY[100];
int ntail;
void setup(){
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    friutX=rand()%width;
    fruitY=rand()%height;
    score=0;
}
void Draw(){
    system("cls");
    for(int i=0;i<width+1;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0||j==width-1){
                cout<<"#";
            }
            else if(i==y && j==x){
                cout<<"O";j++;
            }
            if(i==fruitY && j==friutX){
                cout<<"F";
            }
            else {
                bool print = false;
                for(int k=0;k<ntail;k++){
                    if(tailX[k]==j && tailY[k]==i){
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print){
                    cout<<" ";
                }
                }
        }
        cout<<endl;
    }
    for(int i=0;i<width+1;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"Score:"<<score;
}
void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir=LEFT;
                break;
            case 'w':
                dir=UP;
                break;
            case 's':
                dir=DOWN;
                break;
            case 'd':
                dir=RIGHT;
                break;
            case 'x':
                gameOver=true;
                break;
        }
    }
}
void logic(){
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<ntail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:break;
    }
    if(x>width ||x<0 || y>height || y<0){
        gameOver=true;
    }
    for(int i=0;i<ntail;i++){
        if(tailX[i]==x && tailY[i]==y){
            gameOver=true;
        }
    }
    if(x==friutX && y== fruitY){
        score+=10;
        friutX=rand()%width;
        fruitY=rand()%height;
        ntail++;
    }
}

int main(){
setup();
while(!gameOver){
    Draw();
    input();
    logic();
    Sleep(20);
}
return 0;
}