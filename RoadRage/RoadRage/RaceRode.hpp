#ifndef RaceRoad

#include "Player.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <Windows.h>
#include <wincon.h>

using namespace std;

class RaceRoad{
	vector <vector<unsigned char>> road;
	unsigned short vert;
	unsigned short hori;
	Player* player;

	bool isHit();
	vector <vector<unsigned char>> generateRoad(const int& difficulty);
	void represent();
	
  public:
	RaceRoad(/*Player* player*/);
	~RaceRoad();
	void play();
	void roadStep();
	void moveCar(const short& direction);
	
};

#endif // !RaceRoad