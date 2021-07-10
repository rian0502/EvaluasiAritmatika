#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class postfix
{
char setelah[30],inf[30];
int atas,y,op;
float oper[30],stac[30],so;
public:
postfix()
{
atas=-1;y=0,op=0;
}
void konversi()
{
char temp[30];
int z;
for(int i=0;inf[i]!=0;i++)
{
if(inf[i]>=48&&inf[i]<=57)
{
setelah[y++]=inf[i];
for(z=i;inf[z]<=57&&inf[z]>=48||inf[z]=='.';z++)
temp[z-i]=inf[z];
temp[z-i]='\0';
oper[op++]=atof(temp);
i=z-1;
}
else
{
switch(inf[i])
{
case '+':
case '-':
while(atas>=0&&stac[atas]!='(')
setelah[y++]=stac[atas--];
stac[++atas]=inf[i];
break;
case '*':
case '/':
while(stac[atas]!='+'&&stac[atas]!='-'&&atas>=0&&stac[atas]!='(')
setelah[y++]=stac[atas--];
stac[++atas]=inf[i];
break;
case '^':
stac[++atas]=inf[i];
break;
case '(':
stac[++atas]=inf[i];
break;
case ')':
while(stac[atas]!='(')
setelah[y++]=stac[atas--];
atas--;
break;
}
}
}
while(atas>=0)
setelah[y++]=stac[atas--];
}
float selesai()
{
op=0;
for(int i=0;i<y;i++)
{
if(setelah[i]>=48&&setelah[i]<=57)
stac[++atas]=oper[op++];
else
{
switch(setelah[i])
{
case '+':
so=stac[atas]+stac[atas-1];
stac[--atas]=so;
break;
case '-':
so=stac[atas-1]-stac[atas];
stac[--atas]=so;
break;
case '*':
so=stac[atas-1]*stac[atas];
stac[--atas]=so;
break;
case '/':
so=stac[atas-1]/stac[atas];
stac[--atas]=so;
break;
case '^':
so=powf(stac[atas-1],stac[atas]);
stac[--atas]=so;
break;
}
}
}
return stac[0];
