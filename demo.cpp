#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
template<typename T>

void enter();
int dayWorking(tm* now);
int numberOfDay(tm* now);

int main() {
    time_t t = time(0);
    tm* now = localtime(&t);
    cout<< "\nCurrent time: ";
    cout<< now->tm_year+1900 
    <<"/"<< now->tm_mon+1 
    <<"/"<< now->tm_mday;
    enter();
    cout<<"Total working day in month: "<<now->tm_mon+1
    <<" is: " << dayWorking(now) << " days";
    enter();
}

void enter() {
    cout<<"\n";
}

int dayWorking(tm* now){
    int dayInMoth = numberOfDay(now);
    int week = dayInMoth/7;
    return dayInMoth - week*2;;
}

int numberOfDay(tm* now){
    int month = now->tm_mon+1;
    int year = now->tm_year+1900;
    if(month==2){
        if((year%400==0) || (year%4==0 && year%100!=0)){
            return 29;
        }
        return 28;
    }else if (month==4 || month==6 || month ==9 || month==11){
        return 30;
    }
    return 31;
}