#ifndef XO_layout
#define XO_layout
#include<windows.h>
void gotoxy(int x_cordinate,int y_cordinate)
{
    COORD c;
    c.X=x_cordinate;                                    ///  get cursor to specific position
    c.Y=y_cordinate;;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void horizontal_line(int x1,int y1,int x2,char print)
{
    int start_point,end_point;
    for(start_point=x1,end_point=y1;start_point<=x2;start_point++)          ///  draw horizontal line
    {
        gotoxy(start_point,end_point);
        std::cout<<print;
    }
}
void vertical_line(int x1,int y1,int y2,char print)
{
    int start_point,end_point;
    for(start_point=x1,end_point=y1;end_point<=y2;end_point++)          ///  draw vertical line
    {
        gotoxy(start_point,end_point);
        std::cout<<print;
    }
}
void slant_line()
{
    int x_refernce=38,y_reference=9,i;
    for(i=0;i<13;i++)
    {
        gotoxy(x_refernce,y_reference);                                         ///  draw slant line
        std::cout<<"*";
        x_refernce+=3;
        y_reference++;
    }
}
void reverse_slant_line()
{
    int x_refernce=74,y_reference=9,i;
    for(i=0;i<13;i++)
    {
        gotoxy(x_refernce,y_reference);                                 ///  draw reverse slant line
        std::cout<<"*";
        x_refernce-=3;
        y_reference++;
    }
}
void match_line(int match_l,int l_code)
{
    switch(l_code)
    {
    case 1:
        switch(match_l)
        {
        case 0:
            horizontal_line(32,11,80,'*');
            break;
        case 1:
            horizontal_line(32,16,80,'*');                          ///  horizontal matches
            break;
        case 2:
            horizontal_line(32,21,80,'*');
            break;
        }
        break;
    case 2:
        switch(match_l)
        {
        case 0:
            vertical_line(39,7,24,'*');
            break;
        case 1:
            vertical_line(56,7,24,'*');                 ///  vertical matches
            break;
        case 2:
            vertical_line(71,7,24,'*');
            break;
        }
        break;
    case 3:
       slant_line();    ///  slant matches
        break;
    case 4:
        reverse_slant_line();   ///  reverse slant matches
        break;

    }

}
#endif // XO_layout



