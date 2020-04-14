#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include "array.h"
#include "timer.h"

using namespace std;

int main()
{
   Array<int, 10000> *arrays = new Array<int, 10000>[100];
   Timer timer;

   cout << endl;
   for (int i = 0; i < 100; i++)
      arrays[i].SetArray();
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].introsort();
   timer.stop_measuring();
   timer.print_duration();
 }