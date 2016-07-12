#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pMapBuf;
char chrTable[] = {'.','#','@','*'};

void putTile(int ey, int sy, int ex, int sx, 
		int width, char *ptrBuf, char *pchrTable)

{

	int ix, iy;
	for(iy=ey; iy<sy; iy++) {
		for(ix=ex; ix<sx; ix++) {
			putchar( chrTable [ptrBuf [ (iy*width) +ix] ] );
		}
		printf("\r\n");
		//puts("");
	}
}

int main()
{
	int width, height;
	FILE *fp;
	fp = fopen("./ex2.data.txt","r");

	char buf[256];

	fgets(buf,256,fp);

	puts(buf);

	char *pTemp = strtok(buf,",");
	//puts(pTemp);
	width = atoi(pTemp);
	pTemp = strtok(NULL,",");
	height = atoi(pTemp);

	pMapBuf = (char *)malloc(width*height);

	int ix, iy;	
	for(iy=0; iy<height; iy++) {
		fgets(buf,256,fp);
		pTemp = strtok(buf,",");
		pMapBuf[iy*width + 0] = atoi(pTemp); 
		for(ix=1; ix<width; ix++) {
			pTemp = strtok(NULL,",");
			pMapBuf[iy*width + ix] = atoi(pTemp);


		}
	}
	
	putTile(0,height,0,width,width,pMapBuf,chrTable);

	free(pMapBuf);	
	fclose(fp);

}
