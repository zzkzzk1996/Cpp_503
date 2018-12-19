//
// Created by Zekun Zhang on 2018-12-16.
//
//
#include "StockAccount_Zekun.h"
#include "Filer_Zekun.h"
#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h"
#include <iostream>
#include <engine.h>

#pragma comment(lib, "libmx.lib")
#pragma comment(lib, "libmex.lib")
#pragma comment(lib, "libeng.lib")

using namespace std;

void StockAccount::printGraph() {
    Filer filer;
    Engine *ep;
    ep = engOpen(NULL);
    if (ep == NULL) {
        cout << " Error: engine open failed " << endl;
        exit(1);
    }

    //only draw the graph of the first 100 points(if less than 100, then draw the graph of all points)
    //get the time of the first data
    double time_first;
    //the time when the portfolio value is stored - time_first
    double time[100];
    //the portfolio value
    double value[100];

    ifstream ifs;
    int j = 0;
    ifs.open(PORTFOLIO);
    if (ifs.fail() && !ifs.is_open()) {
        cout << " Error: File can't open " << endl;
        return;
    }
    else {
        string line;
        //while not reach the end of the file and while haven't read in 100 pairs of data
        while (getline(ifs, line) && j < 100) {
            if (j == 0) {
                time_first = convertertime(filer.Getdata(line, "price")); // get the time of the first data
            }
            time[j] = (convertertime(filer.Getdata(line, "price")) - time_first) / 60.0; //  /60.0 to get the minute
            value[j] = stod(filer.Getdata(line, "name")); //get the value
            j++;
        }
        ifs.close();
    }

    for (int i = 0; i < 100; ++i) {
        if (i >= j) { //if the number of value is less than 100, then the rest value and time in the array will equal to the last one
            time[i] = time[i - 1];
            value[i] = value[i - 1];
        }
    }

    mxArray *X;
    X = mxCreateDoubleMatrix(1, 100, mxREAL);
    memcpy((void *)mxGetPr(X), (void *)time, sizeof(double) * 100);
    mxArray *Y;
    Y = mxCreateDoubleMatrix(1, 100, mxREAL);
    memcpy((void *)mxGetPr(Y), (void *)value, sizeof(double) * 100);

    engPutVariable(ep, "x", X);
    engPutVariable(ep, "y", Y);
    engEvalString(ep, "plot(x, y)");

    system("pause");

    //clean operation
    mxDestroyArray(X);
    mxDestroyArray(Y);
    engEvalString(ep, "close;");

    //close engine
    engClose(ep);
}

double StockAccount::convertertime(string time) const {
    double result = 0.0;
    stringstream ss(time);
    int hour, minute,second;
    char* times = (char*)time.c_str();
    sscanf(times,"%d:%d:%d", &hour, &minute, &second);
    result = hour * 3600 + minute * 60 + second;
    return result; //seconds
}


