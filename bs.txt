/**
* Class for an Almost Useless Data Structure (AUDS). Holds
* a dynamically sized array that automatically resizes by 50%
* whenever pushing exceeds current size.
* 
* @author Edric Lin
* @version 2/4/2018
*/

template <typename T>
class AUDS {
public:
    
    /**
    * Default constructor for AUDS object. Initialized with 
    * a capacity for 100 items.
    */
    AUDS() {
        listSize = 100;
        top = 0;
        objList = new T[listSize ];
    }

    /**
    * Copy constructor for AUDS object. Makes a deep copy of
    * an already existing AUDS object.
    *
    * @param other the address of the AUDS object to copy
    */
    AUDS(const AUDS& other) {
       listSize = other.listSize ;
       top = other.top;
       objList = new T[listSize ];

       for (int i = 0; i < top; i++) {
           objList[i] = other.objList[i];
       }
    }

    /**
    * Copy operator= for AUDS object. Swaps data with an
    * existing AUDS object.
    *
    * @param other the AUDS object to swap data with
    */
    AUDS& operator=(AUDS other) {
        std::swap(listSize , other.listSize );
        std::swap(top, other.top);
        std::swap(objList, other.objList);

        return *this;
    }     
    
    /**
    * Deconstructor for AUDS object.
    */
    ~AUDS() {
        delete[] objList;
    }

    /**
    * Checks the current number of items in the AUDS object.
    *
    * @return the current number of items in the AUDS object
    */
    int size() {
        return top;
    }

    /**
    * Checks the current AUDS capacity.
    *
    * @return the current AUDS capacity
    */
    int sizeOfList() {
        return listSize;
    }

    /**
    * Add an item to the AUDS object.
    *
    * @param x the item to add to the AUDS object
    */
    void push(T x) {

        // if object list is full i.e. top is at end of array
        if (top == listSize) {

            // create new array 50% larger
            int newSize = listSize * 1.5;
            T* tempList = new T[newSize];

            // copy current object list to larger array
            for(int i = 0; i < top; i++) {
                tempList[i] = objList[i];
            }

            // swap larger array with object list
            std::swap(objList, tempList);

            // adjust size variable
            listSize = listSize * 1.5;

            // free temp list
            delete[] tempList;	
        }
        objList[top++] = x;
    }

    /**
    * Remove a random item from the AUDS object and replace 
    * it with the last item in the last item.
    *
    * @return the item that was removed
    */
    T pop() {
        int i = rand() % listSize;
        T temp = objList[i];
        objList[i] = objList[top - 1];
        top--;
        return temp;
    }
    
private:

    /** the list of items to be held in the AUDS object */
    T* objList;

    /** the next open spot in the list */
    int top;

    /** the current number of objects in the list */
    int listSize ;
};