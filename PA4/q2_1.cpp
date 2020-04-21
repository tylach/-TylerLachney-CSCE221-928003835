#include<iostream>
#include<climits>
#include"MinHeap.h"


int main(){
    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2);
	h.print(); 
    h.deleteKey(1); 
	h.print();
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45);
	h.print();
    cout << h.extractMin() << " "<<endl; 
    cout << h.getMin() << " "<<endl; 
	h.print();
	
    h.decreaseKey(2, 1); 
	h.print();
    cout << h.getMin(); 
    cout << endl;
	
    /*h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(3); 
    h.insertKey(1); 
    h.insertKey(2); 
	h.extractMin();
	h.extractMin();
	cout << h.getMin() << endl;
	h.print();*/
	
	/*h.insertKey(10);
	h.print();
	 
	h.insertKey(12); 
	h.print();
	
	h.insertKey(1); 
	h.print();
	
	h.insertKey(14); 
	h.print();
	
	h.insertKey(6); 
	h.print();
	
	h.insertKey(5); 
	h.print();
	
	h.insertKey(8); 
	h.print();
	
	h.insertKey(15); 
	h.print();
	
	h.insertKey(3); 
	h.print();
	
	h.insertKey(9); 
	h.print();
	
	h.insertKey(7); 
	h.print();
	
	h.insertKey(4); 
	h.print();
	
	h.insertKey(11); 
	h.print();
	
	h.insertKey(13); 
	h.print();
	
	h.insertKey(2); 	
	h.print();*/
    return 0;
}
