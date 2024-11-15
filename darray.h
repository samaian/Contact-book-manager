#ifndef DARRAY_H
#define DARRAY_H
#include <stdexcept>
#include <iostream>
using namespace std;
template <class T>
class Darray {
private:
    int capacity;
    int sizee;
    T *arr;
    void resizee(int New)
    {
        T *ptr = new T[New];
        for(int i=0; i<sizee; ++i) {
            ptr[i]=arr[i];
        }
        delete []arr;
        arr=ptr;
        capacity=New;

    }
public:
    /*  Darray() {
          capacity=2;
          sizee=0;
          arr=new T[capacity];
      }
  */
    Darray( int cap=2):capacity(cap),sizee(0)
    {
        arr = new T[capacity];
    }
    void append (T element)
    {
        if(sizee>=capacity)
        {
            resizee(capacity*2);
        }
        arr[sizee++]=element;
    }
    void Insert(T elem, int index)
    {
        if(sizee<index)throw std::out_of_range("Index out of range");
        if (sizee >= capacity)
        {
            resizee(capacity *2);
        }
        for (int i = sizee; i >= index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = elem;
        sizee++;
    }
    void Remove()
    {
        sizee = sizee - 1;
        if(sizee<=capacity/4) resizee(capacity/2);
    }
    // Delete
    void Delete(int index)
    {
        if (index >= sizee)
        {
            throw std::overflow_error("Invalid\n");
        }

        for (int i = index; i < sizee; i++)
        {
            arr[i] = arr[i + 1];
        }
        sizee--;
        if(sizee<=capacity/4)resizee(capacity/2);
    }
    void clearr()
    {
        sizee=0;
        resizee(2);
    }

    T Get(int index)
    {
        if (index >= sizee)
        {
            throw std::overflow_error("Invalid\n");
        }
        cout <<endl;

        return arr[index];
    }
    int GetSize() const
    {
        cout << endl;
        return sizee;
    }
    void Reverse()
    {
        int start = 0;
        int End = sizee - 1;
        while (start < End)
        {
            T temp = arr[start];
            arr[start] = arr[End];
            arr[End] = temp;
            start++;
            End--;
        }
    }
    void BubbleSort()
    {
        for (int i = 0; i < sizee - 1; i++)
        {
            for (int j = 0; j < sizee - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    int LinearSearch(T elem)
    {
        for (int i = 0; i < sizee; i++)
        {
            if (arr[i] == elem)
                return i;
        }
        cout << endl;
        return -1; // not found
    }
    // 2- binary search need sorted array
    int  BinarySearch(T elem)
    {
        size_t low = 0, high = sizee - 1, mid = 0;
        while (low < high)
        {
            mid = (low + (high - low)) / 2;
            if (arr[mid] == elem)
            {
                return mid;
            }
            if (arr[mid] < elem)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << endl;
    }
    void print()
    {
        for(int i=0; i<sizee; i++){
            cout<<arr[i];
            cout<<" ";
        }
    }


    ~Darray()
    {
        delete []arr;
    }

    const T& operator[](int index) const {
        if (index < 0  ||index >= sizee) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }
    T& operator[](int index) {
        if (index < 0  ||index >= sizee) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    int getSize() const {
        return sizee;
    }
    void remove(int index) {
        if (index < 0 || index >= sizee) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < sizee - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --sizee;
    }
    int RemoveDuplicates() {
        if (sizee == 0) return 0;  // If the array is empty, return 0.

        int NewSize = 1;  // Initialize the new size to 1.

        for (int i = 1; i < sizee; i++) {  // Start from the second element.
            if (!(arr[i] == arr[NewSize - 1])) {  // Check if the current element is not equal to the previous unique element.
                arr[NewSize++] = arr[i];  // Assign the current element to the new position and increment NewSize.
            }
        }

        sizee = NewSize;  // Update the size of the array.
        return sizee;  // Return the new size of the array after removing duplicates.
    }

    // Display
    void Disply()
    {
        cout << "The Array is : ";
        for (int i = 0; i < sizee; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void SaveToFile(string filename) {
        ofstream file;
        file.open(filename);
        for (int i = 0; i < sizee; i++) {
            file << arr[i] << " ";
        }
        file.close();
    }





};
#endif DARRAY

