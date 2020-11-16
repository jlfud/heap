#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

void create(int* arr, int size); 
void buildHeap(int* arr, int i, int size); 
void display(int* arr, int size); 

int main(){
  
  char in[100]; 
  int* arr = new int[100]; 
  int num;
  int count; 
  cout << "Heap. Commands: create, delete, display, quit" << endl; 
  cout << "values are printed with its parent in parenthases" << endl;
  while(true){
    cout << "enter a command: " << endl;
    cin >> in;
    
    if(strcmp(in, "create")==0){
      cout << "file (f) or input (i)?" << endl;
      cin >> in;
      if(strcmp(in, "f")==0){
	count = 0;
	cout << "file path: " << endl; 
	cin >> in;
	//input by file
      }
      else if(strcmp(in, "i")==0){
	count = 0; 
	while(true){
	  cout << "input number, -1 to stop: " << endl; 
	  cin >> num;
	  if(num == -1){
	    break; 
	  }
	  else{
	    arr[count] = num;
	    count++;
	  }
	}
	create(arr, count);
      }
    }
    
    else if(strcmp(in, "delete")==0){
      cout << "number to delete: " << endl;
      cin >> num;
      for(int i = 0; i < 100; i++){
	if(arr[i]==num){
	  arr[i] = arr[count - 1];
	  //arr[count - 1] = NULL;
	  count -= 1;
	  create(arr, count);
	  break; 
	}
      }
    }
    else if(strcmp(in, "display") == 0){
      display(arr, count);
    }
    else if(strcmp(in, "quit")==0){
      return 0; 
    }
    else{
      cout << "unknown input" << endl;
    }
  }
}

void create(int* arr, int size){
  int start = (size/2) - 1;
  for(int i = start; i >= 0; i--){
    buildHeap(arr, i, size); 
  }
}
void buildHeap(int* arr, int i, int size){ 
  int top = i; //the node at the top
  int left = 2*i +1;  //the node to the left
  int right = 2*i +2; //the node to the right
  if((left < size)&&(arr[left] > arr[top])){
      top = left;
  }
  if((right < size) && (arr[right] > arr[top])){
      top = right; 
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
  int count = 2; 
  for(int i = 0; i < size; i++){
    if((i+2)==count){
      cout << arr[i];
      if(i != 0){
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
