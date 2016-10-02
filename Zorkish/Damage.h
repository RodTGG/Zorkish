#pragma once

namespace Zorkish {
	class Damage
	{
	public:
		Damage();
		Damage(int aDmg[4]);
		~Damage();

		int getFireDmg();
		int getIceDmg();
		int getLightningDmg();
		int getDarkDmg();

		void setFire(int aDamage);
		void setLightning(int aDamage);
		void setIce(int aDamage);
		void setDark(int aDamage);
	private:
		int fDmg[4];
	};

}