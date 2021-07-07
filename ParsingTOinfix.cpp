#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[]){
    string copyStr;
    string ubah = "-1*";
    vector<string>pasteSTR;
    getline(cin,copyStr);
    for(int i=0 ; i < copyStr.length();i++){
        if(copyStr[i] == ' '){
            copyStr.erase(i,1);
        }
        if((copyStr[i] == '-' and copyStr[i+1] == '(') and (copyStr[i-1] == '+' or 
        copyStr[i-1] == '-' or copyStr[i-1] == '/' or copyStr[i-1] == '*' or copyStr[i-1] == '%')){
            copyStr.replace(i,1,ubah);
        }
        else if(copyStr[i] == '-' and (copyStr[i-1] == '+' or copyStr[i-1] == '*' or copyStr[i-1] == '/' or copyStr[i-1] == '%' or copyStr[i-1] == '-') ){
            copyStr.replace(i,1,ubah);
        }    
    }
    if(copyStr[0] == '-' and copyStr[1] == '('){
            copyStr.replace(0,1,ubah);
    }
    int j = 0;
    while (true){
       if(copyStr[j] == '-' and copyStr[j+1] == '1' and (copyStr[j-1] == '+' or copyStr[j-1] == '*' or copyStr[j+1] == '/' or copyStr[j-1] == '%' or copyStr[j-1] == ')' or copyStr[j-1] == '(')){
            pasteSTR.push_back(copyStr.substr(j,2));
            j+=1;
        }
        else if(copyStr[j] == '-' and copyStr[j+1] == '1' and (copyStr[j+2] == '+' or copyStr[j+2] == '*' or copyStr[j+1] == '/' or copyStr[j+2] == '%' or copyStr[j+2] == ')' or copyStr[j+2] == '(')){
            pasteSTR.push_back(copyStr.substr(j,2));
            j+=1;
        }
        else if((copyStr[j] >= 48 and copyStr[j] <= 57) and (copyStr[j+1] >= 48 and copyStr[j+1] <= 57)){
            pasteSTR.push_back(copyStr.substr(j,2));
            j+=1;
        }
        else if((copyStr[j] >= 48 and copyStr[j] <= 57)and(copyStr[j+1] == '+' or copyStr[j+1] == '*' or copyStr[j+1] == '/' or copyStr[j+1] == '%' or copyStr[j+1] == ')' or copyStr[j+1] == '(')){
            pasteSTR.push_back(copyStr.substr(j,1));
        }
        else if((copyStr[j] == '+' or copyStr[j] == '*' or copyStr[j] == '/' or copyStr[j] == '%' or copyStr[j] == ')' or copyStr[j] == '(' or copyStr[j] == '-')){
            pasteSTR.push_back(copyStr.substr(j,1));
        }
        else{
            pasteSTR.push_back(copyStr.substr(j,1));
        }
        j++;
        if(copyStr[j] == copyStr[copyStr.length()]){
            break;
        }
    }

    for(auto e:pasteSTR){
        cout<<e<<" ";
    }
    cout<<endl;

    return 0;
}
