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
	Student bla1("bla1", 33);
	Student bla2("bla2", 2);
	Student bla3("bla3", 28);
	Student bla4("bla4", 90);

	TreeNode<Student> root(&mor);

	TreeNode<Student> amirNode(&amir);
	root.addChild(&amirNode);
	root.addChild(&karmit);
	root.addChild(&nitay);
	root.addChild(&hanan);
	root.removeChild();
	root.removeChild();
	root.addChild(&nitay);
	root.addChild(&hanan);

	root.getChild(2)->getNextChild();
	root.getPrevChild();

	root.findChildIndx(&nitay);
	root.findChildIndx(&shani);
	root.findChild(&hanan);
	root.findChild(&shani);
	root.getChild(5);
	root.getChild(2);

	auto child1 = root.getNextChild();
	auto child2 = child1->getNextChild();
	auto child3 = child2->getNextChild();
	auto child4 = child3->getNextChild();
	auto grandson1 = child4->getNextChild();
	child1->addChild(&sahar);
	grandson1 = child4->getNextChild();

	auto child3_prev = child4->getPrevChild();
	auto child2_prev = child3_prev->getPrevChild();
	auto child1_prev = child2_prev->getPrevChild();
	auto father_prev = child1_prev->getPrevChild();
	
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
	studentTree.addNode(bla1);
	studentTree.addNode(bla2);
	studentTree.addNode(bla3);
	studentTree.addNode(bla4);

	studentTree.treeContains(bla4);
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

