#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_FACTORIALS 10000
#define NUM_FACTS 100
struct FactorialResults{
	int results[MAX_FACTORIALS];
	int numResults;
};

int factorial(const int n){
	return (n <= 1) ? 1 : n * factorial(n - 1); //bug 1: n keeps repeating because n will always be equal to or less than n. changed from n <= n to n <= 1
}
int reduceFactorial(const int n){
	
		return n; //bug 2: cannot be divided when n is 0, changed fron n/n to n

	
}
void computeFactorials(struct FactorialResults * results, int numFactorials){
	int i;
	for (i = 0; i < numFactorials; i++){
		results->results[i] = factorial(i); 
	}
	results->numResults = numFactorials;
}
int main(void) { 
	struct FactorialResults results = { {0}, 0 }; 
	int i;
	computeFactorials(&results, NUM_FACTS); //bug 3: results initializes back to 0 because anpersand wasnt there. changed from results to &results
	for (i = 0; i < NUM_FACTS; i++) { 
		results.results[i] = reduceFactorial(results.results[i]);  

		if (!(results.results[i] == 0) && results.results[i] < MAX_FACTORIALS && !(results.results[i] < 0)) {
			printf("%5d %12d\n", i, results.results[i]); //bug 4: was not printing only 0 because of type specifier. changed from 12f to 12d
			
			//was printing junk numbers, changed to print under certain conditons

		}
	}
	return 0; 
}