#pragma once
class Resistance
{
public:
	Resistance();
	Resistance(int aRes[4]);
	~Resistance();

	int getFireRes();
	int getIceRes();
	int getLightningRes();
	int getDarkRes();
	void setFireRes(int aResistance);
	void setLightningRes(int aResistance);
	void setIceRes(int aResistance);
	void setDarkRes(int aResistance);
private:
	int fRes[4];
};
