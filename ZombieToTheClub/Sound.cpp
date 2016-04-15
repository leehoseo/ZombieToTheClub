#include "Sound.h"
#include "Resource.h"

Sound::Sound()
{
	m_DirectSound = 0;
	m_primaryBuffer = 0;
}

Sound::~Sound()
{
	ShutdownDirectSound();
	ShutdownWaveFile(&m_main.m_music);
	ShutdownWaveFile(&m_letsPatty.m_music);
	ShutdownWaveFile(&m_attack1.m_music);
	ShutdownWaveFile(&m_currentMusic.m_music);
	ShutdownWaveFile(&m_curBufMusic.m_music);
	ShutdownWaveFile(&m_pEffect_ZombieHit);
	ShutdownWaveFile(&m_pEffect_ZombieDeath);
	ShutdownWaveFile(&m_buf1.m_music);
	ShutdownWaveFile(&m_buf2.m_music);
	ShutdownWaveFile(&m_buf3.m_music);
	ShutdownWaveFile(&m_pEffect_PlayerDeath);
	ShutdownWaveFile(&m_pEffect_20Combo);
	ShutdownWaveFile(&m_pEffect_50Combo);
	ShutdownWaveFile(&m_pEffect_100Combo);
	ShutdownWaveFile(&m_pEffect_150Combo);
	ShutdownWaveFile(&m_pEffect_GreatCombo);
	ShutdownWaveFile(&m_pEffect_100Kill);
	ShutdownWaveFile(&m_pEffect_PlayerDown);

	for (int index = 0; index < 10; ++index)
	{
		ShutdownWaveFile(&m_MusicList[index].m_music);
	}
}

Sound * Sound::Instance()
{
	static Sound instance;
	return &instance;
}

bool Sound::Initialize(HWND _hwnd)
{
	bool result;
	// Initialize direct sound and the primary sound buffer.
	result = InitializeDirectSound(_hwnd);
	if (!result)
	{
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\LetsPatty.wav", &m_letsPatty.m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr5");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Attack1.wav", &m_attack1.m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Main.wav", &m_main.m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Buf1.wav", &m_buf1.m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_buf1.m_nEndTime = 17000;

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Buf2.wav", &m_buf2.m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_buf2.m_nEndTime = 60000;

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Buf3.wav", &m_buf3.m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_buf3.m_nEndTime = 90000;

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Music1.wav", &m_MusicList[0].m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_MusicList[0].m_nEndTime = 190000;

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Music2.wav", &m_MusicList[1].m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_MusicList[1].m_nEndTime = 110000;
	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Music3.wav", &m_MusicList[2].m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_MusicList[2].m_nEndTime = 125000;
	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Music4.wav", &m_MusicList[3].m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_MusicList[3].m_nEndTime = 77000;
	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Music5.wav", &m_MusicList[4].m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_MusicList[4].m_nEndTime = 56000;
	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Music6.wav", &m_MusicList[5].m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_MusicList[5].m_nEndTime = 39000;
	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Music7.wav", &m_MusicList[6].m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_MusicList[6].m_nEndTime = 82000;
	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Music8.wav", &m_MusicList[7].m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_MusicList[7].m_nEndTime = 151000;
	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Music9.wav", &m_MusicList[8].m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_MusicList[8].m_nEndTime = 80000;
	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\Music10.wav", &m_MusicList[9].m_music);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}
	m_MusicList[9].m_nEndTime = 74000;

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\ZombieHit.wav", &m_pEffect_ZombieHit);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\ButtonClick.wav", &m_pEffect_ButtonClick);
	if (!result)
	{
		MESSAGEBOX("Erorr6");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\ZombieDeath.wav", &m_pEffect_ZombieDeath);
	if (!result)
	{
		MESSAGEBOX("Erorr8");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\PlayerDeath.wav", &m_pEffect_PlayerDeath);
	if (!result)
	{
		MESSAGEBOX("Erorr8");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\100kill.wav", &m_pEffect_100Kill);
	if (!result)
	{
		MESSAGEBOX("Erorr8");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\20Combo.wav", &m_pEffect_20Combo);
	if (!result)
	{
		MESSAGEBOX("Erorr8");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\50Combo.wav", &m_pEffect_50Combo);
	if (!result)
	{
		MESSAGEBOX("Erorr8");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\100Combo.wav", &m_pEffect_100Combo);
	if (!result)
	{
		MESSAGEBOX("Erorr8");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\150Combo.wav", &m_pEffect_150Combo);
	if (!result)
	{
		MESSAGEBOX("Erorr8");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\GreatCombo.wav", &m_pEffect_GreatCombo);
	if (!result)
	{
		MESSAGEBOX("Erorr8");
		return false;
	}

	result = LoadWaveFile("../\\ZombieToTheClub\\Resource\\Sound\\PlayerDown.wav", &m_pEffect_PlayerDown);
	if (!result)
	{
		MESSAGEBOX("Erorr8");
		return false;
	}

	m_currentMusic = m_main;
	m_curBufMusic = m_buf1;
}


void Sound::ShutdownDirectSound()
{
	// Release the primary sound buffer pointer.
	if (m_primaryBuffer)
	{
		m_primaryBuffer->Release();
		m_primaryBuffer = 0;
	}

	// Release the direct sound interface pointer.
	if (m_DirectSound)
	{
		m_DirectSound->Release();
		m_DirectSound = 0;
	}
	return;
}

void Sound::ShutdownWaveFile(IDirectSoundBuffer8** secondaryBuffer)
{
	// Release the secondary sound buffer.
	if (*secondaryBuffer)
	{
		(*secondaryBuffer)->Release();
		*secondaryBuffer = 0;
	}
	return;
}

bool Sound::InitializeDirectSound(HWND _hwnd)
{
	HRESULT result;
	DSBUFFERDESC bufferDesc;
	WAVEFORMATEX waveFormat;

	result = DirectSoundCreate8(NULL, &m_DirectSound, NULL);
	if (FAILED(result))
	{
		return false;
	}

	result = m_DirectSound->SetCooperativeLevel(_hwnd, DSSCL_PRIORITY);
	if (FAILED(result))
	{
		return false;
	}

	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes = 0;
	bufferDesc.dwReserved = 0;
	bufferDesc.lpwfxFormat = NULL;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	// Get control of the primary sound buffer on the default sound device.
	result = m_DirectSound->CreateSoundBuffer(&bufferDesc, &m_primaryBuffer, NULL);
	if (FAILED(result))
	{
		return false;
	}

	waveFormat.wFormatTag = WAVE_FORMAT_PCM;
	waveFormat.nSamplesPerSec = 44100;
	waveFormat.wBitsPerSample = 16;
	waveFormat.nChannels = 2;
	waveFormat.nBlockAlign = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
	waveFormat.cbSize = 0;

	// Set the primary buffer to be the wave format specified.
	result = m_primaryBuffer->SetFormat(&waveFormat);
	if (FAILED(result))
	{
		return false;
	}

	return true;
}

bool Sound::LoadWaveFile(char* filename, IDirectSoundBuffer8** secondaryBuffer)
{
	int error;
	FILE* filePtr;
	unsigned int count;
	WaveHeaderType waveFileHeader;
	WAVEFORMATEX waveFormat;
	DSBUFFERDESC bufferDesc;
	HRESULT result;
	IDirectSoundBuffer* tempBuffer;
	unsigned char* waveData;
	unsigned char *bufferPtr;
	unsigned long bufferSize;

	error = fopen_s(&filePtr, filename, "rb");
	if (error != 0)
	{
		return false;
	}

	// Read in the wave file header.
	count = fread(&waveFileHeader, sizeof(waveFileHeader), 1, filePtr);
	if (count != 1)
	{
		return false;
	}

	// Check that the chunk ID is the RIFF format.
	if ((waveFileHeader.chunkId[0] != 'R') || (waveFileHeader.chunkId[1] != 'I') ||
		(waveFileHeader.chunkId[2] != 'F') || (waveFileHeader.chunkId[3] != 'F'))
	{
		return false;
	}

	// Check that the file format is the WAVE format.
	if ((waveFileHeader.format[0] != 'W') || (waveFileHeader.format[1] != 'A') ||
		(waveFileHeader.format[2] != 'V') || (waveFileHeader.format[3] != 'E'))
	{
		return false;
	}

	// Check that the sub chunk ID is the fmt format.
	if ((waveFileHeader.subChunkId[0] != 'f') || (waveFileHeader.subChunkId[1] != 'm') ||
		(waveFileHeader.subChunkId[2] != 't') || (waveFileHeader.subChunkId[3] != ' '))
	{
		return false;
	}

	// Check that the audio format is WAVE_FORMAT_PCM.
	if (waveFileHeader.audioFormat != WAVE_FORMAT_PCM)
	{
		return false;
	}

	// Check that the wave file was recorded in stereo format.
	if (waveFileHeader.numChannels != 2)
	{
		return false;
	}

	// Check that the wave file was recorded at a sample rate of 44.1 KHz.
	if (waveFileHeader.sampleRate != 44100)
	{
		return false;
	}

	// Ensure that the wave file was recorded in 16 bit format.
	if (waveFileHeader.bitsPerSample != 16)
	{
		return false;
	}

	// Check for the data chunk header.
	if ((waveFileHeader.dataChunkId[0] != 'd') || (waveFileHeader.dataChunkId[1] != 'a') ||
		(waveFileHeader.dataChunkId[2] != 't') || (waveFileHeader.dataChunkId[3] != 'a'))
	{
		return false;
	}

	//Set the wave format of secondary buffer that this wave file will be loaded onto.
	waveFormat.wFormatTag = WAVE_FORMAT_PCM;
	waveFormat.nSamplesPerSec = 44100;
	waveFormat.wBitsPerSample = 16;
	waveFormat.nChannels = 2;
	waveFormat.nBlockAlign = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
	waveFormat.cbSize = 0;

	// Set the buffer description of the secondary sound buffer that the wave file will be loaded onto.
	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags = DSBCAPS_CTRLVOLUME;				// 2차버퍼와 1차버퍼 다르다
	bufferDesc.dwBufferBytes = waveFileHeader.dataSize;		// 2차버퍼와 1차버퍼 다르다
	bufferDesc.dwReserved = 0;
	bufferDesc.lpwfxFormat = &waveFormat;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	// Create a temporary sound buffer with the specific buffer settings.
	result = m_DirectSound->CreateSoundBuffer(&bufferDesc, &tempBuffer, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Test the buffer format against the direct sound 8 interface and create the secondary buffer.
	result = tempBuffer->QueryInterface(IID_IDirectSoundBuffer8, (void**)&*secondaryBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Release the temporary buffer.
	tempBuffer->Release();

	tempBuffer = 0;
	// Move to the beginning of the wave data which starts at the end of the data chunk header.
	fseek(filePtr, sizeof(WaveHeaderType), SEEK_SET);

	// Create a temporary buffer to hold the wave file data.
	waveData = new unsigned char[waveFileHeader.dataSize];
	if (!waveData)
	{
		return false;
	}

	// Read in the wave file data into the newly created buffer.
	count = fread(waveData, 1, waveFileHeader.dataSize, filePtr);
	if (count != waveFileHeader.dataSize)
	{
		return false;
	}

	// Close the file once done reading.
	error = fclose(filePtr);
	if (error != 0)
	{
		return false;
	}

	// Lock the secondary buffer to write wave data into it.
	result = (*secondaryBuffer)->Lock(0, waveFileHeader.dataSize, (void**)&bufferPtr, (DWORD*)&bufferSize, NULL, 0, 0);
	if (FAILED(result))
	{
		return false;
	}

	// Copy the wave data into the buffer.
	memcpy(bufferPtr, waveData, waveFileHeader.dataSize);

	// Unlock the secondary buffer after the data has been written to it.
	result = (*secondaryBuffer)->Unlock((void*)bufferPtr, bufferSize, NULL, 0);
	if (FAILED(result))
	{
		return false;
	}

	// Release the wave data since it was copied into the secondary buffer.
	delete[] waveData;
	waveData = 0;

	return true;
}

int Sound::GetMusicEndTime() const
{
	return m_currentMusic.m_nEndTime;
}

void Sound::ChangeMusic(int _index)
{
	EndBufMusic();
	EndMusic();
	//10~12 : 버프
	switch (_index)
	{
	case 0:
		m_currentMusic = m_MusicList[0];
		break;
	case 1:
		m_currentMusic = m_MusicList[1];
		break;
	case 2:
		m_currentMusic = m_MusicList[2];
		break;
	case 3:
		m_currentMusic = m_MusicList[3];
		break;
	case 4:
		m_currentMusic = m_MusicList[4];
		break;
	case 5:
		m_currentMusic = m_MusicList[5];
		break;
	case 6:
		m_currentMusic = m_MusicList[6];
		break;
	case 7:
		m_currentMusic = m_MusicList[7];
		break;
	case 8:
		m_currentMusic = m_MusicList[8];
		break;
	case 9:
		m_currentMusic = m_MusicList[9];
		break;
	}
	PlayMusic();
}

int Sound::GetBufMusicEndTime() const
{
	return m_curBufMusic.m_nEndTime;
}

bool Sound::PlayBufMusic()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_curBufMusic.m_music->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_curBufMusic.m_music->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_curBufMusic.m_music->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}

	return true;
}

void Sound::EndBufMusic()
{
	m_curBufMusic.m_music->Stop();
}

void Sound::ChangeBufMusic(int _index)
{
	EndBufMusic();
	EndMusic();
	
	switch (_index)
	{
	case 0:
		m_curBufMusic = m_buf1;
		break;
	case 1:
		m_curBufMusic = m_buf2;
		break;
	case 2:
		m_curBufMusic = m_buf3;
		break;
	}
	PlayBufMusic();
}


bool Sound::PlayAttack1()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_attack1.m_music->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_attack1.m_music->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_attack1.m_music->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}

	return true;
}

bool Sound::PlayLetsPatty()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_letsPatty.m_music->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_letsPatty.m_music->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_letsPatty.m_music->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::PlayZombieHit()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_ZombieHit->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_ZombieHit->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_ZombieHit->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}

	return true;
}

bool Sound::PlayZombieDeath()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_ZombieDeath->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_ZombieDeath->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_ZombieDeath->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::PlayButtonClick()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_ButtonClick->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_ButtonClick->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_ButtonClick->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::PlayPlayerDeath()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_PlayerDeath->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_PlayerDeath->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_PlayerDeath->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::PlayPlayerDown()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_PlayerDown->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_PlayerDown->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_PlayerDown->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::Play20Combo()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_20Combo->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_20Combo->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_20Combo->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::Play50Combo()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_50Combo->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_50Combo->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_50Combo->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::Play100Combo()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_100Combo->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_100Combo->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_100Combo->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::Play150Combo()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_150Combo->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_150Combo->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_150Combo->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::PlayGreatCombo()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_GreatCombo->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_GreatCombo->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_GreatCombo->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::Play100Kill()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_pEffect_100Kill->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_pEffect_100Kill->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_pEffect_100Kill->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Sound::PlayMusic()
{
	HRESULT result;

	// Set position at the beginning of the sound buffer.
	result = m_currentMusic.m_music->SetCurrentPosition(0);
	if (FAILED(result))
	{
		return false;
	}

	// Set volume of the buffer to 100%.
	result = m_currentMusic.m_music->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
	{
		return false;
	}

	// Play the contents of the secondary sound buffer.
	result = m_currentMusic.m_music->Play(0, 0, 0);
	if (FAILED(result))
	{
		return false;
	}
	
	return true;
	
}

void Sound::EndMusic()
{
	m_currentMusic.m_music->Stop();
}
