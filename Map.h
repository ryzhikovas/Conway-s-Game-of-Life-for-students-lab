#pragma once
#include <vector>
#include <memory>
#include "Cell.h"

using namespace std;

class Map {
private:
	vector< vector<Cell>> map;
	unsigned mapWidth;
	unsigned mapHeight;
public:
	static shared_ptr<Map> make(const unsigned mapWidth, const unsigned mapHeight);
	shared_ptr<Map> copy();

	const unsigned width() const;
	const unsigned height() const;
	const Cell& cell(const unsigned column, const unsigned row) const;
	Cell& cell(const unsigned column, const unsigned row);

	const bool operator==(const Map& right) const;
private:
	Map();
	Map& initialize(const unsigned mapWidth, const unsigned mapHeight);

	Map& operator=(const Map& right);
};

