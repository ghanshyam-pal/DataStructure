#include <stdio.h>

int main()
{
  int n, a[1000], i, j, t, f = 0;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (i = 1 ; i <= n - 1; i++)
   {
    t = a[i];

    for (j = i - 1 ; j >= 0; j--) 
    {
      if (a[j] > t) 
      {
        a[j+1] = a[j];
        f = 1;
      }
      else
        break;
    }
    if (f)
      a[j+1] = t;
  }

  printf("Sorted list in ascending order:\n");

  for (i = 0; i <= n - 1; i++) {
    printf("%d\n", a[i]);
  }

  return 0;
}
