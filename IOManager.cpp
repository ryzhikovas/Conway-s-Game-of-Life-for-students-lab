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
	string word;

	file >> word;
	const unsigned height = stoi(word);
	file >> word;
	const unsigned width = stoi(word);

	auto map = Map::make(width, height);

	for (unsigned i = 0; i < map->height(); ++i) {

		for (unsigned j = 0; j < map->width(); ++j) {
			file >> word;
			map->cell(j, i) = Cell::fromString(word);
		}
	}

	return map;
}