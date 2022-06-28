template <class Data> class dequeInterface
{
	virtual int empty() = 0;
	virtual int full() = 0;
	virtual int inRight(Data*) = 0;
	virtual Data outLeft() = 0;
	virtual Data outRight() = 0;
	virtual Data readLeft() = 0;
	virtual Data readRight() = 0;
};