#include <iostream>

class myVector{
private:
    const int defaultSize = 10;
    int lastElement = 0;

    // Allocate new memory with 10 more elements, copy contents, de-allocate old memory
    void grow(){
        int* bigger = new int[sizeVar + 10];

        // Copy contents
        for(int i = 0; i < sizeVar; i++){
            bigger[i] = foo[i];
        }

        delete foo;
        foo = bigger;
        sizeVar += 10;
    }

public:

    int sizeVar;
    int* foo;

    // Default constructor - allocate 10 elements
    myVector(){
        foo = new int[defaultSize];
        sizeVar = defaultSize;
    }

    // Constructor for specified size
    myVector(int number){
        foo = new int[number];
        sizeVar = number;
    }

    // Add element
    // Must perform a size check to see if we need to reallocate
    void add(int numToAdd){

        // If last element less than size, we good
        if(lastElement < sizeVar){
            foo[lastElement] = numToAdd;
            lastElement++;
        }else{
            std::cout << "Resizing the vector\n";
            this->grow();
            foo[lastElement] = numToAdd;
            lastElement++;
        }
    }

    // Remove item
    // Must check size to ensure not empty
    void remove(){

    }

    // Return number of elements in the vector
    int sizeOf(){
        return sizeVar;
    }

    // Retrieve a value at index
    int get(int index){
        return foo[index];
    }

    // Destructor
    ~myVector(){
        delete this;
    }
};


int main(){

    std::cout << "Hello we are testing the Vector" << std::endl;

    myVector v;
    myVector v2(25);
    std::cout << "V: \nWith size: " << v.sizeOf() << std::endl;

    for(int i = 0; i < 100; i++){
    	v.add(i);
    	std::cout << "Added: " << i << std::endl;
    }

    std::cout << "V2: \nWith size: " << v2.sizeOf() << std::endl;

    for(int i = 0; i < 30; i++){
    	v2.add(i);
    	std::cout << "Added: " << i << std::endl;
    }

    std::cout << "V: \nWith size: " << v.sizeOf() << std::endl;
    std::cout << "V2: \nWith size: " << v2.sizeOf() << std::endl;

    return 0;

}
