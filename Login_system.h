#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Application {
private:
	int selection;
public:
	void main();
	void introduction();
	void login();
	void registiration();
	void forgot();
};