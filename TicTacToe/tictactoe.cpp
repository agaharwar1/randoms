#include<iostream>
using namespace std;

int result,result1;
char a='-',b='-',c='-',d='-',e='-',f='-',g='-',h='-',i='-';
string name1,name2,name;


int checkresultX()
{
    if(a=='X'&&b=='X'&&c=='X'  ||  d=='X'&&e=='X'&&f=='X'  ||  g=='X'&&h=='X'&&i=='X' ||
       a=='X'&&d=='X'&&g=='X'  ||  b=='X'&&e=='X'&&h=='X'  ||  c=='X'&&f=='X'&&i=='X' ||
       a=='X'&&e=='X'&&i=='X'  ||  c=='X'&&e=='X'&&g=='X')
        return 1;
    else 
        return 0;
}

int checkresult0()
{
    if(a=='0'&&b=='0'&&c=='0'  ||  d=='0'&&e=='0'&&f=='0'  ||  g=='0'&&h=='0'&&i=='0' ||
       a=='0'&&d=='0'&&g=='0'  ||  b=='0'&&e=='0'&&h=='0'  ||  c=='0'&&f=='0'&&i=='0' ||
       a=='0'&&e=='0'&&i=='0'  ||  c=='0'&&e=='0'&&g=='0')
        return 1;
    else 
        return 0;
}

int draw()
{
    if(a!='-'&&b!='-'&&c!='-'&&d!='-'&&e!='-'&&f!='-'&&g!='-'&&h!='-'&&i!='-')
        return 2;
    else
        return 0;
}


void display()
{
    cout<<"\n\n   "<<"|"<<"   "<<"|"<<"   \n";
    cout<<" "<<a<<" | "<<b<<" | "<<c<<" \n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n";
    cout<<"-----------\n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n";
    cout<<" "<<d<<" | "<<e<<" | "<<f<<" \n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n";
    cout<<"-----------\n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n";
    cout<<" "<<g<<" | "<<h<<" | "<<i<<" \n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n\n";

}


void moves(string name,string name1,string name2,char move)
{
    do
    {
        int choice;
        

        cout<<"\n\n"<<name<<"'s move:";
        cin>>choice;
        
        if(choice==1&&a=='-')
        {
            if(move=='X')
            {
                a='X';
            }
            else
            {
                a='0';
            }
            
        }
        else if(choice==2&&b=='-')
        {
            if(move=='X')
            {
                b='X';
            }
            else
            {
                b='0';
            }
        }
        else if(choice==3&&c=='-')
        {
            if(move=='X')
            {
                c='X';
            }
            else
            {
                c='0';
            }
        }
        else if(choice==4&&d=='-')
        {
            if(move=='X')
            {
                d='X';
            }
            else
            {
                d='0';
            }
        }
        else if(choice==5&&e=='-')
        {
            if(move=='X')
            {
                e='X';
            }
            else
            {
                e='0';
            }
        }
        else if(choice==6&&f=='-')
        {
            if(move=='X')
            {
                f='X';
            }
            else
            {
                f='0';
            }
        }
        else if(choice==7&&g=='-')
        {
            if(move=='X')
            {
                g='X';
            }
            else
            {
                g='0';
            }
        }
        else if(choice==8&&h=='-')
        {
            if(move=='X')
            {
                h='X';
            }
            else
            {
                h='0';
            }
        }
        else if(choice==9&&i=='-')
        {
            if(move=='X')
            {
                i='X';
            }
            else
            {
                i='0';
            }
        }
        else
        {
            cout<<"\nInvalid move";
            moves(name,name1,name2,move);
            
        }

        

        display();
        
        result=checkresultX();
        result1=checkresult0();

        if(result==1||result1==1)
		{
			cout<<"\n"<<name<<" won\n";
			break;
		}

        result=draw();

        if(result==2)
		{
			cout<<"\n\nDraw\n";
			break;
		}

        if(move=='X')
        {
            move='0';
        }

        else 
        {
            move='X';
        }

        if(name==name1)
        {
            name=name2;
        }

        else
        {
            name =name1;
        }
        

        

       
    }
    while(true);

}


int main()
{
    cout<<"Player 1 name:";
    cin>>name1;
    cout<<"Player 2 name:";
    cin>>name2;

    name=name1;
    char move='X';

    cout<<"\nPlayer 1 : X";
    cout<<"\nPlayer 2 : 0\n\n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n";
    cout<<" 1 "<<"|"<<" 2 "<<"|"<<" 3 \n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n";
    cout<<"-----------\n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n";
    cout<<" 4 "<<"|"<<" 5 "<<"|"<<" 6 \n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n";
    cout<<"-----------\n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n";
    cout<<" 7 "<<"|"<<" 8 "<<"|"<<" 9 \n";
    cout<<"   "<<"|"<<"   "<<"|"<<"   \n";

    moves(name,name1,name2,move);
    return 0;

}