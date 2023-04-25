#pragma once
class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(const char* id);
	HotDogStand(const char* id, int amount);
	~HotDogStand();
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
private:
	char* standId; //The ID of the store
	int hotDogSellAmount; //The hot dog sales volume of the store
	static int totalSellAmount; //The total hot dog sales volume of all stores
};

