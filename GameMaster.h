#pragma once
#include <memory>
#include "Cell.h"
#include "GameLogic.h"

using namespace std;
class Map;

class GameMaster {
private:
	GameLogic::NextStateFunction isNeedLivenUp;
	GameLogic::NextStateFunction isNeedDie;

	shared_ptr<Map> map;
	shared_ptr<Map> prevIterationMap;
public:
	static shared_ptr<GameMaster> make(GameLogic::NextStateFunction isNeedLivenUp, GameLogic::NextStateFunction isNeedDie,
										shared_ptr<Map> map = shared_ptr<Map>());

	shared_ptr<Map> getMap() const;
	void setMap(shared_ptr<Map> map);
	GameMaster& next();

	const bool isStable() const;
private:
	GameMaster() {}
	GameMaster(GameLogic::NextStateFunction isNeedLivenUp, GameLogic::NextStateFunction isNeedDie, shared_ptr<Map> map);

	Cell updateCell(shared_ptr<Map> map, unsigned column, unsigned row) const;
private:
	const bool isMapExists() const;
};

