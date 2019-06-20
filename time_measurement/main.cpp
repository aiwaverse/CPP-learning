#include <chrono>
#include <cstdio>
#include <iostream>

void time_cout(void) {
    auto start{std::chrono::high_resolution_clock::now()};
    for (int i = 0; i < 10000; ++i)
        std::cout << i << "\n";
    auto end{std::chrono::high_resolution_clock::now()};
    auto duration{std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()};
    std::cout << "Foram " << duration << " ns, media de " << duration / 10000 << " ns \n";
}
void time_printf(void) {
    auto start{std::chrono::high_resolution_clock::now()};
    for (int i = 0; i < 10000; ++i)
        std::printf("%d\n", i);
    auto end{std::chrono::high_resolution_clock::now()};
    auto duration{std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()};
    std::printf("Foram %ld ns, com media de %ld ns\n", duration, duration / 10000);
}
int main(int argv, char* argc[]) {
    if (argv != 2)
        throw std::runtime_error("dumb bitch\n");
    if (argc[1] == std::to_string(1)) {
        time_printf();
        std::printf("printf time\n");
    }
    if (argc[1] == std::to_string(2)) {
        time_cout();
        std::cout << "cout time\n";
    }
    return 0;
}