////*********************************************Tic Tac Toe OR X and O******************************************************************************************
#include<iostream>
#include<stdlib.h>
#include"layout.h"
#include<string>
using namespace std;
string check_for_matches(string);
void add_to_XOmatrix(int ,int,string);
void get_indices(int );
void loadFrame();
void loadValues();
void refresh_XO_matrix();
string XO_matrix[3][3];
int cordinates[2];
int line_code,line_index;
int main()
{
    int check_count;            ///  this is to check the draw condition i.e. if check_count >9 then game will draw as all places are filled completely
    string value;
    int position;
    int i,j;            /// co-ordinates
    char play='Y';
    while(play=='Y'|play=='y')
    {
        check_count=0;
        refresh_XO_matrix();
         while(check_count<9)
        {
            cout<<"\n\t******************************************************X & O GAME!!!**************************************************************";
            cout<<"\n\t Player 1----->[X]";                     ///  player 1 is X
            cout<<"\n\n\t Player 2----->[O]";                   /// player 2 is O
            loadFrame();        /// load the X O frame
            loadValues();       /// load the values in XO_matrix
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t********************************************This is player 1 chance***********************************";
            cout<<"\n\t Enter Position:=";
            cin>>position;                              /// get position to enter
            get_indices(position);                  /// send position to get indices of matrix XO_matrix
            i=cordinates[0];
            j=cordinates[1];
            ///this loop is to check whether values are entered at  empty spaces or not
            while(XO_matrix[i][j]=="X"|XO_matrix[i][j]=="O")
            {
                system("cls");
                cout<<"\n\t******************************************************X & O GAME!!!**************************************************************";
                cout<<"\n\t Player 1----->[X]";
                cout<<"\n\n\t Player 2----->[O]";
                loadFrame();
                loadValues();
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t********************************************This is player 1 chance***********************************";
                cout<<"\n\t Please Enter Correct Position:=";
                cin>>position;
                get_indices(position);
                i=cordinates[0];
                j=cordinates[1];
            }
            add_to_XOmatrix(i,j,"X");       ///add to X to XO_matrix
            check_count++;
            value=check_for_matches("X");       /// check for three consecutive X match in XO_matrix
            system("cls");
            if(value=="X"|check_count==9)
            break;

            cout<<"\n\t******************************************************X & O GAME!!!**************************************************************";
            cout<<"\n\n\t Player 1----->[X]";
            cout<<"\n\n\t Player 2----->[O]";
            loadFrame();
            loadValues();
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t********************************************This is player 2 chance***********************************";
            cout<<"\n\t Enter Position:=";
            cin>>position;
            get_indices(position);
            i=cordinates[0];
            j=cordinates[1];
            while(XO_matrix[i][j]=="X"|XO_matrix[i][j]=="O")
            {
                system("cls");
                cout<<"\n\t****************4**************************************X & O GAME!!!**************************************************************";
                cout<<"\n\t Player 1----->[X]";
                cout<<"\n\n\t Player 2----->[O]";
                loadFrame();
                loadValues();
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t********************************************This is player 2 chance***********************************";
                cout<<"\n\t Please Enter Correct Position:=";
                cin>>position;
                get_indices(position);
                i=cordinates[0];
                j=cordinates[1];
            }
            add_to_XOmatrix(i,j,"O");       ///add to X to XO_matrix
            check_count++;
            value=check_for_matches("O");
            system("cls");
            if(value=="O")
            break;
        }
        system("cls");
        cout<<"\n\t******************************************************X & O GAME!!!**************************************************************";
        cout<<"\n\n\t Player 1----->[X]";
        cout<<"\n\n\t Player 2----->[O]";
        loadFrame();
        loadValues();
        if(value=="X")
        {
            match_line(line_index,line_code);
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Player 1 WON!!!!!......................\n";
        }
        else if(value=="O")
        {
            match_line(line_index,line_code);
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Player 2 WON!!!!!......................\n";
        }
        else
            cout<<"\n\n\n\n\n\n\n\t\t\t Match is Draw!!!!........................\n";
        cout<<"\n\t Press 'Y' to Play Again OR Press 'N' to Exit:=";
        cin>>play;
        system("cls");
        refresh_XO_matrix();
    }
    return 0;
}
///  get_indices stores indices in cordinate[]  array according to the position
void get_indices(int choice)
{
    switch(choice)
    {
    case 1:
        cordinates[0]=0;
        cordinates[1]=0;
        break;
    case 2:
        cordinates[0]=0;
        cordinates[1]=1;
        break;
    case 3:
        cordinates[0]=0;
        cordinates[1]=2;
        break;
    case 4:
       cordinates[0]=1;
        cordinates[1]=0;
        break;
    case 5:
        cordinates[0]=1;
        cordinates[1]=1;
        break;
    case 6:
        cordinates[0]=1;
        cordinates[1]=2;
        break;
    case 7:
        cordinates[0]=2;
        cordinates[1]=0;
        break;
    case 8:
        cordinates[0]=2;
        cordinates[1]=1;
        break;
    case 9:
        cordinates[0]=2;
        cordinates[1]=2;
        break;

    }
}
void add_to_XOmatrix(int i,int j,string add_value)
{
    XO_matrix[i][j]=add_value;
}
string check_for_matches(string check_value)
{
    int value_count,i,j;
   for(i=0;i<3;i++)
   {
       value_count=0;
       for(j=0;j<3;j++)
       {
           if(XO_matrix[i][j]==check_value)                          ///  checks for vertical matches
           {
               value_count++;
           }
           if(value_count==3)
           {
                line_code=1;
                line_index=i;
                return check_value;
           }

        }

   }


   for(j=0;j<3;j++)
   {
       value_count=0;
       for(i=0;i<3;i++)
       {
           if(XO_matrix[i][j]==check_value)
           {
               value_count++;                                                               ///  checks for horizontal matches
           }
            if(value_count==3)
            {
                line_code=2;
                line_index=j;
                return check_value;
            }

        }

   }

   value_count=0;
   for(i=0,j=0;i<3&j<3;i++,j++)
   {
        if(XO_matrix[i][j]==check_value)
            value_count++;                                                                      ///  checks for slant matches
    }
    if(value_count==3)
    {
        line_code=3;
        return check_value;
    }


    if(XO_matrix[0][2]==check_value&XO_matrix[1][1]==check_value&XO_matrix[2][0]==check_value)
    {
        line_code=4;                                                                            ///  check for reverse slant
        return check_value;
    }
    else
        return "0";
}

void loadFrame()
{
    horizontal_line(32,12,80,'_');
    vertical_line(48,7,24,'|');                                             ///   Load frame
    horizontal_line(32,18,80,'_');
    vertical_line(64,7,24,'|');
}

void loadValues()
{
    gotoxy(40,10);
    cout<<XO_matrix[0][0];
    gotoxy(55,10);
    cout<<XO_matrix[0][1];
    gotoxy(72,10);
    cout<<XO_matrix[0][2];
    gotoxy(40,15);
    cout<<XO_matrix[1][0];                                      ///   Load Values
    gotoxy(55,15);
    cout<<XO_matrix[1][1];
    gotoxy(72,15);
    cout<<XO_matrix[1][2];
    gotoxy(40,20);
    cout<<XO_matrix[2][0];
    gotoxy(55,20);
    cout<<XO_matrix[2][1];
    gotoxy(72,20);
    cout<<XO_matrix[2][2];
}

void refresh_XO_matrix()
{
    int number=0;
    for(int i=0;i<3;i++)
    {                                                                       /// refresh XO_matrix array after every game
        for(int j=0;j<3;j++)
        {
            XO_matrix[i][j]=to_string(++number);
        }
    }
}
