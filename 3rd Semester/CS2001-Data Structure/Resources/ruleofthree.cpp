// In the below C++ code, we have created
// a destructor, but no copy constructor
// and no copy assignment operator.
class Array
{
private:
	int size;
	int* vals;

public:
	~Array();
	Array( int s, int* v );
};

Array::~Array()
{
delete vals;
vals = NULL;
}

Array::Array( int s, int* v )
{
	size = s;
	vals = new int[ size ];
	std::copy( v, v + size, vals );
}

int main()
{
int vals[ 4 ] = { 11, 22, 33, 44 };
Array a1( 4, vals );

// This line causes problems.
Array a2( a1 );

return 0;
}

