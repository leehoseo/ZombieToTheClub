#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <stdio.h>



struct WaveHeaderType
{
	char chunkId[4];
	unsigned long chunkSize;
	char format[4];
	char subChunkId[4];
	unsigned long subChunkSize;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned long sampleRate;
	unsigned long bytesPerSecond;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	char dataChunkId[4];
	unsigned long dataSize;
};

class Sound
{
private:
	Sound();

	IDirectSound8* m_DirectSound;
	IDirectSoundBuffer* m_primaryBuffer;
	IDirectSoundBuffer8* m_hiphop1;
	IDirectSoundBuffer8* m_hiphop2;
	IDirectSoundBuffer8* m_hiphop3;
	IDirectSoundBuffer8* m_letsPatty;
	IDirectSoundBuffer8* m_attack1;

	IDirectSoundBuffer8* m_currentMusic;

	bool InitializeDirectSound(HWND _hwnd);

	bool LoadWaveFile(char* filename, IDirectSoundBuffer8** secondaryBuffer);


public:
	~Sound();

	static Sound * Instance();

	void ShutdownDirectSound();
	void ShutdownWaveFile(IDirectSoundBuffer8** secondaryBuffer);

	bool Initialize(HWND _hwnd);
	bool PlayHiphop1();
	bool PlayHiphop2();
	bool PlayHiphop3();
	bool PlayAttack1();
	bool PlayLetsPatty();

	IDirectSoundBuffer8* GetSound() const;
	void SetSound(int _index);
};

