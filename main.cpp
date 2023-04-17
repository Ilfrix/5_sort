#include <iostream>
#include <ctime>
#include <chrono>

void selection_sort(int *arr, int n){
    int cur_index = 0;
    long long comp = 0, mov = 0;
    int min_val = int(1e9), min_index, i = 0, j = 0;
    while (i < n){
        j = i;
        while (j < n){
            comp ++;
            if (min_val > arr[j]){
                min_val = arr[j];
                min_index = j;
            }
            ++j;
        }
        if (cur_index != min_index) mov++;
        std::swap(arr[cur_index++], arr[min_index]);
        min_val = int(1e9);
        min_index = -1;
        ++i;
    }
    std::cout << comp << '+'<< mov << '\n';
}

void bubble_sort(int *arr, int n){
    long long comp = 0, mov = 0;
    int i = 0, j = 0;
    while (i < n){
        j = n - i;
        bool flag = false;
        while (j >= 1){
            comp ++;
            if (arr[j] > arr[j-1]){
                mov++;
                flag = true;
                std::swap(arr[j], arr[j - 1]);
            }
            --j;
        }
        if (!flag)  break;
        ++i;
    }
    std::cout << comp << '+'<< mov << '\n';
}
int main(){
    const int n = 10000;
    int *b = new int[n];
    srand( time(0) );
    //100, 1000, 10000, 100000, 1000000
    for (int i = 0; i < n; ++i)    b[i] = rand();
    auto start = std::chrono::steady_clock::now();
    bubble_sort(b, n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    bool flag = true;
    for (int i = 1; i < n; ++i){
        if (b[i] < b[i - 1])    flag = false;
    }
    if (flag)   std::cout << "ok\n";
    return 0;
}