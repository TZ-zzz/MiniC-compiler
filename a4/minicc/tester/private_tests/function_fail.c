// Definition fails


void factorial(int n);

void factorial(int n) {
   int i;
   int result;
   if (n < 0)
       return 0;
   else {
       for (i = 1; i <= n; i = i + 1) {
           result = result * i;
       }
   }
   return result;
}



int countDigits(int n);

int countDigits(int n) {
   int count;
   count = 0;
   while (n != 0) {
       count = count + 1;
       n = n / 10;
   }
   return;
}



bool reverse(int n);

bool reverse(int n) {
   int reversed_number;
   reversed_number = 0;

   while (n != 0) {
       reversed_number = reversed_number * 10 + n - n / 10 * 10;
       n = n / 10;
   }

   return reversed_number;
}