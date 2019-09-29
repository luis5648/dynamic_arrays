#include <iostream>
#include <cstdlib>
#include <cstdio>
#define ARR_SIZE 10
using namespace std;

//globals
int random1;
int cont[ARR_SIZE]; 

//prototypes
void stdlibRandom();
void algorithmRandom();

int main(){
	stdlibRandom();
	cin.get();

	return 0;
}

void stdlibRandom(){
	
	for (int i = 0; i < ARR_SIZE; i++){

		random1 = rand() % 10 + 0;
		cont[i]=random1;
		printf("%d\n",cont[i]);
	}
}
