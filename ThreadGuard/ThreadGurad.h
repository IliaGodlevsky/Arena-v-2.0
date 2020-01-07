#ifndef THREAD_GUARD_H_
#define THREAD_GUARD_H_

#include <thread>

class ThreadGuard
{
public:
	ThreadGuard(std::thread& th);
	~ThreadGuard();
private:
	std::thread& m_thread;
};

#endif