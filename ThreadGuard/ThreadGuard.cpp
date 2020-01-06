#include "ThreadGurad.h"

ThreadGuard::ThreadGuard(std::thread& th)
	:m_thread(th)
{

}

ThreadGuard::~ThreadGuard()
{
	if (m_thread.joinable())
		m_thread.join();
}