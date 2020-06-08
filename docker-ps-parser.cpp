#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <array>
#include <memory>
#include <sstream>

const char *COMMAND = "docker ps -a --format '{{.ID}}\t{{.Image}}\t{{.Command}}\t{{.RunningFor}}\t{{.Status}}\t{{.Ports}}\t{{.Names}}'";

class Container {
	private:
		std::string ID = "";
		std::string Image = "";
		std::string Command = "";
		std::string Created = "";
		std::string Status = "";
		std::vector<std::string> Ports = {""};
		std::string Name = "";

	public:
		Container(void) { }
		Container(std::string _id, std::string _image, std::string _command, std::string _created, std::string _status, std::string _ports, std::string _name) {
			ID = _id; Image = _image; Command = _command; Created = _created; Status = _status; Name = _name;

			std::string mAux = "";
			for (int j = 0; j < (int)(_ports.size()); j++ ) {
				if (_ports[j] == ',') {
					addPort(mAux);
					mAux = "";
					while (_ports[j+1] == ' ') j++;
				} else mAux.push_back(_ports[j]);
			}
			addPort(mAux);
			mAux="";
		}

		void clear(void) { ID = ""; Image = ""; Command = ""; Created = ""; Status = ""; Ports = {""}; Name = ""; }

		// Getters
		std::string getID(void) { return ID; }
		std::string getImage(void) { return Image; }
		std::string getCommand(void) { return Command; }
		std::string getCreated(void) { return Created; }
		std::string getStatus(void) { return Status; }
		std::vector<std::string> getPorts(void) { return Ports; }
		int getPortsCount(void) { return Ports.size(); }
		std::string getName(void) { return Name; }

		// Setters
		void setID(std::string _id) { ID = _id; }
		void setImage(std::string _image) { Image = _image; }
		void setCommand(std::string _command) { Command = _command; }
		void setCreated(std::string _created) { Created = _created; }
		void setStatus(std::string _status) { Status = _status; }
		void setPorts(std::string _ports) {
			std::string mAux = "";
			for (int j = 0; j < (int)(_ports.size()); j++ ) {
				if (_ports[j] == ',') {
					addPort(mAux);
					mAux = "";
					while (_ports[j+1] == ' ') j++;
				} else mAux.push_back(_ports[j]);
			}
			addPort(mAux);
			mAux="";
		}
		void addPort(std::string _port) { Ports.push_back(_port); }
		void setName(std::string _name) { Name = _name; }
};

std::string trim(const std::string& _string) {
	size_t mStart = _string.find_first_not_of(" ");
	if (mStart == std::string::npos) return "";

	size_t mEnd = _string.find_last_not_of(" ");
	if (mEnd == std::string::npos) return "";

	return _string.substr(mStart, mEnd - mStart + 1);
}

void print(std::vector<Container> _containers) {
	const char *OUTPUT_FORMAT = "| %-15.15s | %-25.25s | %-30.30s|\n";
	const char *OUTPUT_FORMAT_UP = "| %-15.15s |\033[32m %-25.25s \033[0m| %-30.30s|\n";
	const char *OUTPUT_FORMAT_EXIT = "| %-15.15s |\033[31m %-25.25s \033[0m| %-30.30s|\n";
	const char *SEPARATOR = "+-----------------+---------------------------+-------------------------------+";

	printf(OUTPUT_FORMAT, "Name", "Status", "Ports");
	std::cout << SEPARATOR << std::endl;
	char *mFormat = new char[100];
	for (int i = 0; i < (int)_containers.size(); i++) {
		if ( _containers.at(i).getStatus().substr(0,6) == "Exited" ) strcpy(mFormat, OUTPUT_FORMAT_EXIT);
		else strcpy(mFormat, OUTPUT_FORMAT_UP);

		printf(mFormat, _containers[i].getName().c_str(), _containers[i].getStatus().c_str(), _containers[i].getPorts()[1].c_str());

		for (int j = 2; j < _containers[i].getPortsCount(); j++)
			printf(mFormat, " ", " ", _containers[i].getPorts()[j].c_str());

		std::cout << SEPARATOR << std::endl;
		std::cout << "\033[0m";
	}
}

std::string exec(const char* _command) {
	std::array<char, 128> mBuff;
	std::string mResult;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(_command, "r"), pclose);
	if ( !pipe ) throw std::runtime_error("popen() failed!");

	while ( fgets(mBuff.data(), mBuff.size(), pipe.get()) != nullptr ) mResult += mBuff.data();

	return mResult;
}

int main(void) {
	std::vector<Container> mContainers;
	std::string mOutput = exec(COMMAND);
	std::string mLine = "", mToken = "";
	std::istringstream mOutputISS(mOutput);

	while ( std::getline(mOutputISS, mLine, '\n') ) {
		Container mContainer;
		std::istringstream mLineISS(mLine);

		std::getline(mLineISS, mToken, '\t');
		mContainer.setID(mToken);
		std::getline(mLineISS, mToken, '\t');
		mContainer.setImage(mToken);
		std::getline(mLineISS, mToken, '\t');
		mContainer.setCommand(mToken);
		std::getline(mLineISS, mToken, '\t');
		mContainer.setCreated(mToken);
		std::getline(mLineISS, mToken, '\t');
		mContainer.setStatus(mToken);
		std::getline(mLineISS, mToken, '\t');
		mContainer.setPorts(mToken);
		std::getline(mLineISS, mToken, '\t');
		mContainer.setName(mToken);

		mContainers.push_back(mContainer);
	}

	print(mContainers);

	return 0;
}