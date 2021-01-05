#include <iostream>
#include <sstream>
#include <generate_files.h>
#include "pthreads_summator_lib.h"

using namespace std;

int main() {
    stringstream ss;

    //генерация случайных файлов
    create_files(ss);
    //

    unsigned int time_begin = clock();
    cout << "Сумма высчитанная в одном потоке: " << one_thread() << endl;
    unsigned int time_end = clock();
    cout << "Один поток посчитал сумму чисел во всех файлах за: " << (time_end - time_begin) / 1000.0 << endl;
    time_begin = clock();
    cout << "Сумма высчитанная в " << N << " потоках: " << more_pthr() << endl;
    time_end = clock();
    cout << N << " потоков посчитали сумму чисел во всех файлах за: " << (time_end - time_begin) / 1000.0 << endl;
    return 0;
}
