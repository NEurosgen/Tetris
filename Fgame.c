/*
I Description 
	Стакан
		Ширина 10 Высота 20
	Фигуры
		7 штук
		I J O L S  T Z
		4  кубика 
	Функция отрисовки:
	 на вход подается массив(двумерный) 4 на 4 тип short int
	 Функция отрисовывает его в стакане 
		фигура отрисовывается отн. левого верхнего угла
	Функция проверки:
		Выполняется до отрисовк(Дает добро на отрисовку).
		Отрисовывать если:
			Под кубиками нет другиx кубиков (4 проверки)
			Кубики не пересекаются с кубиками стакана(Проверка нового массива при повороте).
*/

#include "Header.h"

#define SIZE 20
#define XBEGIN 350
#define YBEGIN 100

void square(HDC hdc,int x,int y,Color col) {
	RECT size = { x,y,x+SIZE,y+SIZE};
	HBRUSH bruh = CreateSolidBrush(RGB(col.r,col.g, col.b));
	
	FillRect(hdc, &size, bruh);
	DeleteObject(bruh);
}
void generation(Square* MAS,int* name,int* rot) {
	
	lineb(MAS);
	srand(time(NULL));
	
	*rot = 0;
	*name= (rand() % 7) + 1;
	int x= rand() % 10;
	while (*name == 2 && x >= 9) {
		x= rand() % 10;
	}
	while (*name >2  && x >= 8) {
		x = rand() % 10;
	}
	
	Color col = { 150,10,10 };
	if (*name == 1) {
		col.r = 200;
		col.b = 20;
		col.g = 0;
		for (int i = 0; i < 4; ++i) {
			if ((MAS + i * 10 + x)->rock == 2) {  ///END GAME 234567
				PostQuitMessage(1);
				return;
			}
			(MAS + i*10 + x)->rock = 1;
			(MAS + i*10 + x)->col = col;
		}
		return ;
	}
	if (*name == 2) {
		col.r = 208;
		col.b = 252;
		col.g = 8;
		for (int i = 0; i < 2; ++i) {
			if ((MAS + i * 10 + x)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x)->rock = 1;
(MAS + i * 10 + x)->col = col;
		}
		for (int i = 0; i < 2; ++i) {
			if ((MAS + i * 10 + x+1)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 1)->rock = 1;
			(MAS + i * 10 + x + 1)->col = col;
		}
		return ;
	}
	if (*name == 3) {//L
		col.r = 9;
		col.b = 250;
		col.g = 5;
		for (int i = 0; i < 2; ++i) {
			if ((MAS + i * 10 + x )->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x)->rock = 1;
			(MAS + i * 10 + x)->col = col;
		}
		for (int i = 0; i < 1; ++i) {
			if ((MAS + i * 10 + x + 1)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 1)->rock = 1;
			(MAS + i * 10 + x + 1)->col = col;
		}
		for (int i = 0; i < 1; ++i) {
			if ((MAS + i * 10 + x + 2)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 2)->rock = 1;
			(MAS + i * 10 + x + 2)->col = col;
		}
		return ;
	}
	if (*name == 4) {// J
		col.r = 10;
		col.b = 220;
		col.g = 0;
		for (int i = 0; i < 1; ++i) {
			if ((MAS + i * 10 + x )->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x)->rock = 1;
			(MAS + i * 10 + x)->col = col;
		}
		for (int i = 0; i < 1; ++i) {
			if ((MAS + i * 10 + x + 1)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 1)->rock = 1;
			(MAS + i * 10 + x + 1)->col = col;
		}
		for (int i = 0; i < 2; ++i) {
			if ((MAS + i * 10 + x + 2)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 2)->rock = 1;
			(MAS + i * 10 + x + 2)->col = col;
		}
		return  ;
	}
	if (*name == 5) {   // T
		col.r = 248;
		col.b =20;
		col.g = 252;

		for (int i = 0; i < 1; ++i) {
			if ((MAS + i * 10 + x )->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x)->rock = 1;
			(MAS + i * 10 + x)->col = col;
		}
		for (int i = 0; i < 2; ++i) {
			if ((MAS + i * 10 + x + 1)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 1)->rock = 1;
			(MAS + i * 10 + x + 1)->col = col;
		}
		for (int i = 0; i < 1; ++i) {
			if ((MAS + i * 10 + x + 2)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 2)->rock = 1;
			(MAS + i * 10 + x + 2)->col = col;
		}
		return   ;
	}
	if (*name == 6) {  // z
		col.r = 10;
		col.b = 10;
		col.g = 200;
		for (int i = 0; i < 1; ++i) {
			if ((MAS + i * 10 + x )->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x)->rock = 1;
			(MAS + i * 10 + x)->col = col;
		}
		for (int i = 0; i < 2; ++i) {
			if ((MAS + i * 10 + x + 1)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 1)->rock = 1;
			(MAS + i * 10 + x + 1)->col = col;
		}
		for (int i = 1; i < 2; ++i) {
			if ((MAS + i * 10 + x + 2)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 2)->rock = 1;
			(MAS + i * 10 + x + 2)->col = col;
		}
		return   ;
	}
	if (*name == 7) { //S
		col.r = 10;
		col.b = 20;
		col.g = 80;
		for (int i = 1; i < 2; ++i) {
			if ((MAS + i * 10 + x )->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x)->rock = 1;
			(MAS + i * 10 + x)->col = col;
		}
		for (int i = 0; i < 2; ++i) {
			if ((MAS + i * 10 + x + 1)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 1)->rock = 1;
			(MAS + i * 10 + x + 1)->col = col;
		}
		for (int i = 0; i < 1; ++i) {
			if ((MAS + i * 10 + x + 2)->rock == 2) {  ///END GAME 
				PostQuitMessage(1);
				return;
			}
			(MAS + i * 10 + x + 2)->rock = 1;
			(MAS + i * 10 + x + 2)->col = col;
		}
		return  ;
	}


}


void rock(Square* MAS,int* name,int* rotate) {
	int col = 0;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 10; ++j) {
			if ((MAS + i * 10 + j)->rock == 1) {
				(MAS + i * 10 + j)->rock = 2;
				col++;
			}
		}
		if (col == 4) {
			
			generation(MAS, name, rotate);
			return;
		}
	}
}
int checkd(Square* MAS,int* name,int* rotate) {
	int col = 0;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 10; ++j) {
			if ((MAS + i * 10 + j)->rock == 1) {
				if (((MAS + (i+1) * 10 + j)->rock == 2) || i == 19) {


					rock(MAS,name,rotate);
					return 1;
				}
				col++;
			}
		}
		if (col == 4) {
			return 0;
		}
	}
	return 0;
}
int checkr(Square* MAS, int x) {
	int col = 0;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 10; ++j) {
			if ((MAS + i * 10 + j)->rock == 1) {
				if ( (j+x == 10 || j+x==-1) || ((MAS + (i) * 10 + j + x)->rock == 2)) {


					
					return 1;
				}
				col++;
			}
		}
		if (col == 4) {
			return 0;
		}
	}
	return 0;
}
void moved(Square* MAS,int i,int j) {
	*(MAS + (i + 1) * 10 + j) = *(MAS + (i + 0) * 10 + j);
	(MAS + (i + 0) * 10 + j)->rock = 0;

}
void mover(Square* MAS, int i, int j) {
	*(MAS + (i ) * 10 + j+1) = *(MAS + (i ) * 10 + j);
	(MAS + (i ) * 10 + j)->rock = 0;

}
void movel(Square* MAS, int i, int j) {
	*(MAS + (i ) * 10 + j-1) = *(MAS + (i + 0) * 10 + j);
	(MAS + (i + 0) * 10 + j)->rock = 0;

}
void Moved(Square* MAS,int* name,int* rotate) {
	if (checkd(MAS,name ,rotate)) {
		return;
	}
	int col = 0;
	for (int i = 19; i >= 0; --i) {
		for (int j = 10; j >= 0; --j) {
			if ((MAS + i * 10 + j)->rock == 1) {
				moved(MAS, i, j);	
				col++;
			}
		}
		if (col == 4) {
			return;
		}
	}
}
void Mover(Square* MAS) {
	if (checkr(MAS, 1)) {
		return;
	}
	int col = 0;
	for (int j = 9; j >= 0; --j) {
		for (int i = 20; i >= 0; --i) {
			if ((MAS + i * 10 + j)->rock == 1) {
				mover(MAS, i, j);
				col++;
			}
		}
		if (col == 4) {
			return;
		}
	}
}
void Movel(Square* MAS) {
	if (checkr(MAS, -1)) {
		return;
	}
	int col = 0;
	for (int j = 0; j < 10; ++j) {
		for (int i = 20; i >= 0; --i) {
			if ((MAS + i * 10 + j)->rock == 1) {
				movel (MAS, i, j);
				col++;
			}
		}
		if (col == 4) {
			return;
		}
	}
}

void lineb(Square* MAS) {
	for (int i = 0; i < 20; ++i) {
		int col = 0;
		for (int j = 0; j < 10; ++j) {
			if ((MAS + i * 10 + j)->rock==2) {
				++col;
			}
		}
		if (col == 10) { /// УДАление
			counter(1);
			for (int k = 0; k < 10; ++k) {
				(MAS + i * 10 + k)->rock == 0;
			}
			for (int ii = i-1; ii >= 0; --ii) {
				for (int jj = 9; jj >= 0; --jj) {
					moved(MAS, ii, jj);
				}
			}
		}
	}
}
void grid(HDC hdc) {
	int xbegin = XBEGIN + SIZE;
	int ybegin = YBEGIN;

	for (int i = 0; i < 21; ++i) {
		MoveToEx(hdc, xbegin, ybegin, NULL);
		LineTo(hdc, xbegin + 10 * SIZE, ybegin);
		ybegin += SIZE;
	}
	ybegin = YBEGIN;
	for (int i = 0; i < 10; ++i) {
		MoveToEx(hdc, xbegin, ybegin, NULL);
		LineTo(hdc, xbegin, ybegin + 20 * SIZE);
		xbegin += SIZE;
	}

}
int counter(int c) {
	static int x=0;
	x = x + c;
	return x;
}
void runner(HDC hdc, Square* MAS) {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 10; ++j) {
			if ((MAS + i * 10 + j)->rock != 0) {
				square(hdc, XBEGIN + SIZE + j * SIZE, YBEGIN + i * SIZE, (MAS + i * 10 + j)->col);
			}
		}
	}
}

void glass(HDC hdc,Square* MAS) {
	int xbegin = XBEGIN;
	int ybegin = YBEGIN;
	Color col = { 10,200,200 };
	for (int i = 0; i < 21; ++i) {
		square(hdc, xbegin, ybegin,col);
		square(hdc, xbegin+11*SIZE, ybegin,col);
		ybegin += SIZE;
	}
	ybegin -= SIZE;
	xbegin += SIZE;
	for (int i = 0; i < 10; ++i) {
		square(hdc, xbegin, ybegin,col);
		xbegin += SIZE;
	}
	char* ct = "Counter:";
	TCHAR* text = (ct);
	SetTextColor(hdc, RGB(0, 0,0));
	SetBkMode(hdc, TRANSPARENT);
	TextOutA(hdc, 250, 100, text, 9);
	char num = '0' + counter(0);
	text = (&num);
	SetTextColor(hdc, RGB(0, 0, 0));
	SetBkMode(hdc, TRANSPARENT);
	TextOutA(hdc, 310, 100, &num, 1);
	runner(hdc, MAS);
	grid(hdc);
}



void Rotate(Square* MAS, int* name, int* rotate) {
	int x = -1;
	int y=-1;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 10; ++j) {
			if ((MAS + i * 10 + j)->rock == 1) {
				x = j;
				y = i;
				break;
			}
		}
		if (x != -1) {
			break;
		}
	}
	if (x == -1) {
		return;
	}
	if (*name == 7) {
		if (*rotate == 0 || *rotate == 2) {

		
			if ((MAS + y * 10 + x - 1)->rock == 2) {
				return;
			}
			if ((y + 2 >= 20) || (MAS + (y + 2) * 10 + x)->rock == 2) {
				return;
			}
			*(MAS + y * 10 + x - 1) = *(MAS + y * 10 + x);
			(MAS + y * 10 + x)->rock = 0;
			*(MAS + (y + 2) * 10 + x) = *(MAS + y * 10 + x + 1);
			(MAS + y * 10 + x + 1)->rock = 0;
			*rotate = 1;
			return;
		}
		if (*rotate == 1) {

			
			if ((MAS + y * 10 + x + 1)->rock == 2) {
				return;
			}
			if ((x + 2 >= 10) || (MAS + y * 10 + x + 2)->rock == 2) {
				return;
			}
			*(MAS + y * 10 + x + 1) = *(MAS + y * 10 + x);
			(MAS + y * 10 + x)->rock = 0;
			*(MAS + (y) * 10 + x + 2) = *(MAS + (y + 2) * 10 + x + 1);
			(MAS + (y + 2) * 10 + x + 1)->rock = 0;
			*rotate = 2;
			return;
		}
	}
	if (*name == 6) {
		if (*rotate == 0 || *rotate == 2) {

			
			if ((MAS + (y + 1) * 10 + x)->rock == 2) {
				return;
			}
			if ((y + 2 >= 20) || (MAS + (y + 2) * 10 + x)->rock == 2) {
				return;
			}
			*(MAS + (y + 1) * 10 + x) = *(MAS + y * 10 + x);
			(MAS + y * 10 + x)->rock = 0;
			*(MAS + (y + 2) * 10 + x) = *(MAS + (y + 1) * 10 + x + 2);
			(MAS + (y + 1) * 10 + x + 2)->rock = 0;
			*rotate = 1;
			return;
		}
		if (*rotate == 1) {

			
			if ((MAS + y * 10 + x - 1)->rock == 2) {
				return;
			}
			if ((x + 1>= 10) || (MAS + (y + 1) * 10 + x + 1)->rock == 2) {
				return;
			}
			*(MAS + y * 10 + x - 1) = *(MAS + (y + 1) * 10 + x-1 );
			(MAS + (y + 1) * 10 + x - 1)->rock = 0;
			*(MAS + (y+1) * 10 + x + 1) = *(MAS + (y + 2) * 10 + x - 1);
			(MAS + (y + 2) * 10 + x - 1)->rock = 0;
			*rotate = 2;
			return;
		}
	}
	if (*name == 5) {
		if (*rotate == 0) {

			
			if ((MAS + (y + 1) * 10 + x)->rock == 2) {
				return;
			}
			if ((y + 2 >= 20) || (MAS + (y + 2) * 10 + x+1)->rock == 2) {
				return;
			}
			*(MAS + (y + 1) * 10 + x) = *(MAS + y * 10 + x);
			(MAS + y * 10 + x)->rock = 0;
			*(MAS + (y + 2) * 10 + x+1) = *(MAS + (y ) * 10 + x + 2);
			(MAS + (y ) * 10 + x + 2)->rock = 0;
			*rotate = 1;
			return;
		}
		if (*rotate == 1) {

			
			
			if ((x + 1 >= 10) || (MAS + (y + 1) * 10 + x + 1)->rock == 2) {
				return;
			}
			
			*(MAS + (y + 1) * 10 + x + 1) = *(MAS + (y + 2) * 10 + x );
			(MAS + (y + 2) * 10 + x )->rock = 0;
			*rotate = 2;
			return;
		}
		if (*rotate == 2) {

			
			if ((MAS + (y ) * 10 + x-1)->rock == 2) {
				return;
			}
			if ((y + 2 >= 20) || (MAS + (y + 2) * 10 + x - 1)->rock == 2) {
				return;
			}
			*(MAS + (y ) * 10 + x-1) = *(MAS + y * 10 + x);
			(MAS + y * 10 + x)->rock = 0;
			*(MAS + (y + 2) * 10 + x -1) = *(MAS + (y+1) * 10 + x + 1);
			(MAS + (y+1) * 10 + x + 1)->rock = 0;
			*rotate = 3;
			return;
		}
		if (*rotate == 3) {

			
			if ((MAS + (y) * 10 + x +1)->rock == 2) {
				return;
			}
			if ((x + 2 >= 10) || (MAS + (y ) * 10 + x +2)->rock == 2) {
				return;
			}
			*(MAS + (y) * 10 + x + 1) = *(MAS + (y+1) * 10 + x);
			(MAS + (y+1) * 10 + x)->rock = 0;
			*(MAS + (y )* 10 + x+2 ) = *(MAS + (y +2) * 10 + x );
			(MAS + (y + 2) * 10 + x )->rock = 0;
			*rotate = 0;
			return;
		}
		
	}
	if (*name == 4) {
		if (*rotate == 0) {

			
			
			if ((y + 2 >= 20) || (MAS + (y + 2) * 10 + x + 1)->rock == 2) {
				return;
			}
			if ((MAS + (y + 2) * 10 + x+2)->rock == 2) {
				return;
			}
			*(MAS + (y + 2) * 10 + x+1) = *(MAS + y * 10 + x);
			(MAS + y * 10 + x)->rock = 0;
			*(MAS + (y + 2) * 10 + x + 2) = *(MAS + (y) * 10 + x + 1);
			(MAS + (y) * 10 + x + 1)->rock = 0;
			*rotate = 1;
			return;
		}
		if (*rotate == 1) {

			

			if ((x -2 <0) || (MAS + (y) * 10 + x -2)->rock == 2) {
				return;
			}
			if ((MAS + (y+1 ) * 10 + x - 2)->rock == 2) {
				return;
			}
			if ((MAS + (y+1) * 10 + x - 1)->rock == 2) {
				return;
			}
			*(MAS + (y + 1) * 10 + x - 2) = *(MAS + (y)  * 10 + x);
			(MAS + (y ) * 10 + x)->rock = 0;
			*(MAS + (y ) * 10 + x - 2) = *(MAS + (y+2) * 10 + x);
			(MAS + (y+2) * 10 + x)->rock = 0;
			*(MAS + (y + 1) * 10 + x - 1) = *(MAS + (y+2) * 10 + x-1);
			(MAS + (y+2) * 10 + x-1)->rock = 0;
			*rotate = 2;
			return;
		}
		if (*rotate == 2) {

			
			if ((MAS + (y) * 10 + x + 1)->rock == 2) {
				return;
			}
			if ((y + 2 >= 20) || (MAS + (y + 2) * 10 + x )->rock == 2) {
				return;
			}
			*(MAS + (y) * 10 + x + 1) = *(MAS + (y+1) * 10 + x+1);
			(MAS + (y+1) * 10 + x+1)->rock = 0;
			*(MAS + (y + 2) * 10 + x ) = *(MAS + (y + 1) * 10 + x + 2);
			(MAS + (y + 1) * 10 + x + 2)->rock = 0;
			*rotate = 3;
			return;
		}
		if (*rotate == 3) {

			
			
			if ((x + 2 >= 10) || (MAS + (y) * 10 + x + 2)->rock == 2) {
				return;
			}
			if ((MAS + (y+1) * 10 + x + 2)->rock == 2) {
				return;
			}
			*(MAS + (y) * 10 + x + 2) = *(MAS + (y + 1) * 10 + x);
			(MAS + (y + 1) * 10 + x)->rock = 0;
			*(MAS + (y+1) * 10 + x + 2) = *(MAS + (y + 2) * 10 + x);
			(MAS + (y + 2) * 10 + x)->rock = 0;
			*rotate = 0;
			return;
		}

	}
	if (*name == 3) {
		if (*rotate == 0) {

			

			if ((y + 2 >= 20) || (MAS + (y + 2) * 10 + x + 1)->rock == 2) {
				return;
			}
			if ((MAS + (y + 1) * 10 + x + 1)->rock == 2) {
				return;
			}
			*(MAS + (y + 2) * 10 + x + 1) = *(MAS + (y+1) * 10 + x);
			(MAS + (y+1) * 10 + x)->rock = 0;
			*(MAS + (y + 1) * 10 + x + 1) = *(MAS + (y) * 10 + x + 2);
			(MAS + (y) * 10 + x + 2)->rock = 0;
			*rotate = 1;
			return;
		}
		if (*rotate == 1) {

			

			if ((x + 2 >=10) || (MAS + (y+1) * 10 + x + 2)->rock == 2) {
				return;
			}
			if ((MAS + (y + 1) * 10 + x )->rock == 2) {
				return;
			}
			if ((MAS + (y ) * 10 + x + 2)->rock == 2) {
				return;
			}
			*(MAS + (y + 1) * 10 + x + 2) = *(MAS + (y) * 10 + x);
			(MAS + (y) * 10 + x)->rock = 0;
			*(MAS + (y+1) * 10 + x ) = *(MAS + (y ) * 10 + x+1);
			(MAS + (y) * 10 + x+1)->rock = 0;
			*(MAS + (y ) * 10 + x + 2 ) = *(MAS + (y + 2) * 10 + x + 1);
			(MAS + (y + 2) * 10 + x + 1)->rock = 0;
			*rotate = 2;
			return;
		}
		if (*rotate == 2) {

			
			
			if ((y + 2 >= 20) || (MAS + (y + 2) * 10 + x-1)->rock == 2) {
				return;
			}
			if ((MAS + (y) * 10 + x - 2)->rock == 2) {
				return;
			}
			if ((MAS + (y+2) * 10 + x - 2)->rock == 2) {
				return;
			}
			*(MAS + (y+2) * 10 + x - 1) = *(MAS + (y ) * 10 + x );
			(MAS + (y ) * 10 + x )->rock = 0;
			*(MAS + (y ) * 10 + x-2) = *(MAS + (y + 1) * 10 + x );
			(MAS + (y + 1) * 10 + x )->rock = 0;
			*(MAS + (y+2) * 10 + x - 2) = *(MAS + (y + 1) * 10 + x-1);
			(MAS + (y + 1) * 10 + x-1)->rock = 0;
			*rotate = 3;
			return;
		}
		if (*rotate == 3) {

			

			if ((x + 2 >= 10) || (MAS + (y) * 10 + x + 2)->rock == 2) {
				return;
			}
			if ((MAS + (y ) * 10 + x + 1)->rock == 2) {
				return;
			}
			*(MAS + (y) * 10 + x + 2) = *(MAS + (y + 2) * 10 + x);
			(MAS + (y + 2) * 10 + x)->rock = 0;
			*(MAS + (y ) * 10 + x + 1) = *(MAS + (y + 2) * 10 + x+1);
			(MAS + (y + 2) * 10 + x+1)->rock = 0;
			*rotate = 0;
			return;
		}

	}
	if (*name == 1) {
		if (*rotate == 0 || *rotate == 2) {

			
			if ((x + 3 >= 10) || (MAS + (y ) * 10 + x+1)->rock == 2) {
				return;
			}
			if ((MAS + y * 10 + x + 2)->rock == 2) {
				return;
			}
			if ((MAS + y * 10 + x + 3)->rock == 2) {
				return;
			}
			*(MAS + y * 10 + x + 1) = *(MAS + (y+1) * 10 + x);
			(MAS + (y+1) * 10 + x)->rock = 0;
			*(MAS + (y ) * 10 + x+2) = *(MAS + (y+2) * 10 + x);
			(MAS + (y+2) * 10 + x)->rock = 0;
			*(MAS + (y) * 10 + x + 3) = *(MAS + (y + 3) * 10 + x);
			(MAS + (y + 3) * 10 + x)->rock = 0;
			*rotate = 1;
			return;
		}
		if (*rotate == 1) {

			
			
			if ((y + 3 >= 20) || (MAS + (y+1) * 10 + x )->rock == 2) {
				return;
			}
			if ((MAS + (y+2) * 10 + x )->rock == 2) {
				return;
			}
			if ((MAS + (y+3) * 10 + x )->rock == 2) {
				return;
			}
			*(MAS + (y+1) * 10 + x ) = *(MAS + y * 10 + x+1);
			(MAS + y * 10 + x+1)->rock = 0;
			*(MAS + (y+2) * 10 + x ) = *(MAS + (y ) * 10 + x + 2);
			(MAS + (y ) * 10 + x + 2)->rock = 0;
			*(MAS + (y + 3) * 10 + x) = *(MAS + (y) * 10 + x + 3);
			(MAS + (y) * 10 + x + 3)->rock = 0;
			*rotate = 2;
			return;
		}
	}
}
