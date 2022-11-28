#include<iostream>
using namespace std;
class shape{
	public:
		void set_width(int w)
		{
			width = w;
		}
		void set_height(int h)
		{
			height = h;
		}
		protected:
			int height, width;
};
class paint_cost{
	public:
		int get_cost(int area)
		{
			return area * 70;
		}
};
class rectangle : public shape, public paint_cost{
	public:
		int get_area()
		{
			return (width * height);
		}
};
int main()
{
	rectangle ob1;
	int area;
	ob1.set_height(2);
	ob1.set_width(2);
	area = ob1.get_area();
	cout << "Area is: " << area;
	cout << "\nTotal paint cost is: " << ob1.get_cost(area);
	return 0;
}
