#include <iostream>

using namespace std;

int main()
{
    int number=0,temporal=0,divisor=1,result=0;
    cout << "Ingrese el numero: "; cin>>number;
    temporal=number;
    while((temporal/10)!=0){
        temporal=temporal/10;
        divisor=divisor*10;
        }
    while(divisor!=0){
        int a=0;
        a=(number/divisor)*(number/divisor);
        result=result+a;
        number=number%divisor;
        divisor=divisor/10;
        }
    cout<<"el resultado es: "<<result<<endl;
    return 0;
}
