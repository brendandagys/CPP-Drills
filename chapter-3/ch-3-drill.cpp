#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
  cout << "Enter the name of the person you want to write to: ";
  string first_name;
  cin >> first_name;

  cout << "Name of other friend: ";
  string friend_name;
  cin >> friend_name;

  cout << "Enter 'm' for male, 'f' for female...\n";
  char friend_sex = 0;
  cin >> friend_sex;
  
  cout << "Enter the age of the recipient: ";
  int recipient_age;
  cin >> recipient_age;

  if (recipient_age < 1 || recipient_age > 109) {
    throw std::runtime_error("you're kidding!");
  }

  cout << "\nDear, " + first_name + "\n\n";
  cout << "    How are you? I am fine. I miss you.\n";
  cout << "Have you seen " + friend_name + " lately?\n";
  cout << "If you see " + friend_name + " please ask " + (friend_sex == 'm' ? "him" : "her") + " to call me.\n";
  cout << "I hear you just had a birthday and you are " << recipient_age << " years old.\n";
  
  if (recipient_age < 12) {
    cout << "Next year you will be " << recipient_age + 1 << ".\n";
  } else if (recipient_age == 17) {
    cout << "Next year you will be able to vote.\n";
  } else if (recipient_age > 70) {
    cout << "I hope you are enjoying retirement.\n";
  }

  cout << "\nYours sincerely\n\n\n" << first_name << "\n";

  return 0;
}
