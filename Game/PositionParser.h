#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "SFML/Graphics.hpp"

struct Coordinates {
	int x, y;
};

class PositionParser {
private:
	PositionParser() {}
	PositionParser(const PositionParser&) {}
	PositionParser operator= (const PositionParser&) {}

	int StringToInteger(std::string str) {
		return atoi(str.c_str());
	}
public:
	static PositionParser& Instance() {
		static PositionParser instance;
		return instance;
	}

	std::vector<sf::Vector2i> ReadFile(const char* fileName) {
		std::ifstream file;

		file.open(fileName);

		if (!file.is_open()) {
			std::cout << "Fail to open file for position reading: " << fileName << std::endl;
			return std::vector<sf::Vector2i>();
		}

		std::vector<std::string> positionSTR;
		std::vector<sf::Vector2i> positions;

		while (!file.eof()) {
			std::string s;
			while (file >> s) {
				positionSTR.push_back(s);
			}
		}

		for(int index = 0; index < positionSTR.size(); index++) {
			std::string xCoor, yCoor;
			std::stringstream ss(positionSTR.at(index));
			bool didFindComma = false;
			char i;

			while (ss >> i) {
				if (!didFindComma) {
					xCoor.push_back(i);
				} else {
					yCoor.push_back(i);
				}

				if (ss.peek() == ',') {
					ss.ignore();
					didFindComma = true;
				}
			}

			positions.push_back(sf::Vector2i(StringToInteger(xCoor), StringToInteger(yCoor)));
		}

		file.close();

		return positions;
	}
};

