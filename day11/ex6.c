#include <stdio.h>
#include <stdlib.h>

#include "../mapEditor/map.h"

int main()
{
	_S_MAP_OBJECT screenBuf;
	map_init(&screenBuf);
	map_new(&screenBuf,16,16);
	
	map_PutTile(&screenBuf,2,5,4);
	map_PutTile(&screenBuf,3,5,4);
	map_PutTile(&screenBuf,1,5,4);
	map_PutTile(&screenBuf,0,5,4);
	map_PutTile(&screenBuf,0,6,4);
	map_PutTile(&screenBuf,1,6,4);


	_S_MAP_OBJECT humanObj;
	map_init(&humanObj);
	map_load(&humanObj,"human.dat");
	puts("\r\n---------------------------");

	map_drawTile_trn(&humanObj,5,5,&screenBuf);

	map_dump(&screenBuf,Default_Tilepalette);


	return 0;
}
