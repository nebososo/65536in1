#define BATTERY1MAP_WIDTH 3
#define BATTERY1MAP_HEIGHT 2
const char battery1Map[] PROGMEM={
3,2
,BATTERY0_TILE,20-RAM_TILES_COUNT,21-RAM_TILES_COUNT,BATTERY1_TILE,22-RAM_TILES_COUNT,23-RAM_TILES_COUNT};

#define BATTERY2MAP_WIDTH 3
#define BATTERY2MAP_HEIGHT 2
const char battery2Map[] PROGMEM={
3,2
,BATTERY0_TILE,24-RAM_TILES_COUNT,25-RAM_TILES_COUNT,BATTERY1_TILE,26-RAM_TILES_COUNT,27-RAM_TILES_COUNT};

#define BATTERY3MAP_WIDTH 3
#define BATTERY3MAP_HEIGHT 2
const char battery3Map[] PROGMEM={
3,2
,BATTERY0_TILE,28-RAM_TILES_COUNT,29-RAM_TILES_COUNT,BATTERY1_TILE,30-RAM_TILES_COUNT,31-RAM_TILES_COUNT};

#define BATTERY4MAP_WIDTH 3
#define BATTERY4MAP_HEIGHT 2
const char battery4Map[] PROGMEM={
3,2
,BATTERY0_TILE,32-RAM_TILES_COUNT,33-RAM_TILES_COUNT,BATTERY1_TILE,34-RAM_TILES_COUNT,35-RAM_TILES_COUNT};

#define PEGMAP_WIDTH 1
#define PEGMAP_HEIGHT 2
const char pegMap[] PROGMEM ={
1,2
,-RAM_TILES_COUNT,1-RAM_TILES_COUNT};

#define PEGHOLEMAP_WIDTH 1
#define PEGHOLEMAP_HEIGHT 2
const char pegHoleMap[] PROGMEM ={
1,2
,4-RAM_TILES_COUNT,5-RAM_TILES_COUNT};

#define GOODPEGMAP_WIDTH 1
#define GOODPEGMAP_HEIGHT 2
const char goodPegMap[] PROGMEM ={
1,2
,2-RAM_TILES_COUNT,3-RAM_TILES_COUNT};

#define GOODPEGHOLEMAP_WIDTH 1
#define GOODPEGHOLEMAP_HEIGHT 2
const char goodPegHoleMap[] PROGMEM ={
1,2
,6-RAM_TILES_COUNT,7-RAM_TILES_COUNT};

#define T_TILE (0-RAM_TILES_COUNT)
#define B_TILE (1-RAM_TILES_COUNT)
#define L_TILE (2-RAM_TILES_COUNT)
#define R_TILE (3-RAM_TILES_COUNT)
#define TL_TILE (4-RAM_TILES_COUNT)
#define BL_TILE (5-RAM_TILES_COUNT)
#define BR_TILE (6-RAM_TILES_COUNT)
#define TR_TILE (7-RAM_TILES_COUNT)
#define NO_T_TILE (8-RAM_TILES_COUNT)
#define NO_B_TILE (9-RAM_TILES_COUNT)
#define NO_L_TILE (10-RAM_TILES_COUNT)
#define NO_R_TILE (11-RAM_TILES_COUNT)
#define NO_TILE (12-RAM_TILES_COUNT)
#define GRASS_TILE (13-RAM_TILES_COUNT)
#define SYMBOL_0 (14-RAM_TILES_COUNT)
#define SYMBOL_1 (15-RAM_TILES_COUNT)
#define SYMBOL_2 (16-RAM_TILES_COUNT)
#define SYMBOL_3 (17-RAM_TILES_COUNT)

#define SYMBOLMAP_WIDTH 2
#define SYMBOLMAP_HEIGHT 2
const char symbolMap[] PROGMEM ={
2,2
,SYMBOL_0,SYMBOL_1,SYMBOL_2,SYMBOL_3};

#define TROLLBOXMAP_WIDTH 4
#define TROLLBOXMAP_WIDTH 4
const char trollBoxMap[] PROGMEM ={
4,4
,TL_TILE, T_TILE, T_TILE, TR_TILE
,L_TILE, NO_TILE, NO_TILE, R_TILE
,L_TILE, NO_TILE, NO_TILE, R_TILE
,BL_TILE, B_TILE, B_TILE, BR_TILE
};

#define VTROLLMAP_WIDTH 2
#define VTROLLMAP_HEIGHT 2
const char vTrollMap[] PROGMEM ={
2,2
,18-RAM_TILES_COUNT,19-RAM_TILES_COUNT,20-RAM_TILES_COUNT,21-RAM_TILES_COUNT
};

#define STUNNEDVTROLLMAP_WIDTH 2
#define STUNNEDVTROLLMAP_HEIGHT 2
const char stunnedVTrollMap[] PROGMEM ={
2,2
,22-RAM_TILES_COUNT,23-RAM_TILES_COUNT,20-RAM_TILES_COUNT,21-RAM_TILES_COUNT
};

#define STROLLMAP_WIDTH 2
#define STROLLMAP_HEIGHT 2
const char sTrollMap[] PROGMEM ={
2,2
,24-RAM_TILES_COUNT,25-RAM_TILES_COUNT,26-RAM_TILES_COUNT,27-RAM_TILES_COUNT
};

#define TITLEMAP_WIDTH 28
#define TITLEMAP_HEIGHT 6
const char titleMap[] PROGMEM ={
28,6
, 0-RAM_TILES_COUNT, 0-RAM_TILES_COUNT, 0-RAM_TILES_COUNT, 0x0,
1-RAM_TILES_COUNT, 1-RAM_TILES_COUNT, 1-RAM_TILES_COUNT, 0x0,
2-RAM_TILES_COUNT, 2-RAM_TILES_COUNT, 2-RAM_TILES_COUNT, 0x0,
3-RAM_TILES_COUNT, 3-RAM_TILES_COUNT, 3-RAM_TILES_COUNT, 0x0,
4-RAM_TILES_COUNT, 4-RAM_TILES_COUNT, 4-RAM_TILES_COUNT, 0x0 ,
5-RAM_TILES_COUNT, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 7-RAM_TILES_COUNT,
0-RAM_TILES_COUNT, 0x0, 0x0, 0x0, 1-RAM_TILES_COUNT, 0x0, 0x0, 0x0,
2-RAM_TILES_COUNT, 0x0, 0x0, 0x0 , 0x0, 0x0, 3-RAM_TILES_COUNT, 0x0,
4-RAM_TILES_COUNT, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
7-RAM_TILES_COUNT, 7-RAM_TILES_COUNT, 0-RAM_TILES_COUNT, 0-RAM_TILES_COUNT,
0-RAM_TILES_COUNT, 0x0 , 1-RAM_TILES_COUNT, 1-RAM_TILES_COUNT,
1-RAM_TILES_COUNT, 0x0, 2-RAM_TILES_COUNT, 2-RAM_TILES_COUNT,
2-RAM_TILES_COUNT, 0x0, 3-RAM_TILES_COUNT, 3-RAM_TILES_COUNT,
3-RAM_TILES_COUNT, 0x0, 4-RAM_TILES_COUNT, 4-RAM_TILES_COUNT,
4-RAM_TILES_COUNT, 0x0, 5-RAM_TILES_COUNT, 0x0, 6-RAM_TILES_COUNT,
6-RAM_TILES_COUNT , 6-RAM_TILES_COUNT, 0x0, 0x0, 7-RAM_TILES_COUNT,
0-RAM_TILES_COUNT, 0x0, 0-RAM_TILES_COUNT, 0x0, 0x0, 0x0, 1-RAM_TILES_COUNT,
0x0, 0x0, 0x0, 2-RAM_TILES_COUNT, 0x0, 0x0, 0x0, 3-RAM_TILES_COUNT, 0x0 ,
4-RAM_TILES_COUNT, 0x0, 4-RAM_TILES_COUNT, 0x0, 5-RAM_TILES_COUNT, 0x0,
6-RAM_TILES_COUNT, 0x0, 6-RAM_TILES_COUNT, 0x0, 0x0, 7-RAM_TILES_COUNT,
0-RAM_TILES_COUNT, 0-RAM_TILES_COUNT, 0-RAM_TILES_COUNT, 0x0,
1-RAM_TILES_COUNT, 1-RAM_TILES_COUNT, 1-RAM_TILES_COUNT, 0x0 ,
2-RAM_TILES_COUNT, 2-RAM_TILES_COUNT, 2-RAM_TILES_COUNT, 0x0,
3-RAM_TILES_COUNT, 3-RAM_TILES_COUNT, 3-RAM_TILES_COUNT, 0x0,
4-RAM_TILES_COUNT, 4-RAM_TILES_COUNT, 4-RAM_TILES_COUNT, 0x0,
5-RAM_TILES_COUNT, 0x0, 6-RAM_TILES_COUNT, 0x0, 6-RAM_TILES_COUNT, 0x0, 0x0,
7-RAM_TILES_COUNT , 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 , 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0};

#define EXPLOSIONMAP_WIDTH 2
#define EXPLOSIONMAP_HEIGHT 2
const char explosionMap[] PROGMEM={
2,2
,20-RAM_TILES_COUNT ,21-RAM_TILES_COUNT ,20-RAM_TILES_COUNT ,21-RAM_TILES_COUNT
};
