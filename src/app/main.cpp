#include<iostream>
#include"sorting/mergeSort.hpp"
#include"sorting/parallelMergeSort.hpp"
#include<vector>
#include<chrono>

int main(int argc,char *argv[]){
    const int size=10000000;
    std::vector<int>nums(size);
    std::vector<int>parallelNums(size);
    for(int i=0;i<size;i++){
        nums[i] = rand()%size;
        parallelNums[i] = nums[i];
    }
    MergeSort* mergeSort=new MergeSort(&nums);
    auto start=std::chrono::high_resolution_clock::now();
    mergeSort->sort();
    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double>duration=end-start;
    std::cout<<"Time taken to sort "<<size<<" elements is "<<duration.count()<<" seconds"<<std::endl;
    delete mergeSort;

    ParallelMergeSort* pmergeSort=new ParallelMergeSort(&nums);
    start=std::chrono::high_resolution_clock::now();
    pmergeSort->sort();
    end=std::chrono::high_resolution_clock::now();
    duration=end-start;
    std::cout<<"Time taken to sort via parallel mergeSort "<<size<<" elements is "<<duration.count()<<" seconds"<<std::endl;
    delete pmergeSort;
}