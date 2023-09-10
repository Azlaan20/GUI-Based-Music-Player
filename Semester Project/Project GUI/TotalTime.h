#include <iostream>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include <ctime>
#include<string>
using namespace std;

const int Bit_Rates[16] = { 0, 32000, 40000, 48000, 56000, 64000, 80000, 96000,112000, 128000, 160000, 192000, 224000, 256000, 320000, 0 };

int rev(int i)
{
	int to_return = 0;

	to_return |= ((i & 0x000000FF) << 24);

	to_return |= ((i & 0x0000FF00) << 8);

	to_return |= ((i & 0x00FF0000) >> 8);

	to_return |= ((i & 0xFF000000) >> 24);

	return to_return;
}

int Sync_safe(int i)
{

	int to_return = 0;

	to_return |= ((i & 0x7F000000) >> 24);

	to_return |= ((i & 0x007F0000) >> 9);

	to_return |= ((i & 0x00007F00) << 6);

	to_return |= ((i & 0x0000007F) << 21);

	return to_return;
}

int id3v1siz(ifstream& infile)
{
	streampos savePos = infile.tellg();

	infile.seekg(0, ios::end);

	streampos length = infile.tellg() - (streampos)128;

	infile.seekg(length);

	int siz;

	char buffer[3] = { 0 };

	infile.read(buffer, 3);

	if (buffer[0] == 'T' && buffer[1] == 'A' && buffer[2] == 'G')

		siz = 128;

	else
	{
		siz = 0;

		infile.seekg(savePos);

		return siz;
	}

}

int id3v2siz(ifstream& infile)
{
	streampos savePos = infile.tellg();

	infile.seekg(0, ios::beg);

	char buffer[6] = { 0 };

	infile.read(buffer, 6);

	if (buffer[0] != 'I' || buffer[1] != 'D' || buffer[2] != '3')
	{

		infile.seekg(savePos);

		return 0;
	}

	int siz = 0;

	infile.read(reinterpret_cast<char*>(&siz), sizeof(siz));

	siz = Sync_safe(siz);

	infile.seekg(savePos);

	return siz + 10;
}