#pragma once

#include<iostream>
#include<iomanip>
#include <conio.h>

#include"Func.h"
#include"List.h"
#include"Array.h"
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
		cout << " is attacking "; SetColor(LightBlue, Black);
		cout << w->getType() << endl; SetColor(White, Black);

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
		cout << " is attacking "; SetColor(LightBlue, Black);
		cout << w->getType() << endl; SetColor(White, Black);

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
		cout << " is attacking "; SetColor(LightBlue, Black);
		cout << w->getType() << endl; SetColor(White, Black);

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
		cout << " is attacking "; SetColor(Green, Black);
		cout << w->getType() << endl; SetColor(White, Black);
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
		cout << " is attacking "; SetColor(Green, Black);
		cout << w->getType() << endl; SetColor(White, Black);
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
		cout << " is attacking "; SetColor(Green, Black);
		cout << w->getType() << endl; SetColor(White, Black);
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

	int line = 0;

public:
	WarOfWorld(int party_size, int opponents)
	{
		Light* l = nullptr;
		for (int i = 0; i < party_size; i++)
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
		for (int i = 0; i < opponents; i++)
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

		(party_size >= opponents) ? line = party_size : line = opponents;
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
		SetCursor(0, line+2);
	}

	Warrior* fight(List<Light*>* party, Warrior* enemy)
	{
		int partySize = party->getSize();
		Array<Light*> roster;
		for (int i = 0; i < partySize; ++i)
		{
			Light* member = (*party)[i];
			member->resetSkill();
			roster.add(member);
		}
		enemy->resetSkill();

		Array<int> turns;
		for (int count = 0; count <= partySize; )
		{
			int candidate = rand() % (partySize + 1);

			if (!turns.contains(candidate))
			{
				turns.add(candidate);
				count++;
			}
		}

		Array<Light*> fallen;
		auto deleteFallen = [&fallen]()
			{
				for (int i = 0; i < fallen.getSize(); ++i)
					delete fallen[i];
			};

		while (party->getSize() > 0)
		{
			for (int turn = 0; turn <= partySize; turn++)
			{
				int actor = turns[turn];

				if (actor == partySize) // Enemy's one turn this round
				{
					int targetIndex = rand() % party->getSize();
					Light* target = (*party)[targetIndex];

					enemy->attack(target);

					if (target->getHP() <= 0)
					{
						SetColor(Red, Black);
						cout << target->getType() << " was taken down!" << endl;
						SetColor(White, Black);
						party->remove(targetIndex);
						fallen.add(target);

						if (party->getSize() == 0)
						{
							deleteFallen();
							return nullptr;
						}
					}

					SetColor(Green, Black);
					cout << "HP: " << target->getHP() << endl;
				}
				else // This Light character's scheduled turn
				{
					Light* member = roster[actor];

					// They might have been defeated earlier in this round.
					if (member->getHP() > 0)
					{
						member->attack(enemy);

						if (enemy->getHP() <= 0)
						{
							SetColor(Red, Black);
							cout << enemy->getType() << " defeated!" << endl;
							SetColor(White, Black);
							deleteFallen();
							return enemy;
						}

						SetColor(LightBlue, Black);
						cout << "HP: " << enemy->getHP() << endl;
					}
					else
					{
						cout << "Skipping turn of a fallen warrior" << endl;
					}
				}

				SetColor(DarkGray, Black);
				system("pause");
				SetColor(White, Black);
			}
		}

		deleteFallen();
		return nullptr;

		//Warrior* w = nullptr;
		//bool battle = true; int i = 0;
		//while (battle)
		//{
		//	if (turns[i] == size)
		//	{
		//		int w_ind = rand() % size;
		//		w = (*party)[w_ind];
		//		enemy->attack(w);
		//		if (w->getHP() == 0)
		//		{
		//			SetColor(Red, Black);
		//			cout << w->getType() << " defeated!" << endl;
		//			SetColor(White, Black);
		//			party->remove(w_ind);
		//			if (party->getSize() == 0)
		//			{
		//				battle = false;
		//				return nullptr;
		//			}
		//		}
		//	}
		//	else
		//	{
		//		w = (*party)[turns[i]];
		//		w->attack(enemy);
		//		if (enemy->getHP() == 0)
		//		{
		//			SetColor(Red, Black);
		//			cout << enemy->getType() << " defeated!" << endl;
		//			SetColor(White, Black);
		//			battle = false;
		//			return enemy;
		//		}
		//	}
		//	i++;
		//	SetColor(DarkGray, Black);
		//	system("pause");
		//	SetColor(White, Black);
		//}
		
		//int w_ind = rand() % size;
		//Warrior* w = (*party)[w_ind];
		//cout << "Warrior selected: " << w << endl;
		//Warrior* w1 = nullptr;
		//Warrior* w2 = nullptr;
		//
		//int turn = rand() % 2;
		//if (turn == 1)
		//{
		//	SetColor(LightBlue, Black);
		//	cout << "Enemy"; SetColor(White, Black);
		//	cout << " is first to attack!" << endl;
		//	w1 = enemy;
		//	w2 = w;
		//}
		//else
		//{
		//	SetColor(Green, Black);
		//	cout << "Party member"; SetColor(White, Black);
		//	cout << " is first to attack!" << endl;
		//	w1 = w;
		//	w2 = enemy;
		//}

		//while(true)
		//{
		//	w1->attack(w2);
		//	if (w2->getHP() > 0)
		//	{
		//		w2->attack(w1);
		//	}
		//	else
		//	{
		//		SetColor(Red, Black);
		//		cout << w2->getType() << " defeated!" << endl;
		//		SetColor(White, Black);
		//		if (turn == 1)
		//		{
		//			party->remove(w_ind);
		//		}
		//		else
		//		{
		//			return w2;
		//		}
		//	}
		//	if (w1->getHP() <= 0)
		//	{
		//		SetColor(Red, Black);
		//		cout << w1->getType() << " defeated!" << endl;
		//		SetColor(White, Black);
		//		if (turn == 1)
		//		{
		//			return w1;
		//		}
		//		else
		//		{
		//			party->remove(w_ind);
		//		}
		//	}

		//	if (party->getSize() == 0)
		//	{
		//		return nullptr;
		//	}

		//	w_ind = rand() % party->getSize();
		//	(turn == 1) ? w2 = (*party)[w_ind] : w1 = (*party)[w_ind];
	}

	void game()
	{
		while (lights.getSize() > 0 && darks.getSize() > 0)
		{
			system("cls");
			print();

			int d_ind = rand() % darks.getSize();

			cout << "\n\n    Battle  Started    " << endl;
			cout << "-----------------------" << endl;
			cout << "Enemy selected: "; SetColor(LightBlue, Black);
			cout << darks[d_ind]->getType() << endl;
			cout << "HP: " << darks[d_ind]->getHP() << "\n\n"; SetColor(White, Black);

			Warrior* lost = fight(&lights, darks[d_ind]);

			SetCursor(33, line + 4);
			cout << "    Battle    Ended    "; SetCursor(33, line + 5);
			cout << "-----------------------"; SetCursor(33, line + 6);
			cout << darks[d_ind]; SetCursor(0, line + 8);
			if (lost == darks[d_ind])
			{
				darks.remove(d_ind);
				delete lost;
			}

			SetCursor(0, line+7);
			SetColor(DarkGray, Black);
			system("pause");
			SetColor(White, Black);
		}
		system("cls");
		if (lights.getSize() == 0)
		{
			SetColor(Red, Black);
			SetCursor(24, 5);
			cout << "YOU DIED";
			SetColor(Black, Black);
		}
		else
		{
			SetCursor(20, 5);
			cout << "MISSION COMPLETE";
			SetColor(Yellow, Black);
			SetCursor(24, 6);
			cout << "respect+";
			SetColor(Black, Black);
		}
	}
};