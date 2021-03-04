/*

    Duncan Stannard 
    C0444224

    Comp 166
    
    Feb 16, 2021

*/
#if !defined(STATISTICS_H)
#define STATISTICS_H

double mean(const double sum, const int count);
double ssdev(const double sum, const double sumsq, const int count);

#endif // STATISTICS_H