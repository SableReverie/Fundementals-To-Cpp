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
/*
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
*/
/*
Output:

200000

No mutex needed.

When to Use Atomic

Good:

counter++;
flag = true;

Not good:

bankBalance -= amount;
transactionLog.push_back(...);

Multiple related operations usually require a mutex.
*/

// ============================ Condition Variables =================================

// A condition variable allows threads to wait until something happens.
/*
Without it:

while(queue.empty())
{
    // Keep checking
}

This wastes CPU.

This is called busy waiting.

Producer-Consumer Example

Producer:

Produces data

Consumer:

Waits for data
Processes data
*/
/*
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;

void producer()
{
    {
        std::lock_guard<std::mutex> lock(mtx);

        q.push(42);

        std::cout << "Produced\n";
    }

    cv.notify_one();
}

void consumer()
{
    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock, []{
        return !q.empty();
    });

    int value = q.front();
    q.pop();

    std::cout << "Consumed: " << value << std::endl;
}

int main()
{
    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();
}
*/
/*
Output:

Produced
Consumed: 42
How It Works

Consumer:

cv.wait(lock, condition);

Steps:

Releases mutex
Sleeps
Producer calls:
cv.notify_one();
Consumer wakes up
Re-acquires mutex
Continues execution

Efficient and CPU-friendly.
*/

// =========================== Thread Pools ==================================
// Creating threads repeatedly is expensive.
/*
Bad:

    for(10000 tasks)
    {
        create thread
        run task
        destroy thread
    }

Thread creation has overhead.
*/
/*
Thread Pool Idea

Create a fixed number of worker threads:

Worker 1
Worker 2
Worker 3
Worker 4

Tasks are placed into a queue.

Task Queue
 ├─ Task A
 ├─ Task B
 ├─ Task C

Workers continuously pull tasks from the queue.
*/
/*
#include <iostream>
#include <thread>
#include <queue>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool
{
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;

public:
    ThreadPool(size_t numThreads)
    {
        for(size_t i = 0; i < numThreads; i++)
        {
            workers.emplace_back([this]
            {
                while(true)
                {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(mtx);

                        cv.wait(lock, [this]
                        {
                            return stop || !tasks.empty();
                        });

                        if(stop && tasks.empty())
                            return;

                        task = std::move(tasks.front());
                        tasks.pop();
                    }

                    task();
                }
            });
        }
    }

    void enqueue(std::function<void()> task)
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(task);
        }

        cv.notify_one();
    }

    ~ThreadPool()
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true;
        }

        cv.notify_all();

        for(auto& worker : workers)
            worker.join();
    }
};

int main()
{
    ThreadPool pool(4);

    for(int i = 0; i < 10; i++)
    {
        pool.enqueue([i]
        {
            std::cout << "Task " << i
                      << " running on thread "
                      << std::this_thread::get_id()
                      << std::endl;
        });
    }
}
*/
/*
Concept	            Purpose	                                    Example

Thread	            Run code concurrently	                    std::thread
Mutex	            Protect shared data	                        std::mutex
Lock	            Safe mutex management	                    std::lock_guard
Atomic	            Lock-free simple shared variables	        std::atomic<int>
Condition           Variable	Wait for an event efficiently	std::condition_variable
Thread Pool	        Reuse worker threads	                    Task queue + workers

*/

// ========================== AI SUGGESTIONS :
/*
Where Graphics Programmers Use Multithreading
1. Asset Loading

Imagine loading:

Textures
Models
Sounds
Shaders

If you load everything on the main thread:

Game freezes
↓
Load texture
Load mesh
Load sound
↓
Game resumes

Instead:

Main Thread
  ↓
Render game

Worker Thread
  ↓
Load texture

Worker Thread
  ↓
Load mesh

The game keeps running while resources load in the background.

Concepts Used
Threads
Mutexes
Condition variables
Thread pools
2. Job Systems (Most Important)

Modern engines don't create a new thread for every task.

Instead they use a job system.

Example:

Frame
│
├── Physics
├── Animation
├── Visibility Culling
├── Particle Update
├── AI
└── Audio

These become small jobs:

Job Queue

Animation Job
Particle Job
Physics Job
AI Job

Worker threads pull jobs from the queue.

This is basically a sophisticated thread pool.

Engines like:

Unreal Engine
Unity
Frostbite

all rely heavily on job systems.

3. Frustum Culling

Suppose your world contains:

100,000 objects

You don't want to draw all of them.

Each frame:

Check object visibility

This can be split:

Thread 1 -> Objects 1-25000
Thread 2 -> Objects 25001-50000
Thread 3 -> Objects 50001-75000
Thread 4 -> Objects 75001-100000

Then combine results.

This is a perfect multithreading task.

4. Particle Systems

Imagine:

1,000,000 particles

Each particle:

position += velocity * dt;

can be updated independently.

Split particles across threads:

Thread 1 -> 250k particles
Thread 2 -> 250k particles
Thread 3 -> 250k particles
Thread 4 -> 250k particles

Huge speedup.

5. Animation

Character animation is often parallelized.

Example:

Character A
Character B
Character C
Character D

Each thread computes bone transforms for different characters.

6. Software Rasterizer Practice

One of the best graphics projects.

Instead of:

GPU rasterizes triangles

you write your own rasterizer on the CPU.

Then parallelize:

Thread 1 -> Top screen region
Thread 2 -> Middle region
Thread 3 -> Bottom region

This teaches:

Rendering
Cache efficiency
Synchronization
Work distribution

all at once.

Projects to Practice
Beginner
Project 1: Multithreaded Image Blur

Load an image.

Split rows:

Thread 1 -> rows 0-249
Thread 2 -> rows 250-499
Thread 3 -> rows 500-749
Thread 4 -> rows 750-999

Apply blur.

You'll learn:

Threads
Data partitioning
Joining threads
Project 2: Parallel Mandelbrot Renderer

Render a Mandelbrot set.

Each pixel is independent.

Thread 1 -> top quarter
Thread 2 -> second quarter
Thread 3 -> third quarter
Thread 4 -> bottom quarter

This is a classic graphics-programming exercise.

Intermediate
Project 3: Thread Pool

Build your own thread pool.

Submit jobs:

pool.enqueue(renderChunk);
pool.enqueue(updateParticles);
pool.enqueue(loadTexture);

Learn:

Mutexes
Locks
Condition variables
Project 4: Multithreaded Software Rasterizer

Render triangles on CPU.

Each worker renders tiles:

Tile 0
Tile 1
Tile 2
Tile 3

This starts looking like a real renderer.

Advanced
Project 5: Job System

Create:

class JobSystem
{
    Submit(Job);
    WaitAll();
}

Workers continuously execute jobs.

This mirrors real game engines.

Project 6: Async Resource Streaming

Create a system where:

Player moves
↓
Need texture
↓
Background thread loads texture
↓
Main thread uses texture

This is very close to production engine architecture.

What You Should Learn First

If your goal is graphics programming, I'd learn in this order:

Modern C++
OpenGL or Vulkan basics
Threads
Mutexes
Condition variables
Thread pools
Job systems
CPU-side rendering algorithms
GPU programming
Engine architecture
A Graphics Programmer's View

You will rarely write code like:

std::thread t1(...);
std::thread t2(...);
std::thread t3(...);

in a professional renderer.

What you will write is closer to:

jobSystem.Dispatch(UpdateParticles);
jobSystem.Dispatch(CullObjects);
jobSystem.Dispatch(AnimateCharacters);
jobSystem.Wait();

Under the hood, the engine's job system uses:

Threads
Mutexes
Atomics
Condition variables
Thread pools

So the real value of learning these concepts is that they teach you how a rendering engine distributes work across all CPU cores efficiently. 
Once you understand them, you'll be able to build things like multithreaded asset loaders, software renderers, particle systems, visibility systems, 
and eventually an engine-style job system—the kinds of systems graphics programmers work on regularly.
*/