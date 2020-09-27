#include <iostream>

using namespace std;

int main()
{
    int i=-1;
    while(i!=0){
        cout<<"Introduzcan el probrema que desea realizar, para finalizar introduzca el numero 0. "<<endl;
        cin>>i;       
        switch(i) {



            case 1:{
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
            }


            case 3:{
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


              case 5:{
                int number;
                cout<<"Ingrese un numero impar "<<endl; cin>>number;
                if((number % 2)!=0){
                    int temporal; temporal=number/2;
                    int asterisk; asterisk=-1;
                    for(int j=0;j<((number/2)+1);j++){

                        asterisk+=2;
                        for(int k=(temporal); k>0;k--){
                            cout<<" ";
                        }
                        for(int k=0; k<asterisk;k++){
                            cout<<"*";
                        }
                        for(int k=(temporal); k>0;k--){
                            cout<<" ";
                        }
                        cout<<endl;
                        temporal-=1;
                    }
                    asterisk=number; temporal=1;
                    for(int j=0;j<(number/2);j++){
                        asterisk-=2;
                        for(int k=temporal;k>0;k--){
                            cout<<" ";
                        }
                        for(int k=asterisk;k>0;k--){
                            cout<<"*";
                        }
                        for(int k=temporal;k>0;k--){
                            cout<<" ";
                        }
                        cout<<endl;
                        temporal+=1;
                    }
                }
                else
                    cout<<"El numero ingresado no es un numero impar "<<endl;
            break;
            }

            case 7:{
               int count=0,value=0;
               cout<<"Ingrese un numero"<<endl; cin>>value;
               for(int i=2,j=1,k=1;i<=value;){
                   if(i%2==0){
                        count=count+i;
                   }
                   k=i;
                   i=i+j;
                   j=k;
               }
               cout<<"El resultado de la suma es "<<count<<endl;
            break;
            }

            case 8:{
                int a=0,b=0,c=0,mult=1,result=0;
                cout<<"Ingrese el valor de a "<<endl; cin>>a;
                cout<<"Ingrese el valor de b "<<endl; cin>>b;
                cout<<"Ingrese el valor de c "<<endl; cin>>c;
                int r1=a,r2=b;
                while(r1<c){
                    result=result+r1;
                    cout<<r1;
                    cout<<"+";
                    mult+=1;
                    r1=a*mult;
                }
                mult=1;
                r1=a;r2=b;
                int aux=b;
                while(r2<c){

                    if(r2==a*aux){
                        aux=aux+b;
                    }
                    else{
                        result=result+r2;
                        cout<<r2;
                    }
                    mult+=1;
                    r2=b*mult;
                    if(b*mult+1<c){
                        cout<<"+";
                    }
                    else{
                        break;
                    }
                }
                cout<<"="<<result<<endl;
            break;
            }

            case 10:{
                int n=0,count=1,result=0;
                cout<<"Ingrese un numero n"<<endl; cin>>n;
                i=1;
                while(i<n){
                    count+=2;
                    bool prime=true;
                    for(int j=2; j<count && prime==true;j++){
                        if(count%j==0) prime=false;
                    }
                    if(prime==true){
                        i++;
                        result=count;
                    }
                }
                cout<<"El primo numero "<<n<<" es "<<result<<endl;
            break;
            }


        }
    }

    return 0;
}
