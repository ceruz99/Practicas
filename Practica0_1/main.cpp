// Juan Camilo Mazo Castro. Practica 0 punto 1 grupo 6 laboratorio informática 2.

#include <iostream>

using namespace std;

int main()
{
    char letter='A';
    for(int i=0;i<13; i++)
    {   if(i<7)
        {
          letter='A';
          for (int j=0;j<=i; j++)
          {
              cout << letter;
              letter+=1;
          }
          for(int j=0; j<11-(2*i);j++)
             cout<<' ';
          letter='A'+i;
          for (int j=0;j<=i; j++)
          {
             if(letter!='G')
             {
               cout << letter;
             }
             letter-=1;
          }
         }
        else
        {

            letter='A';
            for(int j=13-i;j>0;j-=1)
            {
                cout<<letter;
                letter+=1;
            }
            for(int j=0;j<1+((i-7)*2);j++){
                cout<<" ";
            }
            letter-=1;
            for(int j=13-i;j>0;j-=1){
                cout<<letter;
                letter-=1;
            }
        }
     cout <<endl;
    }
    return 0;
}
