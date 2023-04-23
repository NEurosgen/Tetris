#pragma once

#include "framework.h"

#include "Tetris.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


struct Color {
	short int r;
	short int g;
	short int b;
};
typedef struct Color Color;
struct Square {

	int rock;

	Color col;
};
typedef struct Square Square;
void generation(Square* MAS, int* name, int* rot);
void glass(HDC,Square*);
void Rotate(Square* MAS, int* name, int* rotate);
void  lineb(Square* MAS);
void Moved(Square* MAS, int* name, int* rotate);
void Movel(Square* MAS);
void Mover(Square* MAS);

