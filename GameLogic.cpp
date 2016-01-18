#include "GameLogic.h"
#include "Map.h"


const unsigned GameLogic::aliveNeighborsCount(unsigned column, unsigned row, std::shared_ptr<Map> map) {
	unsigned xIndex[] = { column, column - 1, column + 1 };
	unsigned yIndex[] = { row, row - 1, row + 1 };

	for (auto& x : xIndex) {
		if (x == -1) {
			x = map->width() - 1;
		}
		else if (x == map->width()) {
			x = 0;
		}
	}

	for (auto& y : yIndex) {
		if (y == -1) {
			y = map->height() - 1;
		}
		else if (y == map->height()) {
			y = 0;
		}
	}

	unsigned aliveNeighbors(0);

	for (const auto y : yIndex) {

		for (const auto x : xIndex) {

			if (map->cell(x, y) == Cell::State::ALIVE) {
				aliveNeighbors++;
			}
		}
	}
	return aliveNeighbors;
};


const bool GameLogic::isNeedLivenUp(unsigned column, unsigned row, shared_ptr<Map> map) {
	return aliveNeighborsCount(column, row, map) == 3;
};


const bool GameLogic::isNeedDie(unsigned column, unsigned row, shared_ptr<Map> map) {
	const auto alivesCount = aliveNeighborsCount(column, row, map);
	return alivesCount < 2 || alivesCount >= 3;
};