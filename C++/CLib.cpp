#include <iostream>
#include <cassert>
#include "CLib.h"
using namespace std;

const int increament = 100;

void initialize(CStash* s, int size)
{
	s->size = size;
	s->quantity = 0;
	s->storage = 0;
	s->next = 0;
}

int add(CStash* s, const void* element)
{
	if (s->next == s->quantity) inflate(s, increament);
	int startBytes = s->next * s->size;
	unsigned char* e = (unsigned char*)element;
	for (int i = 0; i < s->size; i++)
		s->storage[startBytes + i] = e[i];
	s->next++;
	return s->next - 1;
}

void* fetch(CStash* s, int index)
{
	assert(0 <= index);
	if (index >= s->next) return 0;
	return &(s->storage[index * s->size]);
}

int count(CStash* s)
{
	return s->next;
}

void inflate(CStash* s, int increase)
{
	assert(increase > 0);
	int newQuantity = s->quantity + increase;
	int newBytes = newQuantity * s->size;
	int oldBytes = s->quantity * s->size;
	unsigned char* b = new unsigned char[newBytes];
	for (int i = 0; i < oldBytes; i++) b[i] = s->storage[i];
	delete[] s->storage;
	s->storage = b;
	s->quantity = newQuantity;
}

void cleanup(CStash* s)
{
	if (s->storage != 0)
	{
		cout << "freeing storage" << endl;
		delete[] s->storage;
	}
}
