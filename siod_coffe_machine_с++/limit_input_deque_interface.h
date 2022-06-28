template <class Data> class dequeInterface
{
	virtual int empty() = 0;
	virtual int full() = 0;
	virtual int inRight(Data* pSrcData) = 0;
	virtual int outLeft() = 0;
	virtual int outRight() = 0;
	virtual Data readLeft() = 0;
	virtual Data readRight() = 0;
};