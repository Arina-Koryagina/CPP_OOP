#pragma once

#include<iostream>
#include<iomanip>

#include"Func.h"
#include"List.h"
#include"String.h"

using namespace std;

#define TYPES 3

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
	int hp;
	int damage;
	String type;

protected:
	//List<Skill*> skills;
	Skill* skill;

public:
	Warrior(int minHP, int maxHP, int minDMG, int maxDMG, Skill* skill = nullptr, String type = "")
	{
		hp = rand() % (maxHP - minHP + 1) + minHP;
		damage = rand() % (maxDMG - minDMG + 1) + minDMG;
		this->skill = skill;
		this->type = type;
	}

	int getHP() const { return hp; }
	int getDamage() const { return damage; }
	String getType() const { return type; }
	void setHP(int h) { hp = h; }
	void setDamage(int d) { damage = d; }

	virtual void attack(Warrior* w) = 0;

	friend ostream& operator<<(ostream& out, const Warrior* w);
	virtual ostream& print(ostream& out) const
	{
		out << " HP: " << hp << "; Damage: " << damage << endl;
		return out;
	}
};

ostream& operator<<(ostream& out, const Warrior* w)
{
	out << setw(12) << left << setfill('.');
	return w->print(out);
}


void Fireball::execute(Warrior* w)
{
	cout << "Skill Fireball -> " << w->getType() << endl;
}


class Light : public Warrior
{
public:
	Light(int minHP, int maxHP, int minDMG, int maxDMG, Skill* skill, String type) : Warrior(minHP, maxHP, minDMG, maxDMG, skill, type) {}
};

class Dark : public Warrior
{
public:
	Dark(int minHP, int maxHP, int minDMG, int maxDMG, Skill* skill, String type) : Warrior(minHP, maxHP, minDMG, maxDMG, skill, type) {}
};


class Swordsman : public Light
{
public:
	Swordsman(int minHP, int maxHP, int minDMG, int maxDMG, Skill* skill = nullptr, String type = "Swordsman") : Light(minHP, maxHP, minDMG, maxDMG, skill, type) {}

	virtual void attack(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Swordsman";
		return Warrior::print(out);
	}
};
class Archer : public Light
{


public:
	Archer(int minHP, int maxHP, int minDMG, int maxDMG, Skill* skill = nullptr, String type = "Archer") : Light(minHP, maxHP, minDMG, maxDMG, skill, type) {}

	virtual void attack(Warrior* w) override
	{
		cout << "Archer is attacking!" << endl;
		w->setHP(w->getHP() - getDamage());
		cout << "-" << getDamage() << endl;
		if (skill)
		{
			skill->execute(w);
		}
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Archer";
		return Warrior::print(out);
	}
};
class Rider : public Light
{
public:
	Rider(int minHP, int maxHP, int minDMG, int maxDMG, Skill* skill = nullptr, String type = "Rider") : Light(minHP, maxHP, minDMG, maxDMG, skill, type) {}

	virtual void attack(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Rider";
		return Warrior::print(out);
	}
};


class Orc : public Dark
{
public:
	Orc(int minHP, int maxHP, int minDMG, int maxDMG, Skill* skill = nullptr, String type = "Orc") : Dark(minHP, maxHP, minDMG, maxDMG, skill, type) {}

	virtual void attack(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Orc";
		return Warrior::print(out);
	}
};
class Skeleton : public Dark
{
public:
	Skeleton(int minHP, int maxHP, int minDMG, int maxDMG, Skill* skill = nullptr, String type = "Skeleton") : Dark(minHP, maxHP, minDMG, maxDMG, skill, type) {}

	virtual void attack(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Skeleton";
		return Warrior::print(out);
	}
};
class Zombie : public Dark
{
public:
	Zombie(int minHP, int maxHP, int minDMG, int maxDMG, Skill* skill = nullptr, String type = "Zombie") : Dark(minHP, maxHP, minDMG, maxDMG, skill, type) {}

	virtual void attack(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Zombie";
		return Warrior::print(out);
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
		Skill* fireball = new Fireball;
		for (int i = 0; i < size; i++)
		{
			int rnd = rand() % TYPES;
			switch (rnd)
			{
			case 0: l = new Swordsman(50, 70, 10, 20); break;
			case 1: l = new Archer(50, 70, 10, 20, fireball); break;
			case 2: l = new Rider(50, 80, 10, 20);
			}
			lights.push_back(l);
		}

		Dark* d = nullptr;
		for (int i = 0; i < size; i++)
		{
			int rnd = rand() % TYPES;
			switch (rnd)
			{
			case 0: d = new Orc(50, 80, 10, 20); break;
			case 1: d = new Skeleton(50, 70, 10, 20); break;
			case 2: d = new Zombie(50, 70, 10, 20);
			}
			darks.push_back(d);
		}
	}

	void print() const
	{
		cout << "----------   LIGHT   ----------" << "         " << "----------   DARKS   ----------" << endl;
		lights.print();
		cout << endl;
		darks.print(40, 1);
	}

	Warrior* fight(Warrior* w1, Warrior* w2)
	{
		// TODO
		w1->attack(w2);
		w2->attack(w1);

		return nullptr;
	}

	void game()
	{
		while (lights.getSize() > 0 && darks.getSize() > 0)
		{
			system("cls");
			print();

			int l_ind = rand() % lights.getSize();
			int d_ind = rand() % darks.getSize();

			cout << "\n        Battle  Started        " << endl;
			cout << "-------------------------------" << endl;
			cout << lights[l_ind];
			cout << darks[d_ind] << endl;

			Warrior* lost = fight(lights[l_ind], darks[d_ind]);

			cout << "\n        Battle    Ended        " << endl;
			cout << "-------------------------------" << endl;
			cout << lights[l_ind];
			cout << darks[d_ind] << endl;

			if (lost == lights[l_ind])
			{
				lights.remove(l_ind);
			}
			else if (lost == darks[d_ind])
			{
				darks.remove(d_ind);
			}
			system("pause");
		}
	}
};