#pragma once

#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
#define MESSAGEBOX(massage)		{ MessageBox(NULL , massage , "ERROR BOX" , NULL); }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
// Directx Input클래스를 받아오기위해서
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

const char GAME_NAME[] = "Zombie To The Club";
const int GAME_WIDTH = 1024;
const int GAME_HEIGHT = 768;
const int MAX_ZOMBIE = 20;
const double PI = 3.14159265;					// 원주율

enum eSTATE { STAY = 1, MOVE = 2, ATTACK = 3 , HIT = 4};
enum eDIRECTION { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, LEFT_UP = 4, LEFT_DOWN = 5, RIGHT_UP = 6, RIGHT_DOWN = 7 };
enum eTYPE { PLAYER = 1 , BZ = 2 };