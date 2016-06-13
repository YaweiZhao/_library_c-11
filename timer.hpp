#include <chrono>
using namespace std;
using namespace std::chrono;

class Timer
{
    public:
        Timer() : m_begin(high_resolution_clock::now()) {}
        void reset(){ m_begin = high_resolution_clock::now();}

        //defaultly, the unit of the output is milliseconds.
        template<typename Duration = milliseconds> int64_t elapsed() const
        {
            return duration_cast<Duration>(high_resolution_clock::now()-m_begin).count();
        }
        
        //the unit of the output is changed microseconds.
        int64_t elapsed_micro() const
        {
            return elapsed<microseconds>();
        }

        //the unit of the output is changed nanoseconds.
        int64_t elapsed_nano() const
        {
            return elapsed<nanoseconds>();
        }


        //the unit of the output is chanved seconds.
        int64_t elapsed_seconds() const
        {
            return elapsed<seconds>();
        }

        //the unit of the output is changed minutes.
        int64_t elapsed_minutes() const
        {
            return elapsed<minutes>();
        }

        //the unit of the output is changed hours.
        int64_t elapsed_hours() const
        {
            return elapsed<hours>();
        }

    public:
        time_point<high_resolution_clock> m_begin;
};

/*
 *test example
 *
#include "timer.hpp"
#include <iostream>

using namespace std;

 void fun()
{
    cout<<"hello world!"<<endl;
}


int main()
{
    Timer t;
    t.reset();
    fun();
    cout<<t.elapsed()<<endl;
}
*/
