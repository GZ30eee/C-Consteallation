using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        foreach (var number in GenerateNumbers(10))
        {
            Console.WriteLine(number);
        }
    }

    static IEnumerable<int> GenerateNumbers(int count)
    {
        for (int i = 1; i <= count; i++)
        {
            yield return i;
            System.Threading.Thread.Sleep(100); // Simulate delay
        }
    }
}
