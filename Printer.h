#pragma once
#include <memory>
class Map;

class Printer {
public:
	static void print(std::shared_ptr<Map> map, std::ostream& stream);
};

