#include <iostream>
using namespace std;
#define IM INT_MAX

void makeMatrix(int matrix_short_way[6][6], int matrix_sequence_nodes[6][6]) {
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 5; j++)
			cout << "   " << matrix_short_way[i][j];
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 5; j++)
			cout << "   " << matrix_sequence_nodes[i][j];
		cout << "\n";
	}
}

void main() {
	int matrix_short_way[6][6] = { {  0, 28, 21, 59, 12, 27 },
									  {  7,  0, 24, IM, 21,  9 },
									  {  9, 32,  0, 13, 11, IM },
									  {  8, IM,  5,  0, 16, IM },
									  { 14, 13, 15, 10,  0, 22 },
									  { 15, 18, IM, IM,  6,  0 } };

	int matrix_sequence_nodes[6][6] = { { 0, 2, 3, 4, 5, 6 },
									   { 1, 0, 3, 4, 5, 6 },
									   { 1, 2, 0, 4, 5, 6 },
									   { 1, 2, 3, 0, 5, 6 },
									   { 1, 2, 3, 4, 0, 6 },
									   { 1, 2, 3, 4, 5, 0 } };
	for (int m = 0; m < 6; m++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (matrix_short_way[i][j] > matrix_short_way[i][m] + matrix_short_way[m][j]) {
					matrix_short_way[i][j] = matrix_short_way[i][m] + matrix_short_way[m][j];
					matrix_sequence_nodes[i][j] = matrix_sequence_nodes[i][m];
				}
			}
		}
	}
	makeMatrix(matrix_short_way, matrix_sequence_nodes);
}