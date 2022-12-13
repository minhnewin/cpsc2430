#include <bits/stdc++.h>
#include <math.h>
#include <limits>
using namespace std;

int sumDigits(int num)
{
  if (num == 0)
    return 0;
  return (num % 10 + sumDigits(num / 10));
}

int fifthRoot(int num, int temp1, int temp2)
{
  if (num == 0 || num == 1){
    return num;
  }else{
    temp2 = temp1*temp1*temp1*temp1*temp1;
    if (temp2 < num){
      temp1++;
      temp1 = fifthRoot(num, temp1, temp2);
    }
  }
  return temp1;
}


int doubleInt(int num)
{
  return num + num;
}

int halveInt(int c, int counter)
{
  if(counter + counter == c){
    return counter;
  }else{
    return halveInt(c, counter + 1);
  }
}

int egyptDivision(int c, int b)
{
  int a = 1, d = 0, counterA = 1, counterB = 1;
  while (b < c){
    a = doubleInt(a);
    b = doubleInt(b);
  }
  while (c != b){
    if (c > b){
      c = c - b;
      d = a + d;
      cout << endl << d << endl;
    }
    a = halveInt(a, counterA);
    b = halveInt(b, counterB);
  }
  if (c == b){
    d = a + d;
    return d;
  }
  return d + 1;
}

double helper(int depth, int i, int temp) {
  if (i == depth) {
    return (i+1)*(sqrt(i + 6));
  }else{
    temp = helper(depth, i+1, temp);
    return (i + 1)*(sqrt(i + 6 + temp));
  }
}

double ramanujan(int depth) {
  int temp = 0;
  int i = 0;
  return helper(depth, i, temp);
}

int main()
{ 
  //sumDigits
  int num, num2, total;
  double result;
  int a;
  cout << "num? ";
  cin >> num;
  total = sumDigits(num);
  cout << "Sum of digits in " << num << " is "<< total << endl;
  cout << endl << endl;

  //fifthRoot
  int temp1 = 1, temp2 = 0;
  cout << "fifth root of num? ";
  cin >> num;
  result = fifthRoot(num, temp1, temp2);
  cout << "fifth root of " << num << " is: " << result << endl;
  cout << endl << endl;
  
  //egyptianMath
  cout << "eqyptian math: " << endl;
  cout << "dividend? ";
  cin >> num;
  cout << "divisor? ";
  cin >> num2;
  result = egyptDivision(num, num2);
  cout << num << " divided by " << num2 << " using egyptian math is "
       << result << endl;
  cout << endl << endl;

  //ramanujan
  cout << "depth? ";
  cin >> a;
  result = ramanujan(a);
  cout << result << endl;
  cout << "The result if depth carries out to infinity is 4." << endl;
  return 0;
}
