#include "IOManager.h"
#include "Map.h"
#include "Printer.h"
#include <fstream>


void IOManager::save(shared_ptr<Map> map, const string& path) {
	ofstream file(path);

	file << map->height() << endl << map->width() << endl;
	Printer::print(map, file);
}


shared_ptr<Map> IOManager::load(const string& path) {
	ifstream file(path);
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	string word;

	file >> word;
	const unsigned height = stoi(word);
	file >> word;
	const unsigned width = stoi(word);

	auto map = Map::make(width, height);

	for (unsigned i = 0; i < map->height(); ++i) {
		file >> word;

		for (unsigned j = 0; j < map->width(); ++j) {
			map->cell(j, i) = Cell::fromString(word[j]);
		}
	}

	return map;
}