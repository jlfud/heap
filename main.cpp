#include <iostream>

using namespace std;

int main(){
  char in[100]; 
  int num; 
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
	while(true){
	  cout << "input number, -1 to stop: " << endl; 
	  cin >> num;
	  if(num == -1){
	    break; 
	  }
	  else{
	    //add number to heap
	  }
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
