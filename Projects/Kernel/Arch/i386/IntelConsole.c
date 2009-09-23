/*
 * Copyright 2009, Evan Geller. All rights reserved.
 * Distributed under the terms of the Vanguard License.
 */

#include <Kernel/Console.h>

#define TABSTOP 8

#define WIDTH 80
#define HEIGHT 25

unsigned char *videoram = (unsigned char *) 0xb8000;
int column=0, row=0;

#define CHAR(row,column) (*(videoram+2*((WIDTH*(row))+(column))))
#define COLOR(row,column) (*(videoram+2*((WIDTH*(row))+(column))+1))

static void Newline(){
	int r,c;

	row++;
	column = 0;
	
	if(row >= HEIGHT){
		row = HEIGHT-1;

		for(r=1;r<HEIGHT;r++)
		for(c=0;c<WIDTH;c++){
			CHAR(r-1,c) = CHAR(r,c);
			COLOR(r-1,c) = COLOR(r,c);
		}

		for(c=0;c<WIDTH;c++){
			CHAR(row,c)=' ';
			COLOR(row,c)=0x07;
		}
	}
}

static void NextTabStop(){
	column += TABSTOP - (column%TABSTOP);
	if(column > WIDTH)
		Newline();
}

static int Putchar(char c){
	switch(c){
	case '\n': Newline(); return;
	case '\t': NextTabStop(); return;
	}

	CHAR(row,column) = c;	
	COLOR(row,column) = 0x07;
	if(column++ > WIDTH){
		Newline();
	}
}

static const struct ConsoleOps intelConsoleOps = {
	.Putchar = Putchar,
};

void cls(){
	int r,c;
	for(c=0;c<WIDTH;c++)
	for(r=0;r<HEIGHT;r++){
		CHAR(r,c) = ' ';
		COLOR(r,c) = 0x07;
	}
}

void IntelConsoleInit(){
	cls();

	ConsoleAdd(&intelConsoleOps);
}
