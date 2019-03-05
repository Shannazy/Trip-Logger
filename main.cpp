#include <iostream>
#include <ctype.h>
#include <iomanip>
//#include <stdlib.h>
#include <string>

using namespace std;

int CheckSpaces(string);
void AlphaSort(string []);
string StandardForm(string, int);
string CreateAcro(string);
string CreateAcroSpace(string,int);
void comparRepeats(string countries[],string Acro[]);
string Exceptionlist(string);
int countrySize=195;
int main()
{
    string temp;
    string countries[countrySize]={};
    int mycounter=0;


cout<<"Welcome to the acronym creator. You will give me the names of all the countries you visited\nand we will create acronyms\n"
    <<"Now we will just begin:\n(when you are done entering names, just hit done)"<<endl;

do{
    getline(cin,temp);

    for(int i=0;temp[i]!='\0';i++){
            temp[i]=tolower(temp[i]);
        }
        temp=Exceptionlist(temp);
    if (temp!="done"){
        countries[mycounter]=temp;
        mycounter++;
    }
    else{
    }
}while(temp!="done");
countrySize=mycounter;
system("CLS");
string Acro[countrySize]={};
if (countrySize<5){
        cout<<"You need to travel more"<<endl;
}
else if(countrySize>=5&&countrySize<10){
    cout<<"Okay that's a pretty nice amount of countries visited"<<endl;
}
else if(countrySize>=10){
    cout<<"Look at your walking this earth. I wont how much food your tried. Keep going!"<<endl;
}
AlphaSort(countries);
for(int z=0;z<countrySize;z++){
        int spaces=CheckSpaces(countries[z]);
    countries[z]=StandardForm(countries[z],spaces);
    if (spaces>0){
        Acro[z]=CreateAcroSpace(countries[z],spaces);
    }
    else{
        Acro[z]=CreateAcro(countries[z]);
    }
}
comparRepeats(countries,Acro);
for(int q=0;q<countrySize;q++){
    cout<<setw(20)<<left<<countries[q]<<setw(28)<<right<<Acro[q]<<endl;
}
cout<<"To exit just type: exit"<<endl;
cin>>temp;
    return 0;
}
void comparRepeats(string countries[], string Acro[]){
    int change=1;
    while(change>0){
            change=0;
for(int i=0;i<countrySize;i++){
        for (int j=0;j<countrySize;j++){
        if (i==j){
            continue;
        }
        string country1=countries[i];
        string country2=countries[j];
        string word1=Acro[i];
        string word2=Acro[j];
    if(country1==country2){
        Acro[i]=Acro[j];
        }

    if((word1==word2)&&(country1!=country2)){//This is just checking if the Acronyms are the same THATS ALL
        int theirElement=0;
        for(int p=0;p<3;p++){
            if ((country1[p]==country2[p])||(country1[p]==tolower(word1[1]))||(country2[p]==tolower(word1[1]))){
                theirElement++;
            }
            }
        if (theirElement<3){
            word1[1]=toupper(country1[theirElement]);
            Acro[i]=word1;
        }
        else if (theirElement>=3){
            cout<<"We aren't that creative. Can you just create your own acronym for "
                <<country1<<" with only two Capital Letters"<<endl;
            int problemindex=0;
            do{
                    problemindex=0;
            cin>>word1[0]>>word1[1];
                for(int u=0;u<countrySize;u++){
                    if (word1==Acro[u]){
                        cout<<"That acronym already exist.Enter different initials"<<endl;
                        problemindex++;
                        break;
                    }
                }
            }while(problemindex>0);
            Acro[i]=word1;
            }

        change++;
        }
}
}
}
}
string Exceptionlist(string countryName){
if ((countryName=="antigua and barbuda")||(countryName=="antigua and barbuda ")){
    countryName="antigua barbuda";
}
else if ((countryName=="bosnia and herzegovina")||(countryName=="bosnia and herzegovina ")){
    countryName="bosnia herzegovina";
}
else if ((countryName=="bosnia and herzegovina")||(countryName=="bosnia and herzegovina ")){
    countryName="bosnia herzegovina";
}
else if ((countryName=="trinidad and tobago")||(countryName=="trinidad and tobago ")){
    countryName="trinidad tobago";
}
else if ((countryName=="united arab emirates")||(countryName=="united arab emirates ")){
    countryName="arab emirates";
}
else if ((countryName=="united states of america")||(countryName=="united states of america ")){
    countryName="united states";
}
else if ((countryName=="papua new guinea")||(countryName=="papua new guinea ")){
    countryName="new guinea";
}
else if ((countryName=="central african republic")||(countryName=="central african republic  ")){
    countryName="central africa";
}
else if ((countryName=="guinea-bissau")||(countryName=="guinea-bissau ")){
    countryName="guinea bissau";
}
return countryName;
}
string CreateAcroSpace(string countryName, int spaces){
char myAcro[spaces+2]={};
string AcroSpace;

myAcro[0]=toupper(countryName[0]);
int charElement=1;
for(int i=1;countryName[i]!='\0';i++){
    if((countryName[i]==' ')&&(countryName[i+1]!='\0')){
        myAcro[charElement]=toupper(countryName[i+1]);
        charElement++;
    }
}
myAcro[spaces+1]='\0';
AcroSpace =myAcro;
return AcroSpace;
}
string CreateAcro(string country){
    string Acro;
char noSpaceAcro[3]={};
noSpaceAcro[0]=toupper(country[0]);
noSpaceAcro[1]=toupper(country[1]);
noSpaceAcro[2]='\0';
    Acro=noSpaceAcro;
    return Acro;
}
string StandardForm(string country, int spaces){
country[0]=toupper(country[0]);
if (spaces>0){
    for(int i=1;country[i]!='\0';i++){
        if (country[i-1]==' '){
            country[i]=toupper(country[i]);
        }
    }
}
return country;
}
int CheckSpaces( string country){
    int spaces=0;
for(int j=0;country[j]!='\0';j++){
    if(country[j]==' '){
        if(country[j+1]!='\0')
        spaces++;
    }
}
//cout<<country<<"has "<<spaces<<"spaces"<<endl;
return spaces;
}
void AlphaSort(string countries[]){
int swapcounter=0;
string word1;
string word2;
    do{
        swapcounter=0;
    for(int i=0;i<countrySize-1;i++){
        word1=countries[i];
        word2=countries[i+1];
        int j=0;
        if (word1[j]==word2[j]){
            while(word1[j]==word2[j]){
                if (word1[j+1]>word2[j+1]){
                countries[i+1]=word1;
                countries[i]=word2;
                swapcounter++;
            }
            j++;
            }
        }
        else if (word1[j]>word2[j]){
            countries[i]=word2;
            countries[i+1]=word1;
            swapcounter++;
        }
    }
    }while(swapcounter>0);
}
