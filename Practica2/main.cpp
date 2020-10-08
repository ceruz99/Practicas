#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void problem2();

int main(){
    int selection=1;
    while(selection!=0){
        cout<<"Ingrese el numero del problema que desea realizar o ingrese 0 para salir "<<endl; cin>>selection;
        switch (selection) {
            case 2:{
            problem2();
            }

            case 3:{

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
