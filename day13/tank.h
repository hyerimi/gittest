#ifndef __TANK_H__
#define __TANK_H__

typedef struct _S_TANK {
	int m_nXpos;
	int m_nYpos;
	int nFSM_1;
	_S_MAP_OBJECT *m_pBody;
	void (*fpApply)(struct _S_TANK *, double , char );
	void (*fpDraw)(struct _S_TANK *, _S_MAP_OBJECT *);
} _S_TANK;

void Tank_Apply(_S_TANK *pObj,_S_MAP_OBJECT *pBuff);

void Tank_Draw(_S_TANK *pObj, _S_MAP_OBJECT *pBuff);

void Tank_init(_S_TANK *pObj, _S_MAP_OBJECT *pBody, int x, int y);



#endif
