#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include "../engine/engine2d.h"
#include "map.h"

_S_MAP_OBJECT MapObject;

int main()
{
	int bLoop = 1;

	MapObject.m_header.m_nSkima = 1;
	MapObject.m_pBuf = NULL;
	char TilePalette[] = {'.','#','@','%'};

	while(bLoop)
	{
		char szCmd[32];
		gets(szCmd);
		char *pTemp = strtok(szCmd," ");
		if(!strcmp(pTemp,"exit")) {
			bLoop = 0;
			if(MapObject.m_pBuf) {
				free(MapObject.m_pBuf);
			}
		}
		else if(!strcmp(pTemp,"dump")) {
			map_dump( &MapObject, TilePalette);		
		}			
		else if(!strcmp(pTemp,"new")) {
			//new 8 4 
			int nWidth = 
				atoi( strtok(NULL," "));
			int nHeight = 
				atoi( strtok(NULL," "));

			map_new( &MapObject,nWidth,nHeight);
		}
		else if(!strcmp(pTemp,"put")) {
			//put 1 2 1 (x y tile_index)
			int x,y,tile_index;
			x = atoi(strtok(NULL," "));
			y = atoi(strtok(NULL," "));
			tile_index = atoi(strtok(NULL," "));
			//MapObject.m_pBuf[ y*MapObject.m_header.m_nWidth + x ] = tile_index;
			map_PutTile(&MapObject,x,y,tile_index);
			
			//MapObject->PutTile(x,y,tile_index); <-java
		}
		else if(!strcmp(pTemp,"hline")) {
			//hline 1 2
			int xpos, tile_index;
			xpos = atoi(strtok(NULL," "));
			tile_index = atoi(strtok(NULL," "));
			
			for(int i=0; i<MapObject.m_header.m_nHeight; i++) {
				MapObject.m_pBuf[i*MapObject.m_header.m_nWidth + xpos] = tile_index;
			}
		}
		else if(!strcmp(pTemp,"vline")) {
			//vline 1 2
			int ypos, tile_index;
			ypos = atoi(strtok(NULL," "));
			tile_index = atoi(strtok(NULL," "));

			for(int i=0; i<MapObject.m_header.m_nWidth; i++) {
				MapObject.m_pBuf [ypos*MapObject.m_header.m_nWidth + i] = tile_index;
			}
		}
		else if(!strcmp(pTemp,"save")) {
			//save filename
			char *pTemp = strtok(NULL," ");
			map_save(&MapObject,pTemp);
			puts("save ok");
		}
		else if(!strcmp(pTemp,"load")) {
			//load filename
			char *pTemp = strtok(NULL," ");
			map_load(&MapObject,pTemp);
			puts("load ok");
		}
		else if(!strcmp(pTemp,"tridraw_1")) {
			//tridraw_1
			int tile_index;
			tile_index = atoi(strtok(NULL," "));
			for(int i=0; i<MapObject.m_header.m_nHeight; i++) {
				for(int ix=0; (ix<=i) && (ix<=MapObject.m_header.m_nWidth); ix++) {
					MapObject.m_pBuf[(i * MapObject.m_header.m_nWidth) +ix] = tile_index;
				}
			}
		}
		else if(!strcmp(pTemp,"draw_cross")) {
			//draw_cross 1 2 1
			int x,y,tile_index;
			x = atoi(strtok(NULL," "));
			y = atoi(strtok(NULL," "));
			tile_index = atoi(strtok(NULL," "));
			
			MapObject.m_pBuf[ (y* MapObject.m_header.m_nWidth) +x] = tile_index;
			MapObject.m_pBuf[ (y* MapObject.m_header.m_nWidth) +(x+1)] = tile_index;
			MapObject.m_pBuf[ (y* MapObject.m_header.m_nWidth) +(x-1)] = tile_index;
			MapObject.m_pBuf[ ((y+1)* MapObject.m_header.m_nWidth) +x] = tile_index;
			MapObject.m_pBuf[ ((y-1)* MapObject.m_header.m_nWidth) +x] = tile_index;		

		}
	}

	return 0;
}

