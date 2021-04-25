using System;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class Lab1
    {
        static void Main(string[] args)
        {
            void AsterCheck()
            {
                Console.Clear();
                string str = "aetgsff*afdgsf";
                int k = 0;
                for (int i = 0; i < str.Length; i++)
                {
                    if (i == str.Length - 1)
                    {
                        Console.WriteLine("Знак '*' находится в конце, замена невозможна");
                        break;
                    }
                    else
                        if (str[i] == '*')
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
            }
        }
    }
}