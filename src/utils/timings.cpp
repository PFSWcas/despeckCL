#include "timings.h"

#include <algorithm>
#include <iostream>

timings::map timings::join(const map& tm1, const map& tm2)
{
    map new_tm = tm1;

    new_tm = std::accumulate( tm2.begin(), tm2.end(), new_tm,
            []( auto& tm, const auto& p )
            {
            return (tm[p.first] += p.second, tm);
            } );

    return new_tm;
}

double timings::total_time(const map &tm)
{
    return std::accumulate( tm.begin(), tm.end(), 0.0,
            []( const double total, const auto& p )
            {
            return total + p.second;
            } );
}

void timings::print(const map& tm)
{
    for(auto p : tm) {
        std::cout << "kernel execution time for " << p.first \
                  << " is " << p.second << " secs" << std::endl;
    }
    std::cout << "total kernel execution time is " << total_time(tm) << " secs" << std::endl;
}