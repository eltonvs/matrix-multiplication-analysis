#include <iostream>
using std::cout;
using std::endl;

#include "write_file.h"

int main(int argc, char *argv[]) {
    if (argc == 2) {
		WriteFile wf(argv[1], 0);
		// wf.write_result_matrix(vector<vector<int>>());
	} else {
		cout << "Error" << endl;
	}
    return 0;
}
