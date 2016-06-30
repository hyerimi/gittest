#include <stdio.h>
#include <stdlib.h>

void setColor(int fore_color,int backg_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,backg_color);

}

void gotoxy(int x, int y)
{
	printf("%c[%d;%df",0x1b,y,x);
}

int main()
{
	
	int fore_color;
	fore_color = 31; 
	system("clear");
	

	//printf("\x1b[31m"); 와 같다.
	//printf("%c[%dm",0x1b,fore_color);
	gotoxy(20,20);
	setColor(30,41);
	printf("hello");

	gotoxy(20,25);
	setColor(37,44);
	printf("world");
	setColor(0,0); //reset ansi command
	
	gotoxy(15,18);
	printf("|");
	gotoxy(15,19);
	printf("|");
	gotoxy(15,20);
	printf("|");
	gotoxy(15,21);
	printf("|");
	gotoxy(15,22);
	printf("|");
	gotoxy(15,23);
	printf("|");
	gotoxy(15,24);
	printf("|");
	gotoxy(15,25);
	printf("|");
	gotoxy(15,26);
	printf("|");
	gotoxy(15,27);
	printf("|");
	gotoxy(15,28);
	printf("|");
	gotoxy(15,29);
	printf("|");
	gotoxy(15,30);
	printf("|");
	gotoxy(15,31);
	printf("|");

	gotoxy(60,18);
	printf("|");
	gotoxy(60,19);
	printf("|");
	gotoxy(60,20);
	printf("|");
	gotoxy(60,21);
	printf("|");
	gotoxy(60,22);
	printf("|");
	gotoxy(60,23);
	printf("|");
	gotoxy(60,24);
	printf("|");
	gotoxy(60,25);
	printf("|");
	gotoxy(60,26);
	printf("|");
	gotoxy(60,27);
	printf("|");
	gotoxy(60,28);
	printf("|");
	gotoxy(60,29);
	printf("|");
	gotoxy(60,30);
	printf("|");
	gotoxy(60,31);
	printf("|");

	gotoxy(35,18);
	printf("⊂ _＼");
	gotoxy(36,19);
	printf(" ＼＼ Λ＿Λ ");
	gotoxy(38,20);
	printf("＼( 'ㅅ' ) 두둠칫 ");
	gotoxy(38,21);
	printf("  >　  ^ ＼ ");
	gotoxy(38,22);
	printf(" / 　 へ ＼ ");
	gotoxy(37,23);
	printf(" /　　/　＼＼ ");
	gotoxy(36,24);
	printf("  v　ノ 　 ＼_つ ");
	gotoxy(37,25);
	printf("/　/두둠칫 ");
	gotoxy(36,26);
	printf("/　/| ");
	gotoxy(35,27);
	printf("(　(＼");
	gotoxy(35,28);
	printf("|　|、＼");
	gotoxy(35,29);
	printf("| , ＼ ⌒)");
	gotoxy(35,30);
	printf("| | 　)  / ");
	gotoxy(33,31);
	printf("ノ_ )　 Lノ");
	
	
	
	
	
	
	
		
	gotoxy(1,50);
	printf("===================");
	return 0;

}
