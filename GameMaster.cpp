#include "GameMaster.h"
#include "Map.h"
#include <system_error>

shared_ptr<GameMaster> GameMaster::make(NextStateFunction isNeedLivenUp, NextStateFunction isNeedDie, shared_ptr<Map> map) {

	if (!isNeedLivenUp, isNeedDie) {
		throw logic_error("Can't create game master without main logic");
	}
	return shared_ptr<GameMaster>(new GameMaster(isNeedLivenUp, isNeedDie, map));
}


void GameMaster::setMap(shared_ptr<Map> map) {
	this->map = map,
	prevIterationMap = map;
}


GameMaster& GameMaster::next() {

	if (!isMapExists()) {
		throw logic_error("Can't iterate without map");
	}

	prevIterationMap = map->copy();

	for (unsigned i = 0; i < map->height(); ++i) {

		for (unsigned j = 0; j < map->width(); ++j) {
			updateCell(map, j, i);
		}
	}
}


const bool GameMaster::isStable() const {

	if (!isMapExists()) {
		return false;
	}

	return *map == *prevIterationMap;
}


GameMaster::GameMaster(NextStateFunction isNeedLivenUp, NextStateFunction isNeedDie, shared_ptr<Map> map):
	isNeedLivenUp(isNeedLivenUp),
	isNeedDie(isNeedDie),
	map(map),
	prevIterationMap(map) {
}


void GameMaster::updateCell(shared_ptr<Map> map, unsigned column, unsigned row) const {
	auto cell = map->cell(column, row);

	if (	(cell == Cell::State::ALIVE && isNeedDie(column, row, map)) ||
			isNeedLivenUp(column, row, map)) {
		cell.flip();
	}
}


const bool GameMaster::isMapExists() const {
	return map && prevIterationMap;
}