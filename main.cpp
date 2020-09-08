/*This chess engine is created by Abhinav
This is a 2-player chess game
Use position address like a1,c3 etc to move your pieces
Enjoy!!
*/

#include <iostream>

using namespace std;

int board[8][8];

void showBoard();
void pawn(int,int,int,int,int);
int isMate();
void rook(int, int ,int,int, int,int);
void knight(int,int,int,int,int);
void bishop(int,int,int,int,int,int);
void queen(int,int,int,int,int);
void king(int,int,int,int,int);
void en_passant(int,int ,int,int,int);
void castling(int);

int main()
{
    int j, moves=0,running=0,sy,ey,sx,ex,flag=0;
    int isMoveValid=0;
    string startpt,endpt;
    for (int i=0;i<8;i++)
        for (j=0;j<8;j++)
        board[i][j]=0;

    showBoard();

    cout<<"\n";
    /*   BLACK----> pawn=1,rook=3, knight=5, bishop=7, queen=9, king=11*/

    board[0][0]=4;
    board[0][1]=6;
    board[0][2]=8;
    board[0][3]=10;
    board[0][4]=12;
    board[0][5]=8;
    board[0][6]=6;
    board[0][7]=4;

    for (int i=0;i<8;i++)
        board[1][i]=2;

    //    WHITE----->  pawn=2, rook=4, knight=6, bishop=8, queen=10, king=12

    board[7][0]=3;
    board[7][1]=5;
    board[7][2]=7;
    board[7][3]=9;
    board[7][4]=11;
    board[7][5]=7;
    board[7][6]=5;
    board[7][7]=3;

    for (int i=0;i<8;i++)
        board[6][i]=1;

    showBoard();

    while (running==0)
    {
        if (moves%2==0)
        {
            cout<<"White's move\n"<<"Enter starting point\n";
            cin>>startpt;
            cout<<"Enter end point\n";
            cin>>endpt;

            sx=(int)startpt[1]-49;
            ex=(int)endpt[1]-49;

            switch(startpt[0])
            {
                case 'a':sy= 0;break;
                case 'b':sy= 1;break;
                case 'c':sy=2;break;
                case 'd':sy=3;break;
                case 'e':sy=4;break;
                case 'f':sy=4;break;
                case 'g':sy=6;break;
                case 'h':sy=7;break;
                default:sy= 0;
            }

            switch(endpt[0])
            {
                case 'a':ey= 0;break;
                case 'b':ey= 1;break;
                case 'c':ey=2;break;
                case 'd':ey=3;break;
                case 'e':ey=4;break;
                case 'f':ey=5;break;
                case 'g':ey=6;break;
                case 'h':ey=7;break;
                default: ey=0;
            }
        }
        else
        {
            cout<<"Black's move\n"<<"Enter starting point\n";
            cin>>startpt;
            cout<<"Enter end point\n";
            cin>>endpt;

            sx=(int)startpt[1]-49;
            ex=(int)endpt[1]-49;

            switch(startpt[0])
            {
                case 'a':sy= 0;break;
                case 'b':sy= 1;break;
                case 'c':sy=2;break;
                case 'd':sy=3;break;
                case 'e':sy=4;break;
                case 'f':sy=4;break;
                case 'g':sy=6;break;
                case 'h':sy=7;break;
                default:sy= 0;
            }

            switch(endpt[0])
            {
                case 'a':ey= 0;break;
                case 'b':ey= 1;break;
                case 'c':ey=2;break;
                case 'd':ey=3;break;
                case 'e':ey=4;break;
                case 'f':ey=5;break;
                case 'g':ey=6;break;
                case 'h':ey=7;break;
                default: ey=0;
            }

        }
 //en passant
        if(board[ex+1][ey]==20&&ex==2&&board[ex][ey]==0&&board[sx][sy]==1)
            {en_passant(sx,sy,ex,ey,moves);
            flag=1;
            }
        else if(board[ex-1][ey]==21 && ex==5 &&board[ex][ey]==0&&board[sx][sy]==2)
            {en_passant(sx,sy,ex,ey,moves);
            flag=1;
    }

    //castling
    int f=0;
    if(board[sx][sy]==11 && sy==4 && sx==7)
    {
        if(ex==7&&ey==2)
        {
            for(int l=1;l<4;l++)
                if(board[7][l]!=0)
                    f=1;
            if(f==0)
            {
                castling(1);
                flag=1;
            }

        }
        else if(ex==7&&ey==6)
        {
            for(int l=5;l<7;l++)
                if(board[7][l]!=0)
                    f=1;
            if (f==0)
            {
                castling(2);
                flag=1;
            }
        }
    }
    else if(board[sx][sy]==12&&sy==4&&sx==0)
    {
        if(ex==0&&ey==2)
        {
            for(int l=1;l<4;l++)
                if(board[0][l]!=0)
                    f=1;
            if(f==0)
            {
                castling(3);
                flag=1;
            }

        }
        else if(ex==0&&ey==6)
        {
            for(int l=5;l<7;l++)
                if(board[0][l]!=0)
                    f=1;
            if (f==0)
            {
                castling(4);
                flag=1;
            }
        }
    }

    if(flag==0){
        switch(board[sx][sy])
        {
            case 1:pawn(sx,sy,ex,ey, moves);break;
            case 2:pawn(sx,sy,ex,ey,moves);break;
            case 20:pawn(sx,sy,ex,ey,moves);break;
            case 21:pawn(sx,sy,ex,ey,moves);break;
            case 3:rook(sx,sy,ex,ey,moves,0);break;
            case 4:rook(sx,sy,ex,ey,moves,0);break;
            case 5:knight(sx,sy,ex,ey,moves);break;
            case 6:knight(sx,sy,ex,ey,moves);break;
            case 7:bishop(sx,sy,ex,ey,moves,0);break;
            case 8:bishop(sx,sy,ex,ey,moves,0);break;
            case 9:queen(sx,sy,ex,ey,moves);break;
            case 10:queen(sx,sy,ex,ey,moves);break;
            case 11:king(sx,sy,ex,ey,moves);break;
            case 12:king(sx,sy,ex,ey,moves);break;
            default:cout<<"Empty square!!";
        }
    }
        moves++;
        flag=0;

        cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<" "<<board[ex][ey]<<"\n";

        showBoard();

        if (isMate()==1)
            {running=1;
            cout<<"Checkmate";
            }
        else
            continue;
    }

    return 0;
}

//#####################  Function to display the board   ########################

void showBoard()
{
    cout<<"   A B C D E F G H\n   ---------------\n";
        for (int i=0;i<8;i++)
            {
                cout<<i+1<<"| ";
                for (int j=0;j<8;j++)
                cout<<board[i][j]<<" ";
                cout<<"\n";
            }
}

void pawn(int sx, int sy,int ex, int ey, int playerTurn)
{
   cout<<sx<<" "<<ex<<" "<<sy<<" "<<ey<<" "<<board[ex][ey]<<"\n";
    int stepCount=ex-sx;

   if (playerTurn%2==0)

   {
       if (board[ex][ey]==0 && ex==(sx+1)  && ey==sy  &&stepCount==1)
        {
            board[sx][sy]=0;
            board[ex][ey]=2;
        }
        else if (stepCount==2 && board[ex][ey]==0 && ey==sy && ex==(sx+2)&& board[ex-1][ey]==0&&ex==3)
        {
            board[sx][sy]=0;
            board[ex][ey]=20;
        }
        else if(board[ex][ey]!=0&&board[ex][ey]%2!=0 && ex==(sx+1)&&(ey==sy-1||ey==sy+1))
        {
            board[sx][sy]=0;
            board[ex][ey]=2;
        }
        else
            cout<<"MOVE NOT POSSIBLE\n";

   }
   else
   {
       if (board[ex][ey]==0 && ex==(sx-1)  && ey==sy  && stepCount==-1)
        {
            board[sx][sy]=0;
            board[ex][ey]=1;
        }
        else if(stepCount==(-2) && board[ex][ey]==0 && ey==sy && ex==(sx-2)&&board[ex+1][ey]==0&&ex==4)
        {
            board[sx][sy]=0;
            board[ex][ey]=21;
        }
        else if(board[ex][ey]!=0&& board[ex][ey]%2==0&&ex==(sx-1)&& board[ex][ey]>0&&(ey==sy-1||ey==sy+1))
        {
            board[sx][sy]=0;
            board[ex][ey]=1;
        }
        else
            cout<<"MOVE NOT POSSIBLE\n";
        cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<"\n";

        for (int i=0;i<8;i++)
            {
                for (int j=0;j<8;j++)
                cout<<board[i][j]<<" ";
                cout<<"\n";
            }
   }
}

void rook(int sx, int sy, int ex, int ey, int playerTurn, int isQueenKing)
{
    int flag=0;
    if(sx==ex&&sy<ey)
    {
        for(int c=sy+1;c<ey;c++)
        {
            if (board[sx][c]!=0)
                flag=1;
        }
    }
    else if(sx==ex&&sy>ey)
    {
        for (int c=ey+1;c<sy;c++)
        {
            if (board[sx][c]!=0)
                flag=1;
        }
    }
   else if(sy==ey&&sx>ex)
    {
        for (int c=ex+1;c<sx;c++)
        {
            if (board[c][sy]!=0)
                flag=1;
        }
    }
    else if(sy==ey&&sx<ex)
    {
        for (int c=sx+1;c<ex;c++)
        {
            if (board[c][sy]!=0)
                flag=1;
        }
    }
    if (flag==0)
    {
        if (playerTurn%2==0)
        {
            if(board[ex][ey]%2!=0||board[ex][ey]==0)
                if (((sx==ex)||(ey==sy))&& (board[ex][ey]%2!=0||board[ex][ey]>=0))
                {
                    board[sx][sy]=0;
                    if (isQueenKing==0)
                        board[ex][ey]=4;
                    else if(isQueenKing==2)
                        board[ex][ey]=12;
                    else
                        board[ex][ey]=10;
                }
                else
                    cout<<"MOVE NOT POSSIBLE";
            else
                cout<<"You cannot attack your own player";
        }
        else
        {
           if (((sx==ex)||(ey==sy))&&board[ex][ey]%2==0)
            {
                board[sx][sy]=0;
                if (isQueenKing==0)
                        board[ex][ey]=3;
                else if(isQueenKing==2)
                        board[ex][ey]=11;
                else
                        board[ex][ey]=9;
            }
            else
                cout<<"MOVE NOT POSSIBLE";
        }
    }
    else
        cout<<"There is a piece in middle";
}

void knight(int sx, int sy, int ex, int ey, int playerMoves)
{
    if (playerMoves%2==0)
    {
        if(board[ex][ey]%2!=0||board[ex][ey]==0)
            if(((ex==(sx+2)&&ey==(sy+1))||(ex==(sx+1)&&ey==(sy+2))||(ex==(sx+2)&&ey==(sy-1))||(ex==(sx+1)&&ey==(sy-2))||(ex==(sx-2)&&ey==(sy-1))||(ex==(sx-1)&&ey==(sy-2))||(ex==(sx-2)&&ey==(sy+1))||(ex==(sx-1)&&ey==(sy+2)))&&(board[ex][ey]%2!=0||board[ex][ey]>=0))
            {
                board[sx][sy]=0;
                board[ex][ey]=6;
            }
            else
                cout<<"MOVE NOT POSSIBLE##";
        else
            cout<<"You cant attack your own player";

    }
    else
    {
      if(((ex==(sx+2)&&ey==(sy+1))||(ex==(sx+1)&&ey==(sy+2))||(ex==(sx+2)&&ey==(sy-1))||(ex==(sx+1)&&ey==(sy-2))||(ex==(sx-2)&&ey==(sy-1))||(ex==(sx-1)&&ey==(sy-2))||(ex==(sx-2)&&ey==(sy+1))||(ex==(sx-1)&&ey==(sy+2)))&&(board[ex][ey]%2==0))
      {
          board[sx][sy]=0;
          board[ex][ey]=5;
      }
      else
            cout<<"MOVE NOT POSSIBLE";
}
}

void bishop(int sx, int sy,int ex,int ey, int playerMoves, int isQueenKing)
{
    int m,n,i,flag=0;
    m=sx;
    n=sy;
    if(playerMoves%2==0)                                                //if(board[ex][ey]%2!=0||board[ex][ey]==0)
    {
        if(board[ex][ey]%2!=0||board[ex][ey]==0)
        {
            if(sx>ex&&sy>ey)
            {
                cout<<"~~~~~\n";
                //stepNo=sx-ex;
                for (i=sx-1;i>ex;i--)
                {
                    if(board[i][sy-1]==0)
                    {
                        sy--;
                   }
                   else
                    flag=1;
                }
                sy--;
            }

            else if(sx>ex&&sy<ey)
            {
                cout<<"@@@@@\n";
                for (i=sx-1;i>ex;i--)
                {
                    if(board[i][sy+1]==0)
                    {
                        sy++;
                    }
                    else
                    flag=1;
                }
                sy++;
            }
            else if(sx<ex&&sy<ey)
            {
                cout<<"!!!!!\n";
                for (i=sx+1;i<ex;i++)
                {
                    if(board[i][sy+1]==0)
                    {
                        sy++;
                    }
                    else
                    flag=1;
                }
                sy++;
            }
            else if(sx<ex&&sy>ey)
            {

                for (i=sx+1;i<ex;i++)
                {
                    if(board[i][sy-1]==0)
                    {
                        sy--;
                        cout<<"*****\n";
                    }
                    else
                    flag=1;
                }
                sy--;
            }

            if (flag==0)
            {
                if (isQueenKing==0)
                        board[i][sy]=8;
                else if(isQueenKing==2)
                    board[i][sy]=12;
                else
                        board[i][sy]=10;
                board[m][n]=0;
            }
            else{
                cout<<"pieces in middle\n";
            }
        }
        else
            cout<<"cannot attack own pieces";
        }
    else
    {
        if(board[ex][ey]%2==0)
        {
            if(sx>ex&&sy>ey)
                {
                    cout<<"~~~~~\n";
                    //stepNo=sx-ex;
                    for (i=sx-1;i>ex;i--)
                    {
                        if(board[i][sy-1]==0)
                        {
                            sy--;
                       }
                       else
                        flag=1;
                    }
                    sy--;
                }

                else if(sx>ex&&sy<ey)
                {
                    cout<<"@@@@@\n";
                    for (i=sx-1;i>ex;i--)
                    {
                        if(board[i][sy+1]==0)
                        {
                            sy++;
                        }
                        else
                        flag=1;
                    }
                    sy++;
                }
                else if(sx<ex&&sy<ey)
                {
                    cout<<"!!!!!\n";
                    for (i=sx+1;i<ex;i++)
                    {
                        if(board[i][sy+1]==0)
                        {
                            sy++;
                        }
                        else
                        flag=1;
                    }
                    sy++;
                }
                else if(sx<ex&&sy>ey)
                {

                    for (i=sx+1;i<ex;i++)
                    {
                        if(board[i][sy-1]==0)
                        {
                            sy--;
                            cout<<"*****\n";
                        }
                        else
                        flag=1;
                    }
                    sy--;
                }

                if (flag==0)
                {
                    if (isQueenKing==0)
                        board[i][sy]=7;
                    else if(isQueenKing==2)
                        board[i][sy]=11;
                    else
                        board[i][sy]=9;
                    board[m][n]=0;
                }
                else{
                    cout<<"pieces in middle\n";
                }
            }
            else
                cout<<"cannot attack own pieces";
            }

    }

void queen(int sx, int sy, int ex, int ey, int playerTurn)
{
    int dx,dy;
    dx=sx-ex;
    dy=sy-ey;
    if (dx<=0)
        dx*=(-1);
    if (dy<=0)
        dy*=(-1);
    if(sx==ex||sy==ey)
    {
        rook(sx,sy,ex,ey,playerTurn,1);
    }
    else if(dx==dy)
    {
        bishop(sx,sy,ex,ey,playerTurn,1);
    }
    else
        cout<<"Invalid move";
}

void king(int sx, int sy, int ex, int ey, int playerTurn)
{
    int dx,dy;
    dx=sx-ex;
    dy=sy-ey;
    if (dx<=0)
        dx*=(-1);
    if (dy<=0)
        dy*=(-1);
    if((sx==ex&&dy==1)||(dx==1&&sy==ey))
    {
        rook(sx,sy,ex,ey,playerTurn,2);
    }
    else if(dx==1&&dy==1)
        {
            bishop(sx,sy,ex,ey,playerTurn,2);
        }
    else
        cout<<"Invalid move";
}

int isMate()
{
    int j,flag=0;
    for(int i=0;i<8;i++)
        for (j=0;j<8;j++)
            if(board[i][j]==11)
                flag++;
            else if(board[i][j]==12)
                flag++;
    if(flag<2)
        return 1;
    else
        return 0;
}

void en_passant(int sx, int sy, int ex, int ey, int playerTurn)
{
    if(playerTurn%2==0)
    {
        board[ex][ey]=board[sx][sy];
        board[ex-1][ey]=0;
        board[sx][sy]=0;
    }
    else
    {
        board[ex][ey]=board[sx][sy];
        board[ex+1][ey]=0;
        board[sx][sy]=0;


    }
}

void castling(int type)
{
    if(type==1)
    {
        board[7][2]=11;
        board[7][3]=3;
        board[7][0]=0;
        board[7][4]=0;
    }
    else if(type==2)
    {
        board[7][6]=11;
        board[7][5]=3;
        board[7][7]=0;
        board[7][4]=0;
    }
    else if(type==3)
    {
        board[0][2]=12;
        board[0][3]=4;
        board[0][0]=0;
        board[0][4]=0;
    }
    else if(type==4)
    {
        board[0][6]=12;
        board[0][5]=4;
        board[0][7]=0;
        board[0][4]=0;
    }
}
