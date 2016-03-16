#pragma once

#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
#define MESSAGEBOX(massage)		{ MessageBox(NULL , massage , "ERROR BOX" , NULL); }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")


const char GAME_NAME[] = "Zombie Club";
const char Zombi1_IMAGE[] = "Resource\\Zombie1.png";
const int GAME_WIDTH = 900;
const int GAME_HEIGHT = 600;

const double PI = 3.14159265;					// ø¯¡÷¿≤

const enum eMove { LEFT = 37, UP = 38, RIGHT = 39, DOWN = 40 };