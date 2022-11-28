#include<iostream>
using namespace std;
class student{
	protected:
		int roll_num;
		public:
			void get_num(int a){
				roll_num = a;
			}
			void put_num(void){
				cout << "Roll num: " << roll_num << endl;
			}
};
class test : public student{
	protected:
		float part1, part2;
		public:
			void get_marks(float x, float y){
				part1 = x;
				part2 = y;
			}
			void put_marks(){
				cout << "Marks obtained part 1: " << part1 << " part 2: " << part2 << endl;
			}
};
class sport {
	protected:
		float score;
		public:
			void get_score(float s){
				score = s;
			}
			void put_score(){
				cout << "Sport: " << score << endl;
			}
};
class result : public test, public sport{
	float total;
	public:
		void display(){
			total = part1 + part2 + score;
			put_num();put_marks();put_score();
			cout << "Total score = " << total;
		}
};
int main()
{
	result stu;
	stu.get_num(20);
	stu.get_marks(10,21);
	stu.get_score(2.1);
	stu.display();
}
