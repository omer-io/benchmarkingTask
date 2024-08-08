#include <benchmark/benchmark.h>
#include <iostream>
#include <vector> 
#include <list>
using namespace std;

uint64_t sum_of_vector_squared(int num_entries){
    uint64_t sum = 0;
    vector<uint64_t> nums(num_entries);
    for (int i = 0; i < num_entries; i++){
        nums[i] = i;
    }
    
    vector<uint64_t> numsq(num_entries);
    for (int i = 0; i < num_entries; i++){
        numsq[i] = nums[i] * nums[i];
        sum += numsq[i];
    }
    return sum;
    
}

uint64_t sum_of_list_squared(int num_entries){
    uint64_t sum = 0;
    list<uint64_t> nums;
    for (int i = 0; i < num_entries; i++){
        nums.push_back(i);
    }
    
    list<uint64_t> numsq;
    for (auto num : nums){
        numsq.push_back(num * num);
        sum += num * num;
    }
    return sum;
    
}

static void BM_sum_of_vector_squared(benchmark::State& state) {
  for (auto _ : state){
    sum_of_vector_squared(10);
  }

}
static void BM_sum_of_list_squared(benchmark::State& state) {
  for (auto _ : state){
    sum_of_list_squared(10);
  }

}

BENCHMARK(BM_sum_of_vector_squared);
BENCHMARK(BM_sum_of_list_squared);

BENCHMARK_MAIN();