#include "Printer.h"
#include "Map.h"
#include <iostream>

void Printer::print(std::shared_ptr<Map> map, std::ostream& stream) {

	for (unsigned i = 0; i < map->height(); ++i) {

		for (unsigned j = 0; j < map->width(); ++j) {
			stream << " " << map->cell(j, i).toString() << " ";
		}
		stream << std::endl;
	}
	stream << std::endl;
}