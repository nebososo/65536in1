#include <stdint.h>
#include <stdlib.h>
#include <uzebox.h>
#include <string.h>
#include <avr/pgmspace.h>
#include "data/tileset.inc"
#include "data/trollen.inc"

#define WHITE_NUMBER 16
#define BLUE_NUMBER 64
#define GREEN_NUMBER 74
#define CPU_DELAY 30
#define STENCH_ROOM 1
#define BREEZE_ROOM 2
#define BOTH_ROOM 3
#define WUMPUS_ROOM 4
#define HOLE_ROOM 5
#define CORRIDOR 6
#define CAVE_WIDTH 12
#define CAVE_HEIGHT 10
#define MOVE_DELAY 20
#define SHOT_DELAY 6
#define FASTER_DELAY 6
#define NO_TROLL 0
#define V_TROLL 1
#define H_TROLL 2
#define S_TROLL 3
#define TOP_WALL 1
#define RIGHT_WALL 2
#define BOTTOM_WALL 4
#define LEFT_WALL 8
#define MAX_TRAPS 3
#define VICTORY 1
#define DEFEAT 2
#define OUTSIDE 1
#define PEG 2
#define HOLE 3
#define GOOD_CURSOR 0x80
#define BAD_CURSOR 0x40
#define BLINK_DELAY 4

const char strGreed[] PROGMEM = "GREED";
const char strPiles[] PROGMEM = "PILES";
const char strGrab[] PROGMEM = "GRAB";
const char str9[] PROGMEM = "9 SQUARES";
const char strGet[] PROGMEM = "GET 3";
const char strGrid[] PROGMEM = "THE GRID";
const char strTrollen [] PROGMEM = "TROLLEN";
const char strEscape[] PROGMEM = "ESCAPE";
const char strAdventure[] PROGMEM = "ADVENTURE";
const char strSlide[] PROGMEM = "SLIDE";
const char strPuzzle[] PROGMEM = "PUZZLE";
const char strAncient[] PROGMEM = "ANCIENT GAME";
const char strOne[] PROGMEM = "THE ONE";
const char strRemove[] PROGMEM = "REMOVE";
const char strTake[] PROGMEM = "TAKE";
const char strMonster[] PROGMEM = "MONSTER";
const char strDungeon[] PROGMEM = "DUNGEON";
const char strHunt[] PROGMEM = "HUNT";
const char strSurvival[] PROGMEM = "SURVIVAL";
const char strAvoider[] PROGMEM = "AVOIDER";
const char strInstinct[] PROGMEM = "INSTINCT";
const char strRain[] PROGMEM = "RAIN";
const char strFalling[] PROGMEM = "FALLING BUTTONS";
const char strReflex[] PROGMEM = "REFLEX";
const char strArray[] PROGMEM = "ARRAY";
const char strSort[] PROGMEM = "SORT";
const char strFast[] PROGMEM = "BE FAST";
const char strRich[] PROGMEM = "RICH";
const char strChests[] PROGMEM = "CHESTS";
const char strDream[] PROGMEM = "DREAM";
const char * const names[] PROGMEM = {
  strGreed, strPiles, strGrab,
  strGrid, strGet, str9,
  strTrollen, strEscape, strAdventure,
  strSlide, strPuzzle, strAncient,
  strOne, strRemove, strTake,
  strMonster, strDungeon, strHunt,
  strSurvival, strAvoider, strInstinct,
  strRain, strFalling, strReflex,
  strArray, strSort, strFast,
  strRich, strChests, strDream
};
const char strVsCpu[] PROGMEM = "VS CPU";
const char strVsHuman[] PROGMEM = "VS HUMAN";
const char strExit[] PROGMEM = "EXIT";
const char strCFlavio[] PROGMEM = "\\ 2012 FL^VIO ZAVAN";
const char strLicense[] PROGMEM = "CODE LICENSED UNDER";
const char strMIT[] PROGMEM = "THE MIT LICENSE";
const char strTurn[] PROGMEM = "PLAYER  'S TURN";
const char strWins[] PROGMEM = "PLAYER   WINS";
const char strStart[] PROGMEM = "START";
const char strStarting[] PROGMEM = "PICK THE STARTING CHEST";
const char strSee[] PROGMEM = "LET'S SEE WHAT";
const char strInside[] PROGMEM = "WAS INSIDE THE CHEST";
const char strPhone[] PROGMEM = "THE PHONE IS RINGING";
const char strBanker[] PROGMEM = "IT'S THE BANKER";
const char strOffer[] PROGMEM = "HE'S OFFERING YOU";
const char strFor[] PROGMEM = "FOR YOUR CHEST";
const char strAccept[] PROGMEM = "ACCEPT";
const char strRefuse[] PROGMEM = "REFUSE";
const char strReceived[] PROGMEM = "YOU RECEIVED";
const char strCongratulations[] PROGMEM = "CONGRATULATIONS,";
const char strWantKeep[] PROGMEM = "DO YOU WANT TO KEEP";
const char strChestNo[] PROGMEM = "CHEST  OR DO YOU";
const char strTradeChest[] PROGMEM = "TRADE IT FOR CHEST   ?";
const char strKeep[] PROGMEM = "KEEP";
const char strTrade[] PROGMEM = "TRADE";
const char strInsideDef[] PROGMEM = "WAS INSIDE CHEST";
const char strCongrat[] PROGMEM = "CONGRATULATIONS";
const char strPlayer1[] PROGMEM = "PLAYER 1:";
const char strPlayer2[] PROGMEM = "PLAYER 2:";
const char strGenerating[] PROGMEM = "GENERATING LEVEL";
const char strWait[] PROGMEM = "PLEASE WAIT";
const char strAte[] PROGMEM = "THE WUMPUS ATE YOU";
const char strFell[] PROGMEM = "YOU FELL IN A HOLE";
const char strKill[] PROGMEM = "YOU KILLED THE WUMPUS";
const char strLives[] PROGMEM = "LIVES:";
const char strScore[] PROGMEM = "SCORE:";
const char strGameOver[] PROGMEM = "GAME OVER";
const char strDraw[] PROGMEM = "DRAW";
const char strDied[] PROGMEM = "YOU DIED";

const char * const batteries[] PROGMEM = {
  battery0Map,
  battery1Map,
  battery2Map,
  battery3Map,
  battery4Map
};
const char * const monsterRooms[] PROGMEM = {
  clearRoomMap,
  redRoomMap,
  greenRoomMap,
  bothRoomMap,
  wumpusMap,
  holeMap,
  corridor1Map,
  corridor2Map,
  guyMap,
  redGuyMap,
  greenGuyMap,
  bothGuyMap,
  wumpusMap,
  holeMap,
  corridor1Map,
  corridor2Map
};

const uint32_t prizes[] PROGMEM = {
  50, 100, 500, 1000, 2500, 5000, 7500, 10000, 20000, 30000, 40000, 50000,
  75000, 100000, 500000, 1000000, 2500000, 5000000, 7500000, 10000000,
  20000000, 30000000, 40000000, 50000000, 75000000, 100000000
};

struct int8_t_pair {
  int8_t x, y;
};

struct troll {
  struct int8_t_pair pos;
  uint8_t stun;
  uint8_t type;
};

struct trollenLevel {
  struct int8_t_pair hero;
  struct troll troll[2];
  struct int8_t_pair trap[MAX_TRAPS];
  uint8_t map[6][6];
};

extern uint8_t vram[];
/* Controller Handling */
uint16_t held[2] = {0, 0},
  pressed[2] = {0, 0},
  released[2] = {0, 0},
  prev[2] = {0, 0};

void controllerStart();
void controllerEnd();
void printColoredByte(uint8_t x, uint8_t y, uint8_t byte, uint8_t base);
void printColoredByte2(uint8_t x, uint8_t y, uint8_t byte, uint8_t base);
void printColoredShort(uint8_t x, uint8_t y, uint16_t byte, uint8_t base);
void printMoney(uint8_t x, uint8_t y, uint32_t value, uint8_t base);
void greed(uint8_t human);
uint8_t rainMoveDown(uint8_t player);
void rainShoot(uint8_t player, uint8_t key);
void rich();
uint8_t testSlide(uint8_t *m);
void switchSlide(uint8_t p, uint8_t o, uint8_t *m);
void slide();
void theOneDrawMap(const uint8_t map[7][7]);
bool theOneIsHoleGood(struct int8_t_pair peg, struct int8_t_pair hole,
    const uint8_t map[7][7]);
void theOne();
uint8_t getParent(uint8_t v, uint8_t *parent);
uint8_t checkConnectivity(uint8_t map[][CAVE_WIDTH], uint8_t *parent);
void flagAround(uint8_t y, uint8_t x, uint8_t f, uint8_t dist,
  uint8_t map[CAVE_HEIGHT][CAVE_WIDTH]);
void monster();
uint8_t testArray(uint8_t *m);
void gridDrawCursor(int8_t x, int8_t y, uint8_t tile);
int8_t gridCheck(const int8_t l[3][3]);
struct int8_t_pair gridGetMove(int8_t p, int8_t l[3][3]);
void grid(uint8_t human);
bool survivalMoveDown(uint8_t p, int8_t height[2][10], int8_t next[2][10]);
void survival(uint8_t players);
void rain(uint8_t human);
void sort(uint8_t human);
void trollenLoadLevel(uint8_t n, struct trollenLevel *level);
void trollenDrawLevel(const struct trollenLevel *level);
uint8_t trollen(uint8_t level);
uint16_t topmenu();
void drawBaseTitle(uint16_t game);
int8_t twoPlayersMenu();
int8_t onePlayerMenu(uint8_t level, uint8_t levels);
int main();

void controllerStart() {
  held[0] = ReadJoypad(0);
  pressed[0] = held[0] & (held[0] ^ prev[0]);
  released[0] = prev[0] & (held[0] ^ prev[0]);

  held[1] = ReadJoypad(1);
  pressed[1] = held[1] & (held[1] ^ prev[1]);
  released[1] = prev[1] & (held[1] ^ prev[1]);
}

void controllerEnd() {
  prev[0] = held[0];
  prev[1] = held[1];
}

void printColoredByte(uint8_t x, uint8_t y, uint8_t byte, uint8_t base) {
  SetTile(x--, y, base + (byte % 10));

  byte /= 10;
  SetTile(x--, y, (byte? base + (byte % 12) : 0));

  byte /= 10;
  SetTile(x--, y, (byte? base + (byte % 10) : 0));
}

void printColoredByte2(uint8_t x, uint8_t y, uint8_t byte, uint8_t base) {
  /* Print exactly two digits with zero padding */
  SetTile(x--, y, base + (byte % 10));

  byte /= 10;
  SetTile(x--, y, base + (byte % 10));
}

void printColoredShort(uint8_t x, uint8_t y, uint16_t s, uint8_t base) {
  do {
    SetTile(x--, y, base + (s % 10));
    s /= 10;
  } while (s);
}

void printMoney(uint8_t x, uint8_t y, uint32_t value, uint8_t base) {
  SetTile(x--, y, base + (value % 10));
  value /= 10;

  SetTile(x--, y, base + (value % 10));
  value /= 10;

  SetTile(x--, y, '.' - ' ');

  SetTile(x--, y, base + (value % 10));
  value /= 10;

  while (value) {
    SetTile(x--, y, base + (value % 10));
    value /= 10;
  }

  SetTile(x, y, '$' - ' ');
}

void greed(uint8_t human) {
  uint8_t i, n, t, s, v, w, xor, h, nv, d;
  uint8_t array[5];

  ClearVram();

  /* Randomly generate a new game and draw on the screen */
  for (i = 0; i < 5; i++) {
    array[i] = (random() % 8) + 1;
    PrintByte(5 + 5 * i, 24, array[i], 0);
    for (n = 0; n < array[i]; n++) {
      DrawMap2(3 + 5 * i, 21 - (n << 1),
        (const char *) pgm_read_word(batteries + i));
    }
  }

  t = (human? random() % 2 : 0);
  s = 0;
  w = 0;
  v = 0;
  nv = 0;
  d = 0;
  Print(8, 4, strTurn);
  SetTile(15, 4, WHITE_NUMBER + 1 + t);
  printColoredByte(5, 24, array[0], BLUE_NUMBER);

  while (1) {
    controllerStart();

    /* Select returns to the menu */
    if (pressed[0] & BTN_SELECT) {
      return;
    }

    if (!t || human) {
      if (!s) {
        /* Choosing a pile */
        if (pressed[t] & BTN_RIGHT) {
          greed_move_right:
          printColoredByte(5 + 5 * w, 24, array[w], WHITE_NUMBER);
          w = (w + 1) % 5;
          printColoredByte(5 + 5 * w, 24, array[w], BLUE_NUMBER);
        }
        else if (pressed[t] & BTN_LEFT) {
          printColoredByte(5 + 5 * w, 24, array[w], WHITE_NUMBER);
          w = (10 + w - 1) % 5;
          printColoredByte(5 + 5 * w, 24, array[w], BLUE_NUMBER);
        }
        else if (pressed[t] & BTN_A && array[w]) {
          greed_select:
          s = (t && !human? 2 : 1);
          v = array[w];
          printColoredByte(5 + 5 * w, 24, array[w], GREEN_NUMBER);
        }
      }
      /* Reducing */
      else {
        if (pressed[t] & BTN_DOWN && v) {
          greed_reduce:
          Fill(3 + 5 * w, 21 - (--v << 1), 3, 2, 0);
          printColoredByte(5 + 5 * w, 24, v, GREEN_NUMBER);
        }
        else if (pressed[t] & BTN_UP && v < array[w]) {
          DrawMap2(3 + 5 * w, 21 - (v << 1),
            (const char *) pgm_read_word(batteries + w));
          printColoredByte(5 + 5 * w, 24, ++v, GREEN_NUMBER);
        }
        else if (pressed[t] & BTN_B) {
          for (i = 0; i < array[w]; i++) {
            DrawMap2(3 + 5 * w, 21 - (i << 1),
              (const char *) pgm_read_word(batteries + w));
          }
          s = 0;
          printColoredByte(5 + 5 * w, 24, array[w], BLUE_NUMBER);
        }
        else if (pressed[t] & BTN_A && v < array[w]) {
          greed_apply:
          array[w] = v;
          printColoredByte(5 + 5 * w, 24, array[w], WHITE_NUMBER);
          w = 0;
          printColoredByte(5, 24, array[0], BLUE_NUMBER);

          s = 0;
          t ^= 1;
          SetTile(15, 4, WHITE_NUMBER + 1 + t);

          /* Check for victory */
          for (i = 0; i < 5; i++) {
            if (array[i]) {
              break;
            }
          }
          if (i == 5) {
            break;
          }

        }
      }
    }
    else {
      /* AI */
      if (!s) {
        s = 1;
        d = CPU_DELAY;

        /* Calculate the play */
        xor = 0;
        for (i = 0; i < 5; i++) {
          xor ^= array[i];
        }

        /* No winning strategy */
        if (!xor) {
          for (i = 0; i < 5; i++) {
            if (array[i]) {
              n = i;
              break;
            }
          }

          nv = array[n] - 1;
          goto greed_finish;
        }

        /* The if is going to be met because xor != 0 */
        for (h = 3; ; h--) {
          if (xor & (1 << h)) {
            break;
          }
        }

        for (i = 0; i < 5; i++) {
          if (array[i] & (1 << h)) {
            n = i;
            break;
          }
        }

        nv = xor ^ array[n];
      }
      else if (s == 1) {
        /* Select the right pile */
        if (d) {
          d--;
          goto greed_finish;
        }

        d = CPU_DELAY;

        if (w != n) {
          goto greed_move_right;
        }
        else {
          goto greed_select;
        }
      }
      else {
        /* Reduce */
        if (d) {
          d--;
          goto greed_finish;
        }

        d = CPU_DELAY;

        if (v != nv) {
          goto greed_reduce;
        }
        else {
          goto greed_apply;
        }
      }
    }

    greed_finish:
    WaitVsync(1);
    controllerEnd();
  }

  /* Announce the winner */
  Fill(5, 4, 20, 1, 0);
  Print(8, 4, strWins);
  SetTile(15, 4, WHITE_NUMBER + 1 + !t);

  /* Wait one of the players to press start */
  while (1) {
    controllerStart();

    if (pressed[0] & BTN_START || (human && pressed[1] & BTN_START)) {
      controllerEnd();
      break;
    }

    WaitVsync(1);
    controllerEnd();
  }
}

void printChests(uint8_t *available) {
  uint8_t y, x, i;

  x = 3;
  y = 4;
  for (i = 0; i < 26; i++) {
    if (!available[i]) {
      continue;
    }

    DrawMap2(x, y, closedChestMap);
    printColoredByte2(x + 2, y + 1, i, WHITE_NUMBER);

    x += 5;
    if (x > 23) {
      x = 3;
      y += 4;
    }
  }
}

void rich() {
  uint8_t i, n, s, left;
  uint8_t y, x;
  uint32_t r;
  uint8_t available[27];
  uint8_t order[26];
  memset(available, 1, sizeof(available));
  for (i = 0; i < 26; i++) {
    order[i] = i;
  }

  /* Randomize */
  for (i = 0; i < 26; i++) {
    n = (random() % (26 - i)) + i;

    s = order[i];
    order[i] = order[n];
    order[n] = s;
  }

  /* Select the starting chest */
  s = 0;
  ClearVram();
  Print(4, 6, strStarting);
  DrawMap2(13, 12, closedChestMap);
  printColoredByte2(15, 13, 0, GREEN_NUMBER);
  while (1) {
    controllerStart();

    if (pressed[0] & BTN_DOWN || pressed[0] & BTN_LEFT) {
      s = (25 + s) % 26;
      printColoredByte2(15, 13, s, GREEN_NUMBER);
    }
    else if (pressed[0] & BTN_UP || pressed[0] & BTN_RIGHT) {
      s = (s + 1) % 26;
      printColoredByte2(15, 13, s, GREEN_NUMBER);
    }
    else if (pressed[0] & BTN_A) {
      available[s] = 0;
      controllerEnd();
      break;
    }

    WaitVsync(1);
    controllerEnd();
  }

  left = 25;
  r = 0;

  /* Play */
  while (1) {
    /* Pick a chest */
    ClearVram();
    printChests(available);

    for (i = 0; !available[i]; i++);
    printColoredByte2(5, 5, i, BLUE_NUMBER);
    x = 3;
    y = 4;
    while (1) {
      controllerStart();

      if (pressed[0] & BTN_RIGHT) {
        printColoredByte2(x + 2, y + 1, i, WHITE_NUMBER);

        /* The array is 27 elements long, and 26 is always one */
        for (i = i + 1; !available[i]; i++);
        if (i == 26) {
          for (i = 0; !available[i]; i++);
          x = 3;
          y = 4;
        }
        else {
          x += 5;
          if (x > 23) {
            x = 3;
            y += 4;
          }
        }

        printColoredByte2(x + 2, y + 1, i, BLUE_NUMBER);
      }
      else if (pressed[0] & BTN_LEFT) {
        printColoredByte2(x + 2, y + 1, i, WHITE_NUMBER);

        for (i = i - 1; !available[i] && i < 255; i--);
        if (i == 255) {
          for (i = 25; !available[i]; i--);
          x = 3 + ((left - 1) % 5) * 5;
          y = 4 + ((left - 1) / 5) * 4;
        }
        else {
          x -= 5;
          if (x > 23) {
            x = 23;
            y -= 4;
          }
        }

        printColoredByte2(x + 2, y + 1, i, BLUE_NUMBER);
      }
      else if (pressed[0] & BTN_A) {
        controllerEnd();
        break;
      }
      else if (pressed[0] & BTN_SELECT) {
        controllerEnd();
        return;
      }

      WaitVsync(1);
      controllerEnd();
    }

    /* Open the chest */
    left--;
    available[i] = 0;

    ClearVram();
    Print(8, 5, strSee);
    Print(5, 6, strInside);
    DrawMap2(13, 12, closedChestMap);

    WaitVsync(60);

    DrawMap2(13, 12, openChestMap);
    printMoney(19, 10, pgm_read_dword(prizes + order[i]), WHITE_NUMBER);

    /* Wait for the input */
    while (1) {
      controllerStart();

      if (pressed[0] & BTN_A) {
        controllerEnd();
        break;
      }
      else if (pressed[0] & BTN_SELECT) {
        controllerEnd();
        return;
      }

      WaitVsync(1);
      controllerEnd();
    }

    /* Offer */
    if (left != 20 && left != 15 && left != 10 && left != 6 && left != 4
      && left != 2 && left != 1) {

      continue;
    }

    /* Switch chests */
    if (left == 1) {
      ClearVram();

      for (i = 0; !available[i]; i++);

      Print(6, 6, strWantKeep);
      Print(6, 7, strChestNo);
      printColoredByte2(13, 7, s, WHITE_NUMBER);
      Print(4, 8, strTradeChest);
      printColoredByte2(24, 8, i, WHITE_NUMBER);
      Print(12, 15, strKeep);
      Print(12, 16, strTrade);
      SetTile(10, 15, ARROW_TILE);

      n = 0;
      while (1) {
        controllerStart();

        if (pressed[0] & BTN_A) {
          if (n) {
            s ^= i;
            i ^= s;
            s ^= i;
          }

          r = pgm_read_dword(prizes + order[s]);

          /* Animate the opening */
          ClearVram();
          Print(8, 5, strSee);
          Print(5, 6, strInsideDef);
          printColoredByte2(23, 6, i, WHITE_NUMBER);
          DrawMap2(13, 12, closedChestMap);

          WaitVsync(60);

          DrawMap2(13, 12, openChestMap);
          printMoney(19, 10, pgm_read_dword(prizes + order[i]),
            WHITE_NUMBER);

          /* Wait for the input */
          while (1) {
            controllerStart();

            if (pressed[0] & BTN_A) {
              controllerEnd();
              break;
            }

            WaitVsync(1);
            controllerEnd();
          }
          break;
        }
        else if (pressed[0] & BTN_DOWN || pressed[0] & BTN_UP) {
          SetTile(10, 15 + n, 0);
          n ^= 1;
          SetTile(10, 15 + n, ARROW_TILE);
        }
        else if (pressed[0] & BTN_SELECT) {
          controllerEnd();
          return;
        }

        WaitVsync(1);
        controllerEnd();
      }

      goto rich_ending;
    }

    /* Calculate the average */
    r = 0;
    n = 0;
    for (i = 0; i < 26; i++) {
      if (available[i] || i == s) {
        r += pgm_read_dword(prizes + order[i]);
        n++;
      }
    }
    r /= (uint32_t) n;

    /* Banker animation */
    ClearVram();
    DrawMap2(13, 13, phoneMap);
    WaitVsync(60);
    Print(6, 4, strPhone);
    WaitVsync(60);
    Print(8, 5, strBanker);
    WaitVsync(60);
    Print(7, 7, strOffer);
    WaitVsync(60);
    printMoney(20, 8, r, WHITE_NUMBER);
    Print(8, 9, strFor);
    WaitVsync(60);
    Print(12, 18, strAccept);
    Print(12, 19, strRefuse);
    SetTile(10, 18, ARROW_TILE);

    /* Read the input */
    i = 0;
    while (1) {
      controllerStart();

      if (pressed[0] & BTN_A) {
        controllerEnd();

        if (!i) {
          goto rich_ending;
        }
        break;
      }
      else if (pressed[0] & BTN_UP || pressed[0] & BTN_DOWN) {
        SetTile(10, 18 + i, 0);
        i ^= 1;
        SetTile(10, 18 + i, ARROW_TILE);
      }
      else if (pressed[0] & BTN_SELECT) {
        controllerEnd();
        return;
      }

      WaitVsync(1);
      controllerEnd();
    }
  }

  rich_ending:
  ClearVram();
  Print(8, 6, strCongratulations);
  Print(10, 7, strReceived);
  printMoney(20, 9, r, WHITE_NUMBER);
  DrawMap2(13, 11, openChestMap);

  while (1) {
    controllerStart();

    if (pressed[0] & BTN_START) {
      controllerEnd();
      break;
    }

    WaitVsync(1);
    controllerEnd();
  }
}

uint8_t testSlide(uint8_t *m) {
  int i;
  for (i = 0; i < 16; i++) if (m[i] != i) return 0;
  return 1;
}

void switchSlide(uint8_t p, uint8_t o, uint8_t *m) {
  m[p] = m[o];
  m[o] = 0;
  DrawMap2((p & 3) * 6 + 3, (p >> 2) * 5 + 4, boxMap);
  printColoredByte2((p & 3) * 6 + 6,
    (p >> 2) * 5 + 6, m[p],
    m[p] == p? GREEN_NUMBER : WHITE_NUMBER);

  Fill((o & 3) * 6 + 3, (o >> 2) * 5 + 4, 6, 5, 0);
}

void slide() {
  uint8_t m[16];
  uint8_t i, p;

  for (i = 0; i < 16; i++) {
    m[i] = i;
  }

  /* Randomize the board */
  for (i = 0; i < 15; i++) {
    p = (random() % (16 - i)) + i;
    if (p != i) {
      m[p] ^= m[i];
      m[i] ^= m[p];
      m[p] ^= m[i];
    }
  }
  if (testSlide(m)) {
    m[0] = 1;
    m[1] = 0;
  }
  for (p = 0; m[p]; p++);

  /* Draw the initial state */
  ClearVram();
  for (i = 0; i < 16; i++) {
    if (!m[i]) continue;
    DrawMap2((i & 3) * 6 + 3, (i >> 2) * 5 + 4, boxMap);
    printColoredByte2((i & 3) * 6 + 6,
      (i >> 2) * 5 + 6, m[i],
      m[i] == i? GREEN_NUMBER : WHITE_NUMBER);
  }

  /* Process the input */
  while (1) {
    controllerStart();

    if (pressed[0] & BTN_UP && (p >> 2) < 3) {
      switchSlide(p, p + 4, m);
      p += 4;

      if (testSlide(m)) {
        controllerEnd();
        break;
      }
    }
    else if (pressed[0] & BTN_DOWN && p >> 2) {
      switchSlide(p, p - 4, m);
      p -= 4;

      if (testSlide(m)) {
        controllerEnd();
        break;
      }
    }
    else if (pressed[0] & BTN_LEFT && (p & 3) < 3) {
      switchSlide(p, p + 1, m);
      p += 1;

      if (testSlide(m)) {
        controllerEnd();
        break;
      }
    }
    else if (pressed[0] & BTN_RIGHT && p & 3) {
      switchSlide(p, p - 1, m);
      p -= 1;

      if (testSlide(m)) {
        controllerEnd();
        break;
      }
    }
    else if (pressed[0] & BTN_SELECT) {
      controllerEnd();
      return;
    }

    WaitVsync(1);
    controllerEnd();
  }

  /* Winning screen */
  ClearVram();
  Print(8, 12, strCongrat);
  while (1) {
    controllerStart();
    if (pressed[0] & BTN_START) break;
    WaitVsync(1);
    controllerEnd();
  }
  controllerEnd();
}

void theOneDrawMap(const uint8_t map[7][7]) {
  for (uint8_t i = 0; i < 7; i++)
    for (uint8_t j = 0; j < 7; j++) {
      if (map[i][j] == OUTSIDE)
        continue;
      DrawMap2(5+3*j, 7+i*2,
          (map[i][j] & 0xf) == HOLE?
          (map[i][j] & GOOD_CURSOR?
             goodPegHoleMap : (map[i][j] & BAD_CURSOR?
               badPegHoleMap : pegHoleMap))
          : (map[i][j] & GOOD_CURSOR?
             goodPegMap : (map[i][j] & BAD_CURSOR?
               badPegMap : pegMap)));
    }
}

bool theOneIsHoleGood(struct int8_t_pair peg, struct int8_t_pair hole,
    const uint8_t map[7][7]) {
  if ((peg.x != hole.x && peg.y != hole.y)
      || (abs(peg.x-hole.x) + abs(peg.y-hole.y) != 2))
    return false;

  if (peg.x > hole.x && (map[peg.y][peg.x-1] & 0xf) != PEG)
    return false;
  else if (peg.x < hole.x && (map[peg.y][peg.x+1] & 0xf) != PEG)
    return false;
  else if (peg.y > hole.y && (map[peg.y-1][peg.x] & 0xf) != PEG)
    return false;
  else if (peg.y < hole.y && (map[peg.y+1][peg.x] & 0xf) != PEG)
    return false;

  return true;
}

void theOne() {
  uint8_t map[7][7];
  uint8_t pegs = 32;
  struct int8_t_pair nc, peg, hole, c = (struct int8_t_pair) {3, 3};

  memset(map, PEG, sizeof(map));

  map[0][0] = map[0][1] = map[1][0] = map[1][1] = OUTSIDE;
  map[0][5] = map[0][6] = map[1][5] = map[1][6] = OUTSIDE;
  map[5][0] = map[5][1] = map[6][0] = map[6][1] = OUTSIDE;
  map[5][5] = map[5][6] = map[6][5] = map[6][6] = OUTSIDE;
  map[3][3] = HOLE;
  map[c.y][c.x] |= BAD_CURSOR;

  ClearVram();

  while (pegs > 1) {
    /* Picking the peg */
    peg.x = -1;
    nc = c;
    while (peg.x == -1) {
      controllerStart();

      theOneDrawMap(map);

      if (pressed[0] & BTN_SELECT)
        return;
      else if (pressed[0] & BTN_UP)
        nc.y--;
      else if (pressed[0] & BTN_RIGHT)
        nc.x++;
      else if (pressed[0] & BTN_DOWN)
        nc.y++;
      else if (pressed[0] & BTN_LEFT)
        nc.x--;

      if ((nc.x != c.x || nc.y != c.y)) {
        if (nc.x >= 0 && nc.x < 7 && nc.y >= 0 && nc.y < 7
            && map[nc.y][nc.x] != OUTSIDE) {
          map[c.y][c.x] &= 0xf;
          map[nc.y][nc.x] |= (map[nc.y][nc.x] == HOLE?
              BAD_CURSOR : GOOD_CURSOR);
          c = nc;
        }
        else {
          nc = c;
        }
      }
      else if (pressed[0] & BTN_A && (map[c.y][c.x] & GOOD_CURSOR)) {
        peg = c;
      }

      WaitVsync(1);
      controllerEnd();
    }

    /* Picking the hole */
    c.x = 3;
    c.y = peg.x == 3 && peg.y == 3? 2 : 3;
    map[c.y][c.x] |= (map[c.y][c.x] == HOLE && theOneIsHoleGood(peg, c, map)?
        GOOD_CURSOR : BAD_CURSOR);
    hole.x = -1;
    nc = c;
    while (hole.x == -1) {
      controllerStart();

      theOneDrawMap(map);

      if (pressed[0] & BTN_SELECT)
        return;
      else if (pressed[0] & BTN_UP)
        nc.y--;
      else if (pressed[0] & BTN_RIGHT)
        nc.x++;
      else if (pressed[0] & BTN_DOWN)
        nc.y++;
      else if (pressed[0] & BTN_LEFT)
        nc.x--;
      else if (pressed[0] & BTN_B)
        break;

      if ((nc.x != c.x || nc.y != c.y)) {
        if (nc.x >= 0 && nc.x < 7 && nc.y >= 0 && nc.y < 7
            && (nc.x != peg.x || nc.y != peg.y)
            && map[nc.y][nc.x] != OUTSIDE) {
          map[c.y][c.x] &= 0xf;
          map[nc.y][nc.x] |= (map[nc.y][nc.x] == HOLE
              && theOneIsHoleGood(peg, nc, map)?
              GOOD_CURSOR : BAD_CURSOR);
          c = nc;
        }
        else {
          nc = c;
        }
      }
      else if (pressed[0] & BTN_A && (map[c.y][c.x] & GOOD_CURSOR)) {
        hole = c;
      }

      WaitVsync(1);
      controllerEnd();
    }

    if (hole.x != -1) {
      map[peg.y][peg.x] = HOLE;
      map[hole.y][hole.x] = PEG | GOOD_CURSOR;
      c = hole;
      pegs--;

      if (peg.x > hole.x)
        map[peg.y][peg.x-1] = HOLE;
      else if (peg.x < hole.x)
        map[peg.y][peg.x+1] = HOLE;
      else if (peg.y < hole.y)
        map[peg.y+1][peg.x] = HOLE;
      else if (peg.y > hole.y)
        map[peg.y-1][peg.x] = HOLE;
    }
    else {
      map[c.y][c.x] &= 0xf;
      c = peg;
    }
  }

  theOneDrawMap(map);
  Print(8, 12, strCongrat);
  for (bool done = false; !done; ) {
    controllerStart();

    if (pressed[0] & BTN_START)
      done = true;

    WaitVsync(1);
    controllerEnd();
  }
}

/* No memory for recursion */
uint8_t getParent(uint8_t v, uint8_t *parent) {
  uint8_t i, o;

  for (i = v; parent[i] != i; i = parent[i]);
  for (; parent[v] != v; v = o) {
    o = parent[v];
    parent[v] = i;
  }

  return i;
}

uint8_t checkConnectivity(uint8_t map[][CAVE_WIDTH], uint8_t *parent) {
  uint8_t i, y, x, yy, xx, d;
  uint8_t yxType, yyxxType;
  uint8_t visited = 0;
  uint8_t unions = 1;
  /* 255 == -1 because of the overflow */
  const uint8_t dx[] = {0, 1, 0, 255};
  const uint8_t dy[] = {255, 0, 1, 0};
  const uint8_t cor[2][4] =
    {
      {1, 0, 3, 2},
      {3, 2, 1, 0}
    };

  /* Parent array for the union find structure */
  for (y = 0; y < CAVE_HEIGHT; y++) {
    for (x = 0; x < CAVE_WIDTH; x++) {
      parent[(y<<4)|x] = (y<<4)|x;
    }
  }

  /* Union all the edges */
  for (y = 0; y < CAVE_HEIGHT; y++) {
    for (x = 0; x < CAVE_WIDTH; x++) {
      /* Using 0x80 to signal it being visited */
      yxType = map[y][x] & (~0x80);
      if (yxType == HOLE_ROOM || yxType >= CORRIDOR)
        continue;
      map[y][x] |= 0x80;
      for (i = 0; i < 4; i++) {
        d = i;
        xx = x;
        yy = y;
        do {
          yy = yy + CAVE_HEIGHT + dy[d];
          yy %= CAVE_HEIGHT;
          xx = xx + CAVE_WIDTH + dx[d];
          xx %= CAVE_WIDTH;
          yyxxType = map[yy][xx] & (~0x80);
          map[yy][xx] |= 0x80;
          if (yyxxType >= CORRIDOR)
            d = cor[yyxxType-CORRIDOR][d];
        } while(yyxxType >= CORRIDOR);

        /* Don't union holes */
        if (yyxxType != HOLE_ROOM
            && getParent((y<<4)|x, parent) != getParent((yy<<4)|xx, parent)) {
          parent[parent[(y<<4)|x]] = parent[(yy<<4)|xx];
          unions++;
        }
      }
    }
  }

  for (y = 0; y < CAVE_HEIGHT; y++) {
    for (x = 0; x < CAVE_WIDTH; x++) {
      if (map[y][x] & 0x80)
        visited++;
      map[y][x] &= ~0x80;
      if (map[y][x] != HOLE_ROOM && map[y][x] < CORRIDOR)
        unions--;
    }
  }

  return (visited == CAVE_HEIGHT*CAVE_WIDTH && !unions);
}

void flagAround(uint8_t y, uint8_t x, uint8_t f, uint8_t dist,
  uint8_t map[CAVE_HEIGHT][CAVE_WIDTH]) {
  /* 255 == -1 because of the overflow */
  const uint8_t dx[] = {0, 1, 0, 255};
  const uint8_t dy[] = {255, 0, 1, 0};
  const uint8_t cor[2][4] =
    {
      {1, 0, 3, 2},
      {3, 2, 1, 0}
    };
  uint8_t yy, xx, i, d;

  for (i = 0; i < 4; i++) {
    yy = y + CAVE_HEIGHT + dy[i];
    yy %= CAVE_HEIGHT;
    xx = x + CAVE_WIDTH + dx[i];
    xx %= CAVE_WIDTH;
    d = i;
    while (map[yy][xx] >= CORRIDOR) {
      d = cor[map[yy][xx] - CORRIDOR][d];
      yy = yy + CAVE_HEIGHT + dy[d];
      yy %= CAVE_HEIGHT;
      xx = xx + CAVE_WIDTH + dx[d];
      xx %= CAVE_WIDTH;
    }

    if (map[yy][xx] < BOTH_ROOM) {
      map[yy][xx] |= f;
      if (dist > 1)
        flagAround(yy, xx, f, dist - 1, map);
    }
  }
}

void monster() {
  uint8_t parent[CAVE_HEIGHT * 16];
  uint8_t map[CAVE_HEIGHT][CAVE_WIDTH];
  uint8_t i, n, t, l, x, y, d, wx, wy, yy, xx;
  const uint8_t dx[] = {0, 1, 0, 255};
  const uint8_t dy[] = {255, 0, 1, 0};
  const uint8_t cor[2][4] =
    {
      {1, 0, 3, 2},
      {3, 2, 1, 0}
    };

  /* Print loading screen */
  ClearVram();
  Print(7, 9, strGenerating);
  Print(9, 14, strWait);

  /* Generate a map */
  DisableSoundEngine();
  generate_cave:
  memset(map, 0, sizeof(map));
  /* Corridors */
  n = (random() % 31) + 60;
  l = CAVE_WIDTH * CAVE_HEIGHT;
  for (i = 0; i < n; i++) {
    /* Remove the t-th clean room */
    t = random() % l;
    for (y = 0; y < CAVE_HEIGHT; y++) {
      for (x = 0; x < CAVE_WIDTH; x++) {
        if (!map[y][x] && !(t--)) goto tth_found;
      }
    }
    tth_found:
    l--;
    map[y][x] = CORRIDOR + (random() & 1);
  }

  /* Holes */
  n = (random() % 8) + 1;
  for (i = 0; i < n; i++) {
    /* Make the t-th clean room a hole */
    t = random() % l;
    for (y = 0; y < CAVE_HEIGHT; y++) {
      for (x = 0; x < CAVE_WIDTH; x++) {
        if (map[y][x] <= BOTH_ROOM && !(t--)) goto tth_found_hole;
      }
    }
    tth_found_hole:
    l--;
    map[y][x] = HOLE_ROOM;
    /* Put the breeze on the adjacent rooms */
    flagAround(y, x, BREEZE_ROOM, 1, map);
  }

  /* Wumpus */
  t = random() % l;
  for (y = 0; y < CAVE_HEIGHT; y++) {
    for (x = 0; x < CAVE_WIDTH; x++) {
      if (map[y][x] <= BOTH_ROOM && !(t--)) goto tth_found_wumpus;
    }
  }
  tth_found_wumpus:
  map[y][x] = WUMPUS_ROOM;
  wy = y;
  wx = x;
  /* Put the stench on the adjacent rooms */
  flagAround(y, x, STENCH_ROOM, 2, map);

  /* Guy */
  i = 0;
  for (y = 0; y < CAVE_HEIGHT; y++) {
    for (x = 0; x < CAVE_WIDTH; x++) {
      if (!map[y][x]) i++;
    }
  }
  t = random() % i;
  for (y = 0; y < CAVE_HEIGHT; y++) {
    for (x = 0; x < CAVE_WIDTH; x++) {
      if (!map[y][x] && !(t--)) goto tth_found_guy;
    }
  }
  /* This shouldn't happen, but just in case there are no clean rooms */
  goto generate_cave;
  tth_found_guy:

  /* Only accept connected graphs */
  if (!checkConnectivity(map, parent)) goto generate_cave;

  EnableSoundEngine();
  /* If the highest bit is set, the room is visible */
  map[y][x] |= 0x80;

  /* Process input */
  l = 0;
  ClearVram();
  while (1) {
    /* Redraw */
    for (i = 0; i < CAVE_HEIGHT; i++) {
      for (n = 0; n < CAVE_WIDTH; n++) {
        if (map[i][n] & 0x80) {
          DrawMap2(3 + (n << 1),
            4 + (i << 1),
            (const char*) pgm_read_word(monsterRooms
              + (i == y && x == n? 8 : 0) + (map[i][n] & 0x7f)));
        }
      }
    }

    /* Draw the targets if shooting */
    for (i = 0; l && i < 4; i++) {
      yy = y + CAVE_HEIGHT + dy[i];
      yy %= CAVE_HEIGHT;
      xx = x + CAVE_WIDTH + dx[i];
      xx %= CAVE_WIDTH;

      DrawMap2(3 + (xx << 1),
        4 + (yy << 1),
        targetMap);
    }
    /* End game */
    if ((map[y][x] & 0x7f) >= WUMPUS_ROOM) break;

    controllerStart();
    d = 0xff;

    if (pressed[0] & BTN_UP) {
      d = 0;
    }
    else if (pressed[0] & BTN_RIGHT) {
      d = 1;
    }
    else if (pressed[0] & BTN_DOWN) {
      d = 2;
    }
    else if (pressed[0] & BTN_LEFT) {
      d = 3;
    }
    else if (pressed[0] & BTN_A) {
      l ^= 1;
      ClearVram();
    }
    else if (pressed[0] & BTN_SELECT) {
      controllerEnd();
      return;
    }

    /* Moving */
    if (d != 0xff) {
      yy = y;
      xx = x;

      y = y + CAVE_HEIGHT + dy[d];
      y %= CAVE_HEIGHT;
      x = x + CAVE_WIDTH + dx[d];
      x %= CAVE_WIDTH;
      while ((map[y][x] & 0x7f) >= CORRIDOR) {
        map[y][x] |= 0x80;
        d = cor[(map[y][x] & 0x7f) - CORRIDOR][d];
        y = y + CAVE_HEIGHT + dy[d];
        y %= CAVE_HEIGHT;
        x = x + CAVE_WIDTH + dx[d];
        x %= CAVE_WIDTH;
      }
      map[y][x] |= 0x80;
      /* Shooting */
      if (l) {
        if ((map[y][x] & 0x7f) != WUMPUS_ROOM) {
          y = wy;
          x = wx;
        }
        else {
          x = xx;
          y = yy;
        }
        controllerEnd();
        break;
      }
    }

    controllerEnd();
    WaitVsync(1);
  }

  /* Print the result */
  switch(map[y][x] & 0x7f) {
    case WUMPUS_ROOM:
      Print(6, 14, strAte);
      break;

    case HOLE_ROOM:
      Print(6, 14, strFell);
      break;

    default:
      Print(8, 6, strCongratulations);
      Print(4, 14, strKill);
  }
  while (1) {
    controllerStart();
    if (pressed[0] & BTN_START) break;
    WaitVsync(1);
    controllerEnd();
  }
  controllerEnd();

  /* Draw the whole cave */
  for (i = 0; i < CAVE_HEIGHT; i++) {
    for (n = 0; n < CAVE_WIDTH; n++) {
      DrawMap2(3 + (n << 1),
        4 + (i << 1),
        (const char*) pgm_read_word(monsterRooms
          + (i == y && x == n? 8 : 0) + (map[i][n] & 0x7f)));
    }
  }

  while (1) {
    controllerStart();
    if (pressed[0] & BTN_START) break;
    WaitVsync(1);
    controllerEnd();
  }
  controllerEnd();
}

uint8_t testArray(uint8_t *m) {
  int i;
  for (i = 1; i < 16; i++) {
    if (m[i] < m[i - 1]) return 0;
  }
  return 1;
}

int8_t gridCheck(const int8_t l[3][3]) {
  for (uint8_t i = 0; i < 3; i++) {
    if (l[i][0] && l[i][0] == l[i][1] && l[i][0] == l[i][2])
      return l[i][0];
    if (l[0][i] && l[0][i] == l[1][i] && l[0][i] == l[2][i])
      return l[0][i];
  }

  if (l[0][0] && l[0][0] == l[1][1] && l[0][0] == l[2][2])
    return l[0][0];
  if (l[0][2] && l[0][2] == l[1][1] && l[0][2] == l[2][0])
    return l[0][2];

  for (uint8_t i = 0; i < 3; i++)
    for (uint8_t j = 0; j < 3; j++)
      if (!l[i][j])
        return 0x3f;

  return 0;
}

struct int8_t_pair gridGetMove(int8_t p, int8_t l[3][3]) {
  int8_t best = -p;
  int8_t move = -1;
  struct int8_t_pair a;
  int8_t c = gridCheck(l);

  if (c != 0x3f)
    return (struct int8_t_pair) {c, -1};

  for (uint8_t i = 0; i < 3; i++)
    for (uint8_t j = 0; j < 3; j++) {
      if (l[i][j]) continue;
      l[i][j] = p;
      a = gridGetMove(-p, l);
      l[i][j] = 0;
      if (move == -1 || (p > 0 && a.x > best) || (p < 0 && a.x < best)) {
        move = i*3+j;
        best = a.x;
      }
    }

  return (struct int8_t_pair) {best, move};
}

void gridDrawCursor(int8_t x, int8_t y, uint8_t tile) {
  Fill(5+7*x, 6+6*y, 6, 1, tile);
  Fill(5+7*x, 7+6*y, 1, 3, tile);
  Fill(10+7*x, 7+6*y, 1, 3, tile);
  Fill(5+7*x, 10+6*y, 6, 1, tile);
}

void grid(uint8_t players) {
  int8_t level[3][3];
  int8_t x, y, c, winner;
  int8_t turn = 0;

  memset(level, 0, sizeof(level));

  ClearVram();
  Fill(5, 11, 20, 1, PAINTED_TILE);
  Fill(5, 17, 20, 1, PAINTED_TILE);
  Fill(11, 6, 1, 17, PAINTED_TILE);
  Fill(18, 6, 1, 17, PAINTED_TILE);

  for (int8_t p = random()&1; (winner = gridCheck(level)) == 0x3f; p ^= 1) {
    DrawMap2(2, 2, p? openChestMap : phoneMap);
    Print(8, 3, strTurn);
    SetTile(15, 3, WHITE_NUMBER + p+1);

    if (p && players == 1) {
      DisableSoundEngine();
      struct int8_t_pair m = !turn?
        (struct int8_t_pair) {0, random() % 9} :gridGetMove(!p? 1 : -1, level);
      x = m.y%3;
      y = m.y/3;
      EnableSoundEngine();
      if (turn)
        WaitVsync(30);
    }
    else {
      x = y = 0;
      c = players == 1? 0 : p;
      gridDrawCursor(x, y, SKY_TILE);
      for (bool played = false; !played; ) {
        controllerStart();

        if (pressed[0] & BTN_SELECT)
          return;
        else if (pressed[c] & BTN_UP && y) {
          gridDrawCursor(x, y, 0);
          gridDrawCursor(x, --y, SKY_TILE);
        }
        else if (pressed[c] & BTN_RIGHT && x < 2) {
          gridDrawCursor(x, y, 0);
          gridDrawCursor(++x, y, SKY_TILE);
        }
        else if (pressed[c] & BTN_LEFT && x) {
          gridDrawCursor(x, y, 0);
          gridDrawCursor(--x, y, SKY_TILE);
        }
        else if (pressed[c] & BTN_DOWN && y < 2) {
          gridDrawCursor(x, y, 0);
          gridDrawCursor(x, ++y, SKY_TILE);
        }
        else if (pressed[c] & BTN_A && !level[y][x]) {
          gridDrawCursor(x, y, 0);
          played = true;
        }

        WaitVsync(1);
        controllerEnd();
      }
    }

    level[y][x] = !p? 1 : -1;
    DrawMap2(6+7*x, 7+6*y, p? openChestMap : phoneMap);
    turn++;
  }

  Fill(0, 0, 30, 5, 0);
  if (winner) {
    Print(7, 3, strWins);
    Fill(7, 3, 8, 1, 0);
    DrawMap2(10, 2, winner == -1? openChestMap : phoneMap);
  }
  else {
    Print(13, 3, strDraw);
  }

  for (bool done = false; !done; ) {
    controllerStart();

    if (pressed[0] & BTN_START)
      done = true;

    WaitVsync(1);
    controllerEnd();
  }
}

bool survivalMoveDown(uint8_t p, int8_t height[2][10], int8_t next[2][10]) {
  const uint8_t yOffset = 8;
  const uint8_t xOffset = p? 17 : 3;
  uint8_t *vRow = vram + ((yOffset+16)*VRAM_TILES_H) + xOffset;
  uint8_t *vTopRow = vRow - VRAM_TILES_H;
  bool cleaning = true;

  for (uint8_t i = 0; i < 10; i++) {
    if (!height[p][i])
      cleaning = false;
  }
  if (!cleaning)
    for (uint8_t i = 0; i < 10; i++) {
      next[p][i] = 127;
    }

  for (uint8_t y = 0; y < 16; y++) {
    vRow = vTopRow;
    vTopRow -= VRAM_TILES_H;
    for (uint8_t x = 0; x < 10; x++)
      if (cleaning)
        vRow[x] = vTopRow[x];
      else if (y > height[p][x]) {
        vRow[x] = vTopRow[x] == RAM_TILES_COUNT+ABOUT_TILE?
          RAM_TILES_COUNT+SKY_TILE : vTopRow[x];
        if (vRow[x] == RAM_TILES_COUNT+BLOCK_TILE && next[p][x] == 127)
          next[p][x] = y;
      }
      else if (y == height[p][x] && vTopRow[x] != RAM_TILES_COUNT+SKY_TILE) {
        vRow[x] = vTopRow[x];
        if (vRow[x] == RAM_TILES_COUNT+BLOCK_TILE) {
          height[p][x]++;
          vTopRow[x] = RAM_TILES_COUNT+SKY_TILE;
        }
      }
  }

  if (cleaning)
    for (uint8_t i = 0; i < 10; i++) {
      height[p][i]--;
      next[p][i]--;
    }

  Fill(xOffset, yOffset, 10, 1, SKY_TILE);

  return cleaning;
}

void survival(uint8_t players) {
  uint16_t score[2] = {0, 0};
  bool alive[2] = {true, players > 1};
  uint8_t cat[2] = {4, 4};
  uint8_t lastY[2] = {23, 23};
  int8_t height[2][10];
  int8_t next[2][10];
  int8_t about = -1;
  uint8_t movementDelay = MOVE_DELAY;
  uint8_t shotDelay = SHOT_DELAY;
  uint8_t nextMovement = movementDelay;
  uint8_t nextShot = 2*shotDelay;
  uint8_t fasterDelay = FASTER_DELAY;
  uint8_t nextFaster = fasterDelay;
  uint8_t nextBlink = BLINK_DELAY;
  uint8_t blinkState = 0;

  memset(height, 0, sizeof(height));

  ClearVram();
  for (uint8_t i = 0; i < 2; i++) {
    Fill(3+14*i, 8, 10, 16, SKY_TILE);
    Fill(2+14*i, 7, 12, 1, BLOCK_TILE);
    Fill(2+14*i, 24, 12, 1, BLOCK_TILE);
    Fill(2+14*i, 8, 1, 16, BLOCK_TILE);
    Fill(13+14*i, 8, 1, 16, BLOCK_TILE);
    Print(2+14*i, 6, strScore);
  }

  while (alive[0] || alive[1]) {
    controllerStart();

    if (pressed[0] & BTN_SELECT)
      return;

    if (about != -1 && !(--nextBlink)) {
      nextBlink = BLINK_DELAY;
      blinkState ^= 1;
      if (alive[0])
        SetTile(3+about, 8, blinkState? ABOUT_TILE : SKY_TILE);
      if (alive[1])
        SetTile(3+14+about, 8, blinkState? ABOUT_TILE : SKY_TILE);
    }

    if (!(--nextMovement)) {
      if (!(--nextShot) && about != -1) {
        uint8_t type = random() & 0x7;
        if (type < 4)
          type = BLOCK_TILE;
        else if (type == 7)
          type = GREEN_BALL_TILE;
        else
          type = RED_BALL_TILE;
        if (alive[0])
          SetTile(3+about, 8, type);
        if (alive[1])
          SetTile(3+14+about, 8, type);
      }

      for (uint8_t i = 0; i < 2; i++) {
        if (!alive[i])
          continue;

        if (survivalMoveDown(i, height, next))
          lastY[i]--;
      }

      if (!nextShot) {
        about = random() % 10;
        blinkState = 1;
        for (uint8_t i = 0; i < 2; i++)
          if (alive[i] && height[i][about] <= 10)
              SetTile(3+14*i+about, 8, ABOUT_TILE);

        if (!(--nextFaster)) {
          nextFaster = fasterDelay;
          if (movementDelay > 4)
            movementDelay--;
          else if (shotDelay > 2)
            shotDelay--;
        }

        nextShot = shotDelay;
      }

      nextMovement = movementDelay;
    }

    for (uint8_t p = 0; p < 2; p++) {
      if (!alive[p])
        continue;

      uint8_t x = 3+14*p+cat[p];
      uint8_t y = lastY[p];
      uint8_t tile = vram[y*VRAM_TILES_H+x];

      if (tile == RAM_TILES_COUNT+CAT_TILE)
        SetTile(x, y, SKY_TILE);
      else if (tile == RAM_TILES_COUNT+BLOCK_TILE) {
        alive[p] = false;
        SetTile(x, y+1, BLOODY_BLOCK_TILE);
        continue;
      }

      if (pressed[p] & BTN_LEFT && cat[p]
          && next[p][cat[p]] > height[p][cat[p]-1])
        cat[p]--;
      else if (pressed[p] & BTN_RIGHT && cat[p] < 9
          && next[p][cat[p]] > height[p][cat[p]+1])
        cat[p]++;

      x = 3+14*p+cat[p];
      y = 23-height[p][cat[p]];
      tile = vram[y*VRAM_TILES_H+x];
      if (tile == RAM_TILES_COUNT+RED_BALL_TILE)
        score[p]++;
      else if (tile == RAM_TILES_COUNT+GREEN_BALL_TILE)
        score[p] += 3;
      SetTile(x, y, CAT_TILE);

      printColoredShort(13+14*p, 6, score[p], GREEN_NUMBER);

      lastY[p] = y;
    }

    WaitVsync(1);
    controllerEnd();
  }

  Print(11, 12, strGameOver);
  if (players > 1) {
    if (score[0] == score[1])
      Print(13, 14, strDraw);
    else {
      Print(8, 14, strWins);
      SetTile(15, 14, WHITE_NUMBER + (score[0] > score[1]? 1 : 2));
    }
  }
  for (bool done = false; !done; ) {
    controllerStart();

    if (pressed[0] & BTN_START)
      done = true;

    WaitVsync(1);
    controllerEnd();
  }
}

uint8_t rainMoveDown(uint8_t player) {
  const uint8_t yOffset = 8;
  const uint8_t xOffset = player? 18 : 3;
  uint8_t *vRow = vram + ((yOffset+15)*VRAM_TILES_H) + xOffset;
  uint8_t *vTopRow = vRow - VRAM_TILES_H;
  uint8_t hits = 0;

  for (uint8_t x = 0; x < 10; x++) {
    if (vTopRow[x] == RAM_TILES_COUNT+SKY_TILE
        || vTopRow[x] == RAM_TILES_COUNT+HIT_TILE) {
      vRow[x] = RAM_TILES_COUNT + SKY_TILE;
      vRow[x+VRAM_TILES_H] = RAM_TILES_COUNT;
    }
    else {
      hits++;
      vRow[x] = RAM_TILES_COUNT + HIT_TILE;
      vRow[x+VRAM_TILES_H] = RAM_TILES_COUNT + CRACK_TILE;
    }
  }

  Fill(xOffset, yOffset-1, 10, 1, NON_FIRE_TILE);

  for (uint8_t y = yOffset+14; y > yOffset; y--) {
    vRow = vTopRow;
    vTopRow -= VRAM_TILES_H;
    for (uint8_t x = 0; x < 10; x++)
      vRow[x] = vTopRow[x] == RAM_TILES_COUNT + HIT_TILE?
        RAM_TILES_COUNT + SKY_TILE : vTopRow[x];
  }
  Fill(xOffset, yOffset, 10, 1, SKY_TILE);

  return hits;
}

void rainShoot(uint8_t player, uint8_t key) {
  const char charMap[] = "<UD>ABXYLR";
  const uint8_t yOffset = 8;
  const uint8_t xOffset = player? 18 : 3;

  SetTile(xOffset+key, yOffset-1, FIRE_TILE);
  SetTile(xOffset+key, yOffset, charMap[key]-' ');
}

void rainRemove(uint8_t player, uint8_t key) {
  const uint8_t yOffset = 8;
  const uint8_t xOffset = player? 18 : 3;
  uint8_t *vCell = vram + ((yOffset+14)*VRAM_TILES_H) + xOffset + key;

  for (uint8_t y = yOffset+14; y >= yOffset; y--, vCell -= VRAM_TILES_H) {
    if (*vCell != RAM_TILES_COUNT + SKY_TILE) {
      *vCell = RAM_TILES_COUNT + HIT_TILE;
      break;
    }
  }
}

void rain(uint8_t players) {
  int8_t l[2] = {8, 8};
  uint8_t i, j;
  uint16_t score = 0;
  uint8_t movementDelay = MOVE_DELAY;
  uint8_t shotDelay = SHOT_DELAY;
  uint8_t nextMovement = movementDelay;
  uint8_t nextShot = 2*shotDelay;
  uint8_t fasterDelay = FASTER_DELAY;
  uint8_t nextFaster = fasterDelay;
  uint8_t falling[2][10];
  uint16_t buttonMap[10] = {BTN_LEFT, BTN_UP, BTN_DOWN, BTN_RIGHT, BTN_A,
    BTN_B, BTN_X, BTN_Y, BTN_SL, BTN_SR};

  memset(falling, 0, sizeof(falling));

  /* Draw the basic screen */
  ClearVram();
  Fill(0, 5, 30, 19, SKY_TILE);
  Fill(14, 0, 2, 28, PAINTED_TILE);
  for (i = 0; i < players; i++) {
    for (j = 0; j < 10; j++) {
      DrawMap2(3 + j + (15 * i), 6, canonMap);
    }
    Print(3 + 15 * i, 4, strLives);
  }
  if (players == 1) {
    Print(18, 4, strScore);
  }

  while (l[0] && l[1]) {
    controllerStart();

    if (!(--nextMovement)) {
      for (i = 0; i < players; i++)
        l[i] -= rainMoveDown(i);

      if (!(--nextShot)) {
        uint8_t nextKey = random() % 10;
        for (i = 0; i < players; i++) {
          rainShoot(i, nextKey);
          falling[i][nextKey]++;
        }

        if (!(--nextFaster)) {
          nextFaster = fasterDelay;
          if (movementDelay > 4)
            movementDelay--;
          else if (shotDelay > 2)
            shotDelay--;
        }

        nextShot = shotDelay;
      }

      nextMovement = movementDelay;
    }

    for (i = 0; i < players; i++)
      printColoredByte2(11 + (15 * i) , 4, l[i], GREEN_NUMBER);

    /* Destroy falling buttons */
    for (i = 0; i < players; i++) {
      for (j = 0; j < 10; j++) {
        if (pressed[i] & buttonMap[j]) {
          if (falling[i][j]) {
            rainRemove(i, j);
            if (players == 1)
              score++;
          }
        }
      }
    }

    if (players == 1) {
      printColoredShort(27 , 4, score, GREEN_NUMBER);
    }

    if (pressed[0] & BTN_SELECT) {
      controllerEnd();
      return;
    }

    WaitVsync(1);
    controllerEnd();
  }

  ClearVram();
  /* One player, game over */
  if (players == 1) {
    Print(10, 10, strGameOver);
    Print(10, 12, strScore);
    printColoredByte2(18, 12, score, GREEN_NUMBER);
  }
  /* Announce the winner. */
  else {
    if (l[0] == l[1]) {
      Print(12, 12, strDraw);
    }
    else {
      Print(8, 14, strWins);
      SetTile(15, 14, WHITE_NUMBER + 1 + (l[1] > l[0]));
    }
  }

  while (1) {
    controllerStart();
    if (pressed[0] & BTN_START) break;
    WaitVsync(1);
    controllerEnd();
  }
  controllerEnd();
}

void sort(uint8_t human) {
  uint8_t m[2][16], i, n, p[2], s[2], d;

  /* Generate a random order */
  for (i = 0; i < 16; i++) m[0][i] = i;
  while (testArray(m[0])) {
    for (i = 0; i < 16; i++) {
      n = (random() % (16 - i)) + i;
      if (n != i) {
        m[0][n] ^= m[0][i];
        m[0][i] ^= m[0][n];
        m[0][n] ^= m[0][i];
      }
    }
  }
  for (i = 0; i < 16; i++) m[1][i] = m[0][i];
  p[0] = p[1] = 0;
  s[0] = s[1] = 0xff;

  /* Print the initial arrays */
  ClearVram();
  Print(10, 6, strPlayer1);
  Print(10, 14, strPlayer2);
  for (i = 0; i < 8; i++) {
    printColoredByte2(3 * i + 4,
      8, m[0][i],
      (i? WHITE_NUMBER : BLUE_NUMBER));
    printColoredByte2(3 * i + 4,
      10, m[0][i + 8],
      WHITE_NUMBER);

    printColoredByte2(3 * i + 4,
      16, m[1][i],
      (i? WHITE_NUMBER : BLUE_NUMBER));
    printColoredByte2(3 * i + 4,
      18, m[1][i + 8],
      WHITE_NUMBER);
  }

  /* Initialize the AI delay */
  d = CPU_DELAY;

  /* Process input */
  while (1) {
    controllerStart();

    for (i = 0; i < 2; i++) {
      n = p[i];
      if (!i || human) {
        if (pressed[i] & BTN_RIGHT) {
          sort_press_right:
          n = (p[i] + 1) & 0xf;
          if (n == s[i]) n = (n + 1) & 0xf;
        }
        else if (pressed[i] & BTN_LEFT) {
          sort_press_left:
          n = (p[i] + 15) & 0xf;
          if (n == s[i]) n = (n + 15) & 0xf;
        }
        else if (pressed[i] & BTN_A) {
          sort_select:
          if (s[i] == 0xff) {
            printColoredByte2(3 * (p[i] & 7) + 4,
              (p[i] < 8? 8 : 10) + (i? 8 : 0),
              m[i][p[i]], GREEN_NUMBER);
            s[i] = p[i];
            p[i] = n = (p[i] + 15) & 0xf;
          }
          else {
            m[i][s[i]] ^= m[i][p[i]];
            m[i][p[i]] ^= m[i][s[i]];
            m[i][s[i]] ^= m[i][p[i]];

            printColoredByte2(3 * (p[i] & 7) + 4,
              (p[i] < 8? 8 : 10) + (i? 8 : 0),
              m[i][p[i]], WHITE_NUMBER);
            printColoredByte2(3 * (s[i] & 7) + 4,
              (s[i] < 8? 8 : 10) + (i? 8 : 0),
              m[i][s[i]], WHITE_NUMBER);

            s[i] = 0xff;

            if (testArray(m[i])) {
              controllerEnd();
              goto endSort;
            }
          }
        }
        else if (pressed[i] & BTN_B && s[i] != 0xff) {
          printColoredByte2(3 * (s[i] & 7) + 4,
            (s[i] < 8? 8 : 10) + (i? 8 : 0),
            m[i][s[i]], WHITE_NUMBER);

          s[i] = 0xff;
        }
        else if (!i && pressed[i] & BTN_SELECT) {
          controllerEnd();
          return;
        }
      }
      /* AI */
      else if (d) {
        /* Delay the movements */
        d--;
      }
      else {
        d = CPU_DELAY;

        /* Select a number in the wrong position */
        if (s[i] == 0xff) {
          if (m[i][p[i]] == p[i])
            goto sort_press_right;
          else
            goto sort_select;
        }
        /* Put it in the right place */
        else {
          if (m[i][s[i]] != p[i])
            if ((p[i] > m[i][s[i]] && p[i] - m[i][s[i]] < 8) ||
              (p[i] < m[i][s[i]] && m[i][s[i]] - p[i] > 8)) {

              goto sort_press_left;
            }
            else {
              goto sort_press_right;
            }
          else
            goto sort_select;
        }
      }

      printColoredByte2(3 * (p[i] & 7) + 4,
        (p[i] < 8? 8 : 10) + (i? 8 : 0),
        m[i][p[i]], WHITE_NUMBER);
      printColoredByte2(3 * (n & 7) + 4,
        (n < 8? 8 : 10) + (i? 8 : 0),
        m[i][n], BLUE_NUMBER);
      p[i] = n;
    }

    WaitVsync(1);
    controllerEnd();
  }
  endSort:
  ClearVram();

  Print(8, 14, strWins);
  SetTile(15, 14, WHITE_NUMBER + 1 + testArray(m[1]));
  while (1) {
    controllerStart();
    if (pressed[0] & BTN_START) break;
    WaitVsync(1);
    controllerEnd();
  }
  controllerEnd();
}

void trollenLoadLevel(uint8_t n, struct trollenLevel *level) {
  uint8_t i, t, b, o, x, y;
  uint8_t l[13];
  for (i = 0; i < 13; i++)
    l[i] = pgm_read_byte(trollenLevels[n] + i);

  memset(level->map, 0, 6*6*sizeof(uint8_t));

  for (i = 0; i < 6; i++) {
    level->map[0][i] |= TOP_WALL;
    level->map[i][5] |= RIGHT_WALL;
    level->map[5][i] |= BOTTOM_WALL;
    level->map[i][0] |= LEFT_WALL;
  }

  for (i = 0; i < 30; i++) {
    b = i / 8;
    o = i % 8;
    x = i % 5;
    y = i / 5;
    if ((l[b] >> o) & 1) {
      level->map[y][x] |= RIGHT_WALL;
      level->map[y][x+1] |= LEFT_WALL;
    }
  }
  for (i = 0; i < 30; i++) {
    b = (i+30) / 8;
    o = (i+30) % 8;
    x = i % 6;
    y = i / 6;
    if ((l[b] >> o) & 1) {
      level->map[y][x] |= BOTTOM_WALL;
      level->map[y+1][x] |= TOP_WALL;
    }
  }

  t = ((l[8] & 0x3) << 4) | ((l[7] >> 4) & 0xf);
  level->trap[0].x = (t%6)*4;
  level->trap[0].y = (t/6)*4;

  t = (l[8] >> 2) & 0x3f;
  level->trap[1].x = (t%6)*4;
  level->trap[1].y = (t/6)*4;

  t = l[9] & 0x3f;
  level->trap[2].x = (t%6)*4;
  level->trap[2].y = (t/6)*4;

  t = ((l[10] & 0xf) << 2) | ((l[9] >> 6) &  0x3f);
  level->hero.x = (t%6)*4;
  level->hero.y = (t/6)*4;

  t = ((l[11] & 0x3) << 4) | ((l[10] >> 4) & 0xf);
  level->troll[0].pos.x = (t%6)*4;
  level->troll[0].pos.y = (t/6)*4;;

  t = (l[11] >> 2) & 0x3f;
  level->troll[1].pos.x = (t%6)*4;
  level->troll[1].pos.y = (t/6)*4;;

  t = l[12] & 0x1f;
  if (t < 6)
    level->map[0][t] &= ~TOP_WALL;
  else if (t < 12)
    level->map[5][t%6] &= ~BOTTOM_WALL;
  else if (t < 18)
    level->map[t%6][0] &= ~LEFT_WALL;
  else if (t < 24)
    level->map[t%6][5] &= ~RIGHT_WALL;

  if (level->troll[0].pos.x >= 6*4 || level->troll[0].pos.y >= 6*4)
    level->troll[0].type = NO_TROLL;
  else if ((l[12] >> 5) & 1)
    level->troll[0].type = V_TROLL;
  else
    level->troll[0].type = H_TROLL;

  if (level->troll[1].pos.x >= 6*4 || level->troll[1].pos.y >= 6*4)
    level->troll[1].type = NO_TROLL;
  else if ((l[12] >> 6) & 1)
    level->troll[1].type = V_TROLL;
  else
    level->troll[1].type = H_TROLL;

  level->troll[0].stun = 0;
  level->troll[1].stun = 0;
}

void trollenDrawLevel(const struct trollenLevel *level) {
  uint8_t i, j, x, y;

  for (y = 2, i = 0; i < 6; i++, y += 4) {
    for (x = 3, j = 0; j < 6; j++, x += 4) {
      SetTile(x, y,
          level->map[i][j] & TOP_WALL?
            (level->map[i][j] & LEFT_WALL? TL_TILE : T_TILE)
            : (level->map[i][j] & LEFT_WALL? L_TILE : NO_TILE));

      SetTile(x+1, y, level->map[i][j] & TOP_WALL? T_TILE : NO_TILE);
      SetTile(x+2, y, level->map[i][j] & TOP_WALL? T_TILE : NO_TILE);

      SetTile(x+3, y,
          level->map[i][j] & TOP_WALL?
            (level->map[i][j] & RIGHT_WALL? TR_TILE : T_TILE)
            : (level->map[i][j] & RIGHT_WALL? R_TILE : NO_TILE));

      SetTile(x, y+1, level->map[i][j] & LEFT_WALL? L_TILE : NO_TILE);
      SetTile(x+1, y+1, NO_TILE);
      SetTile(x+2, y+1, NO_TILE);
      SetTile(x+3, y+1, level->map[i][j] & RIGHT_WALL? R_TILE : NO_TILE);

      SetTile(x, y+2, level->map[i][j] & LEFT_WALL? L_TILE : NO_TILE);
      SetTile(x+1, y+2, NO_TILE);
      SetTile(x+2, y+2, NO_TILE);
      SetTile(x+3, y+2, level->map[i][j] & RIGHT_WALL? R_TILE : NO_TILE);

      SetTile(x, y+3,
          level->map[i][j] & BOTTOM_WALL?
            (level->map[i][j] & LEFT_WALL? BL_TILE : B_TILE)
            : (level->map[i][j] & LEFT_WALL? L_TILE : NO_TILE));

      SetTile(x+1, y+3, level->map[i][j] & BOTTOM_WALL? B_TILE : NO_TILE);
      SetTile(x+2, y+3, level->map[i][j] & BOTTOM_WALL? B_TILE : NO_TILE);

      SetTile(x+3, y+3,
          level->map[i][j] & BOTTOM_WALL?
            (level->map[i][j] & RIGHT_WALL? BR_TILE : B_TILE)
            : (level->map[i][j] & RIGHT_WALL? R_TILE : NO_TILE));
    }
  }

  for (i = 0; i < MAX_TRAPS; i++)
    if (level->trap[i].x < 6*4 && level->trap[i].y < 6*4)
      DrawMap2(level->trap[i].x+4, level->trap[i].y+3, symbolMap);

  DrawMap2(level->hero.x+4, level->hero.y+3, trollGuyMap);

  for (i = 0; i < 2; i++) {
    if (level->troll[i].type == V_TROLL)
      DrawMap2(level->troll[i].pos.x+4, level->troll[i].pos.y+3,
          level->troll[i].stun? stunnedVTrollMap : vTrollMap);
    else if (level->troll[i].type == H_TROLL)
      DrawMap2(level->troll[i].pos.x+4, level->troll[i].pos.y+3,
          level->troll[i].stun? stunnedHTrollMap : hTrollMap);
    else if (level->troll[i].type == S_TROLL)
      DrawMap2(level->troll[i].pos.x+4, level->troll[i].pos.y+3, sTrollMap);
  }
}

uint8_t trollen(uint8_t levelNum) {
  struct trollenLevel level;
  struct int8_t_pair heroNext;
  struct int8_t_pair trollNext[2];
  uint8_t heroTile, tTile;
  uint8_t outcome = 0;
  trollenLoadLevel(levelNum, &level);

  Fill(0, 0, 30, 28, NO_TILE);
  trollenDrawLevel(&level);

  while (!outcome) {
    /* Waiting for input */
    heroTile = level.map[level.hero.y/4][level.hero.x/4];
    heroNext = (struct int8_t_pair) {0x3f, 0x3f};
    while (heroNext.x == 0x3f) {
      controllerStart();

      if (pressed[0] & BTN_SELECT)
        return levelNum;
      else if (pressed[0] & BTN_UP && !(heroTile & TOP_WALL))
        heroNext = (struct int8_t_pair) {level.hero.x, level.hero.y-4};
      else if (pressed[0] & BTN_RIGHT && !(heroTile & RIGHT_WALL))
        heroNext = (struct int8_t_pair) {level.hero.x+4, level.hero.y};
      else if (pressed[0] & BTN_DOWN && !(heroTile & BOTTOM_WALL))
        heroNext = (struct int8_t_pair) {level.hero.x, level.hero.y+4};
      else if (pressed[0] & BTN_LEFT && !(heroTile & LEFT_WALL))
        heroNext = (struct int8_t_pair) {level.hero.x-4, level.hero.y};

      WaitVsync(1);
      controllerEnd();
    }

    if (heroNext.x >= 6*4 || heroNext.x < 0
        || heroNext.y >= 6*4 || heroNext.y < 0)
      outcome = VICTORY;
    else
      for (uint8_t i = 0; i < MAX_TRAPS; i++)
        if (level.trap[i].x == heroNext.x && level.trap[i].y == heroNext.y)
          outcome = DEFEAT;

    /* Hero moving */
    for (uint8_t i = outcome == VICTORY? 3 : 4; i > 0; i--) {
      if (level.hero.x < heroNext.x)
        level.hero.x++;
      else if (level.hero.x > heroNext.x)
        level.hero.x--;
      else if (level.hero.y < heroNext.y)
        level.hero.y++;
      else if (level.hero.y > heroNext.y)
        level.hero.y--;

      trollenDrawLevel(&level);
      WaitVsync(5);
    }

    if (outcome)
      continue;

    for (uint8_t s = (level.troll[0].type == S_TROLL? 3 : 2); s > 0; s--) {
      for (uint8_t i = 0; i < 2; i++) {
        if (level.troll[i].type == NO_TROLL || level.troll[i].stun)
         continue;

        trollNext[i] = (struct int8_t_pair) {
          level.troll[i].pos.x, level.troll[i].pos.y};

        tTile = level.map[level.troll[i].pos.y/4][level.troll[i].pos.x/4];
        if (level.troll[i].type == V_TROLL) {
          if (level.hero.y < level.troll[i].pos.y && !(tTile & TOP_WALL))
            trollNext[i].y -= 4;
          else if (level.hero.y > level.troll[i].pos.y
              && !(tTile & BOTTOM_WALL))
            trollNext[i].y += 4;
          else if (level.hero.x < level.troll[i].pos.x && !(tTile & LEFT_WALL))
            trollNext[i].x -= 4;
          else if (level.hero.x > level.troll[i].pos.x
              && !(tTile & RIGHT_WALL))
            trollNext[i].x += 4;
        }
        else {
          if (level.hero.x < level.troll[i].pos.x && !(tTile & LEFT_WALL))
            trollNext[i].x -= 4;
          else if (level.hero.x > level.troll[i].pos.x
              && !(tTile & RIGHT_WALL))
            trollNext[i].x += 4;
          else if (level.hero.y < level.troll[i].pos.y && !(tTile & TOP_WALL))
            trollNext[i].y -= 4;
          else if (level.hero.y > level.troll[i].pos.y
              && !(tTile & BOTTOM_WALL))
            trollNext[i].y += 4;
        }
      }

      bool moved[2] = {false, false};
      for (uint8_t i = 4; i > 0; i--) {
        uint8_t still = 0;
        for (uint8_t j = 0; j < 2; j++) {
          if (level.troll[j].type == NO_TROLL || level.troll[j].stun) {
            still++;
            continue;
          }

          if (level.troll[j].pos.x < trollNext[j].x) {
            level.troll[j].pos.x++;
            moved[j] = true;
          }
          else if (level.troll[j].pos.x > trollNext[j].x) {
            level.troll[j].pos.x--;
            moved[j] = true;
          }
          else if (level.troll[j].pos.y < trollNext[j].y) {
            level.troll[j].pos.y++;
            moved[j] = true;
          }
          else if (level.troll[j].pos.y > trollNext[j].y) {
            level.troll[j].pos.y--;
            moved[j] = true;
          }
          else
            still++;
        }

        if (still == 2)
          break;

        trollenDrawLevel(&level);
        WaitVsync(5);
      }

      for (uint8_t i = 0; i < 2; i++) {
        if (level.troll[i].type == NO_TROLL)
          continue;

        if (level.hero.x == level.troll[i].pos.x
            && level.hero.y == level.troll[i].pos.y)
          outcome = DEFEAT;

        for (uint8_t j = 0; j < MAX_TRAPS; j++) {
          if (moved[i] && !level.troll[i].stun
              && level.troll[i].pos.x == level.trap[j].x
              && level.troll[i].pos.y == level.trap[j].y) {
            level.troll[i].stun = 4;
            trollenDrawLevel(&level);
            WaitVsync(1);
          }
        }
      }

      if (level.troll[0].pos.x == level.troll[1].pos.x
          && level.troll[0].pos.y == level.troll[1].pos.y
          && level.troll[0].type && level.troll[1].type) {
        level.troll[0].type = S_TROLL;
        level.troll[0].stun = 0;
        level.troll[1].type = NO_TROLL;

        trollenDrawLevel(&level);
        WaitVsync(1);

        break;
      }
    }

    if (level.troll[0].stun)
      level.troll[0].stun--;
    if (level.troll[1].stun)
      level.troll[1].stun--;
  }

  if (outcome == VICTORY)
    Print(8, 12, strCongrat);
  else
    Print(11, 12, strDied);

  while (1) {
      controllerStart();

      if (pressed[0] & BTN_START) {
        controllerEnd();
        break;
      }

      WaitVsync(1);
      controllerEnd();
  }

  return levelNum + (outcome == VICTORY? 1 : 0);
}

uint16_t topmenu() {
  uint16_t base = 0;
  uint16_t t;
  uint8_t i;
  char goingUp = 0;

  draw_page:
  /* Build the basic interface */
  ClearVram();
  DrawMap2(1, 2, titleMap);

  /* Print the list */
  for (i = 0; i < 16; i++) {
    t = base + (uint16_t) i;

    /* To always generate the same names */
    srandom(t);

    PrintInt(8, 8 + i, t, 0);
    SetTile(9, 8 + i, PERIOD_TILE);
    Print(11, 8 + i,
      (const char *) pgm_read_word(names +
      ((t % 10) * 3) +
      ((t < 30? t / 10: random() % 3))));
  }

  i = (goingUp? 15 : 0);
  SetTile(3, 8 + i, ARROW_TILE);

  while (1) {
    controllerStart();

    if (pressed[0] & BTN_DOWN) {
      if (i < 15) {
        SetTile(3, 8 + i++, 0);
        SetTile(3, 8 + i, ARROW_TILE);
      }
      else {
        base += 16;
        goingUp = 0;
        controllerEnd();
        goto draw_page;
      }
    }
    else if (pressed[0] & BTN_UP) {
      if (i) {
        SetTile(3, 8 + i--, 0);
        SetTile(3, 8 + i, ARROW_TILE);
      }
      else {
        base -= 16;
        goingUp = 1;
        controllerEnd();
        goto draw_page;
      }
    }
    else if (pressed[0] & BTN_RIGHT) {
        base += 16;
        goingUp = 0;
        controllerEnd();
        goto draw_page;
    }
    else if (pressed[0] & BTN_LEFT) {
        base -= 16;
        goingUp = 0;
        controllerEnd();
        goto draw_page;
    }
    /* To properly read the controller */
    else if (pressed[0] & BTN_START) {
      controllerEnd();
      break;
    }

    WaitVsync(1);
    controllerEnd();
  }

  return (base + (uint16_t) i);
}

void drawBaseTitle(uint16_t game) {
  ClearVram();
  Print(5, 21, strCFlavio);
  Print(5, 23, strLicense);
  Print(7, 24, strMIT);

  srandom(game);
  const char *name = (const char *) pgm_read_word(names + (game%10)*3
      + ((game<30? game / 10: random() %3)));
  uint8_t len;
  for (len = 0; pgm_read_byte(name+len); len++);
  Print(15-len/2, 5, name);
}

int8_t twoPlayersMenu() {
  uint8_t i;
  uint32_t r;

  Print(12, 15, strVsCpu);
  Print(12, 16, strVsHuman);
  Print(12, 17, strExit);
  SetTile(10, 15, ARROW_TILE);

  i = 0;
  r = 0;
  while (1) {
    controllerStart();

    if (pressed[0] & BTN_DOWN) {
      SetTile(10, 15 + i, 0);
      i = (i + 1) % 3;
      SetTile(10, 15 + i, ARROW_TILE);
    }
    else if (pressed[0] & BTN_UP) {
      SetTile(10, 15 + i, 0);
      i = (6 + i - 1) % 3;
      SetTile(10, 15 + i, ARROW_TILE);
    }
    else if (pressed[0] & BTN_START) {
      controllerEnd();
      srandom(r);
      return i;
    }

    r++;
    WaitVsync(1);
    controllerEnd();
  }
}

int8_t onePlayerMenu(uint8_t level, uint8_t levels) {
  int8_t i = 0;
  uint32_t r = 0;

  Print(12, 15, strStart);
  Print(12, 16, strExit);
  SetTile(10, 15, ARROW_TILE);

  while (1) {
    controllerStart();

    if (pressed[0] & BTN_DOWN) {
      SetTile(10, 15 + i, 0);
      i = (i + 1) & 1;
      SetTile(10, 15 + i, ARROW_TILE);
    }
    else if (pressed[0] & BTN_UP) {
      SetTile(10, 15 + i, 0);
      i = (6 + i - 1) & 1;
      SetTile(10, 15 + i, ARROW_TILE);
    }
    else if (pressed[0] & BTN_LEFT && !i) {
      /* Level is unsigned */
      if (--level >= levels)
        level = levels-1;
    }
    else if (pressed[0] & BTN_RIGHT && !i) {
      if (++level >= levels)
        level = 0;
    }
    else if (pressed[0] & BTN_START) {
      controllerEnd();
      srandom(r);
      return (i? -1 : level);
    }

    if (levels)
      PrintByte(20, 15, level, 0);

    r++;
    WaitVsync(1);
    controllerEnd();
  }
}

int main() {
  uint16_t game;
  int8_t r;
  uint8_t trollenLevel = 0;
  /* InitMusicPlayer(patches); */
  SetMasterVolume(0xff);
  SetTileTable(tileset);
  SetFontTilesIndex(0);
  /* SetSpritesTileTable(sprite); */

  while (1) {
    beginning:
    game = topmenu();

    while (1) {
      drawBaseTitle(game);

      switch(game % 10) {
        case 0:
          /* Greed */
          DrawMap2(9, 7, (const char *) pgm_read_word(batteries +
            (game % 30) / 10));
          DrawMap2(13, 7, (const char *) pgm_read_word(batteries +
            (game % 30) / 10));
          DrawMap2(17, 7, (const char *) pgm_read_word(batteries +
            (game % 30) / 10));

          r = twoPlayersMenu();
          if (r == 2)
            goto beginning;
          greed(r);
          break;

        case 1:
          /* The Grid */
          r = twoPlayersMenu();
          if (r == 2)
            goto beginning;
          grid(r+1);
          break;

        case 2:
          /* Trollen */
          DrawMap2(11, 8, trollenTitleMap);

          r = onePlayerMenu(trollenLevel, NUM_TROLLEN_LEVELS);
          if (r == -1)
            goto beginning;
          trollenLevel = trollen(r);
          break;

        case 3:
          /* Slide */
          r = onePlayerMenu(0, 0);
          if (r == -1)
            goto beginning;
          slide();
          break;

        case 4:
          /* The One */
          r = onePlayerMenu(0, 0);
          if (r == -1)
            goto beginning;
          theOne();
          break;

        case 5:
          /* Monster */
          DrawMap2(12, 7, redRoomMap);
          DrawMap2(14, 7, redRoomMap);
          DrawMap2(16, 7, redRoomMap);
          DrawMap2(12, 9, redRoomMap);
          DrawMap2(14, 9, wumpusMap);
          DrawMap2(16, 9, redRoomMap);
          DrawMap2(12, 11, redRoomMap);
          DrawMap2(14, 11, redRoomMap);
          DrawMap2(16, 11, redRoomMap);

          r = onePlayerMenu(0, 0);
          if (r == -1)
            goto beginning;
          monster();
          break;

        case 6:
          /* Survival */
          r = twoPlayersMenu();
          if (r == 2)
            goto beginning;
          survival(r+1);
          break;

        case 7:
          /* Rain */
          r = twoPlayersMenu();
          if (r == 2)
            goto beginning;
          rain(r+1);
          break;

        case 8:
          /* Array */
          r = twoPlayersMenu();
          if (r == 2)
            goto beginning;
          sort(r);
          break;

        case 9:
          /* Rich */
          r = onePlayerMenu(0, 0);
          if (r == -1)
            goto beginning;
          rich();
          break;

        default:
          goto beginning;
      }
    }
  }

  return 0;
}
