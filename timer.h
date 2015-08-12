/**
 * @file  timer.h
 * @brief The definition of the timer class.
 */

#ifndef TIMER_H
#define TIMER_H

#include <time.h>


namespace Utility
{

    /**
     * @class Timer
     * @brief The Timer class which be used to timing.
     */
    class Timer
    {
        public:
            Timer();
            bool Start();
            bool Finish();
            long GetDurationInClocks();
            double GetDuration();


        private:
            clock_t Starting;
            clock_t Finished;
            clock_t DurationInClocks;
            double  Duration;
            bool    IsStarted;
            bool    IsEnded;
    };

}


#endif // TIMER_H
