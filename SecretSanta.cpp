#include<iostream>
#include<conio.h>
#include<dos.h>
#include<cstdlib>
#include<fstream>
#include<string.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


using namespace std;
class SecretSanta
{   public:
            int n;
            int num[20];
            char names[20][20];
            char gifts[20][20];

    int generateRand(int n);
    void allot(int i);
    void displaySantas();
    void drawdesign();
    void gift(int x);
    void displaygift();
};



int SecretSanta:: generateRand(int max)
{
    int x=(rand() % max)+1;
    return x;

}
void SecretSanta:: allot(int i)
{
  label:
  int x= generateRand(n);
  if(x == i)
  {
    goto label;
  }
  for(int k=1;k<=n;k++)
  {
    if(num[k] == x)
    {
      goto label;
    }
  }
  num[i]=x;
}

void SecretSanta:: displaySantas()
{
  system("CLS");
  int i;int x;
  char ch ='1';
  char ex;
  for(i=1;i<=n;i++)
  {
    system("CLS");
    drawdesign();

    x=num[i];
    cout<<"\n\n\n\t\t\t\t\t\t\t"<<names[i]<<", You are a Secret santa of - "<<names[x]<<endl;
    gift(x);

    if(i!=n)
    {   label1:
        cout<<"\t\t\t\t\t\t\t Press 1 to know the next Santa"<<endl;
        ch=getch();
    }
    if(i==n)
    {   cout<<"\t\t\t\t\t\t\t Merry Christmas folks"<<endl;
        cout<<"Press any key to continue"<<endl;
        ex=getch();

    }
    if(ch!= '1')
    {
        cout<<"Uh-Oh! Invalid Choice re-enter 1 to continue"<<endl;
        goto label1;
    }


  }
   system("CLS");



}
void SecretSanta:: gift(int i)
{
    cout<<"\t\t\t\t\t\t\tWhat gift are you giving to "<<names[i]<<endl;
    cin>>gifts[i];
}
void SecretSanta:: displaygift()
{
    char fname[20];
    cout<<"Enter the filename/n";
    cin >> fname;
    strcat(fname, ".txt");
    ofstream fobj;
    fobj.open(fname);



    int i;
    for(i=1;i<=n;i++)
    {
        cout<<"\t\t\t\t\t\t\t"<<names[i]<<", You received "<<gifts[i]<<" as a gift\n\n"<<endl;
        fobj<<"\t\t\t\t\t\t\t"<<names[i]<<", You received "<<gifts[i]<<" as a gift\n\n";
    }

}
void SecretSanta:: drawdesign()
{

    cout<<"\t\t\t\t    +      \t\t\t\t\t\t\t\t\t\t       +    "<<endl;
    cout<<"\t\t\t\t    *      \t\t\t\t\t\t\t\t\t\t       *     "<<endl;
    cout<<"\t\t\t\t   ***     \t\t\t\t\t\t\t\t\t\t      ***   "<<endl;
    cout<<"\t\t\t\t  *****    \t\t\t\t\t\t\t\t\t\t     *****  "<<endl;
    cout<<"\t\t\t\t *******   \t\t\t\t\t\t\t\t\t\t    ******* "<<endl;
    cout<<"\t\t\t\t*********  \t\t\t\t\t\t\t\t\t\t   *********"<<endl;
    cout<<"\t\t\t\t   | |     \t\t\t\t\t\t\t\t\t\t      | |\n\n\n"<<endl;
}
int main()
{
    system("color 4E");
    char exch;
    SecretSanta obj;
    start:
    cout<<"\t\t\t\t\t\t\t\tWelcome to Secret Santa: The Game\n\n\n";
    obj.drawdesign();

    cout<<"\t\t\t\t\t\t\t    Enter the number of participants in the game\n";
    cin>>obj.n;
    int i;
    if(obj.n == 1)
    {
        cout<<"You cant play with yourself, That's not how the game works\nPress any key to restart \n"<<endl;
        exch=getch();
        system("CLS");
        goto start;
    }
    else if(obj.n <= 0)
    {
        cout<<"Enter a valid number of Participants\nPress any key to restart the game\n"<<endl;
        exch=getch();
        system("CLS");
        goto start;

    }


    cout<<"\t\t\t\t\t\t\t    Enter the names of the "<<obj.n<<" participants\n\n";
    for(i=1;i<=obj.n;i++)
    {
        cin>>obj.names[i];
    }
    for(i=1;i<=obj.n;i++)
    {
      obj.num[i]=0;
    }

    for(int m=1;m<=obj.n;m++)
    obj.allot(m);

    obj.displaySantas();
    obj.displaygift();
    exch;
    while(1)
   {
   cout<<"\t\t\t\t\t\t\tDo you want to play again (Y/N)??"<<endl;
   exch=getch();
   if(exch == 'Y' || exch == 'y')
   {    system("CLS");
       goto start;
   }
   else if(exch == 'N' || exch == 'n')
    exit(0);
   else cout<<"\t\t\t\t\t\t\tRe-enter a valid choice!"<<endl;
   }

    return 0;
}
