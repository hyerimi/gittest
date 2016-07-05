#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"




int main()
{	
	int bLoop = 1;
	char cmd;
	int xpos,ypos;
	xpos =1; ypos =1;
	
	int orc_xpos,orc_ypos;
	orc_ypos = 10;
	orc_xpos = 10;

	while(bLoop) {
		scanf("%c",&cmd);
		switch(cmd)	{
			case 'u' :
			ypos -=1;
			break;
			case 'd' :
			ypos +=1;
			break;
			case 'l' :
			xpos -=1;
			break;
			case 'r' :
			xpos +=1;
			break;
			case 'q' :
			bLoop =  0;
			break;
		}
		system("clear");
		//주인공 출력
		drawMyBox(3+xpos,3+ypos,44,5);
		drawMyBox(5+xpos,1+ypos,43,1);
		drawMyBox(2+xpos,3+ypos,43,0);
		drawMyBox(2+xpos,4+ypos,43,0);
		drawMyBox(2+xpos,5+ypos,43,0);
		drawMyBox(2+xpos,6+ypos,43,0);
		drawMyBox(9+xpos,3+ypos,43,0);
		drawMyBox(9+xpos,4+ypos,43,0);
		drawMyBox(9+xpos,5+ypos,43,0);
		drawMyBox(9+xpos,6+ypos,43,0);
		drawMyBox(4+xpos,9+ypos,43,0);
		drawMyBox(4+xpos,10+ypos,43,0);
		drawMyBox(4+xpos,11+ypos,43,0);
		drawMyBox(4+xpos,12+ypos,43,0);
		drawMyBox(7+xpos,9+ypos,43,0);
		drawMyBox(7+xpos,10+ypos,43,0);
		drawMyBox(7+xpos,11+ypos,43,0);
		drawMyBox(7+xpos,12+ypos,43,0);
		drawMyBox(4+xpos,5+ypos,41,0);
		drawMyBox(5+xpos,6+ypos,41,0);
		drawMyBox(6+xpos,5+ypos,41,0);
		//몹 AI
		if(orc_xpos > xpos) {
			orc_xpos -= 1;
		}
		else if (orc_xpos < xpos) {
			orc_xpos += 1;
		}
		else {
			
		}
		//몹출력
		drawMyBox(10+orc_xpos,10+orc_ypos,42,2);
		

		gotoxy(0,20);
		printf("====================================");
		
		printf("%d,%d \r",xpos,ypos);
	}
	
	//drawMyBox(2,2,41);
	return 0;
}
