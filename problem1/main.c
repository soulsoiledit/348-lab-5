#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE* fptr;
  fptr = fopen("input", "r"); 

  char buf[100];
  char months[12][20] = {
    "January  ", "February ", "March    ", "April    ", "May      ", "June     ", "July     ", "August   ", "September", "October  ", "November ", "December "
  };
  char months_trimmed[12][20] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
  };
  float sales[12];

  // Monthly report, chronological
  //
  int indx = 0;
  float max = 0.0;
  float min = 1000000000.0;
  float avg = 0.0;
  printf("Monthly sales report for 2022:\n");
  printf("Month      Sales\n");
  while (fscanf(fptr, "%s", buf) == 1) {
      printf("%s   $%s\n", months[indx], buf);

      float floatbuf;
      sscanf(buf, "%f", &floatbuf); 
      sales[indx] = floatbuf;
      avg += floatbuf;
    
      if (floatbuf >= max) {
        max = floatbuf;
      }

      if (floatbuf <= min) {
        min = floatbuf;
      }

      indx++;
  }
  fclose(fptr);

  // Min, max, avg
  //
  printf("\nSales summary:\n");
  for (int i = 0; i < 12; i++) {
    float sale = sales[i];

    if (sale == min) {
      printf("Minimum sales: $%.2f (%s)\n", min, months_trimmed[i]);
    } else if (sale == max) {
      printf("Maximum sales: $%.2f (%s)\n", max, months_trimmed[i]);
    }

    indx++;
  }
  printf("Average sales: $%.2f\n", avg / 12);

  // Moving average
  printf("\nSix-Month Moving Average Report:\n");
  for (int i = 0; i < 12; i++) {
    int maximum = i + 6;
    if (maximum > 12) {
      break;
    }

    float sum = 0;
    for (int j = i; j < maximum; j++) {
      sum += sales[j];
    }
    sum /= 6;
    printf("%s - %s   $%.2f\n", months[i], months[maximum-1], sum);
  }

  // Monthly, highest to lowest, what on earth
  printf("\nSales report (Highest to Lowest):\n");
  printf("Month       Sales\n");

  for (int i = 0; i < 12; i++) {
    float curmax = -1;
    int max_index = -1;

    for (int m = 0; m < 12; m++) {
      if (sales[m] > curmax) {
        curmax = sales[m];
        max_index = m;
      }
    }

    printf("%s   $%.2f\n", months[max_index], curmax);
    sales[max_index] = -1;
  }

  return 0;
}
