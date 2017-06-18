#include <iostream>
#include <fstream>
#include <string>
#include "Tree.h"
#include "Student.h"

using namespace std;


int main() {
	Student mor("MorV", 32);
	Student amir("AmirV", 18);
	Student karmit("Karmit", 21);
	Student nitay("NitayX", 25);
	Student hanan("HananX", 29);
	Student boaz("Boaz", 4);
	Student sahar("Sahar", 33);
	Student nurit("Nurit", 2);
	Student shani("Shani", 28);
	Student david("David", 90);




	
	Tree<Student> studentTree;
	studentTree.addNode(mor);
	studentTree.addNode(amir);
	studentTree.addNode(karmit);
	studentTree.addNode(nitay);
	studentTree.addNode(hanan);
	studentTree.addNode(boaz);
	studentTree.addNode(sahar);
	studentTree.addNode(david);
	studentTree.addNode(nurit);
	studentTree.addNode(shani);


	bool val = studentTree.treeContains(nurit);
	if (val != 1)
		puts("Error in treeContains");
	Student x("x", 0);
	val = studentTree.treeContains(x);
	if (val != 0)
		puts("Error in treeContains");



	ofstream out_file("out_file.bin",ios::binary|ios::out);
	studentTree.save(out_file);
	out_file.close();


	ifstream in_file("out_file.bin", ios::binary | ios::in);
	Tree<Student> newTree;
	newTree.load(in_file);
	if (1 != newTree.treeContains(mor))
		puts("Error in treeContains");
	
	Student temp = newTree.getNodeData(5);
	if (temp.getAge() != boaz.getAge())
		puts("error in getNodeData");
	
	Tree<Student>::Iterator it = studentTree.begin();
	it++;
	if (strcmp((*it).getName(), "AmirV") != 0)
		puts("Iterator error");



	puts("done");
	return 0;
}

