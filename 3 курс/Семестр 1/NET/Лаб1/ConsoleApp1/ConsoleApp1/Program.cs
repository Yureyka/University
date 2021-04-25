using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace ConsoleApp1
{
    class Lab1
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Поиск столбца с наибольшим avg");
            Console.Write("Введите размерность матрицы: ");
            double avg1 = 0, avg2 = 0, num = 0;
            int n = Int32.Parse(Console.ReadLine());
            int[,] arr = new int[n, n];
            Random rnd = new Random();
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    arr[i, j] = rnd.Next(0, 30);
            for (int i = 0, length = arr.GetLength(0); i < length; i++)
            {
                for (int j = 0; j < length; j++)
                    Console.Write((arr[i, j]) + "\t");
                Console.WriteLine();
            }
            for (int j = 0, length = arr.GetLength(0); j < length; j++)
            {
                for (int i = 0; i < length; i++)
                {
                    avg1 += arr[i, j];
                }
                avg1 = avg1 / length;
                if (avg1 > avg2)
                {
                    avg2 = avg1;
                    avg1 = 0;
                    num = j + 1;
                }
            }
            Console.WriteLine("Наибольшее среднее значение в столбце " + num);

            Console.WriteLine("\nПоиск слов, начинающихся и заканчивающихся на одну и ту же букву");
            Console.WriteLine("Введите строку: ");
            string String = Console.ReadLine();
            string[] words = String.Split(new char[] { ' ' });
            IEnumerable<string> resultWords = null;
            if (words.Count() > 0)
                resultWords = words.Where(x => x[x.Length - 1] == x[0]);
            Console.WriteLine("Найденное слово: ");
            if (resultWords.Count() > 0)
                foreach (var s in resultWords)
                    Console.WriteLine(s);
            else
                Console.WriteLine("Слово не найдено");

            Console.WriteLine("\nРаспознавание английского текста");
            Console.WriteLine("Введите текст: ");
            string text = Console.ReadLine();
            if (Regex.IsMatch(text, @"\p{IsLatinExtendedAdditional}", RegexOptions.IgnorePatternWhitespace))
            {
                Console.WriteLine("Текст на английском");
            }
            else Console.WriteLine("Текст не на английском");
            Console.ReadLine();
        }
    }
}