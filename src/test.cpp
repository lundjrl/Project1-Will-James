#include "../include/AUDS.h"
#include <string>
#include <iostream>
int main(int argc, char** argv){
	AUDS<int> dataStruct;
	for(int i = 0; i <= 99; i++){
		dataStruct.push(i);
	}
	dataStruct.printData();
	int popped = dataStruct.pop();
	std::cout << std:: endl << popped << std::endl;
	dataStruct.printData();
	dataStruct.push(100);
	dataStruct.push(101);
	dataStruct.printData();
	std::cout << std:: endl << popped << std::endl;	
	
}
