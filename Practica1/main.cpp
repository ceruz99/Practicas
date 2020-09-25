#include <iostream>

using namespace std;

int main()
{
    int i=-1;
    while(i!=0){
        cout<<"Introduzcan el probrema que desea realizar, para finalizar introduzca el numero 0. "<<endl;
        cin>>i;
        switch(i) {



            case 1:

                char caracter;
                cout<<"Introduzca el caracter para verificar si es una vocal o una consonante "<<endl; cin>>caracter;
                switch(caracter){
                    case 'a': case 'A': case 'e': case 'E': case 'i': case 'I': case 'o': case 'O': case 'u': case 'U':
                    cout<<"Es una vocal "<<endl;
                    break;
                    case 'b': case 'c': case 'd': case 'f': case 'g': case 'h': case 'j': case 'k': case 'l': case 'm':case 'n': case 'p': case 'q': case 'r': case 's': case 't': case 'v': case 'w': case 'x': case 'y': case 'z': case 'B': case 'C': case 'D': case 'F': case 'G': case 'H': case 'J': case 'K': case 'L': case 'M': case 'N': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'V': case 'W': case 'X': case 'Y': case 'Z':
                    cout<<"Es una consonante "<<endl;
                    break;
                    default:
                    cout<<"No es ni vocal ni una consonante "<<endl;
                    break;
                }
            break;


            case 3:
               int month;
               int day;
               cout<<"Introduzca un mes "<<endl; cin>>month;
               if (month<1 or month>12)
                   cout<<month<<" no es un mes "<<endl;
               else{
                   cout<<"Introduzca un dia "<<endl; cin>>day;
                   switch(month){
                       case 1: case 5: case 7: case 10: case 12:
                       if(day<1 or day>31)
                           cout<<day<<"/"<<month<<" no es una fecha valida "<<endl;
                       else
                           cout<<day<<"/"<<month<<" es una fecha valida "<<endl;
                       break;

                       case 2:
                       if(day<1 or day >29)
                           cout<<day<<"/"<<month<<" no es una fecha valida "<<endl;
                       else if(day==29)
                           cout<<day<<"/"<<month<<" es una fecha valida en años bisiestos "<<endl;
                       else
                           cout<<day<<"/"<<month<<" es una fecha valida "<<endl;
                       break;

                       case 3: case 11:
                       if(day<1 or day >29)
                           cout<<day<<"/"<<month<<" no es una fecha valida "<<endl;
                       else
                           cout<<day<<"/"<<month<<" es una fecha valida "<<endl;
                       break;

                       case 4: case 6: case 8: case 9:
                       if(day<1 or day >30)
                           cout<<day<<"/"<<month<<" no es una fecha valida "<<endl;
                       else
                           cout<<day<<"/"<<month<<" es una fecha valida "<<endl;
                       break;


                       }
                   }
              break;

        }
    }

















    return 0;
}
