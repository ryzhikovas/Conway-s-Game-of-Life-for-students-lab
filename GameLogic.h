#pragma once
#include <memory>
#include <functional>

using std::shared_ptr;
class Map;

class GameLogic {
public:
	using NextStateFunction = std::function<bool(unsigned column, unsigned row, shared_ptr<Map> map)>;
public:
	static const unsigned aliveNeighborsCount(unsigned column, unsigned row, shared_ptr<Map> map);

	static const bool isNeedLivenUp(unsigned column, unsigned row, shared_ptr<Map> map);

	static const bool isNeedDie(unsigned column, unsigned row, shared_ptr<Map> map);
};

