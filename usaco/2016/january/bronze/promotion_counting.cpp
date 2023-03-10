#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream fin("promote.in");
	ofstream fout("promote.out");

  vector participants (4, vector(2, 0));
  vector promotions (4, 0);

  int total_before = 0, total_after = 0;

  for(int i = 0; i < 4; i++){
    fin >> participants[i][0] >> participants[i][1];
    total_before += participants[i][0];
    total_after += participants[i][1];
  }

  promotions[0] = total_after - total_before;
  
  for(int i = 0; i < 3; i++){
    promotions[i + 1] = (
      participants[i][0] - participants[i][1] + promotions[i]
    );

    fout << promotions[i + 1] << "\n";
  }

  fin.close();
  fout.close();
}