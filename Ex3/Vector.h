class Vector
{
	int* vec;
	int capacity; //memory size
	int size; //actual size (how many nums inserted), the next available place

public:
	Vector(int cap = 10);
	Vector(const Vector& v);
	Vector(Vector&& v);
	~Vector();

	int getSize() const;
	bool isEmpty() const;

	void addLast(int k);
	int lastValue() const;

	int removeLast();

	void clear();
	int at(int i) const;

	void print() const;

	void sort();

};