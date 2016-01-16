#pragma once
#include <string>
#include <memory>

using namespace std;
class Map;

class IOManager {
public:
	static void save(shared_ptr<Map> map, const string& path);
	static shared_ptr<Map> load(const string& path);
};

