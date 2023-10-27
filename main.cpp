#include <iostream>
#include <conio.h>
#include<windows.h>

using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score , sansa=3 , ok;
int tailX[100], tailY[100];
int nTail;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x= width / 2;
    y= height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw1()
{
    system("cls"); //system("clear");
    for(int i=0; i < width+2; i++)
        cout<<"#";
    cout<<endl;

    for(int i=0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            if(j==0)
                cout<<"#";
            if(i == y && j == x)
                cout<<"0";
            else if (i == fruitY && j == fruitX)
                cout<<"F";
            else
            {
                bool print = false;
                for(int k=0; k < nTail; k++)
                {

                    if(tailX[k] == j && tailY[k] == i)
                    {
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print)
                        cout << " ";
            }
            if(j == width-1)
                cout<<"#";
        }
        cout<<endl;
    }

    for(int i=0; i < width+2; i++)
        cout<<"#";
    cout<<endl;
    cout<<"Score:" << score << endl;
}

void Draw2()
{
    system("cls"); //system("clear");
    for(int i=0; i < width+2; i++)
        cout<<"#";
    cout<<endl;

    for(int i=0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            if(j==0)
                cout<<"#";
            if(i == y && j == x)
                cout<<"0";
            else if (i == fruitY && j == fruitX)
                cout<<"F";
            else
            {
                bool print = false;
                for(int k=0; k < nTail; k++)
                {

                    if(tailX[k] == j && tailY[k] == i)
                    {
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print)
                        cout << " ";
            }
            if(j == width-1)
                cout<<"#";
        }
        cout<<endl;
    }

    for(int i=0; i < width+2; i++)
        cout<<"#";
    cout<<endl;
    cout<<"Score:" << score << endl;
    cout<<"Vietii:" << sansa << endl;
}
void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic1()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i < nTail ; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir)
    {
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
    default:
        break;
    }
    if(x >= width || x < 0 || y >= height || y < 0)
        gameOver = true;
    for(int i = 0; i < nTail; i++)
        if(tailX[i] == x && tailY[i] == y)
            gameOver = true;
    if(x == fruitX && y == fruitY)
    {

        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
void Logic2()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i < nTail ; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir)
    {
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
    default:
        break;
    }
    if(x >= width)
        {x=0;sansa=sansa-1;}
    else
        if(x < 0)
            {x = width -1;sansa=sansa-1;}
    if(y>= height)
        {y = 0;sansa=sansa-1;}
    else if(y < 0)
        {y = height -1;sansa=sansa-1;}
    if(sansa==0)
        gameOver = true;

    for(int i = 0; i < nTail; i++)
        if(tailX[i] == x && tailY[i] == y)
            gameOver = true;
    if(x == fruitX && y == fruitY)
    {

        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
int main()
{
    cout<<"Alege modul de joc 1 sau 2"<<endl;
    cout<<"1-Snake normal"<<endl;
    cout<<"2-Ai 3 vieti cand intrii in pereti"<<endl;
    cout<<"3-Regulile jocului"<<endl;
    ok=0;
    while(ok!=1 || ok!=2)
    {
        cin>>ok;
        if( ok == 1 )
            {
                Setup();
                while(!gameOver)
                {
                    Draw1();
                    Input();
                    Logic1();
                    Sleep(10);//sleep(10);
                }
            }
        if( ok == 2 )
            {
                Setup();
                while(!gameOver)
                {
                    Draw2();
                    Input();
                    Logic2();
                    Sleep(10);//sleep(10);
                }
            }
        if(ok == 3)
            {
                cout<<"Sarpele este reprezentat de O,iar fructele sunt reprezentate prin F"<<endl<<"Jucatorul controleaza sarpele."<<endl<<"Scopul jocului este sa mananci cat mai multe fructe"<<endl;
                cout<<"Sarpele se controleaza cu W,A,S,D."<<endl;
                cout<<"W - sus , A - stanga , S - jos , D - dreapta";
            }

    }
    return 0;
}
