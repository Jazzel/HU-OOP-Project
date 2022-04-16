#include <iostream>
#include <list>

using namespace std;

// list is a std library's doubly linked list implementation. It provides constant time insertion and deletion operations, but it doesn't support indexing.

class Distance
{
	int feet, inches;

public:
	Distance(int ft, int inch) : feet(ft), inches(inch) {}
	void show()
	{
		cout << feet << "'" << inches << "\"" << endl;
	}
};

int main()
{
	list<Distance *> dst;
	Distance *dt = new Distance(3, 4); // It's a list that can store Distance type objects
	dst.push_back(dt);				   // create an object, and push it in vector
	dst.push_back(new Distance(5, 2));
	dst.push_back(new Distance(2, 7));
	dst.push_back(new Distance(7, 8));
	dst.push_back(new Distance(13, 1));

	for (Distance *d : dst)
	{ // list doesn't support indexing, but we can use python's style for loop.
		d->show();
	}

	// Distance *d = new Distance(3, 4);
	dst.remove(dt);

	cout << "dsad";
	for (Distance *d : dst)
	{ // list doesn't support indexing, but we can use python's style for loop.
		d->show();
	}
	// // deleting the objects, need to delete every single object created dynamically
	// for (Distance *d : dst)
	// {
	// 	delete d;
	// }

	// dst.clear(); // clears all the items from vector
}