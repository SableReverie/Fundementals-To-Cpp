// ============================== THREADS ==============================
/*
A thread is the smallest unit of execution within a process.

Think of a process as a restaurant and threads as workers inside it:

Process = Restaurant
Thread = Worker

A single-threaded program performs tasks one after another.

Task A → Task B → Task C

A multithreaded program can perform tasks simultaneously.

Thread 1: Task A
Thread 2: Task B
Thread 3: Task C
*/
/*
#include <iostream>
#include <thread>

void printMessage()
{
    std::cout << "Hello from thread!\n";
}

int main()
{
    std::thread t(printMessage);

    t.join();  // Wait for thread to finish

    return 0;
}
*/

/*
Output
Hello from thread!
Important
t.join();

Waits for the thread to finish before continuing.

Without join(), the program may terminate before the thread completes.
*/

// ============================= MUTEX ========================================

/*
Problem: Race Condition

Imagine two threads incrementing the same counter.

counter++;

This operation is actually:

Read counter
Add 1
Write counter

If two threads do this simultaneously:

Thread A reads 5
Thread B reads 5

Thread A writes 6
Thread B writes 6

Expected:

7

Actual:

6

This is a race condition.
*/
/*
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 0;

void increment()
{
    for(int i = 0; i < 100000; i++)
    {
        mtx.lock();

        counter++;

        mtx.unlock();
    }
}

int main()
{
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << counter << std::endl;
}
*/
/*
Output:

200000

The mutex ensures only one thread modifies counter at a time.
*/


// ====================== LOCKS ===============================

/*
3. Locks

Manually calling:

mtx.lock();
...
mtx.unlock();

is dangerous.

If an exception occurs:

mtx.lock();

throw std::runtime_error("error");

mtx.unlock(); // never reached

The mutex remains locked forever.

std::lock_guard

C++ provides RAII-based locking.

void increment()
{
    for(int i = 0; i < 100000; i++)
    {
        std::lock_guard<std::mutex> lock(mtx);

        counter++;
    }
}

When the scope ends:

}

the lock automatically unlocks.

std::unique_lock

More flexible than lock_guard.

std::unique_lock<std::mutex> lock(mtx);

Allows:

lock.unlock();
lock.lock();

Useful with condition variables.
*/

// ========================== Atomic Operations ===============================

/*
Sometimes a mutex is overkill.

For simple variables, use atomics.

An atomic operation is completed as a single indivisible action.

Example Without Atomic
int counter = 0;

Not thread-safe.
*/

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);

void increment()
{
    for(int i = 0; i < 100000; i++)
    {
        counter++;
    }
}

int main()
{
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << counter << std::endl;
}