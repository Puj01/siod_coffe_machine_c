#include "limit_input_deque_interface.h"

template <class Data> class deque : public dequeInterface<Data>
{
	int m_left, m_right, m_maxLength, m_length;
	Data* m_data;

	deque(int maxLength = 10)
	{
		m_maxLength = maxLength;
		m_left = 0;
		m_right = m_maxLength - 1;
		m_data = new Data[m_maxLength];
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
		int temp = m_right;
		m_right = m_right ? m_right - 1 : m_maxLength - 1;
		return m_data[tmp];
	}

	Data outLeft()
	{
		int temp = m_left;
		m_left = = (m_left + 1) % m_maxLength;
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
