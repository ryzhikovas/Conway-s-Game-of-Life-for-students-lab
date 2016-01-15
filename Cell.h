#pragma once
#include <string>


class Cell {
public:
	enum class State : int {
		DEAD,
		ALIVE
	};
private:
	State state;
public:
	Cell();
	Cell(const State state);

	const bool operator ==(const State state) const;
	operator bool() const;
	const State getState() const;

	Cell& flip();
	Cell& setState(const State state);

	std::string toString() const;
	static Cell fromString(const std::string& line);
};
