#include "RaceRode.hpp"

RaceRoad::RaceRoad(/*Player* player*/){
	/*RaceRoad::player = player;*/
	road=generateRoad(1);
	hori=1;vert=0;
}

RaceRoad::~RaceRoad(){
	/*delete player;*/
}

void RaceRoad::play(){
	//RaceRoad myroad(Player p());
	RaceRoad(/*new Player()*/);
	represent();
	short direction;
	char ispressed(1);

	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD NumInputs = 0;
    DWORD InputsRead = 0;
    bool running = true;
    INPUT_RECORD irInput;
    GetNumberOfConsoleInputEvents(hInput, &NumInputs);
    while(running){
		direction=0;
        ReadConsoleInput(hInput, &irInput, 1, &InputsRead);
        switch(irInput.Event.KeyEvent.wVirtualKeyCode){
            case VK_ESCAPE:
                running = false;
            break;
			case VK_LEFT:
			case VK_NUMPAD4:
				direction=-1;
				ispressed*=-1;
			break;
			case VK_RIGHT:
			case VK_NUMPAD6:
				direction=1;
				ispressed*=-1;
			break;
		}
		if(ispressed>0)moveCar(direction);
		if(isHit())cout<<"HALAL"<<endl;
		represent();
		Sleep(1000);
		
    }
}

void RaceRoad::represent(){
	cout<<endl;
	for(unsigned short i(9);i<=9;i--){
		for(short j(0);j<3;j++){
			if(j==hori && i==vert){
				cout << 'A';
			}else{
				cout << road[i][j];
			}
		}
		cout << endl;
	}
	cout<<endl;
}

void RaceRoad::moveCar(const short& direction){
	if(direction<0){
		if(hori>0){
			hori+=-1;
		}
	}else{
		if(hori<2){
			hori+=1;
		}
	}
}

vector<vector<unsigned char>> RaceRoad::generateRoad(const int& difficulty){
	vector<vector<unsigned char>> idList;
	for(int i(0);i<10;i++){
		vector<unsigned char> idVec;
		for(int j(0);j<3;j++){
			if(rand()%100<30) idVec.push_back('1');
			else idVec.push_back('0');
		}
		idList.push_back(idVec);
	}
	return idList;
}

bool RaceRoad::isHit(){
	if(vert<9){
		vert+=1;
	}else{
		road=generateRoad(1);
		vert=0;
	}
	return '1'==road[vert][hori];
}