#include <iostream>

template <typename T>

class AUDS{
	public:

		
		AUDS(){
			currentSize = 0;
			currentMaxSize = 100;
			data = new T[currentMaxSize];
		}

		~AUDS(){
			delete[] data;
		}

		/*************************************************
  		 * Copy constructor to take parameter AUDS 
 		 * and copy it to this AUDS.
 		 *
 		 * @parameter other AUDS to copy to this AUDS
 		 ************************************************/
		AUDS(const AUDS &other){
			currentSize = other.currentSize;
			currentMaxSize = other.currentMaxSize;
			data = new T[currentMaxSize];
			for(int i = 0; i < currentSize; i++){
				data[i] = other.data[i];
			}
		}

		AUDS& operator=(AUDS other){
			std::swap(currentSize, other.currentSize);
			std::swap(currentMaxSize, other.currentMAxSize);
			std::swap(data, other.data);
			return *this;
		}	

		int size(){
			return currentSize;
		}

		
	private:
		/** Generic Pointer to data array*/
		T* data;
		
		/** Current size of the array*/
		int currentSize;

		/** Max size for the array*/
		int currentMaxSize;
		
		void increaseSize(){
		}
};

