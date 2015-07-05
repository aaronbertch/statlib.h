#ifndef STATLIB.H
#define STATLIB.H


#include <math.h>

extern double mean(int totnum, double data[])
{
    int i;
    double mean;
    double sum = 0;

    for (i=0;i<totnum;i++)
    {
        sum += data[i];
    }

    mean = sum / totnum;

    return mean;


}

extern double variance(int totnum, double data[])
{
    int i;
    double meanResult, temp, squared, total = 0, variance;

    meanResult = mean(totnum, data);


    for (i=0; i<totnum; i++)
    {
            temp = (data[i]-meanResult);
            squared = (temp * temp);
            total += squared;
    }

    variance = total / (totnum - 1);
    return variance;

}


extern double stdDev (int totnum, double data[])
{
    double varianceResult, stdDev;
    varianceResult = variance(totnum, data);
    stdDev = sqrt(varianceResult);
    return stdDev;
}

extern void sort(int totnum, double data[])
{
    int i, j;
    double temp;

    for(i=0; i < totnum-1; i++){
        for(j = i+1; j < totnum; j++){
            if(data[i] > data[j]){
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            }
        }
    }

}



extern double minValue(int totnum, double data[])
{
    int i;
    double minValue;

    sort(totnum, data);
    minValue = data[0];

    return minValue;
}

extern double median(int totnum, double data[])
{
    double medianVal;
    if(totnum % 2)
        medianVal = data[totnum/2];
    else
        medianVal = (data[totnum/2 - 1] + data[totnum/2]) / 2.0;

    return medianVal;
}


extern double maxValue(int totnum, double data[])
{

    double maxValue;

    sort(totnum, data);
    maxValue = data[totnum-1];
    return maxValue;
}



#endif
