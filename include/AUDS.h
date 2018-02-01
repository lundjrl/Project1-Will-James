#include <iostream>
#include <cstdlib>
template <typename T>

class AUDS{
	public:
		/******************************************************
 		 * Constructor for AUDS to make an array of 
 		 * starting size 100 of generic elements
 		 * @author William Shreeve
 		 * ***************************************************/
		AUDS(){
			currentSize = 0;
			currentMaxSize = 100;
			data = new T[currentMaxSize];
		}

		/******************************************************
 		 * Deconstructor for AUDS to free up memory.
 		 * @author William Shreeve
 		 * ***************************************************/
		~AUDS(){
			delete[] data;
		}

		/******************************************************
  		 * Copy constructor to take parameter AUDS 
 		 * and copy it to this AUDS.
 		 *
 		 * @author William Shreeve
 		 *
 		 * @param other AUDS to copy to this AUDS
 		 *****************************************************/
		AUDS(const AUDS &other){
			currentSize = other.currentSize;
			currentMaxSize = other.currentMaxSize;
			data = new T[currentMaxSize];
			for(int i = 0; i < currentSize; i++){
				data[i] = other.data[i];
			}
		}
		
		/******************************************************
 		 * Operator function for AUDS to swap the two 
 		 * values of this and other AUDS
 		 * 
 		 * @author William Shreeve
 		 *
 		 * @param other AUDS to swap this AUDS with 
 		 *****************************************************/
		AUDS& operator=(AUDS other){
			std::swap(currentSize, other.currentSize);
			std::swap(currentMaxSize, other.currentMAxSize);
			std::swap(data, other.data);
			return *this;
		}	
		
		/******************************************************
 		 *Returns the currentSize of the AUDS
 		 *
 		 *@return current size of the array
		 *****************************************************/
		int size(){
			return currentSize;
		}

		/******************************************************
 		 * Generates a random number, then mods it with
 		 * current size of the array. Swaps it with the
 		 * last element of the list and returns it.
 		 *
 		 * @author James Lund
 		 *
 		 * @return a random element of the array
 		 * ***************************************************/
		T pop(){
			if(currentSize >= 2){
				int randIndex = rand() % currentSize;
				std::swap(data[rand], data[currentSize-1]);
				T temp = data[currentSize-1];
				data[currentSize-1] = NULL;
				currentSize--;
				return temp;
			}
			if(currentSize == 1){
				currentSize--;
				return data[0];
			}
			if(currentSize == 0){
				return NULL;
			}
	
		}
		
		/******************************************************
 		 * Adds the generic element to the end of the array
 		 * list
 		 * 
 		 * @author James Lund
 		 *
 		 * @param element to add to data structure
 		 * ***************************************************/
		void push(T e){
			if(currentSize == currentMaxSize){
				increaseSize();
			}
			data[currentSize++] = e;
		}

		
	private:
		/** Generic Pointer to data array*/
		T* data;
		
		/** Current size of the array*/
		int currentSize;

		/** Max size for the array*/
		int currentMaxSize;
		
		/******************************************************
 		 * Creates a new array of size 1.5*current max size
 		 * and copies the data to that array, then assigns
 		 * the adress to this AUDS.
 		 *
 		 * @author William Shreeve
 		 * ***************************************************/
		void increaseSize(){
			T* newData = new T[currentMaxSize * 1.5];
			for(int i = 0; i <= currentSize; i++){
				newData[i] = data[i];
			}
			currentMaxSize = currentMaxSize * 1.5;
			data = newData;	
		}
};

