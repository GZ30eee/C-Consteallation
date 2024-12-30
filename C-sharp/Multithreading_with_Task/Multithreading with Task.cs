using System;
using System.Threading.Tasks;

class Program
{
    static async Task Main()
    {
        Task task1 = Task.Run(() => PrintNumbers(1));
        Task task2 = Task.Run(() => PrintNumbers(2));
        
        await Task.WhenAll(task1, task2);
    }

    static void PrintNumbers(int threadId)
    {
        for (int i = 1; i <= 5; i++)
        {
            Console.WriteLine($""Thread {threadId}: {i}"");
            Task.Delay(100).Wait(); // Simulate work
        }
    }
}
