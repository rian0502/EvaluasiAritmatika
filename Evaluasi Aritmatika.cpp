#include <bits/stdc++.h>
using namespace std;

bool Operator(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%'){
        return true;
    }else{
        return false;
    }
}

int Prioritas(string x){
    if(x == "+" || x == "-"){
        return 1;
    }
    if(x == "*" || x == "/" || x == "%"){
        return 2;
    }
    return 0;
}

bool bigOne(string x, string y){
    int xValue, yValue;
    xValue = Prioritas(x);
    yValue = Prioritas(y);
    return xValue <= yValue;
}

double execute(double x, double y, string n){
    if(n == "+"){
        return x+y;
    }
    if(n == "-"){
        return x-y;
    }
    if(n == "*"){
        return x*y;
    }
    if(n == "/"){
        return x/y;
    }
    if(n == "%"){
        return (int) x % (int) y;
    }
    return 0;
}

vector <string> infix;
vector <string> postfix;
string temp;
vector <string>::iterator itr;
vector <string>::iterator it;
vector <string>::iterator iter;

void PostFiks(){
    stack <string> temp2;
    int i = 0;
    for(itr = infix.begin(); itr != infix.end() ; itr++, i++){
        if(isdigit(infix[i].back())){
            postfix.push_back(infix[i]);
            continue;
        }
        if(infix[i] == "("){
            temp2.push(infix[i]);
            continue;
        }
        if(infix[i] == ")"){
            while(!temp2.empty() && (temp2.top() != "(")){
                string toPush = temp2.top();
                postfix.push_back(toPush);
                temp2.pop();
            }
            temp2.pop();
            continue;
        }
        if(Operator(infix[i][0])){
            if(temp2.empty() || temp2.top() == "("){
                temp2.push(infix[i]);
            }
            else{
                while(!temp2.empty() && (temp2.top() != "(") && bigOne(infix[i], temp2.top())){
                    string toPush = temp2.top();
                    postfix.push_back(toPush);
                    temp2.pop();
                }
                temp2.push(infix[i] );
            }
            continue;
        }
    }
    while(!temp2.empty()){
        string toPush = temp2.top();
        postfix.push_back(toPush);
        temp2.pop();
    }
}

void HasilOperasi(){
    stack <string> temp2;
    int i = 0;
    double res;
    for(iter = postfix.begin(); iter != postfix.end() ; iter++, i++){
        if(isdigit(postfix[i].back())){
            temp2.push(postfix[i]);
        }
        else{
            double A = strtod((temp2.top()).c_str(), NULL);
            temp2.pop();
            double B = strtod((temp2.top()).c_str(), NULL);
            temp2.pop();
            res = execute(B, A, postfix[i]);
            temp2.push(to_string(res));
        }
    }
    res = strtod((temp2.top()).c_str(), NULL);
    cout << res << endl;
}

int main(){
    string str;
    char ch;
    while(cin.get(ch)){
        if(ch == '\n'){
            break;
        }
        if(ch != ' '){
            str.push_back(ch);
        }
    }
    int length = str.length();

    for(int i = 0; i < length; i++){
        if(str[i] == '(' || str[i] == ')'){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            infix.push_back(str.substr(i, 1));
        }
        if(isdigit(str[i]) || (str[i] == '-' && i == 0 && isdigit(str[i+1]))){
            temp.push_back(str[i]);
            continue;
        }
        if(Operator(str[i])){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            if((str[i] == '-' && Operator(str[i-1])) || (str[i] == '-' && i == 0 && str[i+1] == '(') || (str[i] == '-' && str[i-1] == '(')){
                infix.push_back("-1");
                infix.push_back("*");
            }else{
                infix.push_back(str.substr(i, 1));
            }
        }
    }
    if(temp.length() != 0){
        infix.push_back(temp);
        temp.clear();
    }
    PostFiks();
    HasilOperasi();
    return 0;
}
