#include "Map.h"
#include <string>
#include <algorithm>

shared_ptr<Map> Map::make(const unsigned mapWidth, const unsigned mapHeight) {

	if (!mapWidth || !mapHeight) {
		throw logic_error("Can't create empty map");
	}

	try {
		auto map = shared_ptr<Map>(new Map());
		map->initialize(mapWidth, mapHeight);
		return map;
	} catch (bad_alloc ex) {
		throw runtime_error("Can't allocate memory for map " + to_string(mapHeight) + " x " + to_string(mapWidth));
	}
}


shared_ptr<Map> Map::copy() {
	auto map = shared_ptr<Map>(new Map());
	*map = *this;
	return map;
}


Map::Map():
	mapHeight(0),
	mapWidth(0) {
}


Map& Map::initialize(const unsigned mapWidth, const unsigned mapHeight) {
	map.resize(mapHeight, vector<Cell>(mapWidth));	// Build mapHeight x mapWidth matrix of dead cell

	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;
	return *this;
}


const unsigned Map::width() const {
	return mapWidth;
}


const unsigned Map::height() const {
	return mapWidth;
}


const Cell& Map::cell(const unsigned column, const unsigned row) const {
	// This is hack, but safe hack
	return const_cast<Map*>(this)->cell(column, row);
}


Cell& Map::cell(const unsigned column, const unsigned row) {
	try {
		return map.at(row).at(column);
	}
	catch (out_of_range ex) {
		throw out_of_range("Invalid cell index access: row " + to_string(row) + " row " + to_string(column));
	}
}


const bool Map::operator==(const Map& right) const {
	return equal(map.begin(), map.end(), right.map.begin(),
		[](auto lineA, auto lineB) -> bool {
		return equal(lineA.begin(), lineA.end(), lineB.begin());
	});
}


Map& Map::operator=(const Map& right) {
	this->map = right.map;
	this->mapHeight = right.mapHeight;
	this->mapWidth = right.mapWidth;
	return *this;
}