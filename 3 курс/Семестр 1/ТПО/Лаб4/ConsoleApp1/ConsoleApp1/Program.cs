using System;
using System.IO;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            _ = new AsterTester();
            Log.Close();
        }
    }

    class AsterCheck
    {
        public char sym = '*';
        public string Aster(string str)
        {
            int k = 0;
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
            return str;
        }
    }

    class Asterr
    {
        public AsterCheck Changer(string s)
        {
            AsterCheck changed = new AsterCheck();
            changed.sym = 'е';
            return changed;
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
            Asterr asterr = new Asterr();
            string[] strings = {
                "Те/ст",
                "Те*ст",
                "Тест",
            };

            Log.AddString($"Символ на замену: {asterr.Changer("").sym}");
            Log.AddString("---Результаты---");

            foreach (var s in strings)
            {
                asterr.Changer(s);
                Log.AddString($"{asterr.Changer(s).Aster(s), 10}");
            }
        }
    }
}