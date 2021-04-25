using System;
using System.Threading;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            EInString eStr = new EInString();
            eStr.CheckAndPrint();
        }


    }
    class EInString
    {
        private static string str;
        public bool result;

        public EInString()
        {
            str = "qwertfgeeeeeunm";
        }

        public EInString(string _str)
        {
            str = _str;
        }

        public void CheckAndPrint()
        {
            if (EIn(str))
            {
                Console.WriteLine("В строке есть повторяющаяся 5 раз буква \"e\"");
                result = true;
            }
            else
            {
                Console.WriteLine("В строке нет повторяющейся 5 раз буквы \"e\"");
                result = false;
            }
        }

        private bool EIn(string str)
        {
            int n = 0;
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == 'e' || str[i] == 'е')
                {
                    n++;
                    if (n == 5) return true;
                }
                else n = 0;
            }
            return false;
        }
    }
}