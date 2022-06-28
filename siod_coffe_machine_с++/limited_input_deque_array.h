#include "limit_input_deque_interface.h"

template <class Data> class deque : public dequeInterface<Data>
{
	int m_left, m_right, m_maxLength;
	Data* m_data;

public:
	deque(int maxLength = 10)
	{
		m_maxLength = maxLength;
		m_left = 0;
		m_right = m_maxLength - 1;
		m_data = new Data[m_maxLength];
	}

	~deque()
	{
		delete[] m_data;
	}

	int empty()
	{
		return (m_right + 1) % m_maxLength == m_left;
	}

	int full()
	{
		return (m_right + 2) % m_maxLength == m_left;
	}

	int inRight(Data* pSrcData)
	{
		if (full())
			return 0;
		m_right = (m_right + 1) % m_maxLength;
		m_data[m_right] = *pSrcData;
		return 1;
	}
	Data outRight()
	{
		int tmp = m_right;
		m_right = m_right ? m_right - 1 : m_maxLength - 1;
		return m_data[tmp];
	}

	Data outLeft()
	{
		int tmp = m_left;
		m_left= (m_left + 1) % m_maxLength;
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
