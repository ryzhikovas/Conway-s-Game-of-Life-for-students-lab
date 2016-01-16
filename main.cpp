#include "GameMaster.h"
#include "IOManager.h"
#include "map.h"
#include "Printer.h"
#include <iostream>


int main() {
	auto aliveNeighborsCount = [](unsigned column, unsigned row, shared_ptr<Map> map) -> unsigned {
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

				if (x == column && y == row) continue;

				if (map->cell(x, y) == Cell::State::ALIVE) {
					aliveNeighbors++;
				}
			}
		}
		return aliveNeighbors;
	};

	NextStateFunction isNeedLivenUp = [aliveNeighborsCount](unsigned column, unsigned row, shared_ptr<Map> map) -> bool {
		return aliveNeighborsCount(column, row, map) == 3;
	};

	NextStateFunction isNeedDie = [aliveNeighborsCount](unsigned column, unsigned row, shared_ptr<Map> map) -> bool {
		const auto alivesCount = aliveNeighborsCount(column, row, map);
		return alivesCount < 2 || alivesCount > 3;
	};


	auto map = IOManager::load("D://map.txt");

	auto gameMaster = GameMaster::make(isNeedLivenUp, isNeedDie, map);

	do {
		Printer::print(gameMaster->getMap(), cout);
		getchar();
	} while (!gameMaster->next().isStable());
}

