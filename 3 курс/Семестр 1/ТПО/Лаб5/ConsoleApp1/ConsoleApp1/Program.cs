using System;

namespace ConsoleApp1
{
    public class Aster
    {
        int k = 0;
        private string str;

        public Aster(string ss)
        {
            str = ss;
        }

        public string AsterCheck(string str)
        {
            Replace(str);

            if (k > 0)
            {
                Console.WriteLine("Итоговая строка: " + str);
            }
            else Console.WriteLine("Знак '*' не найден");
            return str;
        }

        public int Replace(string str)
        {
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
            return k;
        }

    }
}