#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
struct node{
  int value;
  int parent = -1;
};
void create(node** arr, int size); 
void buildHeap(node** arr, int i, int size); 
void display(node** arr, int size); 

int main(){
  
  char in[100]; 
  node** arr = new node*[100]; 
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
	    node* no = new node();
	    no->value = num;
	    arr[count] = no;
	    count++;
	  }
	}
	create(arr, count);
      }
    }
    
    else if(strcmp(in, "delete")==0){
      //delete
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

void create(node** arr, int size){
  int start = (size/2) - 1;
  for(int i = start; i >= 0; i--){
    buildHeap(arr, i, size); 
  }
}
void buildHeap(node** arr, int i, int size){ 
  int top = i; //the node at the top
  int left = 2*i +1;  //the node to the left
  int right = 2*i +2; //the node to the right
  if((left < size)&&(arr[left]->value > arr[top]->value)){
      top = left;
  }
  if((right < size) && (arr[right]->value > arr[top]->value)){
      top = right; 
  }
  //if something has been swapped, we swap the two
  if(top != i){
    node* placeholder = arr[i];
    arr[i] = arr[top];
    arr[top] = placeholder;
    //if we swap, we need to keep on building to maintain
    buildHeap(arr, top, size); 
  }
}
void display(node** arr, int size){
  int top[size];
  for(int i = 0; i < size; i++){
    top[i] = -1; 
  }
  for(int i = 0; i < size; i++){
    if(arr[(int)floor((i)/2)]->value != arr[(int)floor((i+1)/2)]->value){
      cout << arr[i]->value << "(" << arr[(int)floor(i/2)]->value << ") ";
      cout << endl;
    }
    else{
      cout << arr[i]->value << " (" << arr[(int)floor(i/2)]->value << ") ";
    }
  }
  cout << endl;
}
