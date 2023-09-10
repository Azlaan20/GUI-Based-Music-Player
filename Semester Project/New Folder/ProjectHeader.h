#pragma once
#include <iostream>
#include <dirent.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;

string USBPath = "C:/Users/hp/Desktop/Storage Media/USB";
string CDPath = "C:/Users/hp/Desktop/Storage Media/CD"; //pre-defined directory paths for CD& USB

class AudioPlayer
{
protected:
	string ManufacturerName;
	int ModelNum;
	static int MN;
public:
	AudioPlayer()
	{
		ModelNum = MN;
		MN++;
	}
	virtual bool PlayAudio() = 0;
};

int AudioPlayer::MN = 00001;

class StorageMedia
{
protected:
	int Status; //1 = Mounted, 0 = Unmounted
public:
	int SetStatus()
	{
		cout << "Is the media mounted? 1 = Yes, 0 = No" << endl;
		cin >> Status;
		return Status;
	}
	virtual int Check() = 0;
};

class CD : public StorageMedia
{
protected:
	int Type;
public:
	CD()
	{
		cout << "Please enter the type of your CD. MP3 (1), MP4 (2), BluRay (3)" <<
			endl;
		cin >> Type;
	}
	int Check()
	{
		if (Type != 1)
		{
			cout << "ERROR - CD MUST BE OF TYPE MP3" << endl;
			return 0;
		}
		else
		{
			return 1;
		}
	}
};

class USB : public StorageMedia
{
protected:
	int Size;
public:
	USB()
	{
		cout << "Please enter the size of your USB" << endl;
		cin >> Size;
	}
	int Check()
	{
		if (Size > 16)
		{
			cout << "ERROR - USB MUST BE 16GB OR LESS" << endl;
			return 0;
		}
		else
		{
			return 1;
		}
	}
};

class InCarAudio : public AudioPlayer
{
protected:
	StorageMedia* Media;
	bool Power; //Enter = On, ESC = Off
	bool MountStat, Compatibality;
	int MediaType, ac, SN, ListCount;
	string* A, SongChosen;
	int* ShuffledPL;
	fstream FileHandle;
public:
	vector <vector<string>> List;
	string Display = "";
	int ADisplayCount, PLDisplayCount, PlayCount, PLChoice;
	bool EndOfFile, FromPL, Shuffle, PLFinish;
	InCarAudio() //constructor; initialising everything
	{
		ac = 0;
		Power = false;
		MountStat = false;
		Compatibality = false;
		MediaType = 0;
		A = NULL;
		Media = NULL;
		ShuffledPL = NULL;
		SN = 0;
		ADisplayCount = 2;
		PLDisplayCount = 1;
		PlayCount = 2;
		EndOfFile = false;
		FromPL = false;
		Shuffle = false;
		PLChoice = NULL;
		ListCount = 0;
		PLFinish = false;
	}

	bool ChangePower()
	{
		if (Power == false)
		{
			Power = true;
		}
		else if (Power == true)
		{
			Power = false;
		}

		return Power;
	}

	void SelectMedia(int x)
	{
		if (Power)
		{
			MediaType = x;

			if (MediaType == 1)
			{
				Media = new CD();
			}
			else if (MediaType == 2)
			{
				Media = new USB();
			}
		}
	}

	bool CheckCompat()
	{
		Compatibality = ((*Media).Check());
		return Compatibality;
	}

	bool CheckMount()
	{
		MountStat = (*Media).SetStatus();
		return MountStat;
	}

	bool PlayAudio()
	{
		bool x = false;
		int Index, Count = 0, input;
		string FullPath, CS;

		if (MediaType == 1)
		{
			FullPath = CDPath + "\\" + SongChosen;
		}
		else
		{
			FullPath = USBPath + "\\" + SongChosen;
		}

		if (PLFinish == false)
		{
			FullPath = FullPath.c_str();
			wstring stemp = wstring(FullPath.begin(), FullPath.end());
			LPCWSTR sw = stemp.c_str();

			x = PlaySound((sw), NULL, SND_FILENAME | SND_ASYNC);
			PlayCount++;
		}

		return x;
	}

	void StopSong()
	{
		PlaySound(NULL, 0, 0);
	}

	string DisplayTitle()
	{
		if ((MountStat == 1) && (Power == 1))
		{
			string CurrentSong;
			char CL;
			Display = "";
			int Count = NULL;
			int Size = sizeof(ShuffledPL);

			if (FromPL == true)
			{
				if (Shuffle == true)
				{
					if ((PLDisplayCount + 1) == Size)
					{
						PLFinish = true;
					}
				}
				else if (Shuffle == false)
				{
					if (PLDisplayCount == List[PLChoice].size())
					{
						PLFinish = true;
					}
				}
			}

			if (FromPL == false)
			{
				if (ADisplayCount < ac)
				{
					CurrentSong = A[ADisplayCount];
					SongChosen = CurrentSong;
					if ((CurrentSong != ".") && (CurrentSong != ".."))
					{
						SN++;
						cout << (SN) << ". ";
						int j = 0;
						do
						{
							CL = CurrentSong[j];
							if ((int(CL) != 95) && (int(CL) != 46))
							{
								Display = Display + CL;
							}
							else if (int(CL) == 95)
							{
								Display = Display + " ";
							}
							else if (int(CL) == 46)
							{
								Display = Display + "";
							}
							j++;
						} while ((j < strlen(CurrentSong.c_str())) && (int(CL) != 46));
						ADisplayCount++;
					}
				}
				else
				{
					Display = "NO MORE SONGS";
					EndOfFile = true;
				}
			}
			else if (FromPL == true)
			{
				if (PLFinish == false)
				{
					if (Shuffle == true)
					{
						Count = ShuffledPL[PLDisplayCount];
					}
					else if (Shuffle == false)
					{
						Count = PLDisplayCount;
					}

					CurrentSong = List[PLChoice][Count];
					SongChosen = CurrentSong;
					if ((CurrentSong != ".") && (CurrentSong != ".."))
					{
						SN++;
						cout << (SN) << ". ";
						int j = 0;
						do
						{
							CL = CurrentSong[j];
							if ((int(CL) != 95) && (int(CL) != 46))
							{
								Display = Display + CL;
							}
							else if (int(CL) == 95)
							{
								Display = Display + " ";
							}
							else if (int(CL) == 46)
							{
								cout << "";
							}
							j++;
						} while ((j < strlen(CurrentSong.c_str())) && (int(CL) != 46));
						PLDisplayCount++;
					}
				}
				else
				{
					Display = "END OF PLAYLIST";
				}
			}
			cout << Display << endl;
			return Display;
		}
	}

	void TitleToArray() //TitleToVector
	{
		if ((MountStat == 1) && (Power == 1))
		{
			struct dirent* d;
			DIR* dir;
			int c = 0;
			string path;

			if (MediaType == 1)
			{
				path = CDPath;
			}
			else if (MediaType == 2)
			{
				path = USBPath;
			}

			dir = opendir(path.c_str());
			if (dir != NULL)
			{
				for (d = readdir(dir); d != NULL; d = readdir(dir))
				{
					c++;
				}
				closedir(dir);
				dir = opendir(path.c_str());
				A = new string[c + 1];
				for (d = readdir(dir); d != NULL; d = readdir(dir))
				{
					A[ac] = d->d_name;
					ac++;
				}
				closedir(dir);
			}
			else
			{
				cout << "NO FILE IN DIRECTORY" << endl;
			}
		}
	}

	void GetDetails()
	{
		cout << "Manufacturer Name: " << ManufacturerName << endl;
		cout << "Model Number: " << ModelNum << endl;
	}

	void DisplayASongs()
	{
		string Song, Print;
		char CL;
		for (int i = 2; i < ac; i++)
		{
			Song = A[i];
			cout << i - 1 << ". ";
			Print = "";

			int j = 0;
			do
			{
				CL = Song[j];
				if ((int(CL) != 95) && (int(CL) != 46))
				{
					Print = Print + CL;
				}
				else if (int(CL) == 95)
				{
					Print = Print + " ";
				}
				else if (int(CL) == 46)
				{
					Print = Print + "";
				}
				j++;
			} while ((j < strlen(Song.c_str())) && (int(CL) != 46));

			cout << Print << endl;
		}
	}
};

class AudioPlayerv2 : public InCarAudio
{
public:
	void CreatePlayList(string PLName)
	{
		string PlayListName = PLName;
		vector <string> PlayList;

		PlayList.push_back(PlayListName); //0th index of each playlist will be the name of the playlist chosen by the user at runtime

		List.push_back(PlayList);
		ListCount++;
	}

	string DisplayPlayLists()
	{
		string GUIDisplay = "";
		
		for (int i = 0; i < List.size(); i++)
		{
			GUIDisplay =  GUIDisplay + to_string(i + 1) + ". " + List[i][0] + " "; //will display the name of each playlist
		}
		return GUIDisplay;
	}

	void AddSong(int x)
	{
		int SChoice, Break;

		DisplayPlayLists();
		PLChoice = x;
		PLChoice = PLChoice - 1; //to attain the real index of the chosen playlist

		for (int i = 2; i < ac; i++)
		{
			cout << i - 1 << ". " << A[i] << endl; //displays the songs from the chosen media
		}

		do
		{
			cout << "Which song would you like to add to your playlist?" << endl;
			cin >> SChoice;
			SChoice = SChoice + 1; //to attain the real index of the chosen song

			List[PLChoice].push_back(A[SChoice]); // add chosen song to the chosen playlist

			cout << "Would you like to add another song?" << endl;
			cin >> Break;

		} while (Break != 0);
	}

	void DisplayPlayListSongs()
	{
		for (int i = 1; i < List[PLChoice].size(); i++)
		{
			cout << i << ". " << List[PLChoice][i] << endl;
		}
	}

	void DeleteSong()
	{
		int SChoice, Break;

		DisplayPlayLists();

		cout << "From which playlist would you like to delete a song?" << endl;
		cin >> PLChoice;
		PLChoice = PLChoice - 1;

		DisplayPlayListSongs();

		do
		{
			cout << "Which song would you like to delete?" << endl;
			cin >> SChoice;

			vector<string>::iterator ptr = List[PLChoice].begin();

			ptr = ptr + SChoice;

			List[PLChoice].erase(ptr);

			cout << "Would you like to delete another song?" << endl;
			cin >> Break;
		} while (Break != 0);

		DisplayPlayListSongs();
	}

	void ShuffleIndexes()
	{
		string SongPicked;
		bool Check = false; //flag to check whether a generated random number already exists or not
		int SizeOfPL, RandomNum, Choice;

		cout << "Do you want to shuffle?" << endl;
		cin >> Choice;

		if (Choice == 1)
		{
			Shuffle = true;
			PLDisplayCount--;
		}

		DisplayPlayLists();
		cout << "Which playlist would you like to shuffle?" << endl;
		cin >> PLChoice;
		PLChoice = PLChoice - 1;
		SizeOfPL = List[PLChoice].size();
		SizeOfPL = SizeOfPL - 1;

		ShuffledPL = new int[SizeOfPL];

		srand(time(0));

		for (int i = 0; i < (SizeOfPL); i++)
		{
			RandomNum = (rand() % (SizeOfPL)) + 1;

			if (RandomNum == SizeOfPL)
			{
				RandomNum = (rand() % (SizeOfPL)) + 1;
			}

			if (i != 0)
			{
				do
				{
					for (int j = 0; j < i; j++)
					{
						if (RandomNum != ShuffledPL[j])
						{
							Check = true;
						}
						else
						{
							Check = false;
							RandomNum = (rand() % SizeOfPL) + 1;

							if (RandomNum == SizeOfPL)
							{
								RandomNum = (rand() % (SizeOfPL)) + 1;
							}

							break;
						}
					}
				} while (Check != true);
			}

			ShuffledPL[i] = RandomNum; //stores the shuffled indexes in an array
		}
	}

	void PlayPL()
	{
		FromPL = true;
	}

	void SearchSong()
	{
		int Input;
		DisplayASongs();

		cout << "Which song would you like to play?" << endl;
		cin >> Input;

		SongChosen = A[Input + 1];

		cout << endl << "NOW PLAYING: ";
		int i = 0;
		do
		{
			cout << SongChosen[i];
			i++;
		} while (int(SongChosen[i] != 46) && i < strlen(SongChosen.c_str()));
		cout << endl;

		PlayAudio();
	}

	void SaveToFile()
	{
		FileHandle.open("PlayLists.text", ios::out | ios::app);

		for (int i = 0; i < List.size(); i++)
		{
			FileHandle << "PLAYLIST NAME: " << List[i][0] << endl;
			for (int j = 1; j < List[i].size(); j++)
			{
				FileHandle << j << ". ";
				int n = 0;
				do
				{
					FileHandle << List[i][j][n];
					n++;
				} while ((n < strlen(List[i][j].c_str()) && (int(List[i][j][n]) != 46)));
				FileHandle << endl;
			}
			FileHandle << endl << endl;
		}
	}

	//friend class InCarAudio;
};


/*
int main()
{
	AudioPlayerv2 Obj1;
	int input, i = 0;

	Obj1.ChangePower();

	Obj1.SelectMedia();
	Obj1.CheckCompat();
	Obj1.CheckMount();

	Obj1.TitleToArray();
	system("cls");

	do
	{
		cout << "Enter 1 to create a playlist, 2 to search for a song" << endl;
		cin >> input;

		if (input == 1)
		{
			Obj1.CreatePlayList();
			Obj1.AddSong();

			cout << "Do you want to delete a song?" << endl;
			cin >> input;
			if (input == 1)
			{
				Obj1.DeleteSong();
			}
		}
		else if (input == 2)
		{
			Obj1.SearchSong();
		}
	} while (input != 0);

	Obj1.SaveToFile();

	system("cls");

	Obj1.ShuffleIndexes();
	Obj1.PlayPL();
	while (Obj1.PLFinish == false)
	{
		Obj1.DisplayTitle();
		if (!(Obj1.EndOfFile))
		{
			Obj1.PlayAudio();
		}
	}
	return 0;
}
*/