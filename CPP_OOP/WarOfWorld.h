#pragma once

#include<iostream>
#include<iomanip>

#include"Func.h"
#include"List.h"
#include"String.h"

using namespace std;

#define TYPES 3

int d6()
{
	return rand() % 6 + 1;
}
int d8()
{
	return rand() % 8 + 1;
}
int d10()
{
	return rand() % 10 + 1;
}
int d12()
{
	return rand() % 12 + 1;
}

class Warrior;

class Skill
{
public:
	virtual void execute(Warrior* w) = 0;
};

class Fireball : public Skill
{
public:
	virtual void execute(Warrior* w) override;
};

class Warrior
{
	int HP;
	int (*roll)();
	int bonus;
	String type;

protected:
	//List<Skill*> skills;
	Skill* skill;

public:
	Warrior(int HP, int (*roll)(), int bonus, String type = "")
	{
		this->HP = HP;
		this->roll = roll;
		this->bonus = bonus;
		this->skill = nullptr;
		this->type = type;
	}
	Warrior(int lvl, int baseHP, int increase, int (*roll)(), int bonus, Skill* skill = nullptr, String type = "")
	{
		this->HP = baseHP + (increase * (lvl - 1));
		this->roll = roll;
		this->bonus = bonus;
		this->skill = skill;
		this->type = type;
	}

	virtual ~Warrior()
	{
		if (skill)
		{
			delete skill;
		}
	}

	int getHP() const { return HP; }
	int getDamage() const { return roll() + bonus; }
	String getType() const { return type; }
	void setHP(int h) { HP = h; }

	virtual void attack(Warrior* w) = 0;

	friend ostream& operator<<(ostream& out, const Warrior* w);
	virtual ostream& print(ostream& out) const
	{
		out << " HP: " << setw(2) << right << setfill(' ') << HP << endl;
		return out;
	}
};

ostream& operator<<(ostream& out, const Warrior* w)
{
	out << setw(10) << left << setfill('.');
	return w->print(out);
}


void Fireball::execute(Warrior* w)
{
	cout << "Cast Fireball -> " << w->getType() << endl;
}


class Light : public Warrior
{
protected:
	int level = 1;

public:
	Light(int lvl, int baseHP, int increase, int(*roll)(), int bonus, Skill* skill, String type) : Warrior(lvl, baseHP, increase, roll, bonus, skill, type) { level = lvl; }

	virtual ostream& print(ostream& out) const override
	{
		out << "LVL " << level << ".";
		return Warrior::print(out);
	}
};

class Dark : public Warrior
{
public:
	Dark(int HP, int(*roll)(), int bonus, String type) : Warrior(HP, roll, bonus, type) {}

	virtual ostream& print(ostream& out) const override
	{
		out << "      ";
		return Warrior::print(out);
	}
};


class Fighter : public Light
{
	const static int baseHP = 12;
	const static int increase = 8;
	const static int bonus = 3;

public:
	Fighter(int lvl, Skill* skill = nullptr, String type = "Fighter") : Light(lvl, baseHP, increase, d8, bonus, skill, type) {}

	virtual void attack(Warrior* w) override
	{
		cout << "Fighter is attacking!" << endl;
		int DMG = getDamage();
		w->setHP(w->getHP() - DMG);
		cout << "Damage rolled: -" << DMG << endl;
		if (skill)
		{
			skill->execute(w);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Fighter";
		return Light::print(out);
	}
};
class Ranger : public Light
{
	const static int baseHP = 12;
	const static int increase = 8;
	const static int bonus = 3;

public:
	Ranger(int lvl, Skill* skill = nullptr, String type = "Ranger") : Light(lvl, baseHP, increase, d8, bonus, skill, type) {}

	virtual void attack(Warrior* w) override
	{
		cout << "Ranger is attacking!" << endl;
		int DMG = getDamage();
		w->setHP(w->getHP() - DMG);
		cout << "Damage rolled: -" << DMG << endl;
		if (skill)
		{
			skill->execute(w);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Ranger";
		return Light::print(out);
	}
};
class Wizard : public Light
{
	const static int baseHP = 8;
	const static int increase = 6;
	const static int bonus = 0;

public:
	Wizard(int lvl, Skill* skill = nullptr, String type = "Wizard") : Light(lvl, baseHP, increase, d10, bonus, skill, type) {}

	virtual void attack(Warrior* w) override
	{
		cout << "Wizard is attacking!" << endl;
		int DMG = getDamage();
		w->setHP(w->getHP() - DMG);
		cout << "Damage rolled: -" << DMG << endl;
		if (skill)
		{
			skill->execute(w);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Wizard";
		return Light::print(out);
	}
};


class Orc : public Dark
{
	const static int HP = 15;
	const static int bonus = 3;

public:
	Orc() : Dark(HP, d12, bonus, "Orc") {}

	virtual void attack(Warrior* w) override
	{
		cout << "Orc is attacking!" << endl;
		int DMG = getDamage();
		w->setHP(w->getHP() - DMG);
		cout << "Damage rolled: -" << DMG << endl;
		if (skill)
		{
			skill->execute(w);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Orc";
		return Dark::print(out);
	}
};
class Skeleton : public Dark
{
	const static int HP = 13;
	const static int bonus = 2;

public:
	Skeleton() : Dark(HP, d6, bonus, "Skeleton") {}

	virtual void attack(Warrior* w) override
	{
		cout << "Skeleton is attacking!" << endl;
		int DMG = getDamage();
		w->setHP(w->getHP() - DMG);
		cout << "Damage rolled: -" << DMG << endl;
		if (skill)
		{
			skill->execute(w);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Skeleton";
		return Dark::print(out);
	}
};
class Zombie : public Dark
{
	const static int HP = 22;
	const static int bonus = 1;

public:
	Zombie() : Dark(HP, d6, bonus, "Zombie") {}

	virtual void attack(Warrior* w) override
	{
		cout << "Zombie is attacking!" << endl;
		int DMG = getDamage();
		w->setHP(w->getHP() - DMG);
		cout << "Damage rolled: -" << DMG << endl;
		if (skill)
		{
			skill->execute(w);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Zombie";
		return Dark::print(out);
	}
};

class WarOfWorld
{
	List<Light*> lights;
	List<Dark*>  darks;

public:
	WarOfWorld(int size)
	{
		Light* l = nullptr;
		for (int i = 0; i < size; i++)
		{
			int rnd = rand() % TYPES;
			switch (rnd)
			{
			case 0: l = new Fighter(1); break;
			case 1: l = new Ranger(1); break;
			case 2: l = new Wizard(1, new Fireball);
			}
			lights.push_back(l);
		}

		Dark* d = nullptr;
		for (int i = 0; i < size; i++)
		{
			int rnd = rand() % TYPES;
			switch (rnd)
			{
			case 0: d = new Orc; break;
			case 1: d = new Skeleton; break;
			case 2: d = new Zombie;
			}
			darks.push_back(d);
		}
	}

	~WarOfWorld()
	{
		for (int i = 0; i < lights.getSize(); i++)
		{
			delete lights[i];
		}

		for (int i = 0; i < darks.getSize(); i++)
		{
			delete darks[i];
		}
	}

	void print() const
	{
		SetColor(LightGreen, Black);
		cout << "------   LIGHT   ------" << "          ";
		SetColor(LightBlue, Black);
		cout << "------   DARKS   ------" << endl;
		SetColor(Green, Black);
		lights.print();
		cout << endl;
		SetColor(Blue, Black);
		darks.print(33, 1);
		SetColor(White, Black);
	}

	Warrior* fight(Warrior* w1, Warrior* w2)
	{
		w1->attack(w2);
		if (w2->getHP() > 0)
		{
			w2->attack(w1);
		}
		else
		{
			cout << w2->getType() << " defeated!" << endl;
			w2->setHP(0);
			return w2;
		}
		if (w1->getHP() <= 0)
		{
			cout << w1->getType() << " defeated!" << endl;
			w1->setHP(0);
			return w1;
		}

		return nullptr;
	}

	void game()
	{
		while (lights.getSize() > 0 && darks.getSize() > 0)
		{
			system("cls");
			print();
			int L = lights.getSize(), D = darks.getSize();

			int l_ind = rand() % L;
			int d_ind = rand() % D;

			cout << "\n\n    Battle  Started    " << endl;
			cout << "-----------------------" << endl;
			cout << lights[l_ind];
			cout << darks[d_ind] << endl;

			Warrior* lost = fight(lights[l_ind], darks[d_ind]);

			SetCursor(33, D + 4);
			cout << "    Battle    Ended    " << endl; SetCursor(33, D + 5);
			cout << "-----------------------" << endl; SetCursor(33, D + 6);
			cout << lights[l_ind]; SetCursor(33, D + 7);
			cout << darks[d_ind]; SetCursor(0, D + 9);

			if (lost == lights[l_ind])
			{
				lights.remove(l_ind);
			}
			else if (lost == darks[d_ind])
			{
				darks.remove(d_ind);
			}
			delete lost;

			//if (lights.getSize() > 0 && darks.getSize() > 0)
			//{
				SetCursor(0, 21);
				system("pause");
			//}
		}
		system("cls");
		if (lights.getSize() == 0)
		{
			cout << "THE DARK SIDE WON" << endl;
		}
		else
		{
			cout << "THE LIGHT SIDE WON" << endl;
		}
	}
};