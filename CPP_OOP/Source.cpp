#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>

#include"Array.h"
#include"String.h"
#include"Time.h"
#include"Date.h"
#include"BTree.h"
#include"PoliceBase.h"


using namespace std;

int main()
{
	PoliceBase pb;
	pb.load();
	//pb.addNotice("BE4633CI", "2026-10-17 20:25:32", "FineNotice1", 500, 1);
	//pb.addNotice("BE4633CI", "2026-10-17 21:25:32", "FineNotice2", 500, 1);
	//pb.addNotice("BE4633CI", "2026-10-17 22:25:32", "FineNotice3", 500, 1);
	//pb.addNotice("BE4503CI", "2026-10-17 22:25:32", "FineNotice1", 500, 1);
	//pb.addNotice("BE4703CI", "2026-10-17 22:25:32", "FineNotice1", 500, 1);
	//pb.addNotice("BE4503CI", "2026-10-17 22:25:32", "FineNotice2", 1500, 0);
	pb.print();
	//pb.print("BE4633CI");
	//pb.print("BE4633CI", "BE4703CI");
	pb.save();

	return 0;
}