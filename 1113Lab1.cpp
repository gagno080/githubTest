#include <iostream>
using namespace std;
/*
//g++ -o 1113Lab1.exe 1113Lab1.cpp
int main(){

	int hrs;
	double total;
	int dep;
	int depfee;
	//double soc = total*0.06;
	//double fed = total*0.14;
	//double state = total*0.05;
	int uni = 10;
	//double home = total - (soc + fed + state + depfee + uni);
	//$10 for union
	
	cout << "How many hours did you work this week?";
	cin >> hrs;
	cout << "How many dependents do you have?";
	cin >> dep;
	cout <<"\n";
	
	//total pay
	//each withholding amount
	//take-home pay
	
	if (hrs > 40){
		total = (hrs - 40)*16.78*1.5 + 40*16.78;
	}
		else{
			total = hrs*16.78;
		}
	
	if (dep >= 3){
		depfee = 35;
	}	
		else{
		depfee = 0;	
		}
	
	cout << "Your total pay is: " << total << "\n";
	cout << "Your withholdings inlcude:" << "\n";
	cout << "Social Security Tax: " << total*0.06 << "\n";
	cout << "Federal Income Tax: " << total*0.14 << "\n";
	cout << "State Income Tax: " << total*0.05 << "\n";
	cout << "Union Dues: " << uni << "\n";
	cout << "Your take-home pay is: " << total - (total*0.06 + total*0.14 + total*0.05 + depfee + uni) << "\n";
	
	return 0;
}
*/

int main(){
  int left, right, result;
  char operation;

  std::cout << "Enter an equation: ";
  std::cin >> left >> operation >> right;

  if (operation == '+') {
    result = left + right;
  } else if (operation == '-') {
    result = left - right;
  } else if (operation == '/') {
    result = left / right;
  } else if (operation = '*') {
    result = left * right;
  } else {
    std::cerr << "Invalid operation." << std::endl;
  }

  std::cout << left << operation << right << " = " << result << std::endl;
  
  return 0;
}