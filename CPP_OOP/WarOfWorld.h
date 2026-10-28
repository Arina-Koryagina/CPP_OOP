#pragma once

#include<iostream>
#include<iomanip>
#include <conio.h>

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
	virtual ~Skill() = default;
	virtual void execute(Warrior* me, Warrior* w) = 0;
};

class SecondWind : public Skill
{
public:
	virtual void execute(Warrior* me, Warrior* w) override;
};
class CureWounds : public Skill
{
public:
	virtual void execute(Warrior* me, Warrior* w) override;
};
class Fireball : public Skill
{
public:
	virtual void execute(Warrior* me, Warrior* w) override;
};
class AgressiveCharge : public Skill
{
public:
	virtual void execute(Warrior* me, Warrior* w) override;
};
class BoneVolley : public Skill
{
public:
	virtual void execute(Warrior* me, Warrior* w) override;
};
class UndeadFortitude : public Skill
{
public:
	virtual void execute(Warrior* me, Warrior* w) override;
};

class Warrior
{
	int HP;
	int maxHP;
	int (*roll)();
	int bonus;
	String type;

protected:
	//List<Skill*> skills;
	Skill* skill;
	bool skillUsed = false;

public:
	Warrior(int HP, int (*roll)(), int bonus, Skill* skill = nullptr, String type = "")
	{
		this->HP = maxHP = HP;
		this->roll = roll;
		this->bonus = bonus;
		this->skill = skill;
		this->type = type;
	}
	Warrior(int lvl, int baseHP, int increase, int (*roll)(), int bonus, Skill* skill = nullptr, String type = "")
	{
		this->HP = maxHP = baseHP + (increase * (lvl - 1));
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
	int getMaxHP() const { return maxHP; }
	int getDamage() const { return roll() + bonus; }
	String getType() const { return type; }
	void setHP(int h) { HP = h; }

	void useSkill() { skillUsed = true; }
	void resetSkill() { skillUsed = false; }

	virtual void attack(Warrior* w) = 0;
	virtual int getLevel() const { return 0; }
	//virtual String getSide() const = 0;

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


void SecondWind::execute(Warrior* me, Warrior* w)
{
	cout << "Cast Second Wind -> "; SetColor(Green, Black);
	cout << me->getType() << endl; SetColor(White, Black);
	int oldHP = me->getHP();
	int newHP = oldHP + d10() + me->getLevel();
	if (newHP > me->getMaxHP()) { newHP = me->getMaxHP(); };
	me->setHP(newHP);
	cout << "Health restored: "; SetColor(LightGreen, Black);
	cout << "+" << newHP - oldHP << endl; SetColor(White, Black);
}
void Fireball::execute(Warrior* me, Warrior* w)
{
	cout << "Cast Fireball -> "; SetColor(LightBlue, Black);
	cout << w->getType() << endl; SetColor(White, Black);
	int DMG = d6() + d6(), hit = w->getHP() - DMG;
	(hit <= 0) ? w->setHP(0) : w->setHP(hit);
	cout << "Damage rolled: "; SetColor(LightRed, Black);
	cout << "-" << DMG << endl; SetColor(White, Black);
}


class Light : public Warrior
{
protected:
	int level = 1;

public:
	Light(int lvl, int baseHP, int increase, int(*roll)(), int bonus, Skill* skill, String type) : Warrior(lvl, baseHP, increase, roll, bonus, skill, type) { level = lvl; }

	virtual int getLevel() const final override { return level; }

	//virtual String getSide() const final override { return "LIGHT"; }

	virtual ostream& print(ostream& out) const override
	{
		out << "LVL " << level << ".";
		return Warrior::print(out);
	}
};

class Dark : public Warrior
{
public:
	Dark(int HP, int(*roll)(), int bonus, Skill* skill, String type) : Warrior(HP, roll, bonus, skill, type) {}

	//virtual String getSide() const final override { return "DARK"; }

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
		SetColor(Green, Black);
		cout << "Fighter"; SetColor(White, Black);
		cout << " is attacking!" << endl;

		cout << "[A]ttack   [S]kill\n"; bool action = false;

		while (!action)
		{
			int key = _getch();
			if (key == 'a' || key == 'A')
			{
				int DMG = getDamage(), hit = w->getHP() - DMG;
				(hit <= 0) ? w->setHP(0) : w->setHP(hit);
				cout << "Damage rolled: "; SetColor(LightRed, Black);
				cout << "-" << DMG << endl; SetColor(White, Black);
				action = true;
			}
			else if (key == 's' || key == 'S')
			{
				if (skill && skillUsed == false)
				{
					skill->execute(this, w);
					action = true;
					useSkill();
				}
				else
				{
					cout << "No skill availiable" << endl;
				}
			}
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
		SetColor(Green, Black);
		cout << "Ranger"; SetColor(White, Black);
		cout << " is attacking!" << endl;

		cout << "[A]ttack   [S]kill\n"; bool action = false;

		while (!action)
		{
			int key = _getch();
			if (key == 'a' || key == 'A')
			{
				int DMG = getDamage(), hit = w->getHP() - DMG;
				(hit <= 0) ? w->setHP(0) : w->setHP(hit);
				cout << "Damage rolled: "; SetColor(LightRed, Black);
				cout << "-" << DMG << endl; SetColor(White, Black);
				action = true;
			}
			else if (key == 's' || key == 'S')
			{
				if (skill && skillUsed == false)
				{
					skill->execute(this, w);
					action = true;
					useSkill();
				}
				else
				{
					cout << "No skill availiable" << endl;
				}
			}
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
		SetColor(Green, Black);
		cout << "Wizard"; SetColor(White, Black);
		cout << " is attacking!" << endl;

		cout << "[A]ttack   [S]kill\n"; bool action = false;

		while (!action)
		{
			int key = _getch();
			if (key == 'a' || key == 'A')
			{
				int DMG = getDamage(), hit = w->getHP() - DMG;
				(hit <= 0) ? w->setHP(0) : w->setHP(hit);
				cout << "Damage rolled: "; SetColor(LightRed, Black);
				cout << "-" << DMG << endl; SetColor(White, Black);
				action = true;
			}
			else if (key == 's' || key == 'S')
			{
				if (skill && skillUsed == false)
				{
					skill->execute(this, w);
					action = true;
					useSkill();
				}
				else
				{
					cout << "No skill availiable" << endl;
				}
			}
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
	Orc(Skill* skill = nullptr) : Dark(HP, d12, bonus, skill, "Orc") {}

	virtual void attack(Warrior* w) override
	{
		SetColor(LightBlue, Black);
		cout << "Orc"; SetColor(White, Black);
		cout << " is attacking!" << endl;
		int DMG = getDamage(), hit = w->getHP() - DMG;
		(hit <= 0) ? w->setHP(0) : w->setHP(hit);
		cout << "Damage rolled: "; SetColor(LightRed, Black);
		cout << "-" << DMG << endl; SetColor(White, Black);
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
	Skeleton(Skill* skill = nullptr) : Dark(HP, d6, bonus, skill, "Skeleton") {}

	virtual void attack(Warrior* w) override
	{
		SetColor(LightBlue, Black);
		cout << "Skeleton"; SetColor(White, Black);
		cout << " is attacking!" << endl;
		int DMG = getDamage(), hit = w->getHP() - DMG;
		(hit <= 0) ? w->setHP(0) : w->setHP(hit);
		cout << "Damage rolled: "; SetColor(LightRed, Black);
		cout << "-" << DMG << endl; SetColor(White, Black);
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
	Zombie(Skill* skill = nullptr) : Dark(HP, d6, bonus, skill, "Zombie") {}

	virtual void attack(Warrior* w) override
	{
		SetColor(LightBlue, Black);
		cout << "Zombie"; SetColor(White, Black);
		cout << " is attacking!" << endl;
		int DMG = getDamage(), hit = w->getHP() - DMG;
		(hit <= 0) ? w->setHP(0) : w->setHP(hit);
		cout << "Damage rolled: "; SetColor(LightRed, Black);
		cout << "-" << DMG << endl; SetColor(White, Black);
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
			case 0: l = new Fighter(1, new SecondWind); break;
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
		SetColor(Blue, Black);
		cout << "------   DARKS   ------" << endl;
		SetColor(Green, Black);
		lights.print();
		cout << endl;
		SetColor(LightBlue, Black);
		darks.print(33, 1);
		SetColor(White, Black);
	}

	Warrior* fight(Warrior* w1, Warrior* w2)
	{
		w1->resetSkill(); w2->resetSkill();
		int turn = rand() % 2;
		if (turn == 1)
		{
			Warrior* temp = w1;
			w1 = w2;
			w2 = temp;
		}
		while(true)
		{
			w1->attack(w2);
			if (w2->getHP() > 0)
			{
				w2->attack(w1);
			}
			else
			{
				SetColor(Red, Black);
				cout << w2->getType() << " defeated!" << endl;
				SetColor(White, Black);
				return w2;
			}
			if (w1->getHP() <= 0)
			{
				SetColor(Red, Black);
				cout << w1->getType() << " defeated!" << endl;
				SetColor(White, Black);
				return w1;
			}
			system("pause");
		}
	}

	void game()
	{
		while (lights.getSize() > 0 && darks.getSize() > 0)
		{
			system("cls");
			print();
			int D = darks.getSize();

			int l_ind = rand() % lights.getSize();
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
			if (lost == darks[d_ind])
			{
				darks.remove(d_ind);
			}
			else
			{
				lights.remove(l_ind);
			}
			delete lost;

			SetCursor(0, D+8);
			system("pause");
		}
		system("cls");
		if (lights.getSize() == 0)
		{
			SetColor(Red, Black);
			SetCursor(23, 5);
			cout << "YOU DIED";
			SetColor(White, Black);
			SetCursor(0, 10);
		}
		else
		{
			SetCursor(20, 5);
			cout << "MISSION COMPLETE";
			SetColor(Yellow, Black);
			SetCursor(24, 6);
			cout << "respect+";
			SetColor(White, Black);
			SetCursor(0, 11);
		}
	}
};