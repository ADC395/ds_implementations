#include <iostream>

class myVector{
private:
    const int defaultSize = 10;
    int lastElement = 0;

    // Allocate new memory with 10 more elements, copy contents, de-allocate old memory
    void grow(){
        int* bigger = new int[this->sizeVar + 10];

        // Copy contents
        for(int i = 0; i < this->sizeVar; i++){
            bigger[i] = foo[i];
        }

        delete foo;
        foo = bigger;
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
    }

    // Add element
    // Must perform a size check to see if we need to reallocate
    void add(int numToAdd){

        // If the last element is NULL, we have room to add
        if(foo[sizeVar] == '\0'){
            foo[lastElement + 1] = numToAdd;
            lastElement++;
        }else{
            std::cout << "Your vector doesn't have enough space allocated. Tell your developer to finish his function!";
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
    std::cout << v.sizeOf() << std::endl;

    for(int i = 0; i < v.sizeOf(); i++){
        std::cout << v.get(i) << std::endl;
    }

    return(0);
}
