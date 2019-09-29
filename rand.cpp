#include <iostream>
#include <cstdlib>
#include <cstdio>
#define ARR_SIZE 10
using namespace std;

//globals
int random1; 

//prototypes
void stdlibRandom();
void algorithmRandom();

int main(){

	cin.get();

	return 0;
}

void stdlibRandom(){
	
	for (int i = 0; i < 10; i++){

		random1 = rand() % 10 + 0;

		printf("%d\n",random1);
	}
}

void algorithmRandom(){

}