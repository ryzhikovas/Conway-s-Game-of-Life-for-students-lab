#include "GameMaster.h"
#include "GameLogic.h"
#include "IOManager.h"
#include "Printer.h"
#include <fstream>
#include <iostream>

#include "Map.h"
int main() {
	shared_ptr<Map> map;
	cout << "Please specify the path to map file" << endl;
	string filePath;
	cin >> filePath;

	try {
		map = IOManager::load(filePath);
		auto gameMaster = GameMaster::make(GameLogic::isNeedLivenUp, GameLogic::isNeedDie, map);

		do {
			Printer::print(gameMaster->getMap(), cout);
			getchar();
		} while (!gameMaster->next().isStable());

	} catch (ifstream::failure ex) {
		cerr << "Bad file path or file format" << endl << ex.what();
	} catch (exception ex) {
		cerr << "Unexpected exception. This is a bad error processing. Don't do that. Good luck" << endl << ex.what();
	}
	cout << endl << "Press any key" << endl;
	getchar();
}

