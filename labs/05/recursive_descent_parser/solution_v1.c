#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//FIXME

/***************************
Example:
Grammar:
E --> i E'
E' --> + i E' | e
***************************/

char l;


bool B();
bool B_1();
bool B_2();

void error(){
	printf("Error\n");
	exit(-1);
}
// Match function
bool match(char t) {
    if (l == t) {
        l = getchar();
		return true;
    }
    else
		error();
}

// Definition of E' as per the given production
bool B(){
	if(B_1() || B_2()){
		return true;
	}
}

// Definition of E_1' as per the given production
bool B_2() {
	if (l == 'b')
		return match('b');
}

// Definition of E_2' as per the given production
bool B_1() {
    if (l == 'b') {
		if(match('b') && match('c') && B())
			return true;
    }
}

// Definition of E, as per the given production
bool S() {
    if (l == 'a') {
        if (match('a') && B()){
			return true;
		}
    }else{
		error();
	}
}

int main() {

    do {
        l = getchar();
		// B is a start symbol.
	    B();

    } while (l != '\n' && l != EOF);

    if (l == '\n')
        printf("Parsing Successful\n");
}
