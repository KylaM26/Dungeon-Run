#include "GameSaver.h"



GameSaver::GameSaver()
{
}

void GameSaver::SaveGame(const Player& player)
{
	std::string path = "Saves/Saves.txt";

	if (GameSaver::overWriteSave(path, player.name)) return void(); // exit function

	if (std::filesystem::exists(path)) {

		std::ofstream SaveFile; //fstream is a raii object so it closes after it leaves the scope

		//open files in append mode
		SaveFile.open(path, std::ios_base::app);

		if (SaveFile.is_open())
		{
			SaveFile << player.name << " " << player.health << " " << 
				player.stamina << " " << player.level << std::endl; //flush the stream
			std::cout << "Game Saved\n";
		}
		else
		{
			std::cerr << "Fail\n";
		}
	}
	else
	{
		std::ofstream SaveFile(path); 

		if(SaveFile.is_open())
		{
			SaveFile << player.name << " " << player.health << " " <<
				player.stamina << " " << player.level << std::endl; //flush the stream
			std::cout << "Game Saved\n";
		}
		else
		{
			std::cerr << "Fail\n";
		}
	}
}

bool GameSaver::overWriteSave(const std::string& path, const Player& player)
{
	std::ifstream inFile(path); //fstream is a raii object so it closes after it leaves the scope

	std::vector<std::string> list_names;
	std::vector<std::string> file_contents;

	std::string line;

	//find names that match and store in vector
	while (std::getline(inFile,line))
	{
		file_contents.push_back(line);

		std::string parsed_name = "";

		// The name should be the first word in the file
		// stops adding letters if a space is reached
		for (size_t letter = 0; letter < line.size(); ++letter) {
			if (line.at(letter) == ' ') break;
			parsed_name += line.at(letter);
		}

		if (parsed_name == player.name)
		{
			list_names.push_back(line);
			parsed_name = "";
		}
	}

	std::cout << "\n";

	//show list of saved games
	int count = 0;
	for (const auto& names : list_names)
	{
		std::cout << ++count << " " << names << "\n";
	}

	std::cin.clear();
	std::cin.ignore(0, ' ');

	std::string response;
	std::cout << "Would You like to add a new save or overwrite one\n";
	std::getline(std::cin,response);

	if (response != "overwrite")
	{
		return false;
	}

	int choice;
	std::cout << "Enter the number you would like to overwrite\n";
	std::cin >> choice;

	if (choice > static_cast<int>(list_names.size()) or choice < 0 or std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1, ' ');
		std::cout << "Enter the number you would like to overwrite\n";
		std::cin >> choice;
	}

	std::string replace = list_names[choice - 1];

	//remove save 
	// it is an iterator, think of it as a index of a vector
	auto it = std::find(file_contents.begin(), file_contents.end(), replace);

	if (it != file_contents.end())
	{
		file_contents.erase(it);
	}

	std::ofstream file(path);

	if (file.is_open())
	{
		for (const auto& line : file_contents)
		{
			file << line << "\n";
		}

		std::cout << std::endl;

		std::cout << "Game Saved";
	}
	else
	{
		std::cerr << "Error\n";
	}

	return true;
}


GameSaver::~GameSaver()
{
}
