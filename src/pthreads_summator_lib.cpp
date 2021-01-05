#include <iostream>
#include <fstream>
#include <sstream>
#include <pthread.h>
#include "pthreads_summator_lib.h"

using namespace std;

struct thr_data {
    int numberFile;
    long long sum;
};

long long one_thread() {
    stringstream ss;
    long long sum = 0;
    for (int i = 1; i <= 10; i++) {
        ss << "..\\Files\\" << i << ".txt";
        ifstream in(ss.str());
        ss.str(string());
        if (in.is_open()) {
            while (!in.eof()) {
                int num;
                in >> num;
                sum += num;
            }
        }
        in.close();
    }
    return sum;
}

void* thread(void *thread_data) {
    stringstream ss;
    thr_data *data = (thr_data*) thread_data;

    ss << "..\\Files\\" << data->numberFile << ".txt";
    ifstream in(ss.str());
    ss.str(string());
    if (in.is_open()) {
        while (!in.eof()) {
            int num;
            in >> num;
            data->sum += num;
        }
    }
    in.close();
}

long long more_pthr() {
    pthread_t threads[N];
    thr_data* threadData = new thr_data[N];
    long long all_sum = 0;
    for(int i = 0; i < N; i++){
        threadData[i].numberFile = i + 1;
        threadData[i].sum = 0;
        pthread_create(&(threads[i]), NULL, thread, &threadData[i]);
    }
    for(int i = 0; i < N; i++){
        pthread_join(threads[i], NULL);
        all_sum+=threadData[i].sum;
    }
    unsigned int time_end = clock();
    delete[] threadData;
    return all_sum;
}