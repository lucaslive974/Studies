#include <vector>

namespace algorithms {

using namespace std;
namespace sorting {
void bubbleSort();
void insertionSort();
void selectionSort();
void mergeSort(vector<int> &vec);
void quickSort();
} // namespace sorting

namespace lists {
void floyd();
} // namespace lists

namespace graphs {
void dfs();
void bfs();
} // namespace graphs

namespace numeric {
int fastExponentiation(int num, int expo);
}

} // namespace algorithms