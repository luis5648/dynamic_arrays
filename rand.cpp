#include <iostream>
#include <cstdlib>
#include <cstdio>
#define ARR_SIZE 11
#define RUNS 1000

using namespace std;

//globals
int random1;
int cont[ARR_SIZE][RUNS];

//prototypes
void stdlibRandom();
void algorithmRandom();

int main()
{
	stdlibRandom();

	return 0;
}

void stdlibRandom()
{

	for (int i = 0; i < RUNS; i++){
		
		random1 = rand() % 10 + 0;
		for (int j = 0; j < ARR_SIZE; j++){


			cont[i][j]= random1;
			printf("%d\n", cont[i][j]);
		}
	}
}
