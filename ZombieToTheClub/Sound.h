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
	IDirectSoundBuffer8* m_pEffect_ZombieHit;
	IDirectSoundBuffer8* m_pEffect_ZombieDeath;
	IDirectSoundBuffer8* m_pEffect_PlayerDeath;
	IDirectSoundBuffer8* m_pEffect_ButtonClick;
	IDirectSoundBuffer8* m_pEffect_PlayerDown;
	IDirectSoundBuffer8* m_pEffect_20Combo;
	IDirectSoundBuffer8* m_pEffect_50Combo;
	IDirectSoundBuffer8* m_pEffect_100Combo;
	IDirectSoundBuffer8* m_pEffect_150Combo;
	IDirectSoundBuffer8* m_pEffect_GreatCombo;

	IDirectSoundBuffer8* m_pEffect_100Kill;
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
	bool PlayZombieHit();
	bool PlayZombieDeath();
	bool PlayButtonClick();
	bool PlayPlayerDeath();
	bool PlayPlayerDown();
	bool Play20Combo();
	bool Play50Combo();
	bool Play100Combo();
	bool Play150Combo();
	bool PlayGreatCombo();
	bool Play100Kill();
	bool PlayMusic();
	void EndMusic();

	int GetMusicEndTime() const;
	void ChangeMusic(int _index);

	int GetBufMusicEndTime() const;

	bool PlayBufMusic();
	void EndBufMusic();
	void ChangeBufMusic(int _index);

};

