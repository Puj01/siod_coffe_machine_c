#include "limit_input_deque_interface.h"

template <class Data, size_t N> class deque : public dequeInterface<Data>
{
	int m_left, m_right;
	Data* m_data;

public:
	deque()
	{
		m_left = 0;
		m_right = N - 1;
		m_data = new Data[N];
	}

	~deque()
	{
		delete[] m_data;
	}

	int empty()
	{
		return (m_right + 1) % N == m_left;
	}

	int full()
	{
		return (m_right + 2) % N == m_left;
	}

	int inRight(Data* pSrcData)
	{
		if (full())
			return 0;
		m_right = (m_right + 1) % N;
		m_data[m_right] = *pSrcData;
		return 1;
	}
	Data outRight()
	{
		int tmp = m_right;
		m_right = m_right ? m_right - 1 : N - 1;
		return m_data[tmp];
	}

	Data outLeft()
	{
		int tmp = m_left;
		m_left= (m_left + 1) % N;
		return m_data[m_left];
	}

	Data readRight()
	{
		return m_data[m_right];
	}

	Data readLeft()
	{
		return m_data[m_left];
	}
};
