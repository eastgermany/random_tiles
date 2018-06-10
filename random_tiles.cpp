#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

//edg5000 -> edg5008

int main()
{

	using namespace std;

	cout << "Generates random flat terrain for FOnline Mapper.\n\n";

	string MapFileName;

	cout << "File name: ";
	cin >> MapFileName;

	MapFileName += ".fomap";

	fstream map_file;
	map_file.open(MapFileName, std::fstream::in | std::fstream::out | std::fstream::app); // Could set this to trunc

	unsigned int Width, Height, LowerLimit, UpperLimit, RandomSuffix;
	string TileFolder, TileRoot, FileSuffix;

	srand(time(NULL));

	cout << "\nMap width: ";
		cin >> Width;
	cout << "\nMap height: ";
		cin >> Height;
	cout << "\nTile folder [normally art\\tiles\\]: ";
		cin >> TileFolder;
	cout << "\nTile root [e.g. edg000X - where X is the random suffix]: ";
		cin >> TileRoot;
	cout << "\nLower limit: ";
		cin >> LowerLimit;
	cout << "\nUpper limit: ";
		cin >> UpperLimit;
	cout << "\nFile suffix [normally .frm]: ";
		cin >> FileSuffix;
	cout << "\n";

	for (unsigned int i = 0; i <= Width - 2; i += 2)
	{
		for (unsigned int j = 0; j <= Height - 2; j+= 2 )
		{

			map_file << "tile\t" << j << "\t" << i << "\t";

			RandomSuffix = rand() % (UpperLimit - LowerLimit + 1) + LowerLimit;

			map_file << TileFolder << TileRoot << RandomSuffix << FileSuffix << endl;

		}

	}

	map_file.close();
	return 0;
}

