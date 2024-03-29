// Juan Camilo Mazo Castro - Practica 2 Info II UdeA.
// Problemas a resolver: 2,3,5,7,10,11,13,14,16,17
/*                       3,5,7,8,9,11,13,16,17*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void problem2();//problema 2
bool comparison(char [], char [], int );//Toma dos arreglos char y verifica si ambos son iguales.
int lengthArrayChar(char []);//Indica cual es la medida de un arreglo tipo char.
int countDigits(int );//Indica el numero de digitos que tiene un entero.
void makeArrayInt(int *,int ,int );//Realiza un arreglo con los digitos de un entero.
void problem7();//Toma un arreglo char e imprime el arreglo sin los caracteres repetidos.
void romanValue();//Pide una cadena de caracteres con un numero romano y lo transforma a un numero arabigo.
void cinema();//Muestra los asientos del cine, luego permite reservar y cancelar puestos.
void numberStars(int **,int ,int );//Toma la matriz e indica cuántas estrellas hay en ella.
void turnMatrix(int **);// Toma la matriz 5x5 y la gira 90 grados.
void problem16();//Recibe un numero n para crear la matrix nxn e indicar el numero de caminos en esta.
unsigned long int sumDivisor(unsigned long int );//Toma un numero y suma sus divisores exceptuando el mismo numero.

int main(){
    int selection=1;
    while(selection!=0){
        cout<<"Ingrese el numero del problema que desea realizar o ingrese 0 para salir "<<endl; cin>>selection;
        switch (selection) {
            case 2:{
                problem2();
            break;
            }

            case 3:{
                char word1[25]; char word2[25];
                cout<<"Ingrese la primera palabra "<<endl; cin>>word1;
                cout<<"Ingrese la segunda palabra "<<endl; cin>>word2;
                if(lengthArrayChar(word1)!=lengthArrayChar(word2)) cout<<"Las palabras son diferentes "<<endl;
                else{
                    if(comparison(word1,word2,lengthArrayChar(word1))==true) cout<<"Las palabras son iguales "<<endl;
                    else
                        cout<<"Las palabras son diferentes "<<endl;
                }
                cout<<word1<<endl;
                cout<<word2<<endl;
            break;
            }

            case 5:{
                int number=0;
                cout<<"Ingrese el numero entero: "<<endl; cin>>number;
                int numberDigits=countDigits(number);
                int array[numberDigits];
                int *pArray=array;
                makeArrayInt(pArray, number, numberDigits);
                for(int k=0;k<numberDigits;k++){
                    char lyrics=*(pArray+k)+48;
                    cout<<lyrics;
                }
                cout<<endl;
            break;
            }

            case 7:{
                problem7();
            break;
            }

            case 10:{
                romanValue();
            break;
            }

            case 11:{
                cinema();
            break;
            }

            case 13:{
                int filas=0,columnas=0;
                cout<<"Introduzca el numero de filas de la matriz: "; cin>>filas;
                cout<<"Introduzca el numbero de columnas de la matriz: "; cin>>columnas;
                int **matrix;
                matrix= new int *[filas];
                for(int i=0;i<filas;i++){
                    matrix[i]=new int[columnas];
                }
                for(int j=0; j<filas;j++){
                    for(int k=0;k<columnas;k++){
                        cout<<"Ingrese el valor para la posicion ["<<j<<"]["<<k<<"] "<<endl; cin>>*(*(matrix+j)+k);
                    }
                }
                numberStars(matrix,filas,columnas);
                delete [] matrix;
            break;
            }

            case 14:{
                int **matrix;
                matrix= new int *[5];
                for(int i=0;i<5;i++){
                    matrix[i]= new int [5];
                }
                int number=1;
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        *(*(matrix+i)+j)=number;
                        cout<<number<<" ";
                        number+=1;
                    }
                    cout<<endl;
                }
                int answer;
                cout<<"Ingrese 1 para girar la matriz 90 grados "<<endl<<"Ingrese 2 para girar la matriz 180 grados "<<endl<<"Ingrese 3 para girar la matriz 270 grados "<<endl; cin>>answer;
                for(int i=0;i<answer;i++){
                    turnMatrix(matrix);
                }
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        cout<<*(*(matrix+i)+j)<<" ";
                    }
                    cout<<endl;
                }
                delete [] matrix;
            break;
            }

            case 16:{
                problem16();
            break;
            }

            case 17:{
                unsigned long int n=0;
                cout<<"Ingrese el numero n para hallar la suma de los numeros amigables menores que n: "; cin>>n; cout<<endl;
                if(n<285) cout<<"El resultado es 0 ";
                else{
                    unsigned long int result=0;
                    for(unsigned long int i=220;i<n;i++){
                        unsigned long int result1=sumDivisor(i);
                        unsigned long int result2=sumDivisor(result1);
                        if(result2==i && i<n && result2<n && result1!=result2){
                            result=result+i+result1;
                        }
                    }
                    cout<<"El resultado es: "<<result/2<<endl;
                }
            break;
            }
        }
    }
    return 0;
}

void problem2(){
    srand(time(NULL));
    char list[100];
    for(int k=0;k<100;k++){
        list[k]=65+rand()%(91-65);
        cout<<list[k];
    }
    cout<<endl;
    for(int i=65;i<=90;i++){
        int count=0;
        char letter=i;
        for(int j=0;j<100;j++){
            if(letter==list[j]) count+=1;
        }
        if(count>0) cout<<letter<<":"<<count<<endl;
    }
}

int lengthArrayChar(char array[]){
    int count=1;
    int i=1;
    while(i!=0){
        if(array[i]=='\0')
            i=0;
        else{
            count+=1;
            i+=1;
        }
    }
    return count;
}

bool comparison(char array1[],char array2[],int length){
    bool equal=true;
    for(int i=0;i<length && equal==true;i++){
        if(array1[i]!=array2[i]) equal=false;
    }
    return equal;
}

int countDigits(int number){
    int result=1, count=0, j=1;
    while(result!=0){
        result=number/j;
        if(result!=0){
            count+=1;
            j=j*10;
        }
    }
    return count;
}

void makeArrayInt(int *p,int num,int length){
    int divider=1;
    for(int i=1;i<length;i++){
        divider=divider*10;
    }
    int n=0;
    for(int j=0;j<length;j++){
        n=num/divider;
        num=num%divider;
        *(p+j)=n;
        divider=divider/10;
    }
}

void problem7(){
    char word[25];
    cout<<"Ingrese la palabra a la cual se le retiraran las letras repetidas: "<<endl; cin>>word;
    int n=lengthArrayChar(word);
    char newWord[n];
    for(int i=0;i<n;i++){
        newWord[i]='-';
    }
    newWord[0]=word[0];
    int k=1;
    for(int i=1;i<n;i++){
        char lyrics=word[i];
        bool include=true;
        for(int j=0;j<n;j++){
            if(newWord[j]==lyrics){
                include=false;
                break;
            }
        }
        if(include==true){
            newWord[k]=lyrics;
            k+=1;
        }
    }
    newWord[k]='\0';
    for(int l=0;l<n;l++){
        cout<<newWord[l];
        if(newWord[l+1]=='\0') l=n;
    }
    cout<<endl;
}

void romanValue(){
    char romanNumber[25];
    cout<<"Ingrese el numero romano: "<<endl; cin>>romanNumber;
    int result=0, length=lengthArrayChar(romanNumber),repeated=0; bool correct= true;
    for(int I=0;I<length;I++){
        if(romanNumber[I]=='I') repeated+=1;
        else repeated=0;
        if(repeated>3) correct=false;
    }
    repeated=0;
    for(int V=0;V<length;V++){
        if(romanNumber[V]=='V') repeated+=1;
        else repeated=0;
        if(repeated>1) correct=false;
    }
    repeated=0;
    for(int X=0;X<length;X++){
        if(romanNumber[X]=='X') repeated+=1;
        else repeated=0;
        if(repeated>3) correct=false;
    }
    repeated=0;
    for(int L=0;L<length;L++){
        if(romanNumber[L]=='L') repeated+=1;
        else repeated=0;
        if(repeated>1) correct=false;
    }
    repeated=0;
    for(int C=0;C<length;C++){
        if(romanNumber[C]=='C') repeated+=1;
        else repeated=0;
        if(repeated>3) correct=false;
    }
    repeated=0;
    for(int D=0;D<length;D++){
        if(romanNumber[D]=='D') repeated+=1;
        else repeated=0;
        if(repeated>1) correct=false;
    }
    repeated=0;
    for(int M=0;M<length;M++){
        if(romanNumber[M]=='M') repeated+=1;
        else repeated=0;
        if(repeated>3) correct=false;
    }
    if(correct==true){
        int n=0,result2=0;
        for(int i=0;i<length;i++){
            if(i<length-2){
                switch(romanNumber[i]){
                case 'M':{
                    n=1000;
                    break;
                }
                case 'D':{
                    n=500;
                    break;
                }
                case 'C':{
                    n=100;
                    break;
                }
                case 'L':{
                    n=50;
                    break;
                }
                case 'X':{
                    n=10;
                    break;
                }
                case 'V':{
                    n=5;
                    break;
                }
                case 'I':{
                    n=1;
                    break;
                }
                default:{
                    correct=false;
                    i=25;
                    break;
                }
                }
                if(result>=n) result=result+n;
                else result=n-result;
            }
            else{
                switch(romanNumber[i]){
                case 'M':{
                    n=1000;
                    break;
                }
                case 'D':{
                    n=500;
                    break;
                }
                case 'C':{
                    n=100;
                    break;
                }
                case 'L':{
                    n=50;
                    break;
                }
                case 'X':{
                    n=10;
                    break;
                }
                case 'V':{
                    n=5;
                    break;
                }
                case 'I':{
                    n=1;
                    break;
                }
                default:{
                    correct=false;
                    i=25;
                    break;
                }
                }
                if(result2>=n) result2=result2+n;
                else result2=n-result2;
            }
        }
        result=result+result2;
    }
    if(correct==true) cout<<"El numero romano ingresado corresponde al: "<<result<<endl;
    else cout<<"El numero ingresado es invalido "<<endl;
}

void cinema(){
    int **matrix;
    matrix=new int *[15];
    for(int i=0;i<15;i++){
        matrix[i]=new int[20];
    }
    for(int j=0;j<15;j++){
        for(int k=0;k<20;k++){
            *(*(matrix+j)+k)=0;
        }

    }
    bool finished=false;
    while(finished==false){
        for(int j=0;j<15;j++){
            for(int k=0;k<20;k++){
                if((*(*(matrix+j)+k))==0) cout<<"- ";
                else cout<<"+ ";
            }
            cout<<endl;
        }
        char fila, option; int columna;
        cout<<"Ingrese a para reservar un asiento "<<endl<<"Ingrese b para cancelar una reserva "<<endl;
        cin>>option;
        if(option!='a' && option!='b') break;
        cout<<"Ingrese la fila A-O "<<endl; cin>>fila;
        cout<<"Ingrese la columna 1-20 "<<endl; cin>>columna;
        switch (fila) {
        case 'A':{
            if(option=='a') *(*(matrix)+(columna-1))=1;
            else *(*(matrix)+(columna-1))=0;
            break;
        }
        case 'B':{
            if(option=='a') *(*(matrix+1)+(columna-1))=1;
            else *(*(matrix+1)+(columna-1))=0;
            break;
        }
        case 'C':{
            if(option=='a') *(*(matrix+2)+(columna-1))=1;
            else *(*(matrix+2)+(columna-1))=0;
            break;
        }
        case 'D':{
            if(option=='a') *(*(matrix+3)+(columna-1))=1;
            else *(*(matrix+3)+(columna-1))=0;
            break;
        }
        case 'E':{
            if(option=='a') *(*(matrix+4)+(columna-1))=1;
            else *(*(matrix+4)+(columna-1))=0;
            break;
        }
        case 'F':{
            if(option=='a') *(*(matrix+5)+(columna-1))=1;
            else *(*(matrix+5)+(columna-1))=0;
            break;
        }
        case 'G':{
            if(option=='a') *(*(matrix+6)+(columna-1))=1;
            else *(*(matrix+6)+(columna-1))=0;
            break;
        }
        case 'H':{
            if(option=='a') *(*(matrix+7)+(columna-1))=1;
            else *(*(matrix+7)+(columna-1))=0;
            break;
        }
        case 'I':{
            if(option=='a') *(*(matrix+8)+(columna-1))=1;
            else *(*(matrix+8)+(columna-1))=0;
            break;
        }
        case 'J':{
            if(option=='a') *(*(matrix+9)+(columna-1))=1;
            else *(*(matrix+9)+(columna-1))=0;
            break;
        }
        case 'K':{
            if(option=='a') *(*(matrix+10)+(columna-1))=1;
            else *(*(matrix+10)+(columna-1))=0;
            break;
        }
        case 'L':{
            if(option=='a') *(*(matrix+11)+(columna-1))=1;
            else *(*(matrix+11)+(columna-1))=0;
            break;
        }
        case 'M':{
            if(option=='a') *(*(matrix+12)+(columna-1))=1;
            else *(*(matrix+12)+(columna-1))=0;
            break;
        }
        case 'N':{
            if(option=='a') *(*(matrix+13)+(columna-1))=1;
            else *(*(matrix+13)+(columna-1))=0;
            break;
        }
        case 'O':{
            if(option=='a') *(*(matrix+14)+(columna-1))=1;
            else *(*(matrix+14)+(columna-1))=0;
            break;
        }
        default:{
            cout<<"Los valores ingresados son invalidos "<<endl;
        }
        }
    }
    delete [] matrix;
}

void numberStars(int **p,int filas ,int columnas){
    int result=0;
    int count=0;
    for(int i=1;i<(filas-1);i++){
        for(int j=1;j<(columnas-1);j++){
            result=(*(*(p+i)+j)+*(*(p+(i-1))+(j-1))+*(*(p+(i-1))+(j+1))+*(*(p+(i+1))+(j-1))+*(*(p+(i+1))+(j+1)))/5;
            if(result>6) count+=1;
        }
    }
    cout<<"El numero de estrellas encontradas es: "<<count<<endl;
}

void turnMatrix(int **p){
    int **p2;
    p2= new int*[5];
    for(int i=0;i<5;i++){
        p2[i]=new int[5];
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            *(*(p2+i)+j)=*(*(p+i)+j);
        }
    }
    for(int i=0;i<5;i++){
        int k=4;
        for(int j=0;j<5;j++){
            *(*(p+i)+j)=*(*(p2+k)+i);
            k-=1;
        }
    }
    delete [] p2;
}

void problem16(){
    unsigned int n;
    cout<<"Ingrese el numero n para crear la matriz nxn "<<endl; cin>>n;
    long int matrix[n+1][n+1];
    for(unsigned int i=0;i<=n;i++){
        for(unsigned int j=0;j<=n;j++){
            if(i==0 || j==0) matrix[i][j]=1;
            else matrix[i][j]=(matrix[i-1][j])+(matrix[i][j-1]);
        }
    }
    cout<<"La matriz tiene "<<matrix[n][n]<<" caminos. "<<endl;
}

unsigned long int sumDivisor(unsigned long int number){
    unsigned long int sum=1;
    for(unsigned long int i=2; i<number; i++){
        if(number%i==0) sum=sum+i;
    }
    return sum;
}
