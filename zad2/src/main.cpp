#include <cstdlib>
#include <stdlib.h>
#include<vector>
#include "array.h"
#include "timer.h"

using namespace std;

int main()
{
   Array<int,1000000 >* array = new Array<int,1000000 >[100];
   Timer timer;

   cout << endl;
  /*  cout << "50% sorted" << endl; */
   for (int i = 0; i < 100; i++)
   {
      array[i].SetArray();
   }
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
   {
      array[i].mergesort();
   }
   timer.stop_measuring();
   timer.print_duration();
}