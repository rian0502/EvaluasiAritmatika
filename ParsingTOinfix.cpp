/*
Nama Anggota
Bagus tito
Muhammad Febrian
Fajar Adi
*/ 



#include <iostream>
#include  <string>
#include <cstring>
using namespace std;

int main (){
    string kata;
    getline(cin,kata);    
    cout<<"Print : ";
	int N =  kata.length();
    for(int x = 0; x < N ; x++){
        if(kata[x] == '-' && (kata[x-1] == '+' || kata[x-1] == '-' ||kata[x-1] == '*' || kata[x-1] == '/'|| kata[x-1] == '%' )){
            cout << "-1 * ";
        }
        else if (kata[x] == '-' && (kata[x-1] >= '0'|| kata[x-2] >= '0')){
            cout << " " << kata[x] << " ";
        } 
        else if (kata[x] == '-' && kata[x+1] >= '0'){
            cout << kata[x];
        }
        else if (kata[x-1] >= '0' && kata[x] == '-' ){
            cout << " " << kata[x] << " ";
        }
        else if (kata[x] == '-' && kata[x+1] == '(' ){ 
            cout << "-1 * ";
        }
        else if (kata[x] >= '0'){
            cout << kata[x];
        }
        else if (kata[x] == '('){
            cout << kata[x] << " ";
        }
        else if (kata[x] == ')'){
            cout << " " << kata[x];
        }
        else if(kata[x] == '-' && ( kata[x-1] == '*' || kata[x-1] == '+' || kata[x-1] == '-' || kata[x-1] == '/'|| kata[x-1] == '%' )){
            cout << "-1 * ";
        }
        else if (kata[x] == '-' || kata[x] == '+' || kata[x] == '*' || kata[x] == '/' || kata[x] == '%') {
            cout << " " << kata[x] << " ";
        }
	}
    return 0;
}
