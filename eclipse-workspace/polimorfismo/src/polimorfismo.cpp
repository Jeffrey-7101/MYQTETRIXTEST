//============================================================================
// Name        : polimorfismo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

template <typename type>
 struct Shape{
	 auto getArea(){
		 return static_cast<type*>(this)->computeArea();
	 }
 };

struct Circle: Shape<Circle>{

	/*float radio{}:
	//Circle(float _radio): radio{_radio}{};

	auto computeArea(){
		return 3.1416* radio*radio;*/
	}
};
