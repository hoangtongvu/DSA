#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


class Item
{
public:
	int value;
	int weight;
	float ratio;
	Item(int _weight, int _value);
	~Item();

private:

};



Item::Item(int _weight, int _value)
{
	this->weight = _weight;
	this->value = _value;
	this->ratio = (float) this->value / this->weight;
}

Item::~Item()
{
}




int main()
{
	vector<Item*> itemList;

	int bagWeight, numberOfItem;
	cin >> bagWeight >> numberOfItem;

	for (int i = 0; i < numberOfItem; i++)
	{
		int w, v;
		cin >> w >> v;
		Item* newItem = new Item(w, v);
		itemList.emplace_back(newItem);
	}

	//sort itemList in order of descending ratio.
	
	//put item into bag.
	vector<Item*> bag;
	int currentW = 0;
	int currentV = 0;

	for (int i = 0; i < numberOfItem; i++)
	{
		int itemW = itemList[i]->weight;
		if (itemW + currentW > bagWeight) continue;
		currentW += itemW;
		currentV += itemList[i]->value;
		bag.emplace_back(itemList[i]);


	}

	cout << "currentW = " << currentW << endl;
	cout << "currentV = " << currentV << endl;
	
	for (int i = 0; i < bag.size(); i++)
	{
		cout << bag[i]->weight << " " << bag[i]->value << endl;
	}


    return 0;
}


/*
6
4
1 3
2 3
5 7
3 4
*/