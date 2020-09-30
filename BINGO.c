#include<stdio.h>
#include<strings.h>
#include<math.h>
#include<dos.h>
#include<windows.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>


void gotoxy(int x,int y);
void Load_Bar(void);
void design(void);
void design2(void);
void design3(void);
void keep(int Arr[25][4] ,int X[5],int Y[4],int AB,int AC);
void pinch(int Arr[25][4],int X[5],int Y[5],int qq[5],int pp[5],int &tra,int &luf);
void shot(int &wq,int &er,int pp[5],int qq[5],int &f1,int &tra,int &luf);
void input(int &r,int Arr[25][4],int d[25][4],int X[5],int Y[5],int X1[5],int Y1[5],int &score);


int main()
{
    //declaration Part.
    int Arr[25][4], Arr1[25][4];
    int X[5]={5,9,13,17,21},   X1[5]={35,39,27,43,31}  ,X2[5]={27,31,35,39,43};
    int Y[5]={20,23,26,29,32}, Y1[5]={26,32,29,23,20}  ,Y2[5]={20,23,26,29,32};
    int AB,AC;
    int r,score,con,dan,mir;
    char choice;

    //STRUCT 1:
    typedef struct
    {
        char name[30];
        int score;
    }Val2;

    Val2  Val[200];

    //Loading screen code
    Load_Bar();

    //STRUCT 2:
    struct
    {
        char name[30];
        int score;
    }dat;

    //for menu
    design();
    gotoxy(8,19);
    printf("Enter Player Name:");
    gets(dat.name);

    //Label 1
    START:
    system("cls");
    design();

   // Menu
   gotoxy(36,15);printf("======================");
   gotoxy(36,16);printf("         MENU         ");
   gotoxy(36,17);printf("======================");
   gotoxy(36,19);printf("1. PLAY GAME");
   gotoxy(36,21);printf("2. HOW TO PLAY");
   gotoxy(36,23);printf("3. SCOREBOARD");
   gotoxy(36,25);printf("4. GAME CREDITS");
   gotoxy(36,27);printf("Or type any other key to quit ....");

    //Label 2
    END:
    scanf("%s",&choice);
       if(choice=='m' || choice=='M')
        {
            goto START;
        }
        if(choice == '1')
        {
            system("cls");
            design2();
            AB=3;
            AC=6;
            keep(Arr,X,Y,AB,AC);  //Arr is given the value means a table is created for Arr(player)
            AB=AC;
            keep(Arr1,X1,Y1,AB,AC);//Arr1 is given the values exact same way but opposite or in a reverse manner to have a difference
            input(r,Arr,Arr1,X,Y,X2,Y2,score);

            FILE *fout;
            fout=fopen("DATA.txt","a");
                if(fout==NULL)
                {
                    gotoxy(4,8);
                    printf("Your data cannot be saved...!!!");
                }
                else
                {
                    dat.score=score;
                    //fwrite((char*)&dat,sizeof( dat),1,fout);

                    fprintf(fout,"\n%s\t\t\t",dat.name);
                    fprintf(fout,"%d",dat.score);
                    fclose(fout);
                }
                gotoxy(4,9);
                printf("Press 'M' for main menu & '1' to play again or any key to quit...");
                goto END;
         }
    if(choice=='2')
    {
        system("cls");
        design();
        gotoxy(34,10);
        printf("HELP - GUIDE");
        gotoxy(4,12);printf("In the whole game all you have to do is just keep entering the numbers");
        gotoxy(4,14);printf("left on your card without having a '/' on their right. When you enter");
        gotoxy(4,16);printf("a number the number gets checked and a '/' appears on it's right .");
        gotoxy(4,18);printf("One turn yours and one computer's, and you have to complete five lines");
        gotoxy(4,20);printf("with numbers checked, diogonally or horizontally or vertically.");
        gotoxy(4,22);printf("Do it before the computer does and that's all how you move towards VICTORY.");
        gotoxy(4,25);
    printf("Press 'M' for main menu, '1' to play or any other key to quit.....");
    goto END;
    }
    if(choice=='3')
    {
        con=0;

            system("cls");
            design();
            system("cls");
            design();
        gotoxy(34,10);
        printf("BEST SCORES");
        gotoxy(4,12);
        //printf("    NAME");
        //gotoxy(28,12);
        //printf("Scores");
     FILE *fin;
     fin=fopen("DATA.txt","r");
        while(!feof(fin))
        {
         fgets((char*)&Val,200,fin);
         printf("\t%s",Val);
        }
        gotoxy(4,29);
        char jk;
        printf("Enter 'R' to reset SCORE or Any key to Select option:");
        scanf("%s",&jk);
        if(jk=='R')
        {
            FILE *fR;
            fR=fopen("DATA.txt","w");
            fprintf(fR,"Name\t\t\tScore\n");
            fclose(fR);
            gotoxy(30,27);
            printf("*** SUCCESSFULLY DELETED ***");
        }
    gotoxy(4,31);
    printf("\n\tPress 'M' for main menu, '1' to play or any other key to quit.....");
    fclose(fin);
    goto END;
    }
   if(choice=='4')
    {
    system("cls");
for(int cr=45;cr<=131;cr++)
    {
    system("cls");
    if(cr>45& cr<80){gotoxy(1,80-cr);      printf("                                    Programming BY:                          ");}
    if(cr>52 && cr<86){gotoxy(1,86-cr);    printf("                                    HAMMAD RIAZ                              ");}
    if(cr>54 && cr<89){gotoxy(1,89-cr);    printf("                                 REFERENCES FOR Idea                         ");}
    if(cr>90 && cr<125){gotoxy(3,125-cr);  printf("                           https://skinfonet.wordpress.com                   ");}
    delay(110);
    }
    delay(110);
    goto START;
    }
    else
    {goto quit;
     }
   quit:
       return 0;
 }

 void clreol(void)
{
    printf("\033[K");
     fflush(stdout);
}

void Load_Bar(void)
{
    int i;
    system("cls");
gotoxy(27,10);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(27,11);printf("°°²²²²²²Û°°²Û°²²°°²Û°°²²²²²Û°°²²²²Û°°°²Û°²Û°²Û°°°°°°");
gotoxy(27,12);printf("°°²²°°°²²Û°²Û°²²²°²Û°²²²°°°°°²²²°²²Û°°²Û°²Û°²Û°°°°°°");
gotoxy(27,13);printf("°°²²²²²²Û°°²Û°²²²²²Û°²²°°²²Û°²²°°°²Û°°²Û°²Û°²Û°°°°°°");
gotoxy(27,14);printf("°°²²°°°²²Û°²Û°²²°²²Û°²²²°°²Û°²²²°²²Û°°°°°°°°°°°°°°°°");
gotoxy(27,15);printf("°°²²²²²²Û°°²Û°²²°°²Û°°²²²²²Û°°²²²²Û°°°²Û°²Û°²Û°°°°°°");
gotoxy(27,16);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
    printf("\n\t\t\t\t\tPlease Wait while Loading...\n\n\n\n\n");
    printf("\t");
    for(i=0;i<100;i++)
    {
        Sleep(10);
        printf("%c",219);
    }
    system("cls");
    printf("\n\n\n\t\t\t\t\tSUCCESFULLY Loaded...");
    Sleep(10);
    system("cls");
    }
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
 void design3()
 {
gotoxy(1,1); printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(1,2); printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(1,3); printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(1,4); printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(1,5); printf("°°                                                                            °°");
gotoxy(1,6); printf("°°                                                                            °°");
gotoxy(1,7); printf("°°                                                                            °°");
gotoxy(1,8); printf("°°                                                                            °°");
gotoxy(1,9); printf("°°                                                                            °°");
gotoxy(1,10);printf("°°                                                                            °°");
gotoxy(1,11);printf("°°                                                                            °°");
gotoxy(1,12);printf("°°                                                                            °°");
gotoxy(1,13);printf("°°                                                                            °°");
gotoxy(1,14);printf("°°                                                                            °°");
gotoxy(1,15);printf("°°                                                                            °°");
gotoxy(1,16);printf("°°                                                                            °°");
gotoxy(1,17);printf("°°           °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°           °°");
gotoxy(1,18);printf("°°           °°°°²²²²²²Û°°²Û°²²°°²Û°°²²²²²Û°°²²²²Û°°°²Û°²Û°²Û°°°°°°           °°");
gotoxy(1,19);printf("°°           °°°°²²°°°²²Û°²Û°²²²°²Û°²²²°°°°°²²²°²²Û°°²Û°²Û°²Û°°°°°°           °°");
gotoxy(1,20);printf("°°           °°°°²²²²²²Û°°²Û°²²²²²Û°²²°°²²Û°²²°°°²Û°°²Û°²Û°²Û°°°°°°           °°");
gotoxy(1,21);printf("°°           °°°°²²°°°²²Û°²Û°²²°²²Û°²²²°°²Û°²²²°²²Û°°°°°°°°°°°°°°°°           °°");
gotoxy(1,22);printf("°°           °°°°²²²²²²Û°°²Û°²²°°²Û°°²²²²²Û°°²²²²Û°°°²Û°²Û°²Û°°°°°°           °°");
gotoxy(1,23);printf("°°           °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°           °°");
gotoxy(1,24);printf("°°                                                                            °°");
gotoxy(1,25);printf("°°                                                                            °°");
gotoxy(1,26);printf("°°                                                                            °°");
gotoxy(1,27);printf("°°                                                                            °°");
gotoxy(1,28);printf("°°                                                                            °°");
gotoxy(1,29);printf("°°                                                                            °°");
gotoxy(1,30);printf("°°                                                                            °°");
gotoxy(1,31);printf("°°                                                                            °°");
gotoxy(1,32);printf("°°                                                                            °°");
gotoxy(1,33);printf("°°                                    HAMMAD HR                               °°");
gotoxy(1,34);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(1,35);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
}
void design()
 {
gotoxy(1,1); printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(1,2); printf("°°°°°°°°°°°°°°°°²²²²²²Û°°²Û°²²°°²Û°°²²²²²Û°°²²²²Û°°°²Û°²Û°²Û°°°°   B   °°°°°°°°°");
gotoxy(1,3); printf("°°°°°°°°°°°°°°°°²²°°°²²Û°²Û°²²²°²Û°²²²°°°°°²²²°²²Û°°²Û°²Û°²Û°°°    I    °°°°°°°°");
gotoxy(1,4); printf("°°°°°°°°°°°°°°°°²²²²²²Û°°²Û°²²²²²Û°²²°°²²Û°²²°°°²Û°°²Û°²Û°²Û°°°    N    °°°°°°°°");
gotoxy(1,5); printf("°°°°°°°°°°°°°°°°²²°°°²²Û°²Û°²²°²²Û°²²²°°²Û°²²²°²²Û°°°°°°°°°°°°°    G    °°°°°°°°");
gotoxy(1,6); printf("°°°°°°°°°°°°°°°°²²²²²²Û°°²Û°²²°°²Û°°²²²²²Û°°²²²²Û°°°²Û°²Û°²Û°°°°   O   °°°°°°°°°");
gotoxy(1,7); printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(1,8); printf("°°ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß°°");
gotoxy(1,9); printf("°°                                                                            °°");
gotoxy(1,10);printf("°°                                                                            °°");
gotoxy(1,11);printf("°°                                                                            °°");
gotoxy(1,12);printf("°°                                                                            °°");
gotoxy(1,13);printf("°°                                                                            °°");
gotoxy(1,14);printf("°°                                                                            °°");
gotoxy(1,15);printf("°°                                                                            °°");
gotoxy(1,16);printf("°°                                                                            °°");
gotoxy(1,17);printf("°°                                                                            °°");
gotoxy(1,18);printf("°°                                                                            °°");
gotoxy(1,19);printf("°°                                                                            °°");
gotoxy(1,20);printf("°°                                                                            °°");
gotoxy(1,21);printf("°°                                                                            °°");
gotoxy(1,22);printf("°°                                                                            °°");
gotoxy(1,23);printf("°°                                                                            °°");
gotoxy(1,24);printf("°°                                                                            °°");
gotoxy(1,25);printf("°°                                                                            °°");
gotoxy(1,26);printf("°°                                                                            °°");
gotoxy(1,27);printf("°°                                                                            °°");
gotoxy(1,28);printf("°°                                                                            °°");
gotoxy(1,29);printf("°°                                                                            °°");
gotoxy(1,30);printf("°°                                                                            °°");
gotoxy(1,31);printf("°°                                                                            °°");
gotoxy(1,32);printf("°°                                                                            °°");
gotoxy(1,33);printf("°°                                    HAMMAD HR                               °°");
gotoxy(1,34);printf("°°                                                                            °°");
gotoxy(1,35);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
}
void design2()
{
gotoxy(1,1);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(1,2);printf("°°°°°°°°°°°°°°°°²²²²²²Û°°²Û°²²°°²Û°°²²²²²Û°°²²²²Û°°°²Û°²Û°²Û°°°°   B   °°°°°°°°°");
gotoxy(1,3);printf("°°°°°°°°°°°°°°°°²²°°°²²Û°²Û°²²²°²Û°²²²°°°°°²²²°²²Û°°²Û°²Û°²Û°°°    I    °°°°°°°°");
gotoxy(1,4);printf("°°°°°°°°°°°°°°°°²²²²²²Û°°²Û°²²²²²Û°²²°°²²Û°²²°°°²Û°°²Û°²Û°²Û°°°    N    °°°°°°°°");
gotoxy(1,5);printf("°°°°°°°°°°°°°°°°²²°°°²²Û°²Û°²²°²²Û°²²²°°²Û°²²²°²²Û°°°°°°°°°°°°°    G    °°°°°°°°");
gotoxy(1,6);printf("°°°°°°°°°°°°°°°°²²²²²²Û°°²Û°²²°°²Û°°²²²²²Û°°²²²²Û°°°²Û°²Û°²Û°°°°   O   °°°°°°°°°");
gotoxy(1,7);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(1,8);printf("°°ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß°°");
gotoxy(1,9);printf("°°                                                                            °°");
gotoxy(1,10);printf("°°                                                                            °°");
gotoxy(1,11);printf("°°                                                                            °°");
gotoxy(1,12);printf("°°                                                                            °°");
gotoxy(1,13);printf("°°                                                                            °°");
gotoxy(1,14);printf("°°                                             ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ °°");
gotoxy(1,15);printf("°°                                             ³       INSTRUCTIONS :       ³ °°");
gotoxy(1,16);printf("°°                                             ³			     ³ °°");
gotoxy(1,17);printf("°° ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿³  KEEP ENTERING THE NUMBERS ³ °°");
gotoxy(1,18);printf("°° ³           CARD ONE ³³           CARD TWO ³³			     ³ °°");
gotoxy(1,19);printf("°° ³                    ³³                    ³³    AND COMLETE FIVE LINES  ³ °°");
gotoxy(1,20);printf("°° ³                    ³³                    ³³			     ³ °°");
gotoxy(1,21);printf("°° ³                    ³³                    ³³  BY CHECKS, BEFORE THE     ³ °°");
gotoxy(1,22);printf("°° ³                    ³³                    ³³			     ³ °°");
gotoxy(1,23);printf("°° ³                    ³³                    ³³  COMPUTER DOES.            ³ °°");
gotoxy(1,24);printf("°° ³                    ³³                    ³³		             ³ °°");
gotoxy(1,25);printf("°° ³                    ³³                    ³³  AS THE NUMBERS ARE CHECKED³ °°");
gotoxy(1,26);printf("°° ³                    ³³                    ³³                            ³ °°");
gotoxy(1,27);printf("°° ³                    ³³                    ³³ A '/'WILL APPEAR ON RIGHT. ³ °°");
gotoxy(1,28);printf("°° ³                    ³³                    ³ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ °°");
gotoxy(1,29);printf("°° ³                    ³³                    ³ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ °°");
gotoxy(1,30);printf("°° ³                    ³³                    ³³ GAME CREDITS :             ³ °°");
gotoxy(1,31);printf("°° ³                    ³³                    ³³       HAMMAD RIAZ          ³ °°");
gotoxy(1,32);printf("°° ³                    ³³                    ³³                            ³ °°");
gotoxy(1,33);printf("°° ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ °°");
gotoxy(1,34);printf("°°                                                                            °°");
gotoxy(1,35);printf("°°                                                                            °°");
gotoxy(1,36);printf("°°                                                                            °°");
gotoxy(1,37);printf("°°  									       °°");
gotoxy(1,38);printf("°°                                     HAMMAD HR                              °°");
gotoxy(1,39);printf("°°                                                                            °°");
gotoxy(1,40);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(1,40);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
}


//The purpose of this function is to assign values to the table arrays/the purpose to use 25 by 2 size was to randomly assigning values.
void keep(int Arr[25][4], int X[5], int Y[5], int AB,int AC)
{
    int a=25,r=0,q[5],p[5];
    int e,f,c,d;
    int xy[25][2];

    //THESE LOOPS ARE USED TO ASSIGN VALUE TO THE Arr[25][4] THAT WILL BECOME OUR BINGO CARD:
    //WE GIVE VALUES OF X AND Y TO this given array xy that will give the value to array of cards:
    for(int i=0;i<5;i++)
    {
        xy[i][0]=X[0];
        xy[i][1]=Y[i];
    }
    for(int i=5;i<10;i++)
    {
        xy[i][0]=X[1];
        xy[i][1]=Y[i-5];
    }
    for(int i=10;i<15;i++)
    {
        xy[i][0]=X[2];
        xy[i][1]=Y[i-10];
    }
    for(int i=15;i<20;i++)
    {
        xy[i][0]=X[3];
        xy[i][1]=Y[i-15];
    }
    for(int i=20;i<25;i++)
    {
        xy[i][0]=X[4];
        xy[i][1]=Y[i-20];
    }


//The purpose to assign AB and AC was just to have a contradiction in our own condition it is set a specific criteria
if(AB!=AC)   // this is to put values in the Array of the table of BINGO card for player;
 {
    for(int i=0;i<25;i++)
    {
        Arr[i][3]=0;
        Arr[i][0]=i+1;  //this is the only value containing Table members
        r=rand()%a;
        Arr[i][1]=xy[r][0];  //to randomly give the members different places,(to determine or provide random placements)
        Arr[i][2]=xy[r][1];
        for(int j=r;j<a;j++)
        {
            xy[j][0]=xy[j+1][0];  //to update it so that contradiction does not happen
            xy[j][1]=xy[j+1][1];
        }
    a=a-1; //we decrease it by one number so that next random number is within a particular number or else ignore n0.
    }
}
else if(AB==AC)
{
    for(int i=24;i>=0;i--)
    {
        Arr[i][3]=0;
        Arr[i][0]=i+1;
        r=rand()%a;
        Arr[i][1]=xy[r][0];
        Arr[i][2]=xy[r][1];
        for(int j=r;j<a;j++)
        {
            xy[j][0]=xy[j+1][0];
            xy[j][1]=xy[j+1][1];
        }
    a=a-1;
    }
  }
}
//This function is used as a sub_function It is used to get to calculate and determine whether a diagonal or vertical or horizontal values are checked values in tables.
void pinch(int Arr[25][4],int X[5],int Y[ 5],int qq[5],int pp[5],int &tra,int &luf)
{

}

//this function depends on the above function
void shot(int Arr[25][4],int X[5],int Y[5],int &wq,int &er,int pp[5],int qq[5],int &f1,int &tra,int &luf)
{
       for(int j=0;j<5;j++)
   {
       qq[j]=0;
       pp[j]=0;
   }
   luf=0;tra=0;
   for(int j=0;j<5;j++)
   {
       for(int i=0;i<25;i++)
        {
            if(X[j]==Arr[i][1] && Arr[i][3]==1)
            qq[j]++;
            if(Y[j]==Arr[i][2] && Arr[i][3]==1)
            pp[j]++;
            if(X[j]==Arr[i][1] && Y[j]==Arr[i][2] && Arr[i][3]==1 )
            tra++;
            if(X[j]==Arr[i][1] && Y[4-j]==Arr[i][2] && Arr[i][3]==1)
            luf++;
        }
    }
      f1=0;
      if(luf==5)
      f1++;
      if(tra==5)
      ++f1;
        for(int j=0;j<5;j++)
        {
            if(pp[j]==5 )
            f1++;
            if(f1>=5)
            {
                wq=er;
                break;
            }
            if(qq[j]==5 )
            f1++;
            if(f1>=5)
            {
                wq=er;
                break;
            }
      if(f1>=5)
      {wq=er;
      break;
      }
}
}

//this function here is also used to calculate variables and it depends on the above mentioned function.
void greatest(int pp[5],int qq[5],int &tra,int &luf,int &a,int &j)
{
      int l,g[4];
      a=0;
      g[0]=pp[j];
      g[1]=qq[j];
      g[2]=tra;
      g[3]=luf;
      for(int i=0;i<4;i++)
      {
          if(g[i]>=a)
            a=g[i];
      }
}
//This function is used for only one purpose that is to print / while number are checked! and to print table
void print(int Arr[25][4])
{
   for(int i=0;i<25;i++)
    {
        gotoxy(Arr[i][1],Arr[i][2]);
        printf("%2d",Arr[i][0]);
        if(Arr[i][3]==1)
        {
            gotoxy(Arr[i][1]+2,Arr[i][2]);
            printf("/");
        }
    }
}
//This is for the calculation of time as the score is given and as the score depend on the time
void game(int start,int end,int gain,int &score )
{
      float time;
      time=(end-start)/CLK_TCK;    //start represent the time of the computer CLK_TCK means number of clock ticks per second
      score=(gain*100)/time;
}


//Tis is the most important function in this program as in this program data is entered in tables and game is played:
void input(int &r,int Arr[25][4],int d[25][4],int X[5],int Y[5],int X1[5],int Y1[5],int &score)
{
    int gain,tra,luf,t,s,wq,er,w;
    int c[25],pp[5],qq[5];
    int f1=0,f2=0,w1=5,w2=10,op=0,b=25;
    clock_t start,end;
    start=clock();
  for(int i=0;i<25;i++)
  {
      c[i]=i+1;
  }
   for(int i=0;i<b;i++)
    {
        system("cls");
        design2();
        //to print array
        print(Arr);
        //Label 3
        First:
        if(i>0)
        {
            gotoxy(4,11);
            printf("COMPUTER's Choice is :%d",s);
        }
            gotoxy(4,13);
            printf("Enter Number of your choice:");
            fflush(stdin);
            scanf("%d",&r);
            if(r<=25)
            {
                for(int j=0;j < b;j++)
                {
                    if(c[j]==r)
                    {
                        s=c[j];   //here s is the choice of computer which is equal to that of my "choice" it will update.
                        w=j;
                        goto HR2; //break was supposed to be used here but loops were required in the following that was difficult
                    }
                }
                    if(c[r-1]!=r)  // just to check whether it is already checked or not
                    {
                        system("cls");
                        design2();
                        print(Arr);
                        gotoxy(4,9);
                        printf("This number is already CHECKED...........");
                        goto First;
                    }
            }
            else
            {
                    gotoxy(4,9);
                    printf("NOTE!!! Enter a number from the board...");}
                HR2:

     Arr[s-1][3]=1;  //the value that was given above in keep function was "0" here it is updated for the purpose to print /
     gotoxy(Arr[s-1][1]+2,Arr[s-1][2]);
     printf("/");    //to print / beside it
     d[s-1][3]=1;    //d is here is like a sample or decoy in the main it will be ARR1 that is of computers table
     for(int j=w; j<b ;j++)
     {
         c[j]=c[j+1];//the purpose was to update the value
     }
    b=b-1;
	if(rand()%999%1==0)  //this is always TRUE
      {
          //pinch(Arr,X,Y,qq,pp,tra,luf); //go above in the function the function are just given some values that will be used to determine some conditions only
          shot(Arr,X,Y,wq,er,pp,qq,f1,tra,luf); //here  this function is also used to determine some conditions
          if(wq==er||f1>=5)
          {
                system("cls");
                design2();
                print(Arr);
                print(d);
                gotoxy(4,11);
                gain=60;
                end = clock();          //clock is a function in time.h library to calculate time of execution of program,end is used to convert them in seconds
                game(start,end,gain,score);
                Sleep(5000);
                system("cls");
                design3();
                Sleep(1000);
                gotoxy(13,11);
                printf("Congrats !!!!! You Won And Your Score is :%d ",score);
                break;
            }


      //pinch(d,X1,Y1,qq,pp,tra,luf);
      shot(d,X1,Y1,wq,er,pp,qq,f2,tra,luf);
      if(wq==er || f2>=5)
      {
          system("cls");
          design2();
          print(Arr);
          print(d);
          gotoxy(4,11);
          gain=30;
          end=clock();
          game(start,end,gain,score);
          printf("SHIMATA !!! Computer Won .. You Score is :%d",score);
          break;
      }
    }

    for(int k=0;k<25;k++)
    {
     if(rand()%c[k]!=0)
      {

       //pinch(d,X1,Y1,qq,pp,tra,luf);
       shot(d,X1,Y1,wq,er,pp,qq,f2,tra,luf);
       // printf("eneasdasdasHtesla:");
       // scanf("%d",&q);
      if(wq==er || f2>=5)
      {
           //printf("enetesladsada:");
        //scanf("%d",&q);
          system("cls");
          design2();
          print(Arr);
          print(d);
          gotoxy(4,11);
          gain=50;
          end=clock();
          game(start,end,gain,score);
          printf("Shimata !! Computer Won .. Your score is :%d",score);
          break;
      }
      //pinch(Arr,X,Y,qq,pp,tra,luf);
      shot(Arr,X,Y,wq,er,pp,qq,f1,tra,luf);
      if(wq==er || f1>=5)
      {
          system("cls");
          design2();
          print(Arr);
          print(d);
          gotoxy(4,11);
          gain=97;
          end=clock();
          game(start,end,gain,score);
                Sleep(5000);
                system("cls");
                design3();
                Sleep(1000);
          gotoxy(13,11);
          printf("Congrats!! You WON And your score is :%d",score);
          break;
      }
    }
   }
      w1=5;w2=10;
      //pinch(d,X1,Y1,qq,pp,tra,luf);
      if(b<=25)
        {
             for(int j=0;j<5;j++)
            {
                 greatest(pp,qq,tra,luf,op,j);
                for(i=0;i<25;i++)
                {
                    if(op==pp[j] &&pp[j]>=1 && Y1[j]==d[i][2] && d[i][3]!=1)
                    {
                        d[i][3]=1;
                        Arr[i][3]=1;
                        w1=w2;
                        break;        //here the result would be the same but the conditions are different
                    }
                    if(op==qq[j]&&X1[j]==d[i][1] && d[i][3]!=1 && qq[j]>=1)
                    {
                        d[i][3]=1;
                        Arr[i][3]=1;
                        w1=w2;
                        break;
                    }
                    if(op==tra &&X1[j]==d[i][1] && Y1[j]==d[i][2] && d[i][3]!=1)
                    {
                        d[i][3]=1;
                        Arr[i][3]=1;
                        w1=w2;
                        break;
                    }
                    if(op==luf &&X1[j]==d[i][1] && Y1[4-j]==d[i][2] && d[i][3]!=1)
                    {
                        d[i][3]=1;
                        Arr[i][3]=1;
                        w1=w2;
                        break;
                    }
                }
     if(w1==w2)
     {
         gotoxy(Arr[i][1]+2,Arr[i][2]);
        printf("/");
        s=d[i][0];
       for(int m=0;m<b;m++)
        {
            if(d[i][0]==c[m])
            {
                w=m;
                break;
            }
        }
	for(int l=w;l<b;l++)
	{
	    c[l]=c[l+1];
    }
        b=b-1;
   }
   break;
            }
    }
    if(w1!=w2)
    {
        t=rand()%b;
        for(int m=0;m<b;m++)
        {
            if(c[t]==c[m])
            {
                w=m;
                break;
            }
        }
      d[c[t]-1][3]=1;
      Arr[c[t]-1][3]=1;
      gotoxy(Arr[c[t]-1][1]+2,Arr[c[t]-1][2]);
      printf("/");
      s=d[c[t]-1][0];
      for(int j=w;j<b;j++)
        {
            c[j]=c[j+1];
        }
      b=b-1;
    }
      //pinch(d,X1,Y1,qq,pp,tra,luf);
      shot(d,X1,Y1,wq,er,pp,qq,f2,tra,luf);
      if(wq==er || f2>=5)
      {
          system("cls");
          design2();
          print(Arr);
          print(d);
          gotoxy(4,11);
          gain=70;
          end=clock();
          game(start,end,gain,score);
          printf("SHIMATA !! Computer WON... Your score is :%d",score);
          break;
      }
          //pinch(Arr,X,Y,qq,pp,tra,luf);
          shot(Arr,X,Y,wq,er,pp,qq,f1,tra,luf);
            if(wq==er || f1>=5)
            {
                system("cls");
                design2();
                print(Arr);
                print(d);
                gotoxy(4,11);
                gain=97;
                end=clock();
                game(start,end,gain,score);
               Sleep(5000);
                system("cls");
                design3();
                Sleep(1000);
                gotoxy(13,11);
                printf("Congrats ! You WON.. Your score is %d:",score);
                break;
            }

      else
        {
            gotoxy(4,9);
            printf("NOTE!!! Enter a number from the board...");
            goto First;
        }
    }
}
