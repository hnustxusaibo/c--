#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    const long long N = 1e8; // 数组大小
    int *arr = new int[N];   // 动态分配数组内存
    int *tem = new int[N];

    // 用时间作为随机数种子，以确保每次运行结果不同
    std::srand(std::time(nullptr));

    // 生成随机数
    for (long long i = 0; i < N; ++i)
    {
        arr[i] = std::rand();     // 生成随机数
        tem[i] = std::rand() % N; // 随机访问位置

        if (i % (N / 100) == 0)
        {
            std::cout << "\rrunning " << i / (N / 100) << '%'; // 使用 \r 实现覆盖输出
            std::flush(std::cout);
        }
    }

    std::cout << std::endl; // 输出换行符

    // 暂停程序5秒
    cout << "wait 5s" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));

    cout << "start add" << endl;
    // 记录起始时间
    clock_t start_time = clock();

    // 累加求和
    long long sum = 0;
    for (long long i = 0; i < N; ++i)
    {
        sum = (1ll * sum + arr[tem[i]]) % N;
    }

    // 计算所用时间并输出求和结果和所用时间
    double elapsed_time = static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC;
    std::cout << "Sum: " << sum << '\n';
    std::cout << "Time: " << elapsed_time << " seconds\n";

    delete[] arr; // 释放动态分配的数组内存

    return 0;
}