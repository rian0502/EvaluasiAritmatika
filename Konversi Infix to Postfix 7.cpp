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
}; konversi SC;

class Eval{
private:
    stack Data;
public:
    void push(int masukkan){
        Data.top++;
        Data.Stack[Data.top] = masukkan;
    }
    void pop(){
        Data.top--;
    }
    int Top(){
        return Data.Stack[Data.top];
    }
}; Eval SE;


bool isOperand(char masukkan);
bool isOperator(char masukkan);
int N(char masukkan);
bool persen(char masukkan1, char masukkan2);
string ITP(string masukkan);

double Operation(int op1, char c, int op2);
bool Operand(char masukkan);
int Evaluate(string masukkan);
int pow(int angka, int exp);

bool isOperand(char masukkan){
    int c = (int)masukkan;
    if(c >= 48 && c <= 57 || c >= 65 && c <= 90 || c >= 97 && c <= 122)//
        return true;
    else
        return false;
}

bool isOperator(char masukkan){
    int c = (int)masukkan;
    if(c == 94 || c >= 42 && c <= 43 || c == 45 || c == 47)//
        return true;
    else
        return false;
}


bool persen(char masukkan1, char masukkan2){
    int c1 = N(masukkan1);
    int c2 = N(masukkan2);

    if(c1 <= c2)
        return true;
    else
        return false;
}

string ITP(string masukkan){
    SC.init();
    int i=0;
    string P = "";
    while(masukkan[i] != '\0'){
        if(isOperand(masukkan[i])){
            P += masukkan[i];
        }
        if(masukkan[i] == '('){
            SC.push(masukkan[i]);
        }
        if(masukkan[i] == ')'){
            while(!SC.isEmpty() && SC.Top() != '('){
                P = P + " " + SC.Top(); SC.pop();
            }
            SC.pop();
        }
        if(isOperator(masukkan[i])){
            if(SC.isEmpty() || SC.Top() == '('){
                SC.push(masukkan[i]);
            }else{
                while(!SC.isEmpty() && SC.Top() != '(' && persen(masukkan[i], SC.Top())){
                    P = P + " " + SC.Top(); SC.pop();
                }
                SC.push(masukkan[i]);
            }
        }
        if(isOperator(masukkan[i]))
            P += " ";
        i++;
    }
    while(!SC.isEmpty()){
        P = P + " " + SC.Top(); SC.pop();
    }
    return P;
}

int pow(int angka, int exp){
    for(int i=1; i<exp; i++)
        angka *= angka;
    return angka;
}

bool Operand(char masukkan){
    int c = (int)masukkan;
    if(c >= 48 && c <= 57)
        return true;
    else if(c >= 65 && c <= 90 || c >= 97 && c <= 122){
        cin.get();
        exit(0);
    }
    else
        return false;
}

double Operation(int op1, char c, int op2){
    if(c == '^')
        return (pow(op1,op2));
    else if(c == '*')
        return (op1 * op2);
    else if(c == '/')
        return (op1 / op2);
    else if(c == '+')
        return (op1 + op2);
    else if(c == '-')
        return (op1 - op2);
    else return 0;
}

int Evaluate(string masukkan){
    int i = 0;
    while(masukkan[i] != '\0'){
        if(Operand(masukkan[i])){
            int operand = 0;
            while(masukkan[i] != '\0' && Operand(masukkan[i])){
                operand = (operand * 10) + (masukkan[i] - 48);
                i++;
            }
            SE.push(operand);
        }
        if(isOperator(masukkan[i])){
            int A = SE.Top(); SE.pop();
            int B = SE.Top(); SE.pop();
            int hasil = Operation(B,masukkan[i],A);
            SE.push(hasil);
        }
        i++;
    }
    return SE.Top();
}
int main(){
string I;
    getline(cin,I);
    string P = ITP(I);
    cout<< P;
    return 0;
}
