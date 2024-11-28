#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <string>

template <typename T>
void bubbleSort_while_for_shorter(T arr[], int n) {
    int last = n - 1;
    while (last > 0) {
        int newLast = 0;
        for (int i = 0; i < last; ++i) {
            if (arr[i] > arr[i + 1]) {
                // Swap elements
                T temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                newLast = i;
            }
        }
        last = newLast;
    }
}

template <typename T>
void bubbleSort_while_for(T arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                // Swap elements
                T temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}

template <typename T>
void bubbleSort_for_for(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }
}



template <typename T>
void bubbleSort_while_for_shorter_indicator(T* arr, int n) {
    int last = n - 1;
    while (last > 0) {
        int newLast = 0;
        for (int i = 0; i < last; ++i) {
            if (*(arr + i) > *(arr + i + 1)) {
                // Swap elements
                T temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                newLast = i;
            }
        }
        last = newLast;
    }
}

template <typename T>
void bubbleSort_while_for_indicator(T* arr, int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (*(arr + i) > *(arr + i + 1)) {
                // Swap elements
                T temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                swapped = true;
            }
        }
    } while (swapped);
}

template <typename T>
void bubbleSort_for_for_indicator(T* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (*(arr + j) > *(arr + j + 1)) {
                // Swap elements
                T temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;

            }
        }
    }
}


int* generateRandomArray(int n) {
    // Inicjalizacja generatora liczb losowych
    srand(time(nullptr));

    // Alokacja pami?ci dla tablicy
    int* array = new int[n];

    // Wype?nienie tablicy losowymi liczbami
    for (int i = 0; i < n; i++) {
        array[i] = rand();
    }

    return array;
}

template <typename T>
void showArray(T array[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << "\n";
}

template <typename T>
bool testIfSorted(T array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

float* generateFloatArrayFromIntArray(int tab[], int n) {
    float* array = new float[n];

    for (int i = 0; i < n; i++) {
        float number = (float)tab[i];
        array[i] = number;
    }
    return array;
}

template <typename T>
using SortFunction = void(*)(T[], int);

template <typename T>
int printSortingResult(SortFunction<T> sortFunction, T array[], int size) {
    auto start = std::chrono::high_resolution_clock::now();

    sortFunction(array, size);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    if (testIfSorted(array, size)) {
        std::cout << "Sorting succeeded in " << elapsed.count() << " microseconds" << std::endl;
    }
    else {
        std::cout << "Sorting failed" << std::endl;
    }
    return elapsed.count();
}
void writeResultsToFile(const std::string& filename, const std::vector<std::pair<std::string, int>>& results) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const auto& result : results) {
            file << result.first << ", " << result.second << std::endl;
        }
        file.close();
        std::cout << "Results written to " << filename << std::endl;
    }
    else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}

int main()
{

    std::vector<std::pair<std::string, int>> results;
    int testing_values[3] = {10, 500, 10000};
    for (int i = 0; i < 3; i++) {
        int size = testing_values[i];
        int* intArray_for_for_index = generateRandomArray(size);
        float* floatArray_for_for_index = generateFloatArrayFromIntArray(intArray_for_for_index, size);
        int for_for_index_int_time = printSortingResult<int>(bubbleSort_for_for, intArray_for_for_index, size);
        int for_for_index_float_time = printSortingResult<float>(bubbleSort_for_for, floatArray_for_for_index, size);
        results.push_back({ "for_for_index_int_time, " + std::to_string(size) + " ", for_for_index_int_time});
        results.push_back({ "for_for_index_float_time, " + std::to_string(size) + " ", for_for_index_float_time });

        int* intArray_while_for_index = generateRandomArray(size);
        float* floatArray_while_for_index = generateFloatArrayFromIntArray(intArray_while_for_index, size);
        int while_for_index_int_time = printSortingResult<int>(bubbleSort_while_for, intArray_while_for_index, size);
        int while_for_index_float_time = printSortingResult<float>(bubbleSort_while_for, floatArray_while_for_index, size);
        results.push_back({ "while_for_index_int_time, " + std::to_string(size) + " ", while_for_index_int_time });
        results.push_back({ "while_for_index_float_time, " + std::to_string(size) + " ", while_for_index_float_time });

        int* intArray_while_for_shorter_index = generateRandomArray(size);
        float* floatArray_while_for_shorter_index = generateFloatArrayFromIntArray(intArray_while_for_shorter_index, size);
        int while_for_shorter_index_int_time = printSortingResult<int>(bubbleSort_while_for_shorter, intArray_while_for_shorter_index, size);
        int while_for_shorter_index_float_time = printSortingResult<float>(bubbleSort_while_for_shorter, floatArray_while_for_shorter_index, size);
        results.push_back({ "while_for_shorter_index_int_time, " + std::to_string(size) + " ", while_for_shorter_index_int_time });
        results.push_back({ "while_for_shorter_index_float_time, " + std::to_string(size) + " ", while_for_shorter_index_float_time });


        int* intArray_for_for_indicator = generateRandomArray(size);
        float* floatArray_for_for_indicator = generateFloatArrayFromIntArray(intArray_for_for_indicator, size);
        int for_for_indicator_int_time = printSortingResult<int>(bubbleSort_for_for_indicator, intArray_for_for_indicator, size);
        int for_for_indicator_float_time = printSortingResult<float>(bubbleSort_for_for_indicator, floatArray_for_for_indicator, size);
        results.push_back({ "for_for_indicator_int_time, " + std::to_string(size) + " ", for_for_indicator_int_time });
        results.push_back({ "for_for_indicator_float_time," + std::to_string(size) + " ", for_for_indicator_float_time });


        int* intArray_while_for_indicator = generateRandomArray(size);
        float* floatArray_while_for_indicator = generateFloatArrayFromIntArray(intArray_while_for_indicator, size);
        int while_for_indicator_int_time = printSortingResult<int>(bubbleSort_while_for_indicator, intArray_while_for_indicator, size);
        int while_for_indicator_float_time = printSortingResult<float>(bubbleSort_while_for_indicator, floatArray_while_for_indicator, size);
        results.push_back({ "while_for_indicator_int_time," + std::to_string(size) + " ", while_for_indicator_int_time });
        results.push_back({ "while_for_indicator_float_time, " + std::to_string(size) + " ", while_for_indicator_float_time });


        int* intArray_while_for_shorter_indicator = generateRandomArray(size);
        float* floatArray_while_for_shorter_indicator = generateFloatArrayFromIntArray(intArray_while_for_shorter_indicator, size);
        int while_for_shorter_indicator_int_time = printSortingResult<int>(bubbleSort_while_for_shorter_indicator, intArray_while_for_shorter_indicator, size);
        int while_for_shorter_indicator_float_time = printSortingResult<float>(bubbleSort_while_for_shorter_indicator, floatArray_while_for_shorter_indicator, size);
        results.push_back({ "while_for_shorter_indicator_int_time, " + std::to_string(size) + " ", while_for_shorter_indicator_int_time });
        results.push_back({ "while_for_shorter_indicator_float_time, " + std::to_string(size) + " ", while_for_shorter_indicator_float_time });
    }

    

    writeResultsToFile("sorting_results.txt", results);

}
