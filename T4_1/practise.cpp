#include <iostream>

using std::cout;
using std::endl;

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int , int , int );
  void AddDay(int );
  void AddMonth(int);
  void AddYear(int);

  void ShowDate();
};


void Date::SetDate(int year, int month, int day) {year_ = year; month_ = month; day_=day;}
void Date::AddDay(int ad){day_+=ad;}
void Date::AddMonth(int am){month_+=am;}
void Date::AddYear(int ay){year_+=ay;}
void Date::ShowDate(){
    cout<<year_<<"년 "<<month_<<"월 "<<day_<<"일 입니다.!!"<<endl;
}

int main()
{
    Date date;
    date.SetDate(2018,6,15);
    date.ShowDate();
    
    date.AddYear(2);
    date.AddDay(10);
    date.AddMonth(5);
    date.ShowDate();
}