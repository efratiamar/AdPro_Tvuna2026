class Rect
{
	int width;
	int length;
public:
	Rect() {};
	Rect(int wid, int len) : width(wid), length(len) {};

	//bool isEqual(const Rect& other) const
	//{
	//	return (width == other.width && length == other.length);
	//}

	bool operator==(const Rect& other) const
	{
		return (width == other.width && length == other.length);
	}

	bool operator!=(const Rect& other) const
	{
		//return (width != other.width || length != other.length);
		return !(other == *this);
	}

	Rect operator+(const Rect& other) const
	{
		Rect tmp(width+other.width, length + other.length);

		return  tmp;
	}

	Rect& operator+=(const Rect& other)
	{
		//width += other.width;
		//length += other.length;

		*this = *this + other;
		
		return *this;
	}
};

int main()
{
	int a = 4, b = 8, c = 9;
	a = b + c;

	Rect r1, r2(2,3), r3(4,5);

	r1 = r2 + r3; // r2.operator+(r3);

	r1 += r2 += r3 += r1;


	r1 = r2;

	//if (r2.isEqual(r3))
	//{

	//}

	if (r2 == r3)
	{

	}

	//if (r2.operator==(r3))
	//{

	//}






	//..
	r1 += (r2 + r3); //compilation error
}
