#pragma once
#include <functional>
#include <memory>
#include "Cell.h"

using namespace std;
class Map;

using NextStateFunction = function <bool(unsigned column, unsigned row, shared_ptr<Map> map)>;

class GameMaster {
private:
	NextStateFunction isNeedLivenUp;
	NextStateFunction isNeedDie;

	shared_ptr<Map> map;
	shared_ptr<Map> prevIterationMap;
public:
	static shared_ptr<GameMaster> make(NextStateFunction isNeedLivenUp, NextStateFunction isNeedDie,
										shared_ptr<Map> map = shared_ptr<Map>());

	shared_ptr<Map> getMap() const;
	void setMap(shared_ptr<Map> map);
	GameMaster& next();

	const bool isStable() const;
private:
	GameMaster() {}
	GameMaster(NextStateFunction isNeedLivenUp, NextStateFunction isNeedDie, shared_ptr<Map> map);

	Cell updateCell(shared_ptr<Map> map, unsigned column, unsigned row) const;
private:
	const bool isMapExists() const;
};

