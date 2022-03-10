#include<iostream>
using namespace std;
string n1,n2;
int row,column;
bool tie=false;;
char token = 'X';
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void f1()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
                {cout<<"\t\t\t";}
            cout<<" "<<space[i][j]<<" ";
            if(j!=2)
                cout<<"|";
        }
        cout<<"\n";
        if(i!=2)
        {
            cout<<"\t\t\t------------\n";
        }
    }
}
void f2()
{
    int digit;
    if(token=='X')
    {
        cout<<n1<<", please enter position: ";
        cin>>digit;
    }
     if(token=='O')
    {
        cout<<n2<<", please enter position: ";
        cin>>digit;
    }
    switch(digit)
    {
    case 1:
        row=0;
        column=0;
        break;
    case 2:
        row=0;
        column=1;
        break;
    case 3:
        row=0;
        column=2;
        break;
        case 4:
        row=1;
        column=0;
        break;
        case 5:
        row=1;
        column=1;
        break;
    case 6:
        row=1;
        column=2;
        break;
        case 7:
        row=2;
        column=0;
        break;
        case 8:
        row=2;
        column=1;
        break;
        case 9:
        row=2;
        column=2;
        break;
        default:
            cout<<"Invalid position !!\n";
    }
    if(token=='X' && space[row][column]!='X' && space[row][column]!='O')
    {
        space[row][column] = 'X';
        token = 'O';
    }
     else if(token=='O' && space[row][column]!='X' && space[row][column]!='O')
    {
        space[row][column] = 'O';
        token = 'X';
    }
    else
    {
        cout<<"No empty box available \n";
        f2();
    }
}
bool f3()
{
    for(int i=0;i<3;i++)
    {
        if((space[i][0]==space[i][1]&&space[i][1]==space[i][2]&&space[i][0]==space[i][2])|| (space[0][i]==space[1][i]&&space[1][i]==space[2][i]&&space[0][i]==space[2][i]))
            return true;
    }
    if((space[1][1]==space[0][0]&&space[1][1]==space[2][2]&&space[0][0]==space[2][2])|| (space[0][2]==space[1][1]&&space[1][1]==space[2][0]&&space[0][2]==space[2][0]))
        return true;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j]!='X'&&space[i][j]!='O')
            {
                return false;
            }
        }
    }
    tie=true;
    return false;
}
int main()
{
    cout<<"\t\t\t-----------------------------------------\t\t\t"<<endl;
    cout<<"\t\t\t   TIC TAC TOE  (By Adithya Nanuvala)"<<endl;
    cout<<"\t\t\t-----------------------------------------\t\t\t"<<endl;
    cout<<"Enter first player's name: ";
    cin>>n1;
    cout<<"Enter second player's name: ";
    cin>>n2;
    cout<<n1<<", you are gonna play first."<<endl;
    cout<<n2<<", your's is second turn."<<endl<<endl;
    while(!f3())
    {
        f1();
        f2();
        f3();
    }
    if(token =='X' && tie==false)
    {
        cout<<n2<<", you are the winner.\n";
        f1();
    }
    else if(token =='O' && tie==false)
    {
        cout<<n1<<", you are the winner.\n";
        f1();
    }
    else if(tie==true){
        cout<<"Draw match! \n";
    }

}
