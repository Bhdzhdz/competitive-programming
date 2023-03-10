#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("teleportation.in");
	ofstream fout("teleportation.out");

  int a, b, x, y;
  int ans;

  fin >> a >> b >> x >> y;

  clog << a << " " << b << " " << x << " " << y << "\n";

  ans = min({
    abs(a - b),
    abs(abs(a - x) + abs(b - y)),
    abs(abs(a - y) + abs(b - x))
  });

  fout << ans << "\n";

  fin.close();
  fout.close();
}