#include "read_file.h"

int main(int argc, char *argv[]) {
    
	if (argc == 2) {
    	ReadFile rf(argv[1]);
    	/*rf.get_matrix_a();
    	cout << endl;
    	rf.get_matrix_b();*/
	} else {
		cout << "Error" << endl;
	}

    return 0;
}
