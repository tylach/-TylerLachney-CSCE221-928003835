#ifndef MIN_HEAP_H
#define MIN_HEAP_H

using namespace std;       

class MinHeap
{
  private:

    int *arr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap

  public:

    // Constructor for the MinHeap
    MinHeap(int cap) {
        heap_size = 0; 
        capacity = cap; 
        arr = new int[cap]; 
    }

    // to ge the index of parent of node at index i
    inline int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    inline int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    inline int right(int i) { return (2*i + 2); } 

    // Returns the minimum key (key at root) from min heap 
    inline int getMin() {  return arr[0]; } 


	//print function implemented to help test
	void print(){
		for(int i = 0 ; i < heap_size ; ++i){
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	// parent = (i-1)/2
	// left = (2*i)+1
	//right = (2*i)+2
    // Inserts a new key 'k' 
    void insertKey(int k) {
        if(heap_size == capacity){
        	cout << "couldn't add not enough space" << endl;
			return;
        }
		
		heap_size += 1;
		int temp = 0;
		int i = heap_size - 1;
        arr[i] = k;
		while(i != 0 && arr[(i-1)/2] > arr[i]){
			temp = arr[i];
			arr[i] = arr[(i-1)/2];
			arr[(i-1)/2] = temp;
			i = (i-1)/2;
		}
    }

    // Extract the root which is the minimum element 
    int extractMin() {
		// reconstruct the list without the minimum element;
		if(heap_size <= 0){
			 return INT_MAX;
		}
		int ans = arr[0];
		if (heap_size == 1){ 
			heap_size--; 
		    return ans; 
		}
		arr[0] = arr[heap_size-1];
		heap_size--;
		//move the biggest element down accordingly
		int i = -1;
		int l;
		int r;
		int smallest = 0;
		int temp = 0;
		while(i != smallest){
			
			i = smallest;
			l = left(i);
			r = right(i);
			
			
			if(l < heap_size && arr[l] < arr[i]){
		    	smallest = l; 
			}
		    if(r < heap_size && arr[r] < arr[smallest]){
		    	smallest = r; 
			}
			
		    if(smallest != i){ 
				temp = arr[i];
				arr[i] = arr[smallest];
				arr[smallest] = temp;
		    }
		}
        return ans;
    }
  
    // Decreases key value of key at index i to newVal 
    void decreaseKey(int i, int newVal) {
		if(newVal >= arr[i]){
			return;
		}
		arr[i] = newVal;
		int temp = 0;
		while(i != 0 || arr[parent(i)] > arr[i]){
			temp = arr[i];
			arr[i] = arr[parent(i)];
			arr[parent(i)] = temp;
			
			i = parent(i);
		}
        // Remove below line after your implementation
    }
  
    // Deletes a key stored at index i 
    void deleteKey(int i) {
		decreaseKey(i, INT_MIN); 
		extractMin(); 
        return;
    }
};

#endif
