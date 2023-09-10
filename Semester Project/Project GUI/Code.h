#pragma once
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
#include<fileapi.h>
#include<vector>
#include<dirent.h>
#include<string>
#include <algorithm>
#include "TotalTime.h"

class AudioPlayer
{

public:
	string ManufacturerName = "Panasonic";
	string ModelNum = "HD774";
	BOOLEAN PowerState;
	LPCWSTR Drive = { L"E:\\" };
	UINT Check;
	DWORD SectorsPerCluster, BytesPerSector, FreeClusters, TotalClusters;
	BOOLEAN SuccessfulFileOpen = GetDiskFreeSpaceA("E:", &SectorsPerCluster, &BytesPerSector, &FreeClusters, &TotalClusters);
	BOOLEAN FileOpenSuccess = GetDriveType(Drive);
	static int No_of_Songs;
	float freestorage;
	float totalstorage;

	//CONSTRUCTORS
	AudioPlayer()
	{
		PowerState = false;
	}

	AudioPlayer(string MAN, string MON, bool PS)
	{
		PowerState = PS;
	}

	//GETTERS
	string getManufacturerName()
	{
		return ManufacturerName;
	}

	string getModelNum()
	{
		return ModelNum;
	}

	UINT getCheck()
	{
		return Check;
	}

	//MEMBER FUNCTIONS

	int CheckDriveType()
	{

		Check = GetDriveType(Drive);

		if (!FileOpenSuccess)
		{
			cout << "Could not get drive information.\n";
			exit(EXIT_FAILURE);
		}

		switch (Check)
		{

		case 0:
		{
			cout << "Drive " << Drive << " is type " << Check << " - Cannot be determined.\n";
			exit(EXIT_FAILURE);
			break;
		}

		case 1:
		{
			cout << "Drive " << Drive << " is type " << Check << " - Invalid root path / Not available.\n";
			exit(EXIT_FAILURE);
			break;
		}

		case 2:
		{
			cout << "Drive " << Drive << " is type " << Check << "  - USB.\n";
			break;
		}

		case 3:
		{
			cout << "Drive " << Drive << " is type " << Check << " - Fixed.\n";
			cout << "Inappropriate File Format" << endl;
			exit(EXIT_FAILURE);
			break;
		}

		case 4:
		{
			cout << "Drive " << Drive << " is type " << Check << " - Network.\n";
			cout << "Inappropriate File Format" << endl;
			exit(EXIT_FAILURE);
			break;
		}

		case 5:
		{
			cout << "Drive " << Drive << " is type " << Check << " - CD - ROM.\n";
			break;
		}

		case 6:
		{
			cout << "Drive " << Drive << " is type " << Check << " - RAMDISK.\n";
			cout << "Inappropriate File Format" << endl;
			exit(EXIT_FAILURE);
			break;
		}

		default:
		{
			"Unknown value!\n";
			exit(EXIT_FAILURE);
		}

		}

		return Check;
	}

	void CheckDriveFreeSpace()
	{
		if (!SuccessfulFileOpen)
		{
			cout << "Could not get drive information.\n";
			exit(EXIT_FAILURE);
		}

		cout << "Bytes per sector:" << BytesPerSector << endl;
		cout << "Sectors per cluster: " << SectorsPerCluster << endl;
		cout << "Free clusters: " << FreeClusters << endl;
		cout << "Total clusters: " << TotalClusters << endl;

		unsigned int KBPerCluster = (BytesPerSector * SectorsPerCluster) / 1024;
		unsigned int a, b;

		a = (KBPerCluster * FreeClusters) / 1024;
		freestorage = (a - (0.0236 * (KBPerCluster * FreeClusters) / 1024)) / 1000;
		b = (KBPerCluster * TotalClusters) / 1024;
		totalstorage = (b + (0.0263 * (KBPerCluster * TotalClusters) / 1024)) / 1000;

		if (totalstorage <= 16)
		{
			cout << "You have " << (double)freestorage << " GB of free storage\n";
			cout << "You have " << (double)totalstorage << " GB of total storage\n";
		}

		else if (totalstorage > 16)
		{
			cout << "Exceeding Compatible Storage Capacity.\n";
			exit(EXIT_FAILURE);
		}
	}
};

class Song :public AudioPlayer
{
public:
	string Name;
	time_t PlayTimeSec, PlayTimeMin, TotalTimeSec, TotalTimeMin, RemSec, RemMin;
	vector<string> Songlist;
	vector<string> Videolist;
	string CurrentSong;
	static int No_of_Songs;
	friend AudioPlayer;
	bool Shuffle = false;
	bool Repeat = false;
	static int MP4_Files;

	//CONSTRUCTORS
	Song()
	{
		Name = " ";
		PlayTimeSec = 0;
		PlayTimeMin = 0;
		TotalTimeSec = 0;
		TotalTimeMin = 0;
	}

	Song(string N, time_t PTS, time_t PTM, time_t TTS, time_t TTM)
	{
		Name = N;
		PlayTimeSec = PTS;
		PlayTimeSec = PTM;
		TotalTimeSec = TTS;
		TotalTimeMin = TTM;
	}

	void TurnOn()
	{
		PowerState = true;

		if (PowerState)
		{
			ifstream File;

			File.open("MusicPlayerState.txt");

			if (!File.is_open())
			{

				File.close();

				cout << "File not Found" << endl;
			}

			else if (File.is_open())
			{
		
				File >> PlayTimeSec;
				File >> PlayTimeSec;
				File >> TotalTimeSec;
				File >> TotalTimeMin;

				File.close();
			}
		}
	}

	void TurnOff()
	{
		PowerState = false;

		if (!PowerState)
		{
			ofstream File;

			File.open("MusicPlayerState.txt");

			if (!File.is_open())
			{

				File.close();

				cout << "File not Found" << endl;
			}

			else if (File.is_open())
			{
				File << ManufacturerName << endl;
				File << ModelNum << endl;
				File << PlayTimeSec << endl;
				File << PlayTimeSec << endl;
				File << TotalTimeSec << endl;
				File << TotalTimeMin << endl;

				File.close();
			}
		}
	}

	void Resume_Song()
	{
		mciSendStringA("play mp3", NULL, 0, NULL);
	}

	void Play_Songlist(string GetFileName)
	{
		string szCommand = "open \"E:\\Music\\" + GetFileName + "\" type mpegvideo alias mp3 ";

		cout << szCommand << endl << endl;
		////open the audio file
		mciSendStringA(szCommand.c_str(), NULL, 0, NULL);

		this->CurrentSong = GetFileName;
		//play the audio file
		mciSendStringA("play mp3", NULL, 0, NULL);
	}

	void Pause_Songlist()
	{
		mciSendStringA("pause mp3", NULL, 0, NULL);
	}

	void Close_Songlist()
	{
		mciSendStringA("close mp3", NULL, 0, NULL);
	}

	void Next_Songlist()
	{
		mciSendStringA("close mp3", NULL, 0, NULL);

		if (Repeat == true)
		{
			Play_Songlist(CurrentSong);
		}


		else if (Shuffle == true)
		{
			string S = CurrentSong;
			shuffle();
			CurrentSong = S;
			Next_Song_File();
		}

		else
		{
			Next_Song_File();
		}
	}

	void NextVideo()
	{
		mciSendStringA("close mp3", NULL, 0, NULL);

		if (Repeat == true)
		{
			Play_Songlist(CurrentSong);
		}


		else if (Shuffle == true)
		{
			string S = CurrentSong;
			shuffle();
			CurrentSong = S;
			Next_Song_File();
		}

		else
		{
			Next_Song_File();
		}
	}

	void Previous_Songlist()
	{
		mciSendStringA("close mp3", NULL, 0, NULL);

		if (Repeat == true)
		{
			Play_Songlist(CurrentSong);
		}


		else if (Shuffle == true)
		{
			string S = CurrentSong;
			shuffle();
			CurrentSong = S;
			Previous_Song_File();
		}

		else
		{
			Previous_Song_File();
		}
	}

	int Next_Song_File()
	{
		// directory stream variable for accessing the directory
		DIR* directory;

		// will store pointer to each entry in the directory
		struct dirent* entry;

		// attempt to open the current working directory, opendir() returns NULL 
		// on failure
		directory = opendir("E:\\Music");

		// if opening the directory fails, exit with an error message and status
		if (directory == NULL)
		{
			printf("Error opening directory.\n");
			return 1;
		}

		// Read each entry in the directory with readdir() and store the pointer to 
		// the struct dirent into entry... when there are no more entries in the 
		// directory readdir() will return NULL and terminate the loop at that point.

		int i = 0;

		while ((entry = readdir(directory)) != NULL)
		{
			if (entry->d_type == DT_REG)
			{

				if (CurrentSong == Songlist[i])
				{
					if (CurrentSong == Songlist.back())
					{
						i = 0;
						CurrentSong = Songlist[0];
						Play_Songlist(CurrentSong);
						break;
					}

					else if (CurrentSong != Songlist.back())
					{
						CurrentSong = Songlist[i + 1];
						Play_Songlist(CurrentSong);
						break;
					}

				}

				if(i<Videolist.size())
				{ 
					if (CurrentSong == Videolist[i])
					{
						if (CurrentSong == Videolist.back())
						{
							i = 0;
							CurrentSong = Videolist[0];
							Play_Songlist(CurrentSong);
							break;
						}

						else if (CurrentSong != Videolist.back())
						{
							CurrentSong = Videolist[i + 1];
							Play_Songlist(CurrentSong);
							break;
						}
				}

				}

				i++;
			}
		}

		// close the directory... if closedir() fails it will return -1
		if (closedir(directory) == -1)
		{
			// exit with an error message and status if closedir() fails
			printf("Error closing directory.\n");
			return 1;
		}
	}

	int Previous_Song_File()
	{
		// directory stream variable for accessing the directory
		DIR* directory;

		// will store pointer to each entry in the directory
		struct dirent* entry;

		// attempt to open the current working directory, opendir() returns NULL 
		// on failure
		directory = opendir("E:\\Music");

		// if opening the directory fails, exit with an error message and status
		if (directory == NULL)
		{
			printf("Error opening directory.\n");
			return 1;
		}

		// Read each entry in the directory with readdir() and store the pointer to 
		// the struct dirent into entry... when there are no more entries in the 
		// directory readdir() will return NULL and terminate the loop at that point.

		int i = 0;

		while ((entry = readdir(directory)) != NULL)
		{
			if (entry->d_type == DT_REG)
			{
				if (CurrentSong == Songlist[i])
				{
					if (CurrentSong == Songlist.front())
					{
						CurrentSong = Songlist.back();
						Play_Songlist(CurrentSong);
						break;
					}

					else if (CurrentSong != Songlist.front())
					{
						CurrentSong = Songlist[i - 1];
						Play_Songlist(CurrentSong);
						break;
					}
				}

				if (i < Videolist.size())
				{
					if (CurrentSong == Videolist[i])
					{
						if (CurrentSong == Videolist.front())
						{
							CurrentSong = Videolist.back();
							Play_Songlist(CurrentSong);
							break;
						}

						else if (CurrentSong != Videolist.front())
						{
							CurrentSong = Videolist[i - 1];
							Play_Songlist(CurrentSong);
							break;
						}
					}
				}

				i++;
			}
		}

		// close the directory... if closedir() fails it will return -1
		if (closedir(directory) == -1)
		{
			// exit with an error message and status if closedir() fails
			printf("Error closing directory.\n");
			return 1;
		}
	}

	bool TurnOnShuffle()
	{
		Shuffle = true;
		return Shuffle;
	}

	bool TurnOnRepeat()
	{
		Repeat = true;
		return Repeat;
	}

	void shuffle()
	{
		string temp;

		if (No_of_Songs > 1)
		{
			int i;
			//step through each index of the city name array
			for (i = 0; i < No_of_Songs - 1; i++)
			{
				//pick a random index (j) to swap it with
				//okay to pick same value as i
				int j = rand() % No_of_Songs; //random between 0 and 10
				temp = Songlist[j];
				Songlist[j] = Songlist[i];
				Songlist[i] = temp;
			}
		}

		else if (MP4_Files > 1)
		{
			int i;
			//step through each index of the city name array
			for (i = 0; i < MP4_Files - 1; i++)
			{
				//pick a random index (j) to swap it with
				//okay to pick same value as i
				int j = rand() % MP4_Files; //random between 0 and 10
				temp = Songlist[j];
				Songlist[j] = Songlist[i];
				Songlist[i] = temp;
			}
		}
	}

	int AddSongsFromFile()
	{
		// directory stream variable for accessing the directory
		DIR* directory;

		// will store pointer to each entry in the directory
		struct dirent* entry;

		// attempt to open the current working directory, opendir() returns NULL 
		// on failure
		directory = opendir("E:\\Music");

		// if opening the directory fails, exit with an error message and status
		if (directory == NULL)
		{
			printf("Error opening directory.\n");
			return 1;
		}

		// Read each entry in the directory with readdir() and store the pointer to 
		// the struct dirent into entry... when there are no more entries in the 
		// directory readdir() will return NULL and terminate the loop at that point.

		while ((entry = readdir(directory)) != NULL)
		{
			if (entry->d_type == DT_REG)
			{
				if (checkMP3(entry->d_name))
				{
					No_of_Songs++;
					Songlist.push_back(entry->d_name);

				}

				else if (checkMP4(entry->d_name))
				{
					MP4_Files++;
					Videolist.push_back(entry->d_name);
				}
			}
		}

		// close the directory... if closedir() fails it will return -1
		if (closedir(directory) == -1)
		{
			// exit with an error message and status if closedir() fails
			printf("Error closing directory.\n");
			return 1;
		}
	}

	string DisplayFile()
	{
		DIR* dir;
		struct dirent* ent;
		if ((dir = opendir("E:\\Music\\")) != NULL) 
		{
			/* print all the files and directories within directory */
			while ((ent = readdir(dir)) != NULL)
			{
				if (checkMP3(ent->d_name))
				{
					printf("%s\n", ent->d_name);
					return ent->d_name;

				}
			}
			closedir(dir);
		}
		else {
			/* could not open directory */
			perror("");
			exit(EXIT_FAILURE);
		}
	}

	bool Search(string N)
	{
		// directory stream variable for accessing the directory
		DIR* directory;

		// will store pointer to each entry in the directory
		struct dirent* entry;

		// attempt to open the current working directory, opendir() returns NULL 
		// on failure
		directory = opendir("E:\\Music");

		// if opening the directory fails, exit with an error message and status
		if (directory == NULL)
		{
			printf("Error opening directory.\n");
			return false;
		}

		string str_ = N + ".mp3";
		// Read each entry in the directory with readdir() and store the pointer to 
		// the struct dirent into entry... when there are no more entries in the 
		// directory readdir() will return NULL and terminate the loop at that point.

		int count = 0;

		while ((entry = readdir(directory)) != NULL)
		{
			if (entry->d_type == DT_REG)
			{
				if (str_ == entry->d_name)
				{
					cout << "File Found!" << endl;
					printf("File: %s\n", entry->d_name);
					count++;
					return true;
					break;
				}
			}
		}

		if (count != 1)
		{
			cout << "File not Found" << endl;
			return false;
		}

		// close the directory... if closedir() fails it will return -1
		if (closedir(directory) == -1)
		{
			// exit with an error message and status if closedir() fails
			printf("Error closing directory.\n");
			return false;
		}
	}

	bool checkMP3(char name[10000])
	{
		int o = 0;
		bool flag;
		while (name[o] != '\000' && o < 10000)
		{
			o++;
		}
		while (name[o] != '.' && o > 0)
		{
			o--;
		}

		if (name[o] == '.')
		{
			string s;
			while (name[o] != 0)
			{
				s += name[o];
				o++;
			}
			if (s == ".mp3")
			{
				return true;
			}
		}
		return false;
	}

	bool checkMP4(char name[10000])
	{
		int o = 0;
		bool flag;
		while (name[o] != '\000' && o < 10000)
		{
			o++;
		}
		while (name[o] != '.' && o > 0)
		{
			o--;
		}

		if (name[o] == '.')
		{
			string s;
			while (name[o] != 0)
			{
				s += name[o];
				o++;
			}
			if (s == ".mp4")
			{
				return true;
			}
		}
		return false;
	}
};

int Song::No_of_Songs = 0;
int Song::MP4_Files = 0;

class AudioPlayerV2 : public AudioPlayer, public Song
{
public:
	vector<string> playlist;
	string currentPlaylistName;
	string CurrentPlaylistSong;
	time_t SongPlayTimeSec, SongPlayTimeMin, SongTotalTimeSec, SongTotalTimeMin, SongRemSec, SongRemMin;
	static int Playlist_Songs;
	bool FileMode = true;
	bool PlaylistMode = false;
	bool Video = false;

	//CONSTRUCTORS
	AudioPlayerV2() : AudioPlayer()
	{
		currentPlaylistName = " ";
	}

	AudioPlayerV2(string MAN, string MON, bool PS, string CPN) : AudioPlayer(MAN, MON, PS)
	{
		currentPlaylistName = CPN;
	}

	//GETTERS
	string getCurrentPlaylistName()
	{
		return currentPlaylistName;
	}

	//SETTERS
	void setCurrentPlaylistName(string CPN)
	{
		currentPlaylistName = CPN;
	}

	//MEMBER FUNCTIONS

	void createNewPlaylist(string playlistName)
	{
		currentPlaylistName = playlistName;
	}

	void deletePlaylist()
	{
		currentPlaylistName = " ";
		playlist.clear();
	}

	int addSong()
	{
		string str = CurrentSong;

		DIR* directory;

		// will store pointer to each entry in the directory
		struct dirent* entry;

		// attempt to open the current working directory, opendir() returns NULL 
		// on failure
		directory = opendir("E:\\Music");

		// if opening the directory fails, exit with an error message and status
		if (directory == NULL)
		{
			printf("Error opening directory.\n");
			return 1;
		}

		string str_ = CurrentSong;
		// Read each entry in the directory with readdir() and store the pointer to 
		// the struct dirent into entry... when there are no more entries in the 
		// directory readdir() will return NULL and terminate the loop at that point.

		int count = 0;

		if (directory)
		{
			int i = 0;
			while ((entry = readdir(directory)) != NULL)
			{

				if (entry->d_type == DT_REG)
				{
					if (str_ == entry->d_name)
					{
						Playlist_Songs++;
						playlist.push_back(str_);
						cout << "File Found! Added to Playlist" << endl;
						printf("File: %s\n", entry->d_name);
						count++;
						break;
					}
				}
			}
		}

		if (count != 1)
		{
			cout << "File not Found" << endl;
		}

		// close the directory... if closedir() fails it will return -1
		if (closedir(directory) == -1)
		{
			// exit with an error message and status if closedir() fails
			printf("Error closing directory.\n");
			return 1;
		}

	}

	void ResumeSong_Playlist()
	{
		mciSendStringA("play mp3", NULL, 0, NULL);
	}

	void PlaySong_Playlist(string song)
	{
		for (int i = 0; i < Playlist_Songs; i++)
		{
			if (song == playlist[i])
			{
				string szCommand = "open \"E:\\Music\\" + playlist[i] + "\" type mpegvideo alias mp3 ";

				cout << szCommand << endl << endl;
				////open the audio file
				mciSendStringA(szCommand.c_str(), NULL, 0, NULL);

				CurrentPlaylistSong = playlist[i];
				mciSendStringA("play mp3", NULL, 0, NULL);
			}
		}
	}

	void PauseSong_Playlist()
	{
		mciSendStringA("pause mp3", NULL, 0, NULL);
	}

	void NextSong_Playlist()
	{
		mciSendStringA("close mp3", NULL, 0, NULL);

		if (Repeat == true)
		{
			PlaySong_Playlist(CurrentPlaylistSong);
		}


		else if (Shuffle = true)
		{
			string S = CurrentPlaylistSong;
			shufflePlaylist();
			CurrentPlaylistSong = S;
			Next_Song_Playlist();
		}


		else
		{
			Next_Song_Playlist();
		}
	}

	void PreviousSong_Playlist()
	{
		mciSendStringA("close mp3", NULL, 0, NULL);

		if (Repeat == true)
		{
			PlaySong_Playlist(CurrentPlaylistSong);
		}


		else if (Shuffle == true)
		{
			string S = CurrentPlaylistSong;
			shufflePlaylist();			
			CurrentPlaylistSong = S;
			Previous_Song_Playlist();
		}

		else
		{
			Previous_Song_Playlist();
		}
	}

	int Next_Song_Playlist()
	{
		// directory stream variable for accessing the directory
		DIR* directory;

		// will store pointer to each entry in the directory
		struct dirent* entry;

		// attempt to open the current working directory, opendir() returns NULL 
		// on failure
		directory = opendir("E:\\Music");

		// if opening the directory fails, exit with an error message and status
		if (directory == NULL)
		{
			printf("Error opening directory.\n");
			return 1;
		}

		// Read each entry in the directory with readdir() and store the pointer to 
		// the struct dirent into entry... when there are no more entries in the 
		// directory readdir() will return NULL and terminate the loop at that point.

		int i = 0;

		while ((entry = readdir(directory)) != NULL)
		{
			if (entry->d_type == DT_REG)
			{

				if (CurrentSong == playlist[i])
				{
					if (CurrentSong == playlist.back())
					{
						i = 0;
						CurrentSong = playlist[0];
						PlaySong_Playlist(CurrentSong);
						break;
					}

					else if (CurrentSong != playlist.back())
					{
						CurrentSong = playlist[i + 1];
						PlaySong_Playlist(CurrentSong);
						break;
					}
				}
				i++;
			}
		}

		// close the directory... if closedir() fails it will return -1
		if (closedir(directory) == -1)
		{
			// exit with an error message and status if closedir() fails
			printf("Error closing directory.\n");
			return 1;
		}
	}

	int Previous_Song_Playlist()
	{
		// directory stream variable for accessing the directory
		DIR* directory;

		// will store pointer to each entry in the directory
		struct dirent* entry;

		// attempt to open the current working directory, opendir() returns NULL 
		// on failure
		directory = opendir("E:\\Music");

		// if opening the directory fails, exit with an error message and status
		if (directory == NULL)
		{
			printf("Error opening directory.\n");
			return 1;
		}

		// Read each entry in the directory with readdir() and store the pointer to 
		// the struct dirent into entry... when there are no more entries in the 
		// directory readdir() will return NULL and terminate the loop at that point.

		int i = 0;

		while ((entry = readdir(directory)) != NULL)
		{
			if (entry->d_type == DT_REG)
			{
				if (CurrentSong == playlist[i])
				{
					if (CurrentSong == playlist.front())
					{
						CurrentSong = playlist.back();
						PlaySong_Playlist(CurrentSong);
						break;
					}

					else if (CurrentSong != playlist.front())
					{
						CurrentSong = playlist[i - 1];
						PlaySong_Playlist(CurrentSong);
						break;
					}
				}
				i++;
			}
		}

		// close the directory... if closedir() fails it will return -1
		if (closedir(directory) == -1)
		{
			// exit with an error message and status if closedir() fails
			printf("Error closing directory.\n");
			return 1;
		}
	}

	void removeSong()
	{
		for (int i = 0; i < playlist.size(); i++)
		{
			if (playlist[i] == CurrentPlaylistSong)
			{
				playlist[i]= "  ";
				playlist[i + 1] = playlist[i];
				break;
			}
		}
	}

	void displayPlaylist()
	{
		string song;
		char choice;

		cout << "Playlist: " << currentPlaylistName << endl;
		cout << "Number of songs: " << playlist.size() << endl;
		for (int i = 0; i < playlist.size(); i++)
		{
			cout << playlist[i] << endl;
		}

	retry:
		cout << "Do you want to play song:(Y/N) " << endl;
		cout << "Option: ";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			cout << "Which Song do you want to play: ";
			cin >> song;

			string str = song + ".mp3";

			PlaySong_Playlist(str);
		}

		else if (choice == 'N' || choice == 'n')
		{
		}

		else
		{
			goto retry;
		}
	}

	void shufflePlaylist()
	{
		string temp;

		if (Playlist_Songs > 1)
		{
			int i;
			//step through each index of the city name array
			for (i = 0; i < Playlist_Songs - 1; i++)
			{
				//pick a random index (j) to swap it with
				//okay to pick same value as i
				int j = rand() % Playlist_Songs; //random between 0 and 10
				temp = playlist[j];
				playlist[j] = playlist[i];
				playlist[i] = temp;
			}
		}
	}

	void savePlaylist()
	{
		string play = currentPlaylistName + ".txt";
		ofstream file;
		file.open(play);
		file << currentPlaylistName << endl;
		file << playlist.size() << endl;
		for (int i = 0; i < playlist.size(); i++)
		{
			file << playlist[i] << endl;
		}
		file.close();
	}

	void loadPlaylist()
	{
		string play = currentPlaylistName + ".txt";
		ifstream file;
		file.open(play);
		file >> currentPlaylistName;
		int size;
		file >> size;
		playlist.clear();
		for (int i = 0; i < size; i++)
		{
			string song;
			file >> song;
			playlist.push_back(song);
		}
		file.close();
	}

	bool searchPlaylist(string fileName)
	{
		fileName = fileName + ".mp3";

		for (int i = 0; i < playlist.size(); i++)
		{
			if (playlist[i] == fileName)
			{
				return true;
			}
		}
		return false;
	}
};

int AudioPlayerV2::Playlist_Songs = 0;