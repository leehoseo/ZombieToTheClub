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
const int MAX_ZOMBIE = 1;
const double PI = 3.14159265;					// 원주율

enum eCODE { STAY = 1, MOVE = 2, ATTACK = 3 };