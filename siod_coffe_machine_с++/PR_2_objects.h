#include "limit_input_deque_vector_templates.h"
class pot
{
	int m_maxStorage;
	int m_storage;

public:
	pot(int maxStorage = 250)
	{
		m_maxStorage = maxStorage;
		m_storage = 0;
	}
	void add(int gramms)
	{
		m_storage += gramms;
		//return m_maxStorage - gramms;
	}
	int getMaxStorage()
	{
		return m_maxStorage;
	}
	int getStorage()
	{
		return m_storage;
	}
	void makeEmpty()
	{
		m_storage = 0;
	}
};

class coffeeMachine
{
	int m_coffe;
	Deque <pot> m_conveyor;

public:
	coffeeMachine(int coffe = 1000)
	{
		m_coffe = coffe;
		//MakeNull(&m_conveyor);
	}
	void addCoffe(pot& pot)
	{
		if (m_coffe <= 0)
			return;
		int portion = getPortion(pot.getMaxStorage());
		pot.add(portion);
		m_coffe -= portion;
		
	}

	int Run(pot& Pot)
	{
		if (m_coffe >= Pot.getMaxStorage())
		{
			addCoffe(Pot); //добавление кофе на конвейр
			m_conveyor.InRight(Pot);
			std::cout << "Заполнение банки. Заполнено: " << Pot.getStorage() << " Осталось: " << m_coffe <<  std::endl;

			pot tmpPot = m_conveyor.ReadRight(); // проверка добавленной банки
			if (!checkPot(tmpPot))
			{
				m_conveyor.OutRight();
				m_coffe += tmpPot.getStorage();
				std::cout << "Банка не прошла проверку. Снята с конвейра. Кофе возвращено в хранилище." << std::endl;

			}
		}

		// упаковщик
		if ((m_coffe < Pot.getMaxStorage() || m_conveyor.Full()) && !m_conveyor.Empty())
		{
			Pot = m_conveyor.OutLeft();
			std::cout << "банка упакована." << std::endl;
		}

		if (m_coffe < Pot.getMaxStorage() && m_conveyor.Empty())
			return 0;

		return 1;

	}

	int checkPot(pot& Pot)
	{
		if (Pot.getStorage() == Pot.getMaxStorage())
			return 1;
		return 0;
	}
	int notEmpty()
	{
		if (m_coffe <= 0)
			return 0;
		return 1;
	}
	int getPortion(int target)
	{
		int result = rand() % 20;
		if (result < 10)
			return target;
		return target - result;
	}
};