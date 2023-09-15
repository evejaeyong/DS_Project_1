//#include "Manager.h"
#include "MemberQueue.h"
using namespace std;

int main() {
// 	Manager manager;
// 	manager.run("command.txt");
/*
james 17 2023-08-30 Bg
bob 31 2023-02-22 A
sophia 25 2023-01-01 D
emily 41 2021-08-01 C
chris 20 2022-11-05 A
kevin 58 2023-09-01 B
taylor 11 2023-02-20 A
*/
	MemberQueue a;
	string name = "james";
	string date = "2023-08-30";

	a.push(name, 17, date, 'B');
	

	return 0;
}
