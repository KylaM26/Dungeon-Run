#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "Player.h"

class GameSaver
{
public:
	GameSaver();

	void SaveGame(const Player&);
	bool overWriteSave(const std::string& path, const Player& player);

	~GameSaver();
};

