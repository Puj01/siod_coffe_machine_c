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

template <class Data> class deque
{
	dequeElement<Data>* m_head, * m_tail;

public:
	deque()
	{
		m_head = NULL;
		m_tail = NULL;
	}

	int empty()
	{
		return m_head == NULL, m_tail == NULL;
	}

	void inRight(Data* pSrcData)
	{
		dequeElement<Data>* tmp = new dequeElement<Data>(m_tail, NULL, pSrcData);
		if (empty())
			m_head = tmp;
		else
			m_tail->m_next = tmp;
		m_tail = tmp;
	}

	void inLeft(Data* pSrcData)
	{
		dequeElement<Data>* tmp = new dequeElement<Data>(NULL, m_head, pSrcData);
		if (empty())
			m_tail = tmp;
		else
			m_head->m_previous = tmp;
		m_head = tmp;
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

};