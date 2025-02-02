#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   int n, q;
   cin >> n >> q;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   sort(arr, arr + n);

   while (q--)
   {
      int x;
      cin >> x;
      int l = 0, r = n - 1;
      bool flag = false;

      while (l <= r)
      {
         int mid_idx = (l + r) / 2;

         if (x == arr[mid_idx])
         {
            flag = true;
            break;
         }

         if (x > arr[mid_idx])
         {
            l = mid_idx + 1;
         }
         else
         {
            r = mid_idx - 1;
         }
      }

      if (flag == true)
         cout << "found" << endl;
      else
         cout << "not found" << endl;
   }

   return 0;
}