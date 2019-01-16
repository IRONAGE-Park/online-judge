#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json.h"

using namespace std;

int timestamp; // 타임스탬프

typedef struct COMMAND {
	string str;
	int userId;
}COMMAND;

int abs(int n) {
	if (n > 0) return n;
	return -n;
}

class Person {
	// 사람 클래스
public:
	int id, start, end; // 사람의 Id와 시작, 끝점
	bool use; // 탑승할 예정인지
	void Init(int id, int start, int end, bool use) {
		this->id = id, this->start = start, this->end = end, this->use = use;
	}
};

class Elevator {
	// 엘리베이터 클래스
public:
	int id, curFloor, maxPeople; // 엘리베이터의 Id와 현재 층 수, 최대 수용 인원
	vector<Person> Boarder; // 탑승자
	string status; // 현재 엘리베이터의 상태 { "STOPPED", "OPENED", "UPWARD", "DOWNWARD" }로 구성.

	void Init(int id, int curFloor, int maxPeople, string status) { // 엘리베이터 초기화.
		this->id = id, this->curFloor = curFloor, this->maxPeople = maxPeople, this->status = status;
	}
	void Boarding(Person p) { // 사람을 탑승시킴
		Boarder.push_back(p);
	}
	bool Command(string comm, int num, vector<Person> &list) { // 동작 가능하면 true 반환
		if (comm == "STOP") { // 엘리베이터가 "STOP" 명령을 입력 받았으면,
			if (status == "OPENED") return false;
			else status = "STOPPED";
		}
		else if (comm == "UP") { // 엘리베이터가 "UP" 명령을 입력 받았으면,
			if (status != "STOPPED") return false;
			else {
				status = "UPWARD";
				curFloor++; // 1층을 올려줌
			}
		}
		else if (comm == "DOWN") { // 엘리베이터가 "DOWN" 명령을 입력 받았으면,
			if (status != "STOPPED") return false;
			else {
				status = "DOWNWARD";
				curFloor--; // 1층을 내려줌
			}
		}
		else if (comm == "OPEN") { // 엘리베이터가 "OPEN" 명령을 입력 받았으면,
			if (status == "STOPPED" || status == "OPENED") status = "OPENED";
			else return false;
		}
		else if (comm == "CLOSE") { // 엘리베이터가 "CLOSE" 명령을 입력 받았으면,
			if (status != "OPENED") return false;
			else status = "STOPPED";
		}
		else if (comm == "ENTER") { // 엘리베이터가 "ENTER" 명령을 입력 받았으면,
			for (int i = 0; i < list.size(); i++) {
				if (list[i].id == num) {
					Boarder.push_back(list[i]); // 이 엘리베이터에 그 사람을 추가하고,
					list.erase(list.begin() + i); // 그 사람을 목록에서 제외시킴.
					break;
				}
			}
		}
		else { // 엘리베이터가 "EXIT" 명령을 입력 받았으면,
			for (int i = 0; i < Boarder.size(); i++) {
				if (Boarder[i].id == num) { //
					Person temp_p = Boarder[i];
					Boarder.erase(Boarder.begin() + i);
					if (temp_p.end != curFloor) { // 내리는 층이 도착하는 층이면,
						temp_p.start = curFloor;
						list.push_back(temp_p);
					}
					break;
				}
			}
		}
		timestamp++; // 문제없이 명령이 수행 됐을 경우에는 시간 증가.
		return true;
	}
	int CheckGetOff() { // 현재 층에서 하차할 사람이 있고, 있다면 그 사람의 번호 확인.
		for (int i = 0; i < Boarder.size(); i++)
			if (Boarder[i].end == curFloor) {
				return Boarder[i].id;
			}
		return -1;
	}
	bool CheckBoadring(vector<Person> &list) { // 현재 층에서 승차할 사람이 있는지 확인.
		for (int i = 0; i < list.size(); i++) {
			if (list[i].start == curFloor) {
				return list[i].id;
			}
		}
		return -1;
	}
};

class Commander {
	// 명령 생성기
public:
	COMMAND getNextCommand(Elevator elev, vector<Person> &perList) { // 다음 명령 반출
		COMMAND cmd;
		cmd.userId = -1;
		int minGetOffIndex = 0, minBoardingIndex = 0;
		for (int i = 1; i < perList.size(); i++) {
			if (abs(perList[minBoardingIndex].start - elev.curFloor)> abs(perList[i].start - elev.curFloor))
				minBoardingIndex = i;
		} // 가장 가까운 탑승 예정인 자 알아냄.
		for (int i = 1; i < elev.Boarder.size(); i++) {
			if (abs(elev.Boarder[minGetOffIndex].end - elev.curFloor) > abs(elev.Boarder[i].end - elev.curFloor))
				minGetOffIndex = i;
		} // 가장 가까운 하차 예정인 자 알아냄.
		  /* 엘리베이터 기준 가장 가까운 탑승 예정인 자와 가장 가까운 하차 예정인 자를 구함 */
		if (elev.status == "\"UPWARD\"\n") { // 현재 이 엘리베이터가 올라가는 상태일 때,
			cmd.str = "UP"; // 기본값은 UP
			if (elev.Boarder.size() != 0) {
				if (elev.Boarder[minGetOffIndex].end == elev.curFloor)
					cmd.str = "STOP";
			}
			if (perList.size() != 0) {
				if (perList[minBoardingIndex].start == elev.curFloor)
					cmd.str = "STOP";
			}
		}
		else if (elev.status == "\"DOWNWARD\"\n") { // 내려가는 상태일 때,
			cmd.str = "DOWN"; // 기본값은 DOWN
			if (elev.Boarder.size() != 0) {
				if (elev.Boarder[minGetOffIndex].end == elev.curFloor)
					cmd.str = "STOP";
			}
			if (perList.size() != 0) {
				if (perList[minBoardingIndex].start == elev.curFloor)
					cmd.str = "STOP";
			}
		}
		else if (elev.status == "\"STOPPED\"\n") { // 멈춰있는 상태일 때,
			cmd.str = "STOP"; // 기본값은 STOP
			if (elev.Boarder.size() != 0) {
				if (elev.Boarder[minGetOffIndex].end == elev.curFloor)
					cmd.str = "OPEN";
			}
			if (perList.size() != 0) {
				if (perList[minBoardingIndex].start == elev.curFloor)
					cmd.str = "OPEN";
			}
			else cmd.str = "UP";
		}
		else { // 열려있는 상태일 때,

		}
		return cmd;
	}
};

class JsonParser {
	// Json 데이터 파싱 클래스
public:
	Json::Value root; // 전체 정보
	Json::Reader reader;
	void setJson(string data) {
		reader.parse(data, root);
	}
	Json::Value getOncalls() {
		Json::Value oncall;
		oncall["elevators"] = root["elevators"];
		oncall["calls"] = root["calls"];
		return oncall;
	}
};

int main() {
	ifstream inp("input.json");
	ofstream out("output.json");
	string data;
	JsonParser parser;
	while (!inp.eof()) {
		string line;
		getline(inp, line);
		data += line;
	}
	/* Input Data */
	parser.setJson(data);
	Json::Value parseData = parser.getOncalls(), commands, command;
	vector<Elevator> elevators(parseData["elevators"].size());
	vector<Person> calls(parseData["calls"].size());
	for (int i = 0; i < elevators.size(); i++) {
		Json::FastWriter fw;
		Json::Value getInfo = parseData["elevators"];
		elevators[i].Init(stoi(fw.write(getInfo[i]["id"])), stoi(fw.write(getInfo[i]["floor"])), 8, fw.write(getInfo[i]["status"]));
	}
	for (int i = 0; i < calls.size(); i++) {
		Json::FastWriter fw;
		Json::Value getInfo = parseData["calls"];
		calls[i].Init(stoi(fw.write(getInfo[i]["id"])), stoi(fw.write(getInfo[i]["start"])), stoi(fw.write(getInfo[i]["end"])), false);
	}
	Commander cmd;
	for (int i = 0; i < elevators.size(); i++) {
		COMMAND CMD = cmd.getNextCommand(elevators[i], calls);
		command["command"] = CMD.str;
		command["elevator_id"] = i;
		if (CMD.userId != -1) {
			command["calls_id"] = CMD.userId;
		}
		commands["commands"].append(command);
	}
	out << commands;
	return 0;
}