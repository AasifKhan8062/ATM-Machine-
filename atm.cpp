#include <iostream>
#include <fstream>
using namespace std;
void Statement(int totalamount, int balance,int cash, string str){
  
  ofstream appendfile("statement.txt",ios::app);
  if (appendfile.is_open()) {
      appendfile <<"Old Amount : "<<totalamount<<", Current Amount : "<<balance<<" ,"<<str<<" : "<<cash<<"\n" ;
      appendfile.close();
    } 
  else {
        cout << "Error opening file for appending.\n";
    }
}
int balance = 100;
class ATM{
public:

int totalamount;

void dispositCash(int cash){
  totalamount = balance;
  balance += cash;
  ::Statement(totalamount,balance,cash,"Disposit Cash");
  cout<<"Disposit Successfully "<<endl;
}

void withdrawCash(int cash){
  if(balance > cash){
    totalamount = balance;
    balance -= cash;
    ::Statement(totalamount,balance,cash,"Withdraw Cash");
    cout<<"Withdraw Successfully "<<endl;
  }
  else{
    cout<<"amount not withdraw "<<endl;
  }
}
void totalBalance(){
  cout<<"Your Total balance is : "<<balance<<endl;
}
void Statement(){
  ifstream readfile("statement.txt");
    if (readfile.is_open()) {
        string line;
        while (getline(readfile, line)) {
          cout << line <<endl;
        }
        readfile.close();
    } else {
        cout << "Error opening file for reading.\n";
    }
}
};
void menu(){
  int n;
  cout<<"----------Menu--------"<<endl;
  cout<<"1 : Deposit "<<endl;
  cout<<"2 : Withdraw"<<endl;
  cout<<"3 : Check Balance"<<endl;
  cout<<"4 : Statement "<<endl;
  cout<<"Enter your choice : "<<endl;
  cin>>n;

  int amount;
  
  ATM atm;
  switch (n){
    case 1:
      cout<<"Enter the Amount : ";
      cin>>amount;
      atm.dispositCash(amount);
      break;
    case 2:
      cout<<"Enter the Amount : ";
      cin>>amount;
      atm.withdrawCash(amount);
      break;
    case 3:
      atm.totalBalance();
      break;
    case 4:
    atm.Statement();
    break;
    
    default:
    cout<<"Invalid choice "<<endl;
  }
}
int main() {
  do{
    menu();
  }while(true);
  
  return 0;
}
