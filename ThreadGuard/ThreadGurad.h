#pragma once

#include <thread>

class ThreadGuard
{
public:
	ThreadGuard(std::thread& th);
	~ThreadGuard();
private:
	std::thread& m_thread;
};