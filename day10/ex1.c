#include <stdio.h>

void draw_tri1()
{
	int ix, iy;
	for(iy=0; iy<10; iy++) {
		for(ix=0; ix<iy; ix++) {
			putchar('*');
		}
		puts("");
	}
}

void draw_tri2()
{
	int ix, iy;
	for(iy=0; iy<10; iy++) {
		for(ix=10; ix>iy; ix--){
			putchar('*');
		}
		puts("");
	}
}

void draw_tri3()
{
	int ix, iy;
	for(iy=0; iy<10; iy++) {
		for(ix=10; ix>iy; ix--){
			putchar(' ');
		}
		for(ix=0; ix<=iy; ix++){
			putchar('*');
		}
		puts("");
	}
}

void draw_tri4()
{
	int ix, iy;
	for(iy=0; iy<10; iy++) {
		for(ix=10; ix>iy; ix--){
			putchar(' ');
		}
		for(ix=0; ix>=iy; ix--){
			putchar('*');
		}
		int ix1;
		int iy1=19;
		for(iy=0; iy<10; iy++) {
			for(ix1=20; ix1>iy1; ix1--){
				putchar('*');
			}
		}
		puts("");
	}
}


int main()
{
	draw_tri1();
	draw_tri2();
	draw_tri3();
	draw_tri4();
		
	return 0;
}
