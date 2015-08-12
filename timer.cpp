/**
 * @file timer.cpp
 * @brief The implement of the timer class.
 *
 */



#include "timer.h"

#include <assert.h>


/**
 * @brief The defualt constructor
 *
 * @author sheng
 * @version 0.1.0
 * @history  author    version     date            description      \n
 *           sheng      0.1.0    2014/03/08     build the function
 *
 */
Utility::Timer::Timer():
    Starting(0),Finished(-1),  DurationInClocks(-1),
    Duration(-1.0), IsStarted(false), IsEnded(false)
{

}



/**
 * @brief Start to timing
 * @return true if the timer is never started befor
 *         false otherwise
 *
 * @author sheng
 * @version 0.1.0
 * @history  author    version     date            description      \n
 *           sheng      0.1.0    2014/03/08     build the function
 *
 */
bool Utility::Timer::Start()
{
    // if the timer is not started befor, starting the timer.
    assert(!IsStarted);
    if (IsStarted == false)
    {
        IsStarted = true;
        IsEnded = false;
        Starting = clock();
        return true;
    }

    return false;
}




/**
 * @brief Finishing the timer
 * @return true  if the timer is started and never finished before.
 *         false otherwise
 *
 * @author sheng
 * @version 0.1.0
 * @history  author    version     date            description      \n
 *           sheng      0.1.0    2014/03/08     build the function
 *
 */
bool Utility::Timer::Finish()
{
    // if the timer is started and never finished before, return true.
    assert(IsStarted && (!IsEnded));
    if (IsStarted && (!IsEnded))
    {
        IsEnded = true;
        Finished = clock();
        DurationInClocks = Finished - Starting;
        Duration = (double)DurationInClocks / CLOCKS_PER_SEC;
    }

    return false;
}




/**
 * @brief Get the duration in clocks.
 * @return the duration in clocks.
 *
 * @author sheng
 * @version 0.1.0
 * @history  author    version     date            description      \n
 *           sheng      0.1.0    2014/03/08     build the function
 *
 */
long Utility::Timer::GetDurationInClocks()
{
    return DurationInClocks;
}




/**
 * @brief Get the duration in seconds.
 * @return the duration in seconds
 *
 * @author sheng
 * @version 0.1.0
 * @history  author    version     date            description      \n
 *           sheng      0.1.0    2014/03/08     build the function
 *
 */
double Utility::Timer::GetDuration()
{
    return Duration;
}



