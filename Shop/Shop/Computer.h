#pragma once
#include <iostream>
#include <string>
using namespace std;
class Computer
{
public:
	Computer() : Computer(0, "", "", "", "", "") {}
	~Computer() { 
		delete[] motherBoard;
		delete[] CPU;
		delete[] videoCard;
		delete[] straightPower;
		delete[] RAM;
	}
	Computer(double price, const char* mBoard, const char* CPU, const char* vCard, const char* sPower, const char* RAM) : 
		price(price), motherBoard(_strdup(mBoard)), CPU(_strdup(CPU)),videoCard(_strdup(vCard)), straightPower(_strdup(sPower)), 
		RAM(_strdup(RAM)) {}
	Computer(const Computer& other) : Computer(other.getPrice(), other.getMotherBoard(), other.getCPU(), other.getVideoCard(),
		other.getStraightPower(), other.getRAM()) {}
	double getPrice() const { return price; }
	void setPrice(double p) { price = p;  }
	char* getMotherBoard() const { return motherBoard; }
	void setMotherBoard(const char* mBoard) { delete[] motherBoard; motherBoard = _strdup(mBoard); }
	char* getCPU() const { return CPU; }
	void setCPU(const char* CPU) { delete[] this->CPU; this->CPU = _strdup(CPU); }
	char* getVideoCard() const { return videoCard; }
	void setVideoCard(const char* vCard) { delete[] videoCard; videoCard = _strdup(vCard); }
	char* getStraightPower() const { return straightPower; }
	void setStraightPower(const char* sPower) { delete[] straightPower; straightPower = _strdup(sPower); }
	char* getRAM() const { return RAM; }
	void setRAM(const char* RAM) { delete[] this->RAM; this->RAM = _strdup(RAM); }
private:
	double price;
	char* motherBoard;
	char* CPU;
	char* videoCard;
	char* straightPower;
	char* RAM;
};

inline ostream& operator<<(ostream& out, const Computer computer) {
	out << "price = " << computer.getPrice() << endl;
	out << "Mother Board:" << computer.getMotherBoard() << endl;
	out << "CPU: " << computer.getCPU() << endl;
	out << "Video Card(integrated graphics): " << computer.getVideoCard() << endl;
	out << "Sraight power: " << computer.getStraightPower() << endl;
	out << "RAM: " << computer.getRAM() << endl;
	return out;
}

