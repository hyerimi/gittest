#ifndef __RCAME_H__
#define __RGAME_H__

void drawGame(
int mx, int my, char *pBuf)
{
		//랜더링
		gotoxy(1,1);
		int x,y;
		for(y=0;y<8;y++)
		{
			for(x=0;x<my;x++) {
				switch(pBuf[my*y+x]) {
					case 0 :
						putchar('.');
						break;
					case 1 :
						putchar('#');
						break;
					case 2 :
						putchar('A');
						break;		
				}
			}
			printf("\r\n");
		}


}






#endif
