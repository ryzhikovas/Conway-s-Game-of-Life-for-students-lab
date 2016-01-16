#include "Cell.h"

Cell::Cell()
	:state(State::DEAD) {}


Cell::Cell(const State state)
	:state(state) {}


const bool Cell::operator==(const State state) const {
	return this->state == state;
}


const Cell::State Cell::getState() const {
	return state;
}


Cell& Cell::flip() {

	if (state == State::DEAD) {
		state = State::ALIVE;
	} else {
		state = State::DEAD;
	}
	return *this;
}


Cell& Cell::setState(const State state) {
	this->state = state;
	return *this;
}


Cell::operator bool() const {
	return state == State::ALIVE;
}


std::string Cell::toString() const {
	std::string result;

	if (state == State::DEAD) {
		result = "-";
	}
	else {
		result = "+";
	}
	return result;
}


Cell Cell::fromString(const std::string& line) {
	Cell result;

	if (line == "-") {
		result = State::DEAD;
	} else if (line == "+") {
		result = State::ALIVE;
	} else {
		throw std::logic_error("Invalid map file format");
	}
	return result;
}
