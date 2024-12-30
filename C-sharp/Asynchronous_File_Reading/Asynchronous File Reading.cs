using System;
using System.IO;
using System.Threading.Tasks;

class Program
{
   static async Task Main()
   {
       string path = ""example.txt""; // Ensure this file exists.
       string content = await ReadFileAsync(path);
       Console.WriteLine(content);
   }

   static async Task<string> ReadFileAsync(string path)
   {
       using (StreamReader reader = new StreamReader(path))
       {
           return await reader.ReadToEndAsync();
       }
   }
}
