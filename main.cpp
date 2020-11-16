#include <iostream>
#include <cstring>
#include <math.h>
#include <fstream>

using namespace std;
//function prototypes
void create(int* arr, int size); 
void buildHeap(int* arr, int i, int size); 
void display(int* arr, int size); 

int main(){
  
  char in[100]; //for input
  int* arr = new int[100]; //the heap  
  int num; //int input
  int count;  
  cout << "Heap. Commands: create, delete, display, quit" << endl; 
  cout << "values are printed with its parent in parenthases" << endl;
  while(true){ //continue looping
    cout << "enter a command: " << endl;
    cin >> in;
    
    if(strcmp(in, "create")==0){
      cout << "file (f) or input (i)?" << endl;
      cin >> in;
      if(strcmp(in, "f")==0){
	//get the file
	count = 0;
	cout << "file path: " << endl; 
	cin >> in;
	ifstream file;
	file.open(in);
	//while loop to read nums on the line
	while(file >> num){
	  arr[count] = num;
	  count++;
	}
	file.close();
	//close the file and create the heap
	create(arr, count);
	//input by file
      }
      else if(strcmp(in, "i")==0){
	count = 0; 
	while(true){
	  cout << "input number, -1 to stop: " << endl; 
	  cin >> num;
	  //loop until we get to -1
	  if(num == -1){
	    break; 
	  }
	  else{
	    //add numbers to array
	    arr[count] = num;
	    count++;
	  }
	}
	//create the heap with the inputted numbers
	create(arr, count);
      }
    }
    
    else if(strcmp(in, "delete")==0){
      cout << "number to delete: " << endl;
      cin >> num;
      for(int i = 0; i < 100; i++){
	//identify the number to delete
	if(arr[i]==num){
	  //set the current array index to the last index
	  //we don't need to worry because now the size is restricted after we delete
	  arr[i] = arr[count - 1];
	  //decrease the size by 1
	  count -= 1;
	  //recreate the heap
	  create(arr, count);
	  break; 
	}
      }
    }
    else if(strcmp(in, "display") == 0){
      display(arr, count);
    }
    else if(strcmp(in, "quit")==0){
      delete arr;
      return 0; 
    }
    else{
      cout << "unknown input" << endl;
    }
  }
}

void create(int* arr, int size){
  int start = (size/2) -1;  
  //start from last node that isn't on the bottom 
  for(int i = start; i >= 0; i--){
    //start building from there
    buildHeap(arr, i, size); 
  }
}
//idea for swapping values came from geeksforgeeks
void buildHeap(int* arr, int i, int size){ 
  int top = i; //the node at the top
  int left = 2*i +1;  //the node to the left
  int right = 2*i +2; //the node to the right
  if((left < size)&&(arr[left] > arr[top])){
    top = left; //if the left is within the array and the left is larger than the top
    //swap
  }
  if((right < size) && (arr[right] > arr[top])){
    top = right; //same as before except with right
  }
  //if something has been swapped, we swap the two
  if(top != i){
    int placeholder = arr[i];
    arr[i] = arr[top];
    arr[top] = placeholder;
    //if we swap, we need to keep on building to maintain
    buildHeap(arr, top, size); 
  }
}
void display(int* arr, int size){
  //print out a new line exponentially
  int count = 2; 
  for(int i = 0; i < size; i++){
    if((i+2)==count){
      //if we need to print out a new line
      cout << arr[i];
      if(i != 0){
	//if it is our root, we don't need to add the parent
	cout << "(" << arr[(int)floor((i-1)/2)] << ") ";
      }
      cout << endl;
      count *= 2; 
    }
    else{
      cout << arr[i] << " (" << arr[(int)floor((i-1)/2)] << ") ";
    }
  }
  cout << endl;
}
