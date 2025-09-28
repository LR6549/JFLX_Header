#ifndef JFLX_SORTINGALGORITHMS
#define JFLX_SORTINGALGORITHMS

#include <algorithm>
#include <iterator>
#include <type_traits>

/*
* All sorting objects (list, vector, ...) need Idexing Abilities, as well as a default constructor!
*/
namespace JFLX {
    /*
    *   Stats:
    *   | Best         | Average      | Worst        | Memory     | Stable     |
    *   |--------------|--------------|--------------|------------|------------|
    *   | O(n log(n))  | O(n log(n))  | O(n log(n))  | n          | Yes        |
    */
    namespace MergeSort {
        template <typename T>
        T topDownMerge(T leftList, T rightList) {
            T result;

            auto leftIt = leftList.begin();
            auto rightIt = rightList.begin();

            while (leftIt != leftList.end() && rightIt != rightList.end()) {
                if (*leftIt <= *rightIt) {
                    result.insert(result.end(), *leftIt);
                    ++leftIt;
                } else {
                    result.insert(result.end(), *rightIt);
                    ++rightIt;
                }
            }

            result.insert(result.end(), leftIt, leftList.end());
            result.insert(result.end(), rightIt, rightList.end());

            return result;
        }

        template <typename T>
        T topDownMergeSort(T& list) {
            T leftList;
            T rightList;

            if (list.size() <= 1) {
                return list;
            }

            for (auto it = list.begin(); it < list.end(); ++it) {
                if (distance(list.begin(), it) < list.size() / 2) {
                    leftList.insert(leftList.end(), *it);
                } else {
                    rightList.insert(rightList.end(), *it);
                }
            }

            leftList = topDownMergeSort(leftList);
            rightList = topDownMergeSort(rightList);

            return topDownMerge(leftList, rightList);
        }

        template <typename T>
        T topDownInvertedMerge(T leftList, T rightList) {
            T result;

            auto leftIt = leftList.begin();
            auto rightIt = rightList.begin();

            while (leftIt != leftList.end() && rightIt != rightList.end()) {
                if (*leftIt >= *rightIt) {
                    result.insert(result.end(), *leftIt);
                    ++leftIt;
                } else {
                    result.insert(result.end(), *rightIt);
                    ++rightIt;
                }
            }

            result.insert(result.end(), leftIt, leftList.end());
            result.insert(result.end(), rightIt, rightList.end());

            return result;
        }

        template <typename T>
        T topDownInvertedMergeSort(T& list) {
            T leftList;
            T rightList;

            if (list.size() <= 1) {
                return list;
            }

            for (auto it = list.begin(); it < list.end(); ++it) {
                if (distance(list.begin(), it) < list.size() / 2) {
                    leftList.insert(leftList.end(), *it);
                } else {
                    rightList.insert(rightList.end(), *it);
                }
            }

            leftList = topDownInvertedMergeSort(leftList);
            rightList = topDownInvertedMergeSort(rightList);

            return topDownInvertedMerge(leftList, rightList);
        }

        template <typename T>
        void sort(T& list, bool inverted = false) {
            if (inverted) {
                list = topDownInvertedMergeSort(list);
            } else {
                list = topDownMergeSort(list);
            }
        }
    }

    /*
    *   Stats:
    *   | Best        | Average     | Worst       | Memory     | Stable     |
    *   |-------------|-------------|-------------|------------|------------|
    *   | O(n log(n)) | O(n log(n)) | O(n²)       | log(n)     | No         |
    */
    namespace QuickSort {
        template <typename T>
        int partition(T& list, int low, int high) {
            auto pivot = list[low];
            int i = low - 1;
            int j = high + 1;

            while (true) {
                do {
                    i++;
                } while (list[i] < pivot);

                do {
                    j--;
                } while (list[j] > pivot);

                if (i >= j) {
                    return j;
                }

                swap(list[i], list[j]);
            }
        }

        template <typename T>
        int partitionInverted(T& list, int low, int high) {
            auto pivot = list[low];
            int i = low - 1;
            int j = high + 1;

            while (true) {
                do {
                    i++;
                } while (list[i] > pivot);

                do {
                    j--;
                } while (list[j] < pivot);

                if (i >= j) {
                    return j;
                }

                swap(list[i], list[j]);
            }
        }

        template <typename T>
        void quickSort(T& list, int low, int high) {
            if (low >= 0 && high >= 0 && low < high) {
                int p = partition(list, low, high);
                quickSort(list, low, p);
                quickSort(list, p + 1, high);
            }
        }

        template <typename T>
        void quickSortInverted(T& list, int low, int high) {
            if (low >= 0 && high >= 0 && low < high) {
                int p = partitionInverted(list, low, high);
                quickSortInverted(list, low, p);
                quickSortInverted(list, p + 1, high);
            }
        }
        
        template <typename T>
        void sort(T& list, bool inverted = false) {
            int length = list.size();
            if (inverted) {
                quickSortInverted(list, 0, length - 1);
            } else {
                quickSort(list, 0, length - 1);
            }
        }
    }

    /*
    *   Stats:
    *   | Best        | Average     | Worst       | Memory     | Stable     |
    *   |-------------|-------------|-------------|------------|------------|
    *   | O(n²)       | O(n²)       | O(n²)       |   1        | No         |
    */
    namespace SelectionSort {
        template <typename T>
        int findSmallest(const T& list, int min, int max) {
            int smallestIndex = min;
            for (int i = min + 1; i <= max; ++i) {
                if (list[i] < list[smallestIndex]) {
                    smallestIndex = i;
                }
            }
            return smallestIndex;
        }

        template <typename T>
        void sort(T& list, bool inverted = false) {
            int length = list.size();
            if (inverted) {
                for (int i = length - 1; i > 0; --i) {
                    int index = findSmallest(list, 0, i);
                    swap(list[index], list[i]);
                }
            } else {
                for (int i = 0; i < length ; ++i) {
                    int index = findSmallest(list, i, length - 1);
                    swap(list[index], list[i]);
                }
            }
        }
    }
    
    /*
    *   Stats:
    *   | Best        | Average     | Worst       | Memory     | Stable     |
    *   |-------------|-------------|-------------|------------|------------|
    *   | n           | n²          | n²          | 1          | No         |
    */
    namespace InsertionSort {
        template <typename T>
        void sort(T& list, bool inverted = false, bool optimized = false) {
            int length = list.size();
            if (inverted) {
                for (int i = 1; i < length; ++i) {
                    int j = i;
                    while (j > 0 && list[j] > list[j - 1]) {
                        swap(list[j], list[j - 1]);
                        --j;
                    }
                }
            } else {
                for (int i = 1; i < length; ++i) {
                    int j = i;
                    while (j > 0 && list[j] < list[j - 1]) {
                        swap(list[j], list[j - 1]);
                        --j;
                    }
                }
            }
        }
    }
    
    /*
    *   Stats:
    *   | Best        | Average     | Worst       | Memory     | Stable     |
    *   |-------------|-------------|-------------|------------|------------|
    *   | n           | n²          | n²          | 1          | Yes        |
    */
    namespace GnomeSort {
        template <typename T>
        void sort(T& list, bool inverted = false) {
            int length = list.size();
            if (inverted) {
                int i = length;
                while(i > 0) {
                    if (i == length || list[i] <= list[i-1]) {
                        i --;
                    } else {
                        swap(list[i], list[i+1]);
                        i ++;
                    }
                }
            } else {
                int i = 0;
                while(i < length) {
                    if (i == 0 || list[i] >= list[i-1]) {
                        i ++;
                    } else {
                        swap(list[i], list[i-1]);
                        i --;
                    }
                }
            }
        }
    }
    
    /*
    *   Stats:
    *   | Best        | Average     | Worst       | Memory     | Stable     |
    *   |-------------|-------------|-------------|------------|------------|
    *   | n²          | n²          | n²          | 1          | No         |
    */
    namespace BubbleSort {
        template <typename T>
        void sort(T& list, bool inverted = false, bool optimized = false) {
            int length = list.size();
            bool swapped;

            if (optimized) {
                if (inverted) {
                    do {
                        swapped = false;
                        for (int i = 0; i < length - 1; ++i) {
                            if (list[i] < list[i + 1]) {
                                swap(list[i], list[i + 1]);
                                swapped = true;
                            }
                        }
                        --length;
                    } while (swapped);
                } else {
                    do {
                        swapped = false;
                        for (int i = 0; i < length - 1; ++i) {
                            if (list[i] > list[i + 1]) {
                                swap(list[i], list[i + 1]);
                                swapped = true;
                            }
                        }
                        --length;
                    } while (swapped);
                }
            } else {
                if (inverted) {
                    do {
                        swapped = false;
                        for (int i = 0; i < length - 1; ++i) {
                            if (list[i] < list[i + 1]) {
                                swap(list[i], list[i + 1]);
                                swapped = true;
                            }
                        }
                    } while (swapped);
                } else {
                    do {
                        swapped = false;
                        for (int i = 0; i < length - 1; ++i) {
                            if (list[i] > list[i + 1]) {
                                swap(list[i], list[i + 1]);
                                swapped = true;
                            }
                        }
                    } while (swapped);
                }
            }
        }
    }
}

#endif
