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

struct Music
{
	IDirectSoundBuffer8* m_music;
	int m_nEndTime;
};

class Sound
{
private:
	Sound();

	IDirectSound8* m_DirectSound;
	IDirectSoundBuffer* m_primaryBuffer;

	Music m_letsPatty;
	Music m_attack1;
	Music m_main;
	Music m_currentMusic;
	Music m_curBufMusic;

	Music m_buf1;
	Music m_buf2;
	Music m_buf3;

	Music m_MusicList[10];

	bool InitializeDirectSound(HWND _hwnd);

	bool LoadWaveFile(char* filename, IDirectSoundBuffer8** secondaryBuffer);

public:
	~Sound();

	static Sound * Instance();

	void ShutdownDirectSound();
	void ShutdownWaveFile(IDirectSoundBuffer8** secondaryBuffer);

	bool Initialize(HWND _hwnd);
	bool PlayAttack1();
	bool PlayLetsPatty();

	bool PlayMusic();
	void EndMusic();

	int GetMusicEndTime() const;
	void ChangeMusic(int _index);

	int GetBufMusicEndTime() const;

	bool PlayBufMusic();
	void EndBufMusic();
	void ChangeBufMusic(int _index);

};

