/*
============================================================================================================================
About_this_code: 	 Further implementation on the topic array of finding any missing element and duplicated element in C++.
Compiler: 		 GCC, GNU Compiler Collection, "g++ -std=c++0x lowerTrianglarMatrix.cpp -o compilefile"
Author: 		 Cheung Tsz Yin
Github:			 kevin909cty
Date:   		 25 / 08 / 2019
Comment: 		 Please feel free to contact me if there are any mistake or code that 
			 can be further improve. Thank you very much! ^_^ 
Contact email: 	 	 cheungkevinviola909@gmail.com
============================================================================================================================
*/
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class Matrix{
private:
	int size;
	int* ptr;
public:
	Matrix(int passinSize){
		size = passinSize;
		ptr = new int[size * (size - 1) / 2];
	}
	~Matrix(){delete []ptr;}
	
	void setArray(int i, int j, int passinRand){
		if(i >= j){
			ptr[(((i - 1)/2) * i) + j - 1] = passinRand;
		}
	}
	int getArray(int i, int j){
		if(i >= j){
			return ptr[(((i - 1)/2) * i) + j - 1];
		}
		else{
			return 0;
		}
	}

	void display();
};

int main(){
	int mainSize;
	int tempRand;
	cout << "\n*******************************************\n";
	cout << "** Please input the Diagonal Matrix Size: ";
	cin >> mainSize;
	printf("** The size you entered is: %d\n", mainSize);
	cout << "*******************************************\n";

	Matrix newMatrix(mainSize);

	for(int i = 0; i < mainSize; i++){
		for(int j = 0; j < mainSize; j++){
			tempRand = (rand() % 10);
			newMatrix.setArray(i, j, tempRand);
		}
	}

	newMatrix.display();

	return 0;
}

void Matrix::display(){
	for(int i = 0; i < size * (size - 1) / 2; i++){
		if(i >= size){
			break;
		}
		else{
			for(int j = 0; j <= i; j++){
				printf("%d ", ptr[i]);
			}
			printf("\n");
		}
	}
}