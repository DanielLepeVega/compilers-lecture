// Fernando Martinez
// A01630401

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
	Grammar:
	S -> aBc
	B -> bc | b
*/

typedef struct Node {
	char parent[50];
	char letter[50];
};

struct Node ast[100];
int i = 0;
int j = 0;
char line[500];

char l;

bool S();
bool B();
bool B_2();
bool B_1();

void addNode(char par[50], char lett[50]) {
	strcpy(ast[i].parent, par);
	strcpy(ast[i].letter, lett);
	i++;
}

void error() {
	printf("Error\n");
	while(line[j] != '\n')
		j++;
}

bool match(char t) {
	printf("l: %c\n", l);
	printf("t: %c\n", t);
	if(l == t) {
		j++;
		l = line[j];
		return true;
	}
	else
		error();
}

bool B_1() {
	if(l == 'b') {
		if(match('b') && match('c')) {
			addNode("B", "c ");
			addNode("B", "b");
			return true;
		}
	}
}

bool B_2() {
	if(l == 'b') {
		if(match('b')) {
			addNode("B", "b");
			return true;
		}
	}
}

// bool B() {
// 	if(B_1())
// 		return true;
// }


bool S() {
	if(line[j] == 'a' && line[j+1] == 'b' && line[j+2] == 'c' && line[j+3] == 'c') {
		if(match('a') && B_1() && match('c')) {
			addNode("S", "c");
			addNode("S", "B");
			addNode("S", "a");
			return true;
		}
	}
	else if(line[j] == 'a' && line[j+1] == 'b' && line[j+3] == 'c') {
		if(match('a') && B_2() && match('c')) {
			addNode("S", "c");
			addNode("S", "B");
			addNode("S", "a");
			return true;
		}
	}
	else
		error();
}

int main(int argc, char **argv) {
	char buffer[10000];
	FILE *fp;
	fp = fopen("tokens.txt", "r");
	fread(buffer, 10000, 1, fp);
	int p = 0;
	int q = 0;
	while(buffer[p] != '\0') {
		line[q] = buffer[p];
		if(buffer[p] == '\n') {
			j = 0;
			printf("New token\n");
			l = line[j];
			printf("%d\n", l);
			S();
			for(int e = i-1; e >= 0; e--) {
				printf("\"%s\" -> \"%s\"\n", ast[e].parent, ast[e].letter);
			}
			q = 0;
		}
		p++;
		q++;
	}
	if(l == '\n')
		printf("Parsing Successful\n");
	return 0;
}