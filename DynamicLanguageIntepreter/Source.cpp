#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

string toString(int i) {
	std::stringstream ss;
	ss << i;

	return ss.str();
}

struct Variable {
	bool isInt;
	int intValue;
	string stringValue;

	Variable(int value) {
		isInt = true;
		this->intValue = value;
	}

	Variable(string value) {
		isInt = false;
		this->stringValue = value;
	}

	int GetInt() {
		if (isInt) {
			return intValue;
		}
		else {
			if (stringValue == "" || (!isdigit(stringValue[0]) && stringValue[0] != '-')) return 0;	//STOI errors
			return stoi(stringValue);
		}
	}

	string GetString() {
		if (isInt) {
			return toString(intValue);
		}
		else {
			return stringValue;
		}
	}

	void Print() {
		if (isInt) {
			cout << intValue << endl;
		}
		else {
			cout << "\"" << stringValue << "\"" << endl;
		}
	}
};

void SetVariable(const string &name, const Variable &var, map<string, Variable>& variables) {
	//if !exist create new, else edit value
	auto it = variables.find(name);
	if (it == variables.end()) {
		variables.insert({ name, var });
	}
	else {
		it->second = var;
	}
}

Variable GetVariable(const string &name, map<string, Variable>& variables) {
	auto it = variables.find(name);
	if (it == variables.end()) {
		return Variable("");
	}
	else {
		return it->second;
	}
}

void InstructionSwitch(std::vector<std::string>& tokens, std::map<std::string, Variable>& variables, int& pointer)
{
	if (tokens.size() <= 0) {
		//empty line
		return;
	}
	string instruction = tokens[0];
	//INT A = 5
	if (instruction == "number") {
		SetVariable(tokens[1], Variable(stoi(tokens[2])), variables);
	}
	//STRING B = "C"
	if (instruction == "text") {
		SetVariable(tokens[1], Variable(tokens[2]), variables);
	}
	//INT TRG = A + B
	if (instruction == "sum") {
		int a = GetVariable(tokens[2], variables).GetInt();
		int b = GetVariable(tokens[3], variables).GetInt();
		int sum = a + b;
		SetVariable(tokens[1], Variable(sum), variables);
	}
	//INT TRG = A * B
	if (instruction == "product") {
		/*int a = stoi(GetVariable(tokens[2], variables).GetString());
		int b = stoi(GetVariable(tokens[3], variables).GetString());*/
		int a = GetVariable(tokens[2], variables).GetInt();
		int b = GetVariable(tokens[3], variables).GetInt();
		//cout << "\t\t\t\t\t\t\t" << tokens[2]<< " in:" << a << "|" << endl;
		//cout << "\t\t\t\t\t\t\t" << tokens[3] << " in:" << b << "|" << endl;
		//int aInt = stoi(a);
		int product = a * b;
		SetVariable(tokens[1], Variable(product), variables);
	}
	//INT TRG = A.tostring + B.tostring
	if (instruction == "concat") {
		string a = GetVariable(tokens[2], variables).GetString();
		string b = GetVariable(tokens[3], variables).GetString();
		string concat = a + b;
		SetVariable(tokens[1], Variable(concat), variables);
	}
	//BOOL TRG = A > B
	if (instruction == "greaterThen") {
		int a = GetVariable(tokens[2], variables).GetInt();
		int b = GetVariable(tokens[3], variables).GetInt();
		bool expression = a > b;
		int outcome;
		if (expression) outcome = 1; else outcome = 0;
		SetVariable(tokens[1], Variable(outcome), variables);
	}
	//BOOL TRG = A < B
	if (instruction == "lessThen") {
		int a = GetVariable(tokens[2], variables).GetInt();
		int b = GetVariable(tokens[3], variables).GetInt();
		bool expression = a < b;
		int outcome;
		if (expression) outcome = 1; else outcome = 0;
		SetVariable(tokens[1], Variable(outcome), variables);
	}
	//PRINT A
	if (instruction == "print") {
		Variable var = GetVariable(tokens[1], variables);
		var.Print();
	}
	//GOTO A
	if (instruction == "goto") {
		pointer = stoi(tokens[1]) - 1;
	}
	//BRT LINE COND
	if (instruction == "jumpIfTrue") {
		int cond = GetVariable(tokens[2], variables).GetInt();
		if (cond != 0) {
			pointer = stoi(tokens[1]) - 1;
		}
	}
	//BRF LINE COND
	if (instruction == "jumpIfFalse") {
		int cond = GetVariable(tokens[2], variables).GetInt();
		if (cond == 0) {
			pointer = stoi(tokens[1]) - 1;
		}
	}
}

void ProcessLine(string line, int& pointer, map<string, Variable>& variables) {
	//split line into tokens
	stringstream ss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(ss), istream_iterator<string>(), back_inserter(tokens));

	//all instructions
	InstructionSwitch(tokens, variables, pointer);
}

int main(int argc, char* argv[]) {

	//LOAD FILE TO MEMORY
	ifstream file(argv[1]);
	vector<string> lines;
	lines.push_back("");	//line 0
	string temp;
	while (getline(file, temp))
	{
		lines.push_back(temp);
	}
	int lineCount = lines.size();

	//CREATE PROGRAM MEMORY
	map<string, Variable> variables = {};

	//RUN PROGRAM
	int pointer = 1;
	while (pointer < lineCount) {
		ProcessLine(lines[pointer], pointer, variables);
		pointer++;
	}
}

