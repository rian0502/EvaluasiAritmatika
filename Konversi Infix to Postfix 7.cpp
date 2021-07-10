#include <iostream>
using namespace std;
int N(char masukkan){
    if(masukkan == '^') return 3;
    else if(masukkan == '*' || masukkan == '/') return 2;
    else if(masukkan == '+' || masukkan == '-') return 1;
    else if(masukkan == '(' || masukkan == ')') return 0;
    else return -1;
}

struct stack{
    int STACK[100];
    char Stack[100];
    int top;
}
;

class konversi{
private:
    stack list;
public:
    void init(){
        list.top = -1;
    }
    void push(char masukkan){
        list.top++;
        list.STACK[list.top] = masukkan;
    }
    void pop(){
        list.top--;
    }
    char Top(){
        return list.STACK[list.top];
    }
    bool isEmpty(){
        if(list.top <= -1)
            return true;
        else
            return false;
    }
