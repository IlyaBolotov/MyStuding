/*
 * Задача: написать программу для ввода квадратной матрицы 2х2 или 3х3 и нахождения её определителя
 */


using System;

namespace Матрицы
{
    class Program
    {
        static void Main(string[] args)
        {
            int N, det=0, i; // N - Размерность матрицы, det - детерминант, i - циклы
            string S;
            bool f;
            do
            {
                Console.WriteLine("Введите размеры квадратной матрицы (2 или 3)");
                S = Console.ReadLine();
                f = int.TryParse(S, out N);
                if (f)
                {
                    N = Convert.ToInt32(S);
                }
            } while ((N != 2) && (N != 3));
            N = (N * N);
            Console.WriteLine(N);
            int[] matrix = new int[N];
            Console.WriteLine("Вводите элементы матрицы построчно");
            i = 0;
            while (i<N)
            {
                matrix[i] = Convert.ToInt32(Console.ReadLine()); // Вводится сразу числовое, поэтому если не формата int, тог краш (:)
                i++;
            }
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine("Введённая матрица: ");
            Console.WriteLine();
            for (i = 0; i < N; ++i)
            {
                Console.Write(matrix[i] + " ");
                if ((matrix[i] < 10) && (matrix[i] >= 0)) Console.Write(" ");
                if (N == 4)
                { 
                    if (i==1)   Console.WriteLine(); 
                }
                else if ((i == 2) || (i == 5)) Console.WriteLine();
            }
            Console.WriteLine();
            if (N == 4) 
            {
                det = matrix[0] * matrix[3] - matrix[1] * matrix[2];
            }
            if (N == 9)
            {
                det = matrix[0] * matrix[4] * matrix[8] + matrix[6] * matrix[1] * matrix[5] + matrix[3] * matrix[7] * matrix[2] - matrix[6] * matrix[4] * matrix[2] - matrix[0] * matrix[7] * matrix[5] - matrix[1] * matrix[3] * matrix[8];
            }
            Console.WriteLine("Определитель = " + det);
            Console.ReadLine();
        }
    }
}
