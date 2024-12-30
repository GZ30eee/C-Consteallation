using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        var numbers = new List<int> { 5, 3, 8, 1, 4 };
        
        var sortedEvenNumbers = numbers
            .Where(n => n % 2 == 0)
            .OrderBy(n => n);

        Console.WriteLine(""Sorted Even Numbers:"");
        foreach (var number in sortedEvenNumbers)
        {
            Console.WriteLine(number);
        }
    }
}
