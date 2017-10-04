#include "read_file.h"
#include "write_file.h"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        ReadFile rf(argv[1]);
        WriteFile wf(argv[1], 0);
        /*
        wf.write_result_matrix(vector<vector<int>>());
        rf.get_matrix_a();
        cout << endl;
        rf.get_matrix_b();
        */
    } else {
        cout << "Error" << endl;
    }

    return 0;
}
