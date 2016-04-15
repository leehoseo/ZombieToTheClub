#pragma once

#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
#define MESSAGEBOX(massage)		{ MessageBox(NULL , massage , "ERROR BOX" , NULL); }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
// Directx InputŬ������ �޾ƿ������ؼ�
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

const char GAME_NAME[] = "Zombie To The Club";
const int GAME_WIDTH = 1600;
const int GAME_HEIGHT = 900;
const int MAX_ZOMBIE = 150;
const double PI = 3.14159265;					// ������

enum eSTATE { STAY = 1, MOVE = 2, ATTACK1 = 3, ATTACK2 = 4, ATTACK3 = 5, HIT = 6, DEATH = 7, TRACE = 8, HIT_DOWN = 9 };

enum eDIRECTION { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, LEFT_UP = 4, LEFT_DOWN = 5, RIGHT_UP = 6, RIGHT_DOWN = 7 };

enum eTYPE { PLAYER = 1 , BZ = 2 };

enum eHAND { ANOTHER = 1 , STAND = 2 };