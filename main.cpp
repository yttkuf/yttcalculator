#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace boost {}

class Calculator{
string str="";string strO="";int sizes=0;string str2;
int xi=0;int yi=0;
int sxi=0;int syi=0;
string ax;
string ay;
string result;
string conflictcheck="*/+-";
int count=0;
private:int check(int index,int mode){//find beggin and end of variabkles
    int q;
    int i;
    int ss=0;

    if (mode==-1){i=index-1;
    while (ss==0){

        if ((str[i]=='*')|(str[i]=='/')|(str[i]=='+')|(str[i]=='-')|(str[i]=='^')|(i<0)){ss=1;if (str[i]=='-')q=i; else q=i+1;return q;}
        else i-=1; }}


    else if (mode==1){i=index+1;
        while (ss==0){

            if ((str[i]=='*')or(str[i]=='/')or(str[i]=='+')or(str[i]=='-')or(str[i]=='^')or(i>sizes-1)){ss=1; q=i-1;return q;}
            else i+=1; }}
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void umn(int i){//умножение
    rasbiv(i);
     if (ax[0]=='-')result+='+';
    result=to_string(stod(ax)*stod(ay));
    str.replace(xi,yi+1-xi,result);


}
void add(int i){//сложение
    rasbiv(i);
    if (ax[0]=='-'){
        ax.erase(0,1);
    result=to_string(-stod(ax)+stod(ay));}
     else
    result=to_string(stod(ax)+stod(ay));
    str.replace(xi,yi+1-xi,result);

}
void minus(int i){//вычитание
    rasbiv(i);
    if (ax[0]=='-'){
        ax.erase(0,1);
    result+=to_string(-stod(ax)-stod(ay));}
     else
    result=to_string(stod(ax)-stod(ay));
    str.replace(xi,yi+1-xi,result);
    if (((stod(ax)-stod(ay))<0) &(str[xi-1]=='+')) str.erase(xi-1,1);

}
void del(int i){//деление
    rasbiv(i);
    result=to_string(stod(ax)/stod(ay));
    str.replace(xi,yi+1-xi,result);

}
void st(int i){
rasbiv(i);
string ay2=ay;
double r1=1;double r2=1;string x1,x2;
int x=ay.find_first_of('.');
if (x<0)for (int i=0;i<stoi(ay);i++)
r1=r1*(stod(ax));
else { x1=ay.erase(x,ay.length()-x); x2=ay2.erase(0,x+1);
    for (int i=0;i<stoi(x1);i++)
        r1=r1*(stod(ax));
    for (int i=0;i<stoi(x2);i++)
        r2=r2*(stod(ax));
    r1=r1/r2;}
result=to_string(r1);
str.replace(xi,yi+1-xi,result);}
////////////////////////////////////////////////////////////////////////////////////////////////////
void rasbiv(int i){//разбив части строки на переменные
        {xi=check(i,-1);yi=check(i,1);
            for (int j=xi;j<i;j++)
                ax+=str[j];
            for (int j=i+1;j<yi+1;j++)
                ay+=str[j];
    }
}
void obn(){//обнуление переменных
    ax="";ay="";xi=0;yi=0;
    result="";
}
////////////////////////////////////////////////////////////////////////////////////////////////////
private:void calculation(string a){//сам калькулятор
        str=a;
        cout<<"    "<<str<<endl;
        sizes=a.length();
        int i=0;
        while (i<sizes){
        sizes=str.length();
            if (str[i]=='^'){ st(i);obn();sizes=str.length();cout<<"^   "<<str<<endl;i=0;}i++;}  i=0;
        while (i<sizes){
        sizes=str.length();
            if (str[i]=='*'){ umn(i);obn();sizes=str.length();cout<<"*   "<<str<<endl;i=0;}i++;}  i=0;
        //////////////
        while (i<sizes){
        sizes=str.length();
            if (str[i]=='/'){ del(i);obn();sizes=str.length();cout<<"/   "<<str<<endl;i=0;} i++;} i=0;
        //////////////
        while (i<sizes){
        sizes=str.length();
            if (str[i]=='-')if (i>0){ minus(i);obn();cout<<"-   "<<str<<endl;i=0;} i++;} i=0;
        //////////////
        while (i<sizes){
              sizes=str.length();
            if (str[i]=='+'){ add(i);obn();sizes=str.length();cout<<"+   "<<str<<endl;i=0;} i++;}
       cout<<endl<<"fgfgfgfgfgf     "<<str;

       // cout<<endl<<endl<<str;
}
string conflict(string a){
    string m;
    int i=0;int ii=-1;
    sizes=a.length();

      while (i<sizes){
         if ((a[i]=='*')&(a[i+1]=='-')) {
                 a.replace(i+1,1,"");int end=a.find_first_of("*/+-",i+1);if (end==-1)end=a.length();
                 m="";m+=a[end-1];m+=')';a.replace(end-1,1,m);cout<<"KKKKKKKKKKK    "<<a<<endl;
                 int j=i-1;cout<<i<<"   jkjkjk   "<<a<<"      fdfdfdfdfdaaaaaaa     "<<j<<endl;
                 while (ii==(-1)){
                 if ((a[j]=='*')or(a[j]=='/')or(a[j]=='+')or(a[j]=='-')or(j==0)){ii=j;
                     cout<<endl<<"   dsdsdsd  "<<j<<endl;}
                 else j--;} m="";m+='-';m+='(';m+=a[j];a.replace(j,1,m);  i=0;ii=-1;cout<<"KONCA    "<<a<<endl;}
          else i++;}sizes=a.length();i=0;

      while (i<sizes){
         if ((a[i]=='/')&(a[i+1]=='-')) {
                  a.replace(i+1,1,"");int end=a.find_first_of("*/+-",i+1);if (end==-1)end=a.length();
                  m="";m+=a[end-1];m+=')';a.replace(end-1,1,m);cout<<"KKKKKKKKKKK    "<<a<<endl;
                  int j=i-1;cout<<i<<"   jkjkjk   "<<a<<"      fdfdfdfdfdaaaaaaa     "<<j<<endl;
                  while (ii==(-1)){
                  if ((a[j]=='*')or(a[j]=='/')or(a[j]=='+')or(a[j]=='-')or(j==0)){ii=j;
                      cout<<endl<<"   dsdsdsd  "<<j<<endl;}
                  else j--;} m="";m+='-';m+='(';m+=a[j];a.replace(j,1,m); i=0;ii=-1;}
         else i++;} sizes=a.length();i=0;
      while (i<sizes){
          if ((a[i]=='-')&(a[i+1]=='-')) {a.replace(i,2,"+");i=0;}else i++;} sizes=a.length();i=0;
       while (i<sizes){
          if ((a[i]=='+')&(a[i+1]=='-')) {a.replace(i,2,"-");i=0;}else i++; }sizes=a.length();i=0;
    for (int i=0;i<sizes;i++){
        if ((a[i]=='(')&(a[i+1]=='+'))a.erase(i+1,1);
    }

    if (a[0]=='+')a.erase(0,1);
    counting(a);
    return a;
}
void counting(string a){count=0;sizes=a.length();
for (int i=0;i<sizes;i++){
  if ((a[i])=='(') count+=1;}}


public:void decompose(string a){
    strO=a;  
cout<<count<<endl;
counting(a);
decomposeagain:
if (count>0){
    sxi=strO.find_last_of('(');str2=strO;str2=str2.erase(0,sxi+1);syi=strO.find_first_of(')',sxi);
    int sss=str2.find_first_of(')');str2=str2.erase(sss,str2.length()-sss);
calculation(str2);string r=str;strO.replace(sxi,str2.length(),r);strO.erase(strO.find_first_of(')',sxi),1);
cout<<endl<<str2<<endl<<sxi<<" ; "<<syi<<endl<<endl<<"dsdsdsds"<<strO<<endl;strO=conflict(strO);}
counting(strO);
if (count>0) goto decomposeagain;
calculation(strO);
cout<<endl;
system("clear");
cout<<"Результат: "<<str<<endl;
   } };


/////////////////////////////////////-////////////////////////////////////////////
int main()
{
    string a;
    cout << "Hello World!" << endl;
    cin>>a;
    Calculator q;
    q.decompose(a);

    return 0;
}

