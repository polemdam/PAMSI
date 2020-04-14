#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include "array.h"
#include "timer.h"

using namespace std;

int main()
{
   Array<int, 100000> *arrays = new Array<int, 100000>[100];
   Timer timer;

   cout << "Tablica 100 000 elementów" << endl;
   cout << "Tablica posortowana 25% " << endl;
   

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(25);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].quicksort();
   timer.stop_measuring();
   cout << "Quicksort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(25);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].mergesort();
   timer.stop_measuring();
   cout << "Mergesort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(25);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].introsort();
   timer.stop_measuring();
   cout << "Introsort: ";
   timer.print_duration();
   cout << endl;

   cout << "Tablica posortowana 50% " << endl;

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(50);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].quicksort();
   timer.stop_measuring();
   cout << "Quicksort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(50);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].mergesort();
   timer.stop_measuring();
   cout << "Mergesort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(50);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].introsort();
   timer.stop_measuring();
   cout << "Introsort: ";
   timer.print_duration();
   cout << endl;

   cout << "Tablica posortowana 75% " << endl;

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(75);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].quicksort();
   timer.stop_measuring();
   cout << "Quicksort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(75);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].mergesort();
   timer.stop_measuring();
   cout << "Mergesort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(75);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].introsort();
   timer.stop_measuring();
   cout << "Introsort: ";
   timer.print_duration();
   cout << endl;

   cout << "Tablica posortowana 95% " << endl;

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(95);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].quicksort();
   timer.stop_measuring();
   cout << "Quicksort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(95);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].mergesort();
   timer.stop_measuring();
   cout << "Mergesort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(95);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].introsort();
   timer.stop_measuring();
   cout << "Introsort: ";
   timer.print_duration();
   cout << endl;

   cout << "Tablica posortowana 99% " << endl;

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(99);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].quicksort();
   timer.stop_measuring();
   cout << "Quicksort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(99);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].mergesort();
   timer.stop_measuring();
   cout << "Mergesort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(99);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].introsort();
   timer.stop_measuring();
   cout << "Introsort: ";
   timer.print_duration();
   cout << endl;

   cout << "Tablica posortowana 99.7% " << endl;

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(99.7);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].quicksort();
   timer.stop_measuring();
   cout << "Quicksort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(99.7);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].mergesort();
   timer.stop_measuring();
   cout << "Mergesort: ";
   timer.print_duration();

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(99.7);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].introsort();
   timer.stop_measuring();
   cout << "Introsort: ";
   timer.print_duration();
   cout << endl;

     cout << "Tablica posortowana odwrotnie " << endl;

      for (int i = 0; i < 100; i++)
      arrays[i].SetArray(-1);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].quicksort();
   timer.stop_measuring();
   cout << "Quicksort: ";
   timer.print_duration();
   

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(-1);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].mergesort();
   timer.stop_measuring();
   cout << "Mergesort: ";
   timer.print_duration();
  

   for (int i = 0; i < 100; i++)
      arrays[i].SetArray(-1);
   timer.start_measuring();
   for (int i = 0; i < 100; i++)
      arrays[i].introsort();
   timer.stop_measuring();
   cout << "Introsort: ";
   timer.print_duration();
   cout << endl;
}