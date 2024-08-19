#include <iostream>
#include <stdexcept>

class SmartArray {
private:
    int* data;
    int capacity;
    int size;

public:
   
    SmartArray(int initialCapacity) : capacity(initialCapacity), size(0) {
        if (initialCapacity <= 0) {
            throw std::invalid_argument("Должна быть положительной");
        }
        data = new int[capacity];
    }

   
    ~SmartArray() {
        delete[] data;
    }

 
    SmartArray(const SmartArray& other) : capacity(other.capacity), size(other.size) {
        data = new int[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    
    SmartArray& operator=(const SmartArray& other) {
        if (this != &other) {
            delete[] data; 
            capacity = other.capacity;
            size = other.size;
            data = new int[capacity];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

  
    void push_back(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

  
    int at(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Out of bounds");
        }
        return data[index];
    }
};

int main() {
    try {
        setlocale(LC_ALL, "Russian");


        SmartArray arr(5);
        arr.push_back(1);
        arr.push_back(4);
        arr.push_back(155);

        SmartArray new_array(2);
        new_array.push_back(44);
        new_array.push_back(34);

        
        arr = new_array;

       
        std::cout << "Elements of arr: ";
        for (int i = 0; i < sizeof(arr); ++i) {
            std::cout << arr.at(i) << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}