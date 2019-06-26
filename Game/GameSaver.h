#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "Player.h"

class GameSaver
{
private:
	std::string path;
public:
	GameSaver() {
		path = "saves/Saves.txt";
	};

	void SaveGame(const Player&);
	bool overWriteSave(const Player& player);
	std::string format(std::string name) {
		std::string replstr = "";
		for (auto& letter : name) {
			if (letter == ' ') {
				replstr.push_back('_');
			}
			else {
				replstr.push_back(letter);
			}
		}
		return replstr;
	}
	std::string deformat(std::string name) {
		std::string replstr = "";
		for (auto& letter : name) {
			if (letter == '_') {
				replstr.push_back(' ');
			}
			else {
				replstr.push_back(letter);
			}
		}
		return replstr;
	}
	void LoadGame(const Player& player);

	~GameSaver();
};


