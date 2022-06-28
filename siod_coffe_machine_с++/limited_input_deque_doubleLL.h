#include "limit_input_deque_interface.h"
template <class elData> class dequeElement
{
	template <class Data> friend class deque;
	dequeElement<elData>* m_previous, * m_next;
	elData m_data;
	dequeElement(dequeElement<elData>* previous, dequeElement<elData>* next, elData* data)
	{
		m_previous = previous;
		m_next = next;
		m_data = *data;
	}
};

template <class Data,size_t N> class deque : public dequeInterface <Data> /* 0 или любое отрицательное число - безграничный дек. любое положительное число - размер дека*/
{
	dequeElement<Data>* m_head, * m_tail;
	int N, m_length;

public:
	deque()
	{
		m_head = NULL;
		m_tail = NULL;
		m_length = 0;
	}
	
	~deque()
	{
		dequeElement<Data>* tmp;
		while (m_head)
		{
			tmp = m_head;
			m_head = m_head->m_next;
			delete tmp;
		}
	}

	int empty()
	{
		return m_head == NULL || m_tail == NULL;
	}

	int full()
	{
		return m_length == N;
	}

	int inRight(Data* pSrcData)
	{
		if (full())
			return 0;
		dequeElement<Data>* tmp = new dequeElement<Data>(m_tail, NULL, pSrcData);
		if (empty())
			m_head = tmp;
		else
			m_tail->m_next = tmp;
		m_tail = tmp;
		m_length++;
		return 1;
	}

	int inLeft(Data* pSrcData)
	{
		if (full())
			return 0;
		dequeElement<Data>* tmp = new dequeElement<Data>(NULL, m_head, pSrcData);
		if (empty())
			m_tail = tmp;
		else
			m_head->m_previous = tmp;
		m_head = tmp;
		m_length++;
		return 1;
	}

	void printDeque()
	{
		dequeElement<Data>* tmp = m_head;
		while (tmp)
		{
			std::cout << tmp->m_data << std::endl;
			tmp = tmp->m_next;
		}
	}

	Data outRight()
	{
		if (empty())
			return 0;
		dequeElement<Data>* tmp = m_tail;
		m_tail = m_tail->m_previous;
		return tmp->m_data;
	}

	Data outLeft()
	{
		if (empty())
			return 0;
		dequeElement<Data>* tmp = m_head;
		m_head = m_head->m_next;
		return tmp->m_data;
	}

	Data readRight()
	{
		if (empty())
			return 0;
		return m_head->m_data;
	}

	Data readLeft()
	{
		if (empty())
			return 0;
		return m_head->m_data;
	}
};