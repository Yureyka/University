using System;
using System.IO;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            _ = new AsterTester();
            Log.Close();
        }
    }

    public class AsterCheck
    {
        public Tuple<string, string> Aster(string str)
        {
            int k = 0;
            char sym = '/';
            string ss = str;
            for (int i = 0; i < str.Length; i++)
            {
                if (i == str.Length - 1)
                {
                    Console.WriteLine("Знак '*' находится в конце, замена невозможна");
                    break;
                }
                else
                    if (str[i] == sym)
                    {
                        k++;
                        char[] charStr = str.ToCharArray();
                        charStr[i + 1] = '-';
                        str = new string(charStr);
                    }
            }
            if (k > 0)
            {
                Console.WriteLine("Итоговая строка: " + str);
            }
            else Console.WriteLine("Знак '*' не найден");
            return new Tuple<string, string>(ss, str);
        }
        
    }

    public class Log
    {
        private static readonly StreamWriter log = new StreamWriter("log.txt");
        static public void AddString(string s)
        {
            log.WriteLine(s);
        }
        static public void Close()
        {
            log.Close();
        }
    }

    abstract class Tester
    {
        protected void LogMessage(string s)
        {
            Log.AddString(s);
        }
    }

    class AsterTester : Tester
    {
        private readonly AsterCheck OUT;
        public AsterTester()
        {
            OUT = new AsterCheck();
            Run();
        }

        private void Run()
        {
            AsterTest1();
        }
        public void AsterTest1()
        {
            string[] strings = {
                "Первая строка",
                "*Вторая строка",
                "Третья строка*",
                "Четвертая строк*а",
                "Пят/ая ст/рока",
                "Шест**ая строка",
                "********"
            };

            foreach (var str in strings)
            {
                var result = OUT.Aster(str);
                Log.AddString($"Исходная строка: {result.Item1}");
                Log.AddString($"Конечная строка: {result.Item2} \n\n");
            }

        }
    }
}
