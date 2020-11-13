#include <iostream>
#include <cstring>

using namespace std;

void create(int* heap, int i); 

int main(){
  char in[100]; 
  int* heap = new int[100]; 
  int num;
  int count; 
  cout << "Heap. Commands: create, delete, display, quit" << endl; 

  while(true){
    cout << "enter a command: " << endl;
    cin >> in;
    
    if(strcmp(in, "create")==0){
      cout << "file (f) or input (i)?" << endl;
      cin >> in;
      if(strcmp(in, "f")==0){
	cout << "file path: " << endl; 
	cin >> in;
	//input by file
      }
      else if(strcmp(in, "i")==0){
	//by manual input
	count = 0; 
	while(true){
	  cout << "input number, -1 to stop: " << endl; 
	  cin >> num;
	  if(num == -1){
	    break; 
	  }
	  else{
	    heap[count] = num;
	    count++;
	  }
	}
	for(int i = count/2 - 1; i >= 0; i++){
	  create(heap, i); 
	}
      }
    }
    
    else if(strcmp(in, "delete")==0){
      //delete 
    }
    else if(strcmp(in, "display") == 0){
      //display
    }
    else if(strcmp(in, "quit")==0){
      return 0; 
    }
    else{
      cout << "unknown input" << endl;
    }
  }
}

void create(int* heap, int i){
  int size = sizeOf(heap)/sizeOf(heap[0]);
  int left = (i*2)+1;
  int right = (i*2)+2;
  if(left < 
}
